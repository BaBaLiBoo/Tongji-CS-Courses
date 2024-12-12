#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <tchar.h>  // 包含TCHAR和_stprintf_s函数的头文件
#include <cstdio>   // 包含标准输入输出库的头文件
// 棋盘大小
const int BOARD_SIZE = 7;
// 棋子半径
const int PEG_RADIUS = 17;
// 棋盘初始状态
struct Board
{
    int board_standard[BOARD_SIZE][BOARD_SIZE] = {
         {-1, -1,  1,  1,  1, -1, -1},
    { -1, -1,  1,  1,  1, -1, -1 },
    {  1,  1,  1,  1,  1,  1,  1 },
    {  1,  1,  1,  0,  1,  1,  1 },
    {  1,  1,  1,  1,  1,  1,  1 },
    { -1, -1,  1,  1,  1, -1, -1 },
    { -1, -1,  1,  1,  1, -1, -1 }
    };
    int board_mess1[BOARD_SIZE][BOARD_SIZE] = {
        { -1 ,-1, 0 ,0 ,0 ,-1 ,-1},
    {-1, -1 ,0 ,1 ,0 ,-1 ,-1},
    { 0 ,0, 1, 1, 1 ,0 ,0 },
    { 0, 0 ,0, 1, 0, 0 ,0 },
    { 0, 0 ,0 ,1 ,0, 0, 0 },
    { -1, -1, 0, 0, 0 ,-1 ,-1 },
    { -1 ,-1, 0 ,0 ,0 ,-1 ,-1 }
    };
    int board_mess2[BOARD_SIZE][BOARD_SIZE] = {
        {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 1, 1, 0, -1, -1},
    { 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
    {-1, -1, 1, 1, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess3[BOARD_SIZE][BOARD_SIZE] = {
         {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess4[BOARD_SIZE][BOARD_SIZE] = {
            { -1, -1, 0, 0, 0, -1, -1 },
    { -1, -1, 0, 0, 0, -1, -1 },
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 1, 1, 1, 0, 0 },
    { -1, -1, 1, 1, 1, -1, -1 },
    { -1, -1, 0, 0, 0, -1, -1 }
    };
    int board_mess5[BOARD_SIZE][BOARD_SIZE] = {
            {-1, -1,  0,  0,  0, -1, -1},
    {-1, -1,  0,  0,  0, -1, -1},
    { 0,  0,  0,  0,  0,  1,  0},
    { 0,  0,  0,  0,  1,  1,  0},
    { 0,  0,  0,  0,  1,  0,  0},
    {-1, -1,  0,  1,  0, -1, -1},
    {-1, -1,  1,  1,  0, -1, -1}
    };
    int board_mess6[BOARD_SIZE][BOARD_SIZE] = {
        {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1},
    {0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 1, 1},
    {0, 0, 0, 1, 0, 1, 0},
    {-1, -1, 1, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess7[BOARD_SIZE][BOARD_SIZE] = {
        {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1},
    {0, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess8[BOARD_SIZE][BOARD_SIZE] = {
            {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1}
    };
    int board_mess9[BOARD_SIZE][BOARD_SIZE] = {
         {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0},
    {-1, -1, 1, 1, 1, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1}
    };
    int board_mess10[BOARD_SIZE][BOARD_SIZE] = {
          {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1},
    {0, 0, 1, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess11[BOARD_SIZE][BOARD_SIZE] = {
           {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1}
    };
    int board_mess12[BOARD_SIZE][BOARD_SIZE] = {
           {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 1, 0, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess13[BOARD_SIZE][BOARD_SIZE] = {
           {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess14[BOARD_SIZE][BOARD_SIZE] = {
         {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {-1, -1, 1, 1, 1, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess15[BOARD_SIZE][BOARD_SIZE] = {
        {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1},
    {0, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 0},
    {-1, -1, 0, 0, 1, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess16[BOARD_SIZE][BOARD_SIZE] = {
         {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 1, 1, 0, -1, -1},
    {0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 0},
    {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess17[BOARD_SIZE][BOARD_SIZE] = {
         {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 1, 0, 1, -1, -1},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {-1, -1, 1, 0, 1, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess18[BOARD_SIZE][BOARD_SIZE] = {
            {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1},
    {0, 0, 0, 0, 1, 1, 0},
    {1, 1, 0, 0, 0, 1, 1},
    {0, 1, 1, 0, 0, 0, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess19[BOARD_SIZE][BOARD_SIZE] = {
          {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1},
    {0, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess20[BOARD_SIZE][BOARD_SIZE] = {
            {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1},
    {0, 1, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 0},
    {0, 1, 1, 0, 1, 0, 0},
    {-1, -1, 1, 1, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess21[BOARD_SIZE][BOARD_SIZE] = {
        {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1},
    {0, 0, 1, 1, 1, 0, 0},
    {1, 1, 0, 1, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess22[BOARD_SIZE][BOARD_SIZE] = {
         {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 1, 1, 1, -1, -1},
    {0, 0, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess23[BOARD_SIZE][BOARD_SIZE] = {
            {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0},
    {0, 0, 1, 1, 1, 0, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1}
    };
    int board_mess24[BOARD_SIZE][BOARD_SIZE] = {
        {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1},
    {0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess25[BOARD_SIZE][BOARD_SIZE] = {
            {-1, -1, 0, 1, 1, -1, -1},
    {-1, -1, 1, 1, 0, -1, -1},
    {0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0},
    {-1, -1, 0, 1, 1, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess26[BOARD_SIZE][BOARD_SIZE] = {
            {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 1, 0},
    {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess27[BOARD_SIZE][BOARD_SIZE] = {
            {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 1, -1, -1},
    {0, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 0, 0},
    {-1, -1, 1, 1, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess28[BOARD_SIZE][BOARD_SIZE] = {
            {-1, -1, 0, 1, 1, -1, -1},
    {-1, -1, 0, 1, 1, -1, -1},
    {0, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 1, 0, 0, 0},
    {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0, 0, -1, -1}
    };
    int board_mess29[BOARD_SIZE][BOARD_SIZE] = {
           {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0},
    {0, 0, 1, 1, 1, 0, 0},
    {-1, -1, 0, 1, 0, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1}
    };
    int board_mess30[BOARD_SIZE][BOARD_SIZE] = {
           {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 1, 0, -1, -1},
    {0, 0, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 0, 1, 1},
    {0, 1, 1, 0, 1, 1, 0},
    {-1, -1, 0, 0, 0, -1, -1},
    {-1, -1, 0, 0,0,-1, -1}
    };
    int board_mess31[BOARD_SIZE][BOARD_SIZE] = {
           {-1, -1,  0,  0,  0, -1, -1},
    {-1, -1,  0,  0,  0, -1, -1},
    { 0,  0,  1,  1,  1,  0,  0},
    { 0,  1,  1,  1,  1,  1,  0},
    { 0,  0,  1,  1,  1,  0,  0},
    {-1, -1,  0,  0,  0, -1, -1},
    {-1, -1,  0,  0,  0, -1, -1}
    };
    int board_mess32[BOARD_SIZE][BOARD_SIZE] = {
          {-1, -1,  0,  0,  0, -1, -1},
    {-1, -1,  0,  0,  0, -1, -1},
    { 0,  0,  0,  1,  0,  0,  0},
    { 0,  1,  1,  0,  1,  1,  0},
    { 1,  1,  0,  1,  0,  1,  1},
    {-1, -1,  0,  1,  0, -1, -1},
    {-1, -1,  0,  1,  0, -1, -1}
    };
    int board_mess33[BOARD_SIZE][BOARD_SIZE] = {
           {-1, -1,  0,  1,  0, -1, -1},
    {-1, -1,  1,  1,  1, -1, -1},
    { 0,  0,  1,  1,  1,  0,  0},
    { 0,  1,  0,  0,  0,  1,  0},
    { 0,  0,  1,  0,  1,  0,  0},
    {-1, -1,  1,  0,  1, -1, -1},
    {-1, -1,  0,  0,  0, -1, -1}
    };
    int board_mess34[BOARD_SIZE][BOARD_SIZE] = {
            {-1, -1,  0,  0,  1, -1, -1},
    {-1, -1,  0,  1,  1, -1, -1},
    { 0,  0,  1,  1,  0,  0,  0},
    { 0,  1,  0,  1,  1,  0,  0},
    { 1,  1,  0,  1,  0,  1,  0},
    {-1, -1,  0,  0,  0, -1, -1},
    {-1, -1,  0,  0,  0, -1, -1}
    };
    int board_mess35[BOARD_SIZE][BOARD_SIZE] = {
          {-1, -1,  0,  0,  0, -1, -1},
    {-1, -1,  1,  0,  1, -1, -1},
    { 0,  0,  1,  1,  1,  0,  0},
    { 0,  1,  0,  1,  0,  1,  0},
    { 0,  0,  1,  1,  1,  0,  0},
    {-1, -1,  0,  1,  0, -1, -1},
    {-1, -1,  0,  0,  0, -1, -1}
    };
    int board_mess36[BOARD_SIZE][BOARD_SIZE] = {
           {-1, -1,  0,  0,  0, -1, -1},
    {-1, -1,  0,  0,  0, -1, -1},
    { 0,  0,  0,  0,  0,  0,  0},
    { 0,  1,  0,  1,  1,  0,  0},
    { 0,  0,  1,  1,  1,  0,  0},
    {-1, -1,  1,  1,  1, -1, -1},
    {-1, -1,  1,  1,  1, -1, -1}
    };
    int board_mess37[BOARD_SIZE][BOARD_SIZE] = {
         {-1, -1,  0,  0,  0, -1, -1},
    {-1, -1,  0,  0,  0, -1, -1},
    { 0,  0,  0,  0,  0,  0,  0},
    { 0,  1,  1,  1,  1,  1,  1},
    { 0,  0,  0,  1,  1,  0,  0},
    {-1, -1,  0,  1,  1, -1, -1},
    {-1, -1,  1,  1,  0, -1, -1}
    };
    int board_mess38[BOARD_SIZE][BOARD_SIZE] = {
          {-1, -1,  0,  1,  0, -1, -1},
    {-1, -1,  0,  1,  0, -1, -1},
    { 0,  0,  1,  1,  1,  0,  0},
    { 0,  1,  0,  0,  0,  1,  0},
    { 0,  0,  1,  1,  1,  0,  0},
    {-1, -1,  1,  0,  1, -1, -1},
    {-1, -1,  0,  0,  0, -1, -1}
    };
    int board_mess39[BOARD_SIZE][BOARD_SIZE] = {
         {-1, -1,  0,  0,  1, -1, -1},
    {-1, -1,  0,  1,  0, -1, -1},
    { 0,  0,  1,  1,  0,  0,  0},
    { 1,  1,  1,  1,  0,  0,  0},
    { 0,  0,  1,  1,  1,  1,  0},
    {-1, -1,  0,  0,  0, -1, -1},
    {-1, -1,  0,  0,  0, -1, -1}
    };
    int board_mess40[BOARD_SIZE][BOARD_SIZE] = {
         {-1, -1,  0,  0,  0, -1, -1},
    {-1, -1,  0,  1,  0, -1, -1},
    { 0,  0,  0,  1,  0,  0,  0},
    { 1,  1,  0,  1,  0,  1,  1},
    { 1,  1,  0,  0,  0,  1,  1},
    {-1, -1,  0,  1,  0, -1, -1},
    {-1, -1,  0,  1,  0, -1, -1}
    };
}board;
//主页
void menu();
//关卡选择页1
void menu1_mess();
//关卡选择页2
void menu2_mess();
//游戏规则页
bool help();
//弹窗：悔棋
bool askToRegret();
//弹窗：复原
bool askToRestore();
//弹窗：悔棋失败
void Remind();
//计算剩余棋子
int restPieces(int board_input[BOARD_SIZE][BOARD_SIZE]);
//绘制棋盘
bool drawBoard(int board_input[BOARD_SIZE][BOARD_SIZE], int rest, bool canMove);
//获取鼠标位置并对应数组
bool getMousePosition(int x, int y, int& row, int& col);
//游戏结束判断
bool endGame(int board_input[BOARD_SIZE][BOARD_SIZE]);
//游戏主体
bool playGame_standard(int board_input[BOARD_SIZE][BOARD_SIZE]);


int main()
{
    initgraph(500, 500);
    BeginBatchDraw();
    IMAGE img1;
    loadimage(NULL, _T("beginnew.jpg"), 500, 500, 1);
    putimage(0, 0, &img1);
    FlushBatchDraw();
    Sleep(1500);
    while (true)
    {
        menu();
        FlushBatchDraw();
        int x = 0;
        int y = 0;
        while (true)
        {
            if (MouseHit())
            {
                MOUSEMSG msg = GetMouseMsg();
                if (msg.uMsg == WM_LBUTTONDOWN)
                {
                    x = msg.x;
                    y = msg.y;
                }
                if (x > 285 && x < 460 && y>195 && y < 240)//经典模式
                {
                    playGame_standard(board.board_standard);
                    break; // 跳出内层循环，回到主循环
                }
                else if (x > 285 && x < 460 && y>255 && y < 300)//闯关模式
                {
                    bool page = true;
                    bool back = false;

                    while (true)
                    {
                        if (back)
                            break;
                        menu1_mess();
                        FlushBatchDraw();
                        int x2 = 0;
                        int y2 = 0;
                        while (true)
                        {
                            if (MouseHit())
                            {
                                MOUSEMSG msg = GetMouseMsg();
                                if (msg.uMsg == WM_LBUTTONDOWN)
                                {
                                    x2 = msg.x;
                                    y2 = msg.y;
                                }
                                if (x2 > 5 && x2 < 70 && y2>5 && y2 < 70)
                                {
                                    back = true;
                                    break;
                                }
                                if (x2 > 430 && x2 < 500 && y2>450 && y2 < 500 && page == true)//翻页
                                {
                                    menu2_mess();
                                    FlushBatchDraw();
                                    page = false;
                                }
                                if (x2 > 0 && x2 < 70 && y2>450 && y2 < 500 && page == false)//翻页
                                {
                                    page = true;
                                    break;
                                }
                                if (x2 > 40 && y2 > 110 && x2 < 100 && y2 < 180)//1
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess1);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess21);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 130 && y2 > 110 && x2 < 190 && y2 < 180)//2
                                {

                                    if (page == true)
                                        playGame_standard(board.board_mess2);
                                    else if (page == false)
                                    {
                                        playGame_standard(board.board_mess22);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 220 && y2 > 110 && x2 < 280 && y2 < 180)//3
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess3);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess23);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 310 && y2 > 110 && x2 < 370 && y2 < 180)//4
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess4);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess24);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 400 && y2 > 110 && x2 < 460 && y2 < 180)//5
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess5);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess25);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 40 && y2 > 200 && x2 < 100 && y2 < 270)//6
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess6);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess26);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 130 && y2 > 200 && x2 < 190 && y2 < 270)//7
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess7);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess27);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 220 && y2 > 200 && x2 < 280 && y2 < 270)//8
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess8);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess28);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 310 && y2 > 200 && x2 < 370 && y2 < 270)//9
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess9);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess29);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 400 && y2 > 200 && x2 < 460 && y2 < 270)//10
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess10);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess30);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 40 && y2 > 290 && x2 < 100 && y2 < 360)//11
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess11);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess31);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 130 && y2 > 290 && x2 < 190 && y2 < 460)//12
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess12);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess32);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 220 && y2 > 290 && x2 < 280 && y2 < 460)//13
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess13);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess33);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 310 && y2 > 290 && x2 < 370 && y2 < 460)//14
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess14);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess34);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 400 && y2 > 290 && x2 < 460 && y2 < 460)//15
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess15);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess35);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 40 && y2 > 380 && x2 < 100 && y2 < 450)//16
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess16);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess36);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 130 && y2 > 380 && x2 < 190 && y2 < 450)//17
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess17);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess37);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 220 && y2 > 380 && x2 < 280 && y2 < 450)//18
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess18);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess38);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 310 && y2 > 380 && x2 < 370 && y2 < 450)//19
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess19);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess39);
                                        page = true;
                                    }
                                    break;
                                }
                                if (x2 > 400 && y2 > 380 && x2 < 460 && y2 < 450)//20
                                {
                                    if (page == true)
                                        playGame_standard(board.board_mess20);
                                    if (page == false)
                                    {
                                        playGame_standard(board.board_mess40);
                                        page = true;
                                    }
                                    break;
                                }

                            }
                        }
                    }
                    break;
                }
                else if (x > 285 && x < 460 && y>315 && y < 360)//查看帮助
                {
                    help();
                    FlushBatchDraw();
                    break;

                }
            }
        }
    }
    EndBatchDraw();
    return 0;
}

//统计剩余棋子数
int restPieces(int board_input[BOARD_SIZE][BOARD_SIZE])
{
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board_input[i][j] == 1 || board_input[i][j] == 2) {
                count++;
            }
        }
    }
    return count;
}

// 绘制棋盘
bool drawBoard(int board_input[BOARD_SIZE][BOARD_SIZE], int rest, bool canMove)
{
    cleardevice();
    IMAGE img2;
    loadimage(NULL, _T("boardnew.jpg"), 500, 500, 1);
    // 将图片绘制到窗口上
    putimage(0, 0, &img2);
    setbkcolor(RGB(234, 221, 202));
    // 绘制棋盘背景
    //绘制棋盘网络
    setlinestyle(PS_SOLID, 3); // 设置线条样式，实线，宽度为 5
    setlinecolor(RGB(202, 202, 202)); // 设置线条颜色
    for (int i = 2; i < BOARD_SIZE - 1; ++i) {
        line(75, 75 + i * 50, 425, 75 + i * 50);
        line(75 + i * 50, 75, 75 + i * 50, 425);
    }
    for (int i = 0; i < 2; ++i) {
        line(175, 75 + i * 50, 325, 75 + i * 50);
        line(75 + i * 50, 175, 75 + i * 50, 325);
    }
    for (int i = 6; i < 8; ++i) {
        line(175, 75 + i * 50, 325, 75 + i * 50);
        line(75 + i * 50, 175, 75 + i * 50, 325);
    }
    // 绘制棋子
    FlushBatchDraw();
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board_input[i][j] != -1) {
                int x = 100 + j * 50;
                int y = 100 + i * 50;

                if (board_input[i][j] == 1) {
                    setfillcolor(RGB(255, 69, 0));
                    solidcircle(x, y, PEG_RADIUS);
                }
                else if (board_input[i][j] == 0) {
                    setfillcolor(RGB(245, 245, 220));
                    solidcircle(x, y, PEG_RADIUS + 2);
                }
                else if (board_input[i][j] == 2) {
                    setfillcolor(RGB(255, 255, 120));
                    solidcircle(x, y, PEG_RADIUS + 4);
                    setfillcolor(RGB(255, 69, 0));
                    solidcircle(x, y, PEG_RADIUS);

                }
            }
        }
    }
    FlushBatchDraw();
    // 绘制图标
    settextstyle(25, 0, _T("黑体"));
    settextcolor(BLACK);
    outtextxy(278, 460, _T("当前剩余棋子:"));
    setlinecolor(BLACK);
    FlushBatchDraw();
    TCHAR tmp[10];
    // 使用_stprintf_s将整数变量格式化为TCHAR字符串
    _stprintf_s(tmp, _T("%d"), rest);
    settextcolor(RED);
    outtextxy(460, 460, tmp);
    if (canMove == false && rest > 1)
    {
        Sleep(500);
        cleardevice();
        IMAGE img;
        loadimage(NULL, _T("sadnew.jpg"), 500, 500, 1);
        // 将图片绘制到窗口上
        putimage(0, 0, &img);
        settextcolor(BLACK);
        setbkmode(TRANSPARENT);
        settextstyle(30, 0, _T("楷体"));
        outtextxy(160, 300, _T("剩余棋子:"));
        outtextxy(310, 301, tmp);
        FlushBatchDraw();
        return false;
    }
    else if (canMove == false && rest == 1)
    {
        Sleep(500);
        cleardevice();
        IMAGE img;
        loadimage(NULL, _T("succeednew.jpg"), 500, 500, 1);
        // 将图片绘制到窗口上
        putimage(0, 0, &img);
        FlushBatchDraw();
        return false;
    }
    return true;
}

// 鼠标操作
bool getMousePosition(int x, int y, int& row, int& col)
{
    if ((x >= 175 && x <= 325 && y >= 75 && y <= 425) || (y >= 175 && y <= 325 && x >= 75 && x <= 425))
    {
        row = (y - 75) / 50;
        col = (x - 75) / 50;
        return true;
    }
    return false;
}

//游戏结束判断
bool endGame(int board_input[BOARD_SIZE][BOARD_SIZE])
{
    bool canMove = false;
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (board_input[i][j] == 1 || board_input[i][j] == 2)
            {
                if (i > 2)
                {
                    if ((board_input[i - 1][j] == 1 || board_input[i - 1][j] == 2) && board_input[i - 2][j] == 0)
                    {
                        canMove = true;
                        break;
                    }
                }
                if (i + 2 < 7)
                {
                    if ((board_input[i + 1][j] == 1 || board_input[i + 1][j] == 2) && board_input[i + 2][j] == 0)
                    {
                        canMove = true;
                        break;
                    }
                }
                if (j > 2)
                {
                    if ((board_input[i][j - 1] == 1 || board_input[i][j - 1] == 2) && board_input[i][j - 2] == 0)
                    {
                        canMove = true;
                        break;
                    }
                }
                if (j + 2 < 7)
                {
                    if ((board_input[i][j + 1] == 1 || board_input[i][j + 1] == 2) && board_input[i][j + 2] == 0)
                    {
                        canMove = true;
                        break;
                    }
                }
            }

        }
    return canMove;
}

//游戏主体
bool playGame_standard(int board_input[BOARD_SIZE][BOARD_SIZE])
{
    int x, y, row, col;
    bool end = true;
    int regretX1 = 0;//复原移动棋子
    int regretY1 = 0;
    int regretX2 = 0;//复原空位
    int regretY2 = 0;
    int regretX3 = 0;//复原消除棋子
    int regretY3 = 0;
    bool haveregret = false;
    int board_origin[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
            board_origin[i][j] = board_input[i][j];//保存初始状态以复原棋盘
    drawBoard(board_input, restPieces(board_input), endGame(board_input)); // 绘制初始盘面
    FlushBatchDraw();
    while (true)
    {
        if (MouseHit())
        {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN)
            {
                x = msg.x;
                y = msg.y;
                getMousePosition(x, y, row, col);
                if (x > 5 && x < 70 && y>5 && y < 38)
                {
                    // 返回菜单界面
                    for (int i = 0; i < BOARD_SIZE; ++i)
                        for (int j = 0; j < BOARD_SIZE; ++j)
                            board_input[i][j] = board_origin[i][j];//复原棋盘
                    return false;
                }
                else if (x > 435 && x < 495 && y>5 && y < 38)//悔棋
                {
                    if (haveregret == true && askToRegret())
                    {
                        board_input[regretX1][regretY1] = 1;
                        board_input[regretX2][regretY2] = 0;
                        board_input[regretX3][regretY3] = 1;
                        drawBoard(board_input, restPieces(board_input), endGame(board_input));
                        FlushBatchDraw();
                        haveregret = false;
                    }
                    else if (haveregret == false)
                    {
                        Remind();
                    }
                }
                else if (x > 5 && x < 70 && y>445 && y < 495)//复原
                {
                    if (askToRestore())
                    {
                        for (int i = 0; i < BOARD_SIZE; ++i)
                            for (int j = 0; j < BOARD_SIZE; ++j)
                                board_input[i][j] = board_origin[i][j];//复原棋盘
                        drawBoard(board_input, restPieces(board_input), endGame(board_input));
                        haveregret = false;
                        FlushBatchDraw();
                    }
                }
                if (getMousePosition(x, y, row, col))
                {
                    if (board_input[row][col] == 1)//选中棋子
                    { // 将之前被选中的棋子恢复，保证只有一个棋子被选中
                        for (int i = 0; i < BOARD_SIZE; ++i) {
                            for (int j = 0; j < BOARD_SIZE; ++j) {
                                if (board_input[i][j] == 2) {
                                    board_input[i][j] = 1;
                                }
                            }
                        }
                        board_input[row][col] = 2; // 选中当前点击的棋子
                        if (end == true)
                        {
                            drawBoard(board_input, restPieces(board_input), endGame(board_input));
                            FlushBatchDraw();
                        }
                    }
                    else if (board_input[row][col] == 0)//移动棋子
                    {
                        if (board_input[row - 2][col] == 2 && board_input[row - 1][col] == 1)
                        {
                            haveregret = true;
                            regretX1 = row - 2;
                            regretY1 = col;
                            regretX2 = row;
                            regretY2 = col;
                            regretX3 = row - 1;
                            regretY3 = col;
                            board_input[row - 2][col] = 0;
                            board_input[row][col] = 1;
                            board_input[row - 1][col] = 0;
                            if (endGame(board_input) == false)
                                end = false;
                            if (end == true)
                            {
                                drawBoard(board_input, restPieces(board_input), endGame(board_input));
                                FlushBatchDraw();
                            }
                        }
                        else if (board_input[row + 2][col] == 2 && board_input[row + 1][col] == 1)
                        {
                            haveregret = true;
                            regretX1 = row + 2;
                            regretY1 = col;
                            regretX2 = row;
                            regretY2 = col;
                            regretX3 = row + 1;
                            regretY3 = col;
                            board_input[row + 2][col] = 0;
                            board_input[row][col] = 1;
                            board_input[row + 1][col] = 0;
                            if (endGame(board_input) == false)
                                end = false;
                            if (end == true)
                            {
                                drawBoard(board_input, restPieces(board_input), endGame(board_input));
                                FlushBatchDraw();
                            }
                        }
                        else if (board_input[row][col - 2] == 2 && board_input[row][col - 1] == 1)
                        {
                            haveregret = true;
                            regretX1 = row;
                            regretY1 = col - 2;
                            regretX2 = row;
                            regretY2 = col;
                            regretX3 = row;
                            regretY3 = col - 1;
                            board_input[row][col - 2] = 0;
                            board_input[row][col] = 1;
                            board_input[row][col - 1] = 0;
                            if (endGame(board_input) == false)
                                end = false;
                            if (end == true)
                            {
                                drawBoard(board_input, restPieces(board_input), endGame(board_input));
                                FlushBatchDraw();
                            }
                        }
                        else if (board_input[row][col + 2] == 2 && board_input[row][col + 1] == 1)
                        {
                            haveregret = true;
                            regretX1 = row;
                            regretY1 = col + 2;
                            regretX2 = row;
                            regretY2 = col;
                            regretX3 = row;
                            regretY3 = col + 1;
                            board_input[row][col + 2] = 0;
                            board_input[row][col] = 1;
                            board_input[row][col + 1] = 0;
                            if (endGame(board_input) == false)
                                end = false;
                            if (end == true)
                            {
                                drawBoard(board_input, restPieces(board_input), endGame(board_input));
                                FlushBatchDraw();
                            }
                        }
                    }
                    if (end == false)//结束
                    {
                        drawBoard(board_input, restPieces(board_input), endGame(board_input));
                        FlushBatchDraw();
                        for (int i = 0; i < BOARD_SIZE; ++i)
                            for (int j = 0; j < BOARD_SIZE; ++j)
                                board_input[i][j] = board_origin[i][j];//复原棋盘
                        Sleep(1500);
                        return false;
                    }

                }
            }
        }
    }
    return true;
}

//初始界面
void menu()
{
    cleardevice();
    IMAGE img2;
    loadimage(NULL, _T("background.jpg"), 500, 500, 1);

    // 将图片绘制到窗口上
    putimage(0, 0, &img2);
    settextstyle(60, 0, _T("宋体"));
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    outtextxy(150, 50, _T("孔明棋"));
    settextstyle(30, 0, _T("Times New Roman"));
    outtextxy(180, 115, _T("Peg Solitaire"));
    settextstyle(40, 0, _T("楷体"));
    settextcolor(BLACK);
    outtextxy(290, 200, _T("经典模式"));
    outtextxy(290, 260, _T("残局模式"));
    outtextxy(290, 320, _T("游戏规则"));
}

//游戏规则
bool help()
{
    int x = 0;
    int y = 0;
    cleardevice();
    IMAGE img2;
    loadimage(NULL, _T("rule.jpg"), 500, 500, 1);
    FlushBatchDraw();
    // 将图片绘制到窗口上
    putimage(0, 0, &img2);
    settextstyle(30, 0, _T("宋体"));
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    outtextxy(430, 450, _T("返回"));
    FlushBatchDraw();
    while (true)
    {
        if (MouseHit())
        {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN)
            {
                x = msg.x;
                y = msg.y;
                if (x > 425 && x < 490 && y>445 && y < 490)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

//悔棋确定
bool askToRegret()
{
    int msgboxID = MessageBox(
        NULL,
        L"确定悔棋吗",
        L"Do you want to regret",
        MB_ICONQUESTION | MB_YESNO
    );

    return (msgboxID == IDYES);
}

//复原确定
bool askToRestore()
{
    int msgboxID = MessageBox(
        NULL,
        L"确定复原棋盘吗",
        L"Do you want to restore",
        MB_ICONQUESTION | MB_YESNO
    );

    return (msgboxID == IDYES);
}

//无法悔棋提示
void Remind()
{
    int msgboxID = MessageBox(
        NULL,
        L"当前状态无法悔棋",
        L"提示",
        MB_ICONQUESTION | MB_OK
    );
}

//第一页目录
void menu1_mess()
{
    cleardevice();
    IMAGE img2;
    loadimage(NULL, _T("choose1.jpg"), 500, 500, 1);
    // 将图片绘制到窗口上
    putimage(0, 0, &img2);
}

//第二页目录
void menu2_mess()
{
    cleardevice();
    IMAGE img2;
    loadimage(NULL, _T("choose2.jpg"), 500, 500, 1);
    // 将图片绘制到窗口上
    putimage(0, 0, &img2);
}
