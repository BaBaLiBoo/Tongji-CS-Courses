# 给定条件下构造矩阵
## 题目描述
给你一个 正 整数 k ，同时给你：

一个大小为 n 的二维整数数组 rowConditions ，其中 rowConditions[i] = [abovei, belowi] 和

一个大小为 m 的二维整数数组 colConditions ，其中 colConditions[i] = [lefti, righti] 。

两个数组里的整数都是 1 到 k 之间的数字。

你需要构造一个 k x k 的矩阵，1 到 k 每个数字需要 恰好出现一次 。剩余的数字都是 0 。

矩阵还需要满足以下条件：

对于所有 0 到 n - 1 之间的下标 i ，数字 abovei 所在的 行 必须在数字 belowi 所在行的上面。

对于所有 0 到 m - 1 之间的下标 i ，数字 lefti 所在的 列 必须在数字 righti 所在列的左边。

返回满足上述要求的矩阵，题目保证若矩阵存在则一定唯一；如果不存在答案，返回一个空的矩阵。
## 输入
第一行包含3个整数k、n和m

接下来n行，每行两个整数abovei、belowi，描述rowConditions数组

接下来m行，每行两个整数lefti、righti，描述colConditions数组
## 输出
如果可以构造矩阵，打印矩阵；否则输出-1

矩阵中每行元素使用空格分隔

样例输入
3 2 2

1 2

2 3

2 3

3 1

样例输出
0 0 1

2 0 0

0 3 0

## 题目来源
LeetCode 2392.给定条件下构造矩阵
