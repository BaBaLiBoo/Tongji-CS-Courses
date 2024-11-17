//大作业：2048

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int only_ask_once = 0;//在通关后，只询问一次是否继续
//自定义函数声明
void wait_for_enter();//等待换行
void print_menu();//主页菜单
void print_help();//帮助
void print_exit();//退出
void hideCursor();//隐藏光标
void setCursorPosition(int x, int y);//设置光标位置
void print_interface(int board[4][4], int& score, int step);//展示游戏版面
void play_game();//游戏主体
void Random(int board[4][4]);//随机位置生成随机数2/4
int generateNumber();//随机生成2/4
bool move_up(int board[4][4],int& score);//上移
bool move_down(int board[4][4], int& score);//下移
bool move_left(int board[4][4], int& score);//左移
bool move_right(int board[4][4], int& score);//右移
bool End(int board[4][4]);//判断游戏是否结束
bool askToContinue();//选择游戏是否继续


int main()
{
	char choice = '\0';
	// 设置控制台标题为2048
	SetConsoleTitle(TEXT("2048"));
	// 主循环
	while (1)
	{
		// 调用菜单显示函数
		print_menu();
		// 获取用户选择
		choice = _getche();

		// 根据用户选择进行相应操作
		switch (choice)
		{
		case 'a':
			play_game();
			break;
		case 'b':
			print_help();
			break;
		case 'c':
			print_exit();
			exit(0);
		default:
			cout << "\n输入错误，请从新输入" << endl;
			wait_for_enter();
		}
	}
	return 0;
}

void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

void print_menu()
{
	// 清屏
	system("CLS");
	// 获取标准输出设备句柄
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	// 设置控制台文字颜色
	SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN);
	// 打印菜单
	cout << "--------------------------------------------\n";
	cout << "********************************************\n";
	// 设置控制台文字颜色
	SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	// 打印标题
	cout << "                   2048\n";
	cout << "                a.经典模式\n";
	cout << "                b.游戏规则\n";
	cout << "                c.退出游戏\n";
	// 设置控制台文字颜色
	SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN);
	// 打印菜单
	cout << "********************************************\n";
	cout << "--------------------------------------------\n";

	// 恢复控制台文字颜色为默认颜色
	SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n请输入你的选择(a-c):";
}

void print_help()
{
	// 清屏
	system("CLS");
	// 获取标准输出设备句柄
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	// 设置控制台文字颜色
	SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << "--------------------------------------------\n";
	cout << "********************************************\n\n";
	// 设置控制台文字颜色
	SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	// 打印游戏规则
	cout << "操作说明：\n\n";
	cout << "↓：下   ←：左  ↑：上  →：右  ESC键：退出\n\n";
	cout << "游戏介绍：\n\n";
	cout << "每次选择一个方向移动，移动时数字向该方向靠拢\n";
	cout << "相同数字可合并，移动后空格处会生成随机数字2/4\n";
	cout << "如果得到数字2048，则游戏胜利!\n";
	cout << "如果棋盘被数字填满，无法进行移动，则游戏失败!\n\n";
	// 设置控制台文字颜色
	SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << "********************************************\n";
	cout << "--------------------------------------------\n";
	// 恢复控制台文字颜色为默认颜色
	SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wait_for_enter();
}

void print_exit()
{
	cout << "\n退出中";
	for (int i = 4; i > 0; --i)
	{
		Sleep(200);
		cout << ".";
	}
}

void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void setCursorPosition(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(consoleHandle, cursorPosition);
}


void print_interface(int board[4][4], int& score, int step)
{
	hideCursor();
	setCursorPosition(0, 0); // 设置光标位置到控制台左上角
	//获取标准输入设备句柄
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	// 设置控制台文字颜色
	SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN);
	// 打印游戏界面
	cout << "            --------------------------------------------\n";
	cout << "            分数：" << setw(6) << score << "              步数：" << setw(6) << step << endl;
	cout << "            --------------------------------------------\n";
	cout << "            ********************************************\n";
	// 设置控制台文字颜色
	SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "                       |----|----|----|----|\n";

	for (int i = 0; i < 4; i++)
	{
		cout << "                       |";
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != 0)
			{
				if (board[i][j] == 2)
				{
					SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 白色
					cout << setw(4) << board[i][j] ;
				}
				else if (board[i][j] == 4)
				{
					SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//浅黄
					cout << setw(4) << board[i][j];
				}
				else if (board[i][j] == 8)
				{
					SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN);//黄色
					cout << setw(4) << board[i][j];
				}
				else if (board[i][j] == 16)
				{
					SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//浅紫色
					cout << setw(4) << board[i][j];
				}
				else if (board[i][j] == 32)
				{
					SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_BLUE);//紫色
					cout << setw(4) << board[i][j];
				}
				else if (board[i][j] == 64)
				{
					SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_INTENSITY);//浅红
					cout << setw(4) << board[i][j];
				}
				else if (board[i][j] == 128)
				{
					SetConsoleTextAttribute(handle_out, FOREGROUND_RED);//红色
					cout << setw(4) << board[i][j];
				}
				else if (board[i][j] == 256)
				{
					SetConsoleTextAttribute(handle_out, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//浅蓝绿色
					cout << setw(4) << board[i][j];
				}
				else if (board[i][j] == 512)
				{
					SetConsoleTextAttribute(handle_out, FOREGROUND_GREEN | FOREGROUND_BLUE);//蓝绿色
					cout << setw(4) << board[i][j];
				}
				else if (board[i][j] == 1024)
				{
					SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE);//蓝色
					cout << setw(4) << board[i][j];
				}
				else if (board[i][j] == 2048)
				{
					SetConsoleTextAttribute(handle_out, FOREGROUND_GREEN);//绿色
					cout << setw(4) << board[i][j];

					if (only_ask_once == 0)
					{
						if (!askToContinue()) {
							// 清屏
							system("CLS");
							only_ask_once++;
							exit(0);
						}
						else
							only_ask_once++;
					}
				}
				else
				{
					SetConsoleTextAttribute(handle_out, FOREGROUND_GREEN);//超过2048后均显示绿色
					cout << setw(4) << board[i][j];
				}
				SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "|";
			}
			else
			{
				cout << "    |";
			}
		}
		cout << "\n                       |----|----|----|----|\n";
	}

	// 设置控制台文字颜色
	SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "            ********************************************\n";
	cout << "            --------------------------------------------\n";
	cout << "            ↓：下   ←：左  ↑：上  →：右  ESC键：退出\n\n";

	// 恢复控制台文字颜色为默认颜色
	SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void play_game()
{
	// 变量声明
	int board[4][4] = {}; // 4*4的棋盘
	int score = 0;		  // 分数
	int step = 0;		  // 步数
	char choice;	  // 用户选择
	bool validmove=true;
	// 游戏初始化，包括生成随机数等操作
	srand((int)time(0));
	Random(board);
	Random(board);
	
	// 打印游戏界面
	print_interface(board, score, step);
	while (1)
	{
		validmove = true;
		// 获取用户输入
		choice = _getch();
		if (choice < 0) // 检查是否是特殊键
		{ 
			choice = _getch(); // 获取第二个字符（键码）
		}
		// 根据用户输入进行相应操作
		switch (choice)
		{
		case 72: // 上箭头键
			validmove = move_up(board, score);
			break;
		case 80: // 下箭头键
			validmove = move_down(board, score);
			break;
		case 75: // 左箭头键
			validmove = move_left(board, score);
			break;
		case 77: // 右箭头键
			validmove = move_right(board, score);
			break;
		case 27://ESC键
			exit(0);
		default:
			cout << "错误按键：请输入↑↓←→键" << endl;
			wait_for_enter();
			system("CLS");
			break;
		}
		if (validmove)
			step++;
		print_interface(board, score, step);
		Sleep(80);
		//在空格处随机生成2/4
		if (validmove)
			Random(board);
		// 打印游戏界面
		print_interface(board, score, step);
		// 判断游戏是否结束，如果结束则跳出循环
		int count = 0;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				if (board[i][j] == 0)
				{
					count++;
				}
		if (count == 0&& End(board))
		{
			cout << "游戏结束" << endl;
			print_exit();
			exit(0);
		}
	}
	// 游戏结束
	print_exit();
}

void Random(int board[4][4])
{
	//创建一个二维数组，储存当前盘面所有空格位置
	int blank_in_board[16][2] = {};
	int count_blank = 0;
	//查找盘面空格
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			if (board[i][j] == 0)
			{
				blank_in_board[count_blank][0] = i;
				blank_in_board[count_blank][1] = j;
				++count_blank;
			}
	
	int random_position = rand() % (count_blank) + 0;
	int randon_row = blank_in_board[random_position][0];
	int randon_col = blank_in_board[random_position][1];
	board[randon_row][randon_col] = generateNumber();
}

int generateNumber()//按9：1的比例随机生成2/4
{
	
	int r = rand() % 100; // 生成一个在 [0, 100) 范围内的随机数
	if (r < 90)
		return 2; // 90% 的概率返回 2
	else 
		return 4; // 10% 的概率返回 4
}

bool move_up(int board[4][4],int& score)
{
	bool move = false;//判断是否可以沿此方向移动
	for (int i = 1; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (board[i][j] != 0)
			{	//移动盘面
				for (int n = i - 1; n >= 0; --n)
					if (board[n][j] != 0)
					{
						//合并相同数字
						if (board[n][j] == board[n + 1][j] )
						{
							board[n][j] *= 2;
							board[n + 1][j] = 0;
							score += board[n][j];
							move = true;
							board[n][j] ++;//使它变为奇数，从而防止被二次合并
						}
						break;
					}
					else
					{
						board[n][j] = board[n + 1][j];
						board[n + 1][j] = 0;
						move = true;
					}
			}
		}
	}
	//将所有的奇数还原
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (board[i][j] % 2 == 1)
				--board[i][j];
	if (move == true)
		return true;
	else
		return false;
}

bool move_down(int board[4][4],int& score)
{
	bool move = false;
	for (int i = 2; i >= 0; --i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (board[i][j] != 0)
			{	//移动盘面
				for (int n = i + 1; n < 4; ++n)
					if (board[n][j] != 0)
					{
						//合并相同数字
						if (board[n][j] == board[n - 1][j])
						{
							board[n][j] *= 2;
							board[n - 1][j] = 0;
							score += board[n][j];
							move = true;
							board[n][j]++;
						}
						break;
					}
					else
					{
						board[n][j] = board[n - 1][j];
						board[n - 1][j] = 0;
						move = true;
					}
			}
		}
	}
	//将所有的奇数还原
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (board[i][j] % 2 == 1)
				--board[i][j];

	if (move == true)
		return true;
	else
		return false;
}

bool move_left(int board[4][4],int& score)
{
	bool move = false;
	for (int j = 1; j < 4; ++j)
		for (int i = 0; i < 4; ++i)
		{
			if (board[i][j] != 0)
			{	//移动盘面
				for (int n = j - 1; n >= 0; --n)
					if (board[i][n] != 0)
					{
						//合并相同数字
						if (board[i][n] == board[i][n+1])
						{
							board[i][n] *= 2;
							board[i][n+1] = 0;
							score += board[i][n];
							move = true;
							board[i][n]++;
						}
						break;
					}
					else
					{
						board[i][n] = board[i][n+1];
						board[i][n+1] = 0;
						move = true;
					}
			}
		}
	//将所有的奇数还原
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (board[i][j] % 2 == 1)
				--board[i][j];

	if (move == true)
		return true;
	else
		return false;
}

bool move_right(int board[4][4],int& score)
{
	bool move = false;
	for (int j = 2; j >= 0; --j)
		for (int i = 0; i < 4; ++i)
		{
			if (board[i][j] != 0)
			{	
				//移动盘面
				for (int n = j + 1; n <4; ++n)
					if (board[i][n] != 0)
					{
						//合并相同数字
						if (board[i][n] == board[i][n - 1])
						{
							board[i][n] *= 2;
							board[i][n - 1] = 0;
							score += board[i][n];
							move = true;
							board[i][n]++;
						}
						break;
					}
					else
					{
						board[i][n] = board[i][n - 1];
						board[i][n - 1] = 0;
						move = true;
					}
			}
		}
	//将所有的奇数还原
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (board[i][j] % 2 == 1)
				--board[i][j];

	if (move == true)
		return true;
	else
		return false;
}

bool End(int board[4][4])
{
	bool move = false;//判断是否可以沿此方向移动
	//向上
	for (int i = 1; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (board[i][j] != 0)
				for (int n = i - 1; n >= 0; --n)
					if (board[n][j] != 0)
					{
						if (board[n][j] == board[n + 1][j])
							move = true;
						break;
					}
					else
						move = true;
	//向下
	for (int i = 2; i >=0; --i)
		for (int j = 0; j < 4; ++j)
			if (board[i][j] != 0)
				for (int n = i + 1; n <4;++n)
					if (board[n][j] != 0)
					{
						if (board[n][j] == board[n - 1][j])
							move = true;
						break;
					}
					else
						move = true;
	//向左
	for (int j = 1; j < 4; ++j)
		for (int i = 0; i < 4; ++i)
			if (board[i][j] != 0)
				for (int n = j - 1; n >= 0; --n)
					if (board[i][n] != 0)
					{
						if (board[i][n] == board[i][n+1])
							move = true;
						break;
					}
					else
						move = true;
	//向右
	for (int j = 2; j >=0 ; --j)
		for (int i = 0; i < 4; ++i)
			if (board[i][j] != 0)
				for (int n = j + 1; n < 4;++n)
					if (board[i][n] != 0)
					{
						if (board[i][n] == board[i][n - 1])
							move = true;
						break;
					}
					else
						move = true;
	if (move == true)
		return false;
	else
		return true;
}

bool askToContinue()
{
	int msgboxID = MessageBox(
		NULL,
		L"成功通关！你想要继续游戏吗？",
		L"Continue Game",
		MB_ICONQUESTION | MB_YESNO
	);

	return (msgboxID == IDYES);
}
