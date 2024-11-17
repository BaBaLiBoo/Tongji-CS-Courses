#include <conio.h>
#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
bool isNumber(const string input);
char menu();
void wait_for_enter();
bool  matriplus();
bool nummulti();
bool matritrans();
bool matrimulti();
bool hadamulti();
bool conv();
void demo();
void OTSU();
void segmention();

int main()
{
	cout << "欢迎来到我的大作业之<矩阵运算>" << endl;
	wait_for_enter();
	while (true) // 注意该循环退出的条件
	{
		char ch;
		char choice;
		system("cls"); // 清屏函数
		choice = menu();
		if (choice == '0') // 选择退出
		{
			cout << "\n 确定退出吗? 输入yes（退出）/no（继续）" << endl;
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
				break;
			else
				continue;
		}
		switch (choice)
		{
		case '1':
			matriplus();
			break;
		case '2':
			nummulti();
			break;
		case '3':
			matritrans();
			break;
		case '4':
			matrimulti();
			break;
		case '5':
			hadamulti();
			break;
		case '6':
			conv();
			break;
		case '7':
			demo();
			break;
		case '8':
			OTSU();
			break;
		case '9':
			segmention();
			break;
		default:
			cout << "\n 输入错误，请重新输入" << endl;
			wait_for_enter();
		}
	}
	return 0;
}

bool isNumber(const string input)//判断是否为数字输入
{
	if (input.empty()) //检查输入是否为空
		return false;
	size_t i = 0;
	bool hasDigits = false;
	// 检查可能存在的符号部分
	if (input[i] == '+' || input[i] == '-')
		++i;
	// 检查数字部分
	while (i < input.size())
	{
		if (isdigit(input[i]))
			hasDigits = true;
		else
			return false; // 非数字的字符
		++i;
	}
	return hasDigits; // 至少要有一个数字字符
}
char menu()//主页菜单
{
	for (int i = 1; i <= 57; ++i)
		cout << "*";
	cout << endl;
	cout << " *      1 矩阵加法      2 矩阵数乘      3 矩阵转置      *" << endl;
	cout << " *      4 矩阵乘法      5 Hadamard乘积  6 矩阵卷积      *" << endl;
	cout << " *      7 卷积应用      8 OTSU 算法     9 segmentation  *" << endl;
	cout << " *                      0 退出系统                      *" << endl;
	for (int i = 1; i <= 57; ++i)
		cout << "*";
	cout << endl;

	cout << "选择菜单项<0~9>：";
	char ch = _getch();
	cout << ch << endl;
	return ch;
}
void wait_for_enter()
{
	cout << endl
		<< "按回车键继续...";
	while (_getch() != '\r')
		;
	cout << endl
		<< endl;
}
bool  matriplus()//矩阵加法
{
	int row, col;
	int Matrix_1[256 * 256] = {};
	int Matrix_2[256 * 256] = {};
	string input;
	cout << "欢迎来到：矩阵加法";
	cout << "（返回目录：输入'quit'）" << endl;
	wait_for_enter();
	while (true)
	{
		system("cls");
		cout << "请输入计算的矩阵行数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵加法计算。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			row = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}
	while (row > 256 || row < 1)
	{
		cout << "超出范围！请重新输入矩阵行数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵加法计算。" << endl;
			wait_for_enter();
			return false;
		}
		else row = stoi(input);
	}

	while (true)
	{
		cout << "请输入计算的矩阵列数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵加法计算。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			col = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}

	while (col > 256 || col < 1)
	{
		cout << "超出范围！请重新输入矩阵列数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵加法计算。" << endl;
			wait_for_enter();
			return false;
		}
		else col = stoi(input);
	}
	cout << "请输入第一个" << row << "×" << col << "矩阵：" << endl;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			cin >> input;
			if (input == "quit")
			{
				cout << "退出矩阵加法计算。" << endl;
				wait_for_enter();
				return false;
			}
			else
				Matrix_1[i * col + j] = stoi(input);
		}
	cout << "请输入第二个" << row << "×" << col << "矩阵：" << endl;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			cin >> input;
			if (input == "quit")
			{
				cout << "退出矩阵加法计算。" << endl;
				wait_for_enter();
				return false;
			}
			else
				Matrix_2[i * col + j] = stoi(input);
		}

	cout << "两矩阵相加的结果为：" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << Matrix_1[i * col + j] + Matrix_2[i * col + j] << " ";
		}
		cout << endl;
	}
	wait_for_enter();

}
bool nummulti()//矩阵数乘
{
	string input;
	int row, col, k;
	int Matrix[256 * 256] = {};
	cout << "欢迎来到：矩阵数乘";
	cout << "（返回目录：输入'quit'）" << endl;
	wait_for_enter();
	while (true)
	{
		system("cls");
		cout << "请输入计算的矩阵行数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵数乘计算。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			row = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}
	while (row > 256 || row < 1)
	{
		cout << "超出范围！请重新输入矩阵行数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵数乘计算。" << endl;
			wait_for_enter();
			return false;
		}
		else row = stoi(input);
	}
	while (true)
	{
		cout << "请输入计算的矩阵列数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵数乘计算。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			col = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}
	while (col > 256 || col < 1)
	{
		cout << "超出范围！请重新输入矩阵列数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵数乘计算。" << endl;
			wait_for_enter();
			return false;
		}
		else col = stoi(input);
	}

	cout << "请输入一个" << row << "×" << col << "矩阵：" << endl;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			cin >> input;
			if (input == "quit")
			{
				cout << "退出矩阵数乘计算。" << endl;
				wait_for_enter();
				return false;
			}
			else
				Matrix[i * col + j] = stoi(input);
		}

	while (true)
	{
		cout << "请输入一个整数：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵数乘计算。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			k = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}
	cout << "数乘运算的结果为：" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << k * Matrix[i * col + j] << " ";
		}
		cout << endl;
	}
	wait_for_enter();
}
bool matritrans()//矩阵转置
{
	int row, col;
	int Matrix[256 * 256] = {};
	string input;
	cout << "欢迎来到：矩阵转置";
	cout << "（返回目录：输入'quit'）" << endl;
	wait_for_enter();
	while (true)
	{
		system("cls");
		cout << "请输入计算的矩阵行数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵转置。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			row = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}
	while (row > 256 || row < 1)
	{
		cout << "超出范围！请重新输入矩阵行数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵转置。" << endl;
			wait_for_enter();
			return false;
		}
		else row = stoi(input);
	}

	while (true)
	{
		cout << "请输入计算的矩阵列数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵转置。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			col = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}

	while (col > 256 || col < 1)
	{
		cout << "超出范围！请重新输入矩阵列数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵转置。" << endl;
			wait_for_enter();
			return false;
		}
		else col = stoi(input);
	}
	cout << "请输入初始的" << row << "×" << col << "矩阵：" << endl;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			cin >> input;
			if (input == "quit")
			{
				cout << "退出矩阵转置。" << endl;
				wait_for_enter();
				return false;
			}
			else
				Matrix[i * col + j] = stoi(input);
		}
	cout << "矩阵转置的结果为：" << endl;
	for (int j = 0; j < col; ++j)
	{
		for (int i = 0; i < row; ++i)
			cout << Matrix[i * col + j] << " ";
		cout << endl;
	}
	wait_for_enter();
}
bool matrimulti()//矩阵乘法
{
	int row, col, col2;
	int Matrix_1[256 * 256] = {};
	int Matrix_2[256 * 256] = {};
	int Matrix_multi[256 * 256] = {};
	string input;
	cout << "欢迎来到：矩阵乘法";
	cout << "（返回目录：输入'quit'）" << endl;
	wait_for_enter();
	while (true)
	{
		system("cls");
		cout << "请输入第一个矩阵的行数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵乘法计算。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			row = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}
	while (row > 256 || row < 1)
	{
		cout << "超出范围！请重新输入第一个矩阵的行数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵乘法计算。" << endl;
			wait_for_enter();
			return false;
		}
		else row = stoi(input);
	}
	while (true)
	{
		cout << "请输入第一个矩阵的列数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵乘法计算。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			col = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}
	while (col > 256 || col < 1)
	{
		cout << "超出范围！请重新输入第一个矩阵的列数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵乘法计算。" << endl;
			wait_for_enter();
			return false;
		}
		else col = stoi(input);
	}
	while (true)
	{
		cout << "请输入第二个的矩阵列数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵数乘计算。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			col2 = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}
	while (col2 > 256 || col2 < 1)
	{
		cout << "超出范围！请重新输入第二个矩阵的列数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵乘法计算。" << endl;
			wait_for_enter();
			return false;
		}
		else col2 = stoi(input);
	}
	cout << "请输入第一个" << row << "×" << col << "矩阵：" << endl;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			cin >> input;
			if (input == "quit")
			{
				cout << "退出矩阵乘法计算。" << endl;
				wait_for_enter();
				return false;
			}
			else
				Matrix_1[i * col + j] = stoi(input);
		}
	cout << "请输入第二个" << col << "×" << col2 << "矩阵：" << endl;
	for (int i = 0; i < col; ++i)
		for (int j = 0; j < col2; ++j)
		{
			cin >> input;
			if (input == "quit")
			{
				cout << "退出矩阵乘法计算。" << endl;
				wait_for_enter();
				return false;
			}
			else
				Matrix_2[i * col2 + j] = stoi(input);
		}

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col2; ++j)
			for (int k = 0; k < col; ++k)
				Matrix_multi[i * col2 + j] += Matrix_1[i * col + k] * Matrix_2[j * col + k];
	cout << "两矩阵相乘的结果为：" << endl;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col2; ++j)
			cout << Matrix_multi[i * col2 + j] << " ";
	cout << endl;
	wait_for_enter();
}
bool hadamulti()//Hadamard乘积
{
	int row, col;
	int Matrix_1[256 * 256] = {};
	int Matrix_2[256 * 256] = {};
	string input;
	cout << "欢迎来到：Hadamard乘积";
	cout << "（返回目录：输入'quit'）" << endl;
	wait_for_enter();
	while (true)
	{
		system("cls");
		cout << "请输入计算的矩阵行数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出Hadamard乘积计算。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			row = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}

	while (row > 256 || row < 1)
	{
		cout << "超出范围！请重新输入矩阵行数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出Hadamard乘积计算。" << endl;
			wait_for_enter();
			return false;
		}
		else row = stoi(input);
	}

	while (true)
	{
		cout << "请输入计算的矩阵列数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出Hadamard乘积计算。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			col = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}
	while (col > 256 || col < 1)
	{
		cout << "超出范围！请重新输入矩阵列数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出Hadamard乘积计算。" << endl;
			wait_for_enter();
			return false;
		}
		else col = stoi(input);
	}
	cout << "请输入第一个" << row << "×" << col << "矩阵：" << endl;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			cin >> input;
			if (input == "quit")
			{
				cout << "退出Hadamard乘积计算。" << endl;
				wait_for_enter();
				return false;
			}
			else
				Matrix_1[i * col + j] = stoi(input);
		}
	cout << "请输入第二个" << row << "×" << col << "矩阵：" << endl;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			cin >> input;
			if (input == "quit")
			{
				cout << "退出Hadamard乘积计算。" << endl;
				wait_for_enter();
				return false;
			}
			else
				Matrix_2[i * col + j] = stoi(input);
		}

	cout << "两矩阵相加的结果为：" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << Matrix_1[i * col + j] * Matrix_2[i * col + j] << " ";
		}
		cout << endl;
	}
	wait_for_enter();
}
bool conv()//矩阵卷积
{
	int row;
	int Matrix[256 * 256] = {};
	int Matrix_padding[258 * 258] = {};
	int Matrix_kernel[3 * 3] = {};
	int Matrix_result[256 * 256] = {};
	string input;
	cout << "欢迎来到：矩阵卷积";
	cout << "（返回目录：输入'quit'）" << endl;
	wait_for_enter();
	//1.输入被卷积矩阵
	while (true)
	{
		system("cls");
		cout << "请输入被卷积的矩阵行（列）数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵卷积计算。" << endl;
			wait_for_enter();
			return false;
		}
		else if (isNumber(input))
		{
			row = stoi(input);
			break;
		}
		else if (!isNumber(input))
		{
			cout << "输入错误，请重新输入" << endl;
			wait_for_enter();
			system("cls");
		}
	}
	while (row > 256 || row < 1)
	{
		cout << "超出范围！请重新输入矩阵行（列）数<1~256>：";
		cin >> input;
		if (input == "quit")
		{
			cout << "退出矩阵卷积计算。" << endl;
			wait_for_enter();
			return false;
		}
		else row = stoi(input);
	}
	cout << "请输入一个" << row << "×" << row << "的被卷积矩阵：" << endl;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j)
		{
			cin >> input;
			if (input == "quit")
			{
				cout << "退出矩阵卷积计算。" << endl;
				wait_for_enter();
				return false;
			}
			else
				Matrix[i * row + j] = stoi(input);
		}
	//2.padding=1
	for (int j = 0; j < row + 2; ++j)
	{
		Matrix_padding[0 * (row + 2) + j] = 0;
		Matrix_padding[(row + 1) * (row + 2) + j] = 0;
	}
	for (int i = 0; i < row + 2; ++i)
	{
		Matrix_padding[i * (row + 2) + 0] = 0;
		Matrix_padding[i * (row + 2) + (row + 1)] = 0;
	}
	for (int i = 1; i < row + 1; ++i)
		for (int j = 1; j < row + 1; ++j)
			Matrix_padding[i * (row + 2) + j] = Matrix[(i - 1) * row + (j - 1)];
	//3.输入卷积核
	cout << "请输入一个3×3的矩阵（卷积核）：" << endl;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			cin >> input;
			if (input == "quit")
			{
				cout << "退出矩阵卷积计算。" << endl;
				wait_for_enter();
				return false;
			}
			else
				Matrix_kernel[i * 3 + j] = stoi(input);
		}
	//4..进行卷积计算
	for (int i = 1; i < row + 1; ++i)
		for (int j = 1; j < row + 1; ++j)
		{
			Matrix_result[(i - 1) * row + (j - 1)] = Matrix_padding[(i - 1) * (row + 2) + (j - 1)] * Matrix_kernel[0] + Matrix_padding[(i - 1) * (row + 2) + j] *
				Matrix_kernel[1] + Matrix_padding[(i - 1) * (row + 2) + (j + 1)] * Matrix_kernel[2] + Matrix_padding[i * (row + 2) + (j - 1)] *
				Matrix_kernel[3] + Matrix_padding[i * (row + 2) + j] * Matrix_kernel[4] + Matrix_padding[i * (row + 2) + (j + 1)] *
				Matrix_kernel[5] + Matrix_padding[(i + 1) * (row + 2) + (j - 1)] * Matrix_kernel[6] + Matrix_padding[(i + 1) * (row + 2) + j]
				* Matrix_kernel[7] + Matrix_padding[(i + 1) * (row + 2) + (j + 1)] * Matrix_kernel[8];
		}
	//5.输出卷积结果
	cout << "矩阵卷积结果为：" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row; ++j)
			cout << Matrix_result[i * row + j] << " ";
		cout << endl;
	}
	wait_for_enter();
}
void demo() {
	cout << "欢迎来到：卷积应用" << endl;
	wait_for_enter();
	//读入图像
	Mat image = imread("C:\\Users\\29532\\Desktop\\同济 学习\\高程\\作业\\bHomeork_matrix\\images\\demolena.jpg", IMREAD_GRAYSCALE); // 以灰度模式读取图像
	Mat kernel1 = (Mat_<float>(3, 3) << 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0);
	Mat kernel2 = (Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
	Mat kernel3 = (Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	Mat kernel4 = (Mat_<float>(3, 3) << -1, -1, -1, -1, 9, -1, -1, -1, -1);
	Mat kernel5 = (Mat_<float>(3, 3) << -1, -1, 0, -1, 0, 1, 0, 1, 1);
	Mat kernel6 = (Mat_<float>(3, 3) << 1.0 / 16.0, 1.0 / 8.0, 1.0 / 16.0, 1.0 / 8.0, 1.0 / 4.0, 1.0 / 8.0, 1.0 / 16.0, 1.0 / 8.0, 1.0 / 16.0);
	//定义六张输出图像
	Mat output_image1;
	Mat output_image2;
	Mat output_image3;
	Mat output_image4;
	Mat output_image5;
	Mat output_image6;
	//卷积，其中2、3、5卷积核的和为0，增加偏移量128
	filter2D(image, output_image1, -1, kernel1);
	filter2D(image, output_image2, -1, kernel2, Point(-1, -1), 128);
	filter2D(image, output_image3, -1, kernel3, Point(-1, -1), 128);
	filter2D(image, output_image4, -1, kernel4);
	filter2D(image, output_image5, -1, kernel5, Point(-1, -1), 128);
	filter2D(image, output_image6, -1, kernel6);
	//输出原始图像与六张卷积后的图像
	namedWindow("Original Image", WINDOW_NORMAL);
	resizeWindow(" Original Image", 200, 200);
	imshow("Original Image", image);
	moveWindow("Original Image", 280, 250);

	namedWindow("1 Output Image", WINDOW_NORMAL);
	resizeWindow("1 Output Image", 200, 200);
	imshow("1 Output Image", output_image1);
	moveWindow("1 Output Image", 480, 250);

	namedWindow("2 Output Image", WINDOW_NORMAL);
	resizeWindow("2 Output Image", 200, 200);
	imshow("2 Output Image", output_image2);
	moveWindow("2 Output Image", 680, 250);

	namedWindow("3 Output Image", WINDOW_NORMAL);
	resizeWindow("3 Output Image", 200, 200);
	imshow("3 Output Image", output_image3);
	moveWindow("3 Output Image", 880, 250);

	namedWindow("4 Output Image", WINDOW_NORMAL);
	resizeWindow("4 Output Image", 200, 200);
	imshow("4 Output Image", output_image4);
	moveWindow("4 Output Image", 480, 450);

	namedWindow("5 Output Image", WINDOW_NORMAL);
	resizeWindow("5 Output Image", 200, 200);
	imshow("5 Output Image", output_image5);
	moveWindow("5 Output Image", 680, 450);

	namedWindow("6 Output Image", WINDOW_NORMAL);
	resizeWindow("6 Output Image", 200, 200);
	imshow("6 Output Image", output_image6);
	moveWindow("6 Output Image", 880, 450);

	waitKey(0);  // 等待按键
	destroyAllWindows();//关闭所有窗口
}
void OTSU()//OTSU算法
{
	cout << "欢迎来到：OTSU算法" << endl;
	wait_for_enter();
	// 读取图像
	Mat src = imread("C:\\Users\\29532\\Desktop\\同济 学习\\高程\\作业\\bHomeork_matrix\\images\\demolena.jpg");
	// 转换为灰度图像
	Mat gray_img;
	cvtColor(src, gray_img, COLOR_BGR2GRAY);
	// 应用 OTSU自动阈值
	Mat dst;
	double otsu_thresh = threshold(gray_img, dst, 0, 255, THRESH_BINARY + THRESH_OTSU);

	namedWindow("Original Image", WINDOW_NORMAL);
	namedWindow("Otsu Thresholded Image", WINDOW_NORMAL);

	// 调整窗口大小
	resizeWindow("Original Image", 200, 200);
	resizeWindow("Otsu Thresholded Image", 200, 180);
	// 显示结果
	imshow("Original Image", src);
	imshow("Otsu Thresholded Image", dst);
	waitKey(0);
	destroyAllWindows();
}
void segmention()
{
	cout << "欢迎来到：segmention" << endl;
	wait_for_enter();
	// 读取图像
	Mat img1 = imread("C:\\Users\\29532\\Desktop\\同济 学习\\高程\\作业\\bHomeork_matrix\\images\\snowball.jpg");
	Mat img2 = imread("C:\\Users\\29532\\Desktop\\同济 学习\\高程\\作业\\bHomeork_matrix\\images\\polyhedrosis.jpg");
	Mat img3 = imread("C:\\Users\\29532\\Desktop\\同济 学习\\高程\\作业\\bHomeork_matrix\\images\\ship.jpg");
	Mat img4 = imread("C:\\Users\\29532\\Desktop\\同济 学习\\高程\\作业\\bHomeork_matrix\\images\\brain.jpg");
	// 转换为灰度图像
	Mat gray_img1;
	Mat gray_img2;
	Mat gray_img3;
	Mat gray_img4;
	cvtColor(img1, gray_img1, COLOR_BGR2GRAY);
	cvtColor(img2, gray_img2, COLOR_BGR2GRAY);
	cvtColor(img3, gray_img3, COLOR_BGR2GRAY);
	cvtColor(img4, gray_img4, COLOR_BGR2GRAY);
	// 计算图像像素值的中位数
	Scalar mean_value1 = mean(gray_img1);
	Scalar mean_value2 = mean(gray_img2);
	Scalar mean_value3 = mean(gray_img3);
	Scalar mean_value4 = mean(gray_img4);
	double median_value1 = mean_value1[0];
	double median_value2 = mean_value2[0];
	double median_value3 = mean_value3[0];
	double median_value4 = mean_value4[0];
	// 阈值处理，得到二值化图像
	Mat thresh1;
	Mat thresh2;
	Mat thresh3;
	Mat thresh4;
	threshold(gray_img1, thresh1, median_value1, 255, THRESH_BINARY);
	threshold(gray_img2, thresh2, median_value2, 255, THRESH_BINARY);
	threshold(gray_img3, thresh3, 0, 255, THRESH_BINARY + THRESH_OTSU);
	threshold(gray_img4, thresh4, median_value4, 255, THRESH_BINARY);
	// 进行形态学操作，运用开运算去除小物体
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); // 定义形态学操作的核
	morphologyEx(thresh1, thresh1, MORPH_OPEN, kernel);
	morphologyEx(thresh2, thresh2, MORPH_OPEN, kernel);
	morphologyEx(thresh3, thresh3, MORPH_OPEN, kernel);
	morphologyEx(thresh4, thresh4, MORPH_OPEN, kernel);
	// 创建一个和原始图像大小一样的掩码图像
	Mat mask1 = Mat::zeros(img1.size(), CV_8UC1);
	Mat mask2 = Mat::zeros(img2.size(), CV_8UC1);
	Mat mask3 = Mat::zeros(img3.size(), CV_8UC1);
	Mat mask4 = Mat::zeros(img4.size(), CV_8UC1);
	// 将阈值化后的图像作为掩码，保留原始图像中阈值化后的区域
	img1.copyTo(mask1, thresh1);
	img2.copyTo(mask2, thresh2);
	img3.copyTo(mask3, thresh3);
	img4.copyTo(mask4, thresh4);
	//将星星、船两张图片的保留部分提亮
	double alpha1 = 2;  // 亮度增益因子
	double alpha2 = 1.2;
	double beta = 0;    // 增加的亮度偏移量
	Mat brighter_mask2;
	Mat brighter_mask3;
	mask2.convertTo(brighter_mask2, -1, alpha1, beta);  // 执行亮度增强
	mask3.convertTo(brighter_mask3, -1, alpha2, beta);
	// 显示原始图像和结果图像
	namedWindow("1 Original Image", WINDOW_NORMAL);
	resizeWindow("1 Original Image", 200, 150);
	imshow("1 Original Image", img1);
	//设置窗口位置
	moveWindow("1 Original Image", 120, 320);

	namedWindow("1 Result Image", WINDOW_NORMAL);
	resizeWindow("1 Result Image", 200, 150);
	imshow("1 Result Image", mask1);
	moveWindow("1 Result Image", 320, 320);

	namedWindow("2 Original Image", WINDOW_NORMAL);
	resizeWindow("2 Original Image", 196, 180);
	imshow("2 Original Image", img2);
	moveWindow("2 Original Image", 520, 320);

	namedWindow("2 Result Image", WINDOW_NORMAL);
	resizeWindow("2 Result Image", 196, 180);
	imshow("2 Result Image", brighter_mask2);
	moveWindow("2 Result Image", 716, 320);

	namedWindow("3 Original Image", WINDOW_NORMAL);
	resizeWindow("3 Original Image", 192, 144);
	imshow("3 Original Image", img3);
	moveWindow("3 Original Image", 120, 500);

	namedWindow("3 Result Image", WINDOW_NORMAL);
	resizeWindow("3 Result Image", 192, 144);
	imshow("3 Result Image", brighter_mask3);
	moveWindow("3 Result Image", 321, 500);

	namedWindow("4 Original Image", WINDOW_NORMAL);
	resizeWindow("4 Original Image", 179, 117);
	imshow("4 Original Image", img4);
	moveWindow("4 Original Image", 511, 520);

	namedWindow("4 Result Image", WINDOW_NORMAL);
	resizeWindow("4 Result Image", 179, 117);
	imshow("4 Result Image", mask4);
	moveWindow("4 Result Image", 690, 520);
	// 等待用户按下任意键
	waitKey(0);

	// 关闭所有窗口
	destroyAllWindows();
}
