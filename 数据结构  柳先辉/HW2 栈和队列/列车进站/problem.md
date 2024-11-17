# **列车进站**

## **描述**
每一时刻，列车可以从入口进车站或直接从入口进入出口，再或者从车站进入出口。即每一时刻可以有一辆车沿着箭头a或b或c的方向行驶。 现在有一些车在入口处等待，给出该序列，然后给你多组出站序列，请你判断是否能够通过上述的方式从出口出来。 

## **输入**
第1行，一个串，入站序列。
后面多行，每行一个串，表示出栈序列
当输入=EOF时结束
## **输出**
多行，若给定的出栈序列可以得到，输出yes,否则输出no

样例输入
abc
abc
acb
bac
bca
cab
cba

样例输出
yes
yes
yes
yes
no
yes

## **提示**
判断是否读入EOF，可用while (cin>>str)来作为循环条件

## **解题思路**
参考leetcode 31题的题解 https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/solution/
