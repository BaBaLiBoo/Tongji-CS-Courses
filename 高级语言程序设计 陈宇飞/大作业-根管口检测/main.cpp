#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include<algorithm>
#include <numeric>
#include <cmath> 
#include <cstdlib>
using namespace std;
using namespace cv;
using namespace ml;


//1.图像预处理
Mat Preprocess(Mat img);

//2.获取Hot特征
void computeGradient(const Mat& image, Mat& gradX, Mat& gradY);
void computeHistogram(const Mat& gradX, const Mat& gradY, Mat& hist, int cellSize);
void normalizeBlocks(const Mat& hist, Mat& hog, int blockSize, int cellSize);
vector<float> extractHOG(const Mat& image, int cellSize, int blockSize, double gamma);

//3.非极大值抑制
pair<float, float> calculateCenter(const Rect& box);
vector<int> nonMaximumSuppression(const vector<Rect>& boxes, const vector<float>& scores, float iouThreshold, float minDistance);

//4.根管口检测
void Predict(const Mat& origin, const Mat& img, const Mat& img_pre);


//主函数
int main()
{
    // 设置 OpenCV 日志等级为静默模式
    utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);
    cout << "开始检测，请耐心等待" << endl;
    Mat img = imread("tooth/test_img/30.1.png");
    Mat origin = img.clone();
    if (img.empty()) {
        cerr << "Error: Unable to open image!" << endl;
        return -1;
    }
    Mat img_pre = Preprocess(img);
    Predict(origin, img, img_pre);
    return 0;
}


// 1.图像预处理
Mat Preprocess(Mat img)
{
    //灰度化
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    Mat edges5;
    double otsuThresh = threshold(gray, gray, 0, 255, THRESH_BINARY | THRESH_OTSU);
    double lowThresh = 0.5 * otsuThresh;
    double highThresh = otsuThresh;
    //边缘检测
    GaussianBlur(gray, gray, Size(5, 5), 0);
    Canny(gray, edges5, lowThresh, highThresh);
    //二值化应用自适应阈值
    Mat adaptiveThresh;
    adaptiveThreshold(edges5, adaptiveThresh, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);
    vector<vector<Point> > contours_tmp;//存放所有轮廓
    vector<vector<Point> > contours;//存放最终轮廓
    vector<Vec4i> hierarchy;// 存放轮廓层次
    findContours(adaptiveThresh, contours_tmp, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
    //绘制所有边缘
    Mat drawing = Mat::zeros(adaptiveThresh.size(), CV_8UC3);
    for (int i = 0; i < contours_tmp.size(); i++)
    {
        Scalar color = Scalar(255, 255, 255);
        drawContours(drawing, contours_tmp, i, color, 2, 8, hierarchy, 0, Point());
    }
    //筛选有效轮廓
    for (size_t t = 0; t < contours_tmp.size(); t++)
    {
        //计算轮廓周长
        double len = arcLength(contours_tmp[t], true);
        if (len > 500)
            contours.push_back(contours_tmp[t]);
    }
    //拟合椭圆并绘制有效轮廓
    bool found = false;
    Mat drawing_valid = Mat::zeros(edges5.size(), CV_8UC3);
    RotatedRect oval_best;
    double area_min = 1000000;
    for (int i = 0; i < contours.size(); i++)
    {
        if (contours[i].size() >= 1000) {
            // 拟合椭圆
            RotatedRect ellipse1 = fitEllipse(contours[i]);
            double width = ellipse1.size.width;
            double height = ellipse1.size.height;
            // 绘制拟合的椭圆
            if (width > 0 && height > 0)
            {
                double a = max(height, width) / 2.0;  // 长轴的一半
                double b = min(height, width) / 2.0;  // 短轴的一半
                double eccentricity = sqrt(1 - (b * b) / (a * a)); // 离心率计算
                double ellipseArea = CV_PI * a * b; //面积计算
                if (eccentricity < 0.7 && ellipseArea>300000 && ellipseArea < 400000)
                {
                    if (ellipseArea < area_min)
                    {
                        area_min = ellipseArea;
                        oval_best = ellipse1;
                        found = true;
                    }
                }
            }
        }
        Scalar color = Scalar(255, 255, 255);
        // 绘制近似轮廓
        drawContours(drawing_valid, contours, i, color, 2, 8, hierarchy, 0, Point());
    }
    if (found)
        ellipse(drawing_valid, oval_best, Scalar(0, 0, 255), 2); // 用红色绘制
    else {
        // 设置椭圆的参数
        oval_best = RotatedRect(Point(605, 540), Size(600, 500), 90);
        ellipse(drawing_valid, oval_best, Scalar(0, 0, 255), 2); // 用红色绘制
    }
    // 使用掩膜提取原图的椭圆部分
    Mat mask = Mat::zeros(img.size(), CV_8UC1); // 创建掩膜，初始化为全黑    // 在掩膜上绘制白色椭圆
    ellipse(mask, oval_best, Scalar(255), -1); // 用白色填充椭圆区域
    Mat extracted;
    img.copyTo(extracted, mask);
    Mat extracted2 = Mat::Mat(img.size(), CV_8UC3, Scalar(255, 255, 255));
    extracted.copyTo(extracted2, mask);

    //二值化突出根管口
    Mat gray2;
    cvtColor(extracted2, extracted2, COLOR_BGR2GRAY);
    //计算像素平均值
    Scalar grayMean = mean(extracted2);
    //计算像素最小值
    int min = 255;
    for (int i = 0; i < extracted2.rows; ++i) {
        for (int j = 0; j < extracted2.cols; ++j) {
            if (min > extracted2.at<uchar>(i, j))
                min = extracted2.at<uchar>(i, j);
        }
    }
    int count_min = 0;
    int count_mean = 0;
    for (int i = 0; i < extracted2.rows; ++i) {
        for (int j = 0; j < extracted2.cols; ++j) {
            if (grayMean[0] - 150 > extracted2.at<uchar>(i, j))
                count_mean++;
        }
    }
    for (int i = 0; i < extracted2.rows; ++i) {
        for (int j = 0; j < extracted2.cols; ++j) {
            if (min + 30 > extracted2.at<uchar>(i, j))
                count_min++;
        }
    }
    if (count_mean > 10000 && count_min > 10000)
        threshold(extracted2, gray2, grayMean[0] - 160, 255, THRESH_BINARY_INV);
    else if (count_mean > 20000 && count_min < 20000)
    {
        if (count_min < 300)
            threshold(extracted2, gray2, min + 45, 255, THRESH_BINARY_INV);
        else
            threshold(extracted2, gray2, min + 30, 255, THRESH_BINARY_INV);
    }
    else if (count_mean < 20000 && count_min > 20000)
    {
        if (count_mean < 300)
            threshold(extracted2, gray2, grayMean[0] - 140, 255, THRESH_BINARY_INV);
        else
            threshold(extracted2, gray2, grayMean[0] - 150, 255, THRESH_BINARY_INV);
    }
    else if (count_mean < 20000 && count_min < 20000)
    {
        if (count_mean > 2000 && count_min > 2000)
            count_mean < count_min ?
            threshold(extracted2, gray2, grayMean[0] - 150, 255, THRESH_BINARY_INV) :
            threshold(extracted2, gray2, min + 25, 255, THRESH_BINARY_INV);
        else
            count_mean > count_min ?
            threshold(extracted2, gray2, grayMean[0] - 150, 255, THRESH_BINARY_INV) :
            threshold(extracted2, gray2, min + 30, 255, THRESH_BINARY_INV);

    }
    medianBlur(gray2, gray2, 5);
    return gray2;
}

// 2.获取Hot特征
void computeGradient(const Mat& image, Mat& gradX, Mat& gradY)
{
    Sobel(image, gradX, CV_32F, 1, 0, 3);
    Sobel(image, gradY, CV_32F, 0, 1, 3);
}
void computeHistogram(const Mat& gradX, const Mat& gradY, Mat& hist, int cellSize)
{
    int bins = 9;
    float binWidth = 180.0 / bins;
    hist = Mat::zeros(gradX.rows / cellSize, gradX.cols / cellSize, CV_32FC(bins));

    for (int i = 0; i < gradY.rows; i++) {
        for (int j = 0; j < gradY.cols; j++) {
            float angle = atan2(gradY.at<float>(i, j), gradX.at<float>(i, j)) * 180 / CV_PI;
            if (angle < 0) angle += 180;
            float magnitude = sqrt(gradX.at<float>(i, j) * gradX.at<float>(i, j) + gradY.at<float>(i, j) * gradY.at<float>(i, j));
            int bin = static_cast<int>(angle / binWidth);

            int histRow = i / cellSize;
            int histCol = j / cellSize;
            if (histRow < hist.rows && histCol < hist.cols && bin < bins) {
                hist.at<Vec<float, 9>>(histRow, histCol)[bin] += magnitude;
            }
        }
    }
}
void normalizeBlocks(const Mat& hist, Mat& hog, int blockSize, int cellSize)
{
    int blocksX = hist.cols - blockSize / cellSize + 1;
    int blocksY = hist.rows - blockSize / cellSize + 1;
    int bins = hist.channels();
    hog = Mat::zeros(blocksY * blocksX, (blockSize / cellSize) * (blockSize / cellSize) * bins, CV_32F);

    for (int i = 0; i < blocksY; i++) {
        for (int j = 0; j < blocksX; j++) {
            Mat blockHist = hist(Range(i, i + blockSize / cellSize), Range(j, j + blockSize / cellSize)).clone();
            blockHist = blockHist.reshape(1, 1);
            normalize(blockHist, blockHist);
            blockHist.copyTo(hog.row(i * blocksX + j));
        }
    }
}
vector<float> extractHOG(const Mat& image, int cellSize, int blockSize, double gamma) {

    // 计算梯度
    Mat gradX, gradY;
    computeGradient(image, gradX, gradY);

    // 计算方向直方图
    Mat hist;
    computeHistogram(gradX, gradY, hist, cellSize);

    // 特征块标准化
    Mat hog;
    normalizeBlocks(hist, hog, blockSize, cellSize);

    // 将HOG特征转换为vector并返回
    if (hog.total() > 0) {
        hog = hog.reshape(1, 1); // 将其转换为一维
    }
    vector<float> hogFeatures;
    hog.copyTo(hogFeatures);

    return hogFeatures;
}

// 3.非极大值抑制
pair<float, float> calculateCenter(const Rect& box) {
    float centerX = box.x + box.width / 2.0f;
    float centerY = box.y + box.height / 2.0f;
    return { centerX, centerY };
}
vector<int> nonMaximumSuppression(const vector<Rect>& boxes, const vector<float>& scores, float iouThreshold, float minDistance) {
    if (boxes.empty()) return {};

    vector<int> indices;
    vector<int> sortedIndices(boxes.size());
    iota(sortedIndices.begin(), sortedIndices.end(), 0);
    sort(sortedIndices.begin(), sortedIndices.end(), [&scores](int i, int j) { return scores[i] > scores[j]; });

    vector<bool> suppressed(boxes.size(), false);

    for (size_t i = 0; i < sortedIndices.size(); ++i) {
        int idx = sortedIndices[i];
        if (suppressed[idx]) continue;

        // 保留当前框
        indices.push_back(idx);

        // 普通方式获取中心点
        std::pair<float, float> center1 = calculateCenter(boxes[idx]);
        float centerX1 = center1.first;
        float centerY1 = center1.second;

        for (size_t j = i + 1; j < sortedIndices.size(); ++j) {
            int nextIdx = sortedIndices[j];
            if (suppressed[nextIdx]) continue;

            // 计算 IoU
            float iou = (float)(boxes[idx] & boxes[nextIdx]).area() / (boxes[idx] | boxes[nextIdx]).area();
            if (iou > iouThreshold) {
                if (scores[nextIdx] > scores[idx]) {
                    // 抑制当前框
                    suppressed[idx] = true;
                    indices.pop_back(); // 移除当前框的索引
                    indices.push_back(nextIdx); // 保留得分更高的框
                    idx = nextIdx; // 更新当前框索引
                }
                else {
                    suppressed[nextIdx] = true; // 抑制得分较低的框
                }
            }

            // 计算中心点距离
            std::pair<float, float> center2 = calculateCenter(boxes[nextIdx]);
            float centerX2 = center2.first;
            float centerY2 = center2.second;
            float distance = std::sqrt(std::pow(centerX2 - centerX1, 2) + std::pow(centerY2 - centerY1, 2));

            // 如果距离小于minDistance，保留得分更高的框
            if (distance < minDistance) {
                if (scores[nextIdx] > scores[idx]) {
                    // 抑制当前框
                    suppressed[idx] = true;
                    indices.pop_back(); // 移除当前框的索引
                    indices.push_back(nextIdx); // 保留得分更高的框
                    idx = nextIdx; // 更新当前框索引
                }
                else {
                    suppressed[nextIdx] = true; // 抑制得分较低的框
                }
            }
        }
    }

    return indices; // 返回保留的边界框索引
}

// 4.根管口检测
void Predict(const Mat& origin, const Mat& img, const Mat& img_pre)
{
    Ptr<SVM> svm = SVM::load("310_svm_64.xml"); 
    if (svm->empty()) {
        cerr << "加载SVM模型失败！请检查文件路径。" << endl;
        exit(0);
    }
    Size window_size = Size(128, 128);
    Size block_size = Size(16, 16);
    Size cell_size = Size(8, 8);
    int num_bins = 9;
    // 在图片上滑动窗口并提取HOG特征
    std::vector<Rect> boxes; // 存储检测框
    std::vector<float> scores;   // 存储对应的置信度分数
    for (int y = 0; y <= img_pre.rows - window_size.height; y += 64) {
        for (int x = 0; x <= img_pre.cols - window_size.width; x += 64) {
            // 定义窗口区域
            Rect window(x, y, window_size.width, window_size.height);
            Mat windowImage = img_pre(window);
            vector<float> hogFeatures = extractHOG(windowImage, cell_size.width, block_size.width, 0.0);
            Mat sampleFeature(hogFeatures);
            Mat transposedFeature = sampleFeature.t();
            // 使用SVM模型进行预测
            float response = svm->predict(transposedFeature, cv::noArray(), cv::ml::StatModel::RAW_OUTPUT);
            if (0.46 > response && response > 0.25)
            {
                boxes.push_back(window);
                scores.push_back(response);

            }
            // 输出进度条
            int totalSteps = (img_pre.rows / 16) * (img_pre.cols / 16); 
            int currentStep = (y / 16) * (img_pre.cols / 16) + (x / 16);
            float progress = static_cast<float>(currentStep) / totalSteps;
            int barWidth = 50;
            std::cout << "\r[";
            int pos = barWidth * progress;
            for (int i = 0; i < barWidth; ++i) {
                if (i < pos) std::cout << "=";
                else std::cout << " ";
            }
            std::cout << "] " << std::setw(6) << std::setprecision(2) << std::fixed << (progress * 100) << " %";
            std::cout.flush(); // 刷新输出流
        }
    }
    system("cls");
    // 非极大值抑制
    std::vector<int> finalIndices = nonMaximumSuppression(boxes, scores, 0, 175);
    for (int idx : finalIndices) {
        if (idx < 0 || idx >= boxes.size() || idx >= scores.size()) {
            std::cerr << "Index out of range: " << idx << std::endl;
            continue;
        }
        rectangle(img, boxes[idx], Scalar(0, 255, 0), 2); // 绘制检测框
        std::string label = cv::format("%.2f", scores[idx]); // 在检测框上写出置信度
        cv::putText(img, label, boxes[idx].tl(), cv::FONT_HERSHEY_SIMPLEX,1.2, cv::Scalar(0, 0, 0), 2);
    }
    cout << "检测完成！" << endl;
    // 输出原始图像 & 检测结果
    namedWindow("Original Image", WINDOW_NORMAL);
    namedWindow("result", WINDOW_NORMAL);
    resizeWindow("Original Image", 450, 400);
    resizeWindow("result", 450, 400);
    imshow("Original Image", origin);
    imshow("result", img);
    waitKey(0);
}
