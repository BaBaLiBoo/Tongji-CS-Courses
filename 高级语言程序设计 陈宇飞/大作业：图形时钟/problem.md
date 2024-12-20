# 图形时钟
## 一、题目描述
一个钟表工厂遇到了难题，他们想设计一些新的钟表形式，但是却苦于没有想法。他们的钟表非常神奇，内置了一个可编程模块和一块 RGB 全彩显示屏，支持 C/C++的语言烧录。现在他们找到了你，希望你能帮他们设计一款好的钟表界面，下面是他们上一个被辞退的员工作品，可以供你参考。

![image](https://github.com/user-attachments/assets/5330cd5e-299d-4021-a259-dcc34bdc289d)

## 二、TODO
⚠ 本次作业请使用结构体 / 类和对象进行程序设计与实现。 ⚠

⭕ 本次作业请在完成全部基础项的同时，在进阶项中任选一个进行完成。如果你完成了多个进阶项的要求，将酌情加分。⭕

### 1. 基础项
① 使用 EasyX 库进行钟表编程，在屏幕中以图形的方式绘制时钟，要求时针、分针、秒针随时间的变化而变化。

② 时钟面盘可以随意设计，能看出主要分隔和功能即可，但是注意显示时间的准确。不要做得和参考界面相似。

### 2. 进阶项
① 时钟设计融入自己的巧思

② 时钟能够实现抗锯齿算法

③ 使用了其他图像处理算法

请在提交项目中添加 readme 文件简要说明你实现的进阶项。

## 三、参考资料
EasyX参考下载地址：EasyX doc.rar，请自行下载安装并学习使用。

参考框架如下：
```
int main()
{
    struct tm t;
    time_t now;
    time(&now);
    localtime_s(&t, &now);	// 获取当地时间
    initgraph(640, 480);	// 图形方式初始化
    init();			// 自定义图形初始化函数，用于绘制时钟界面

    while (!_kbhit())	// 无键盘操作时进入循环
    {
        /* 不停获取当前时间，与之前绘制时/分/秒针时的时间相比，
        以判断新时间的到来 */
        /* 根据新的时间重新绘制时针，分针，秒针，
        可以自定义函数完成，注意坐标数据类型 */
    }
    _getch();		// 按任意键准备退出时钟程序
    closegraph();		// 退出图形界面
    return 0;
}
```
