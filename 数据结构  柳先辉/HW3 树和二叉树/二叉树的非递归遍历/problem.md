# 二叉树的非递归遍历
描述:
二叉树的非递归遍历可通过栈来实现。例如对于由abc##d##ef###先序建立的二叉树，如下图1所示，中序非递归遍历（参照课本p131算法6.3）可以通过如下一系列栈的入栈出栈操作来完成：push(a) push(b) push(c) pop pop push(d)pop pop push(e) push(f) pop pop。
![image](https://github.com/user-attachments/assets/2ea3e7fb-4f11-4fd2-993c-ea48d551198d)

提示：本题有多种解法，仔细分析二叉树非递归遍历过程中栈的操作规律与遍历序列的关系，可将二叉树构造出来。

输入:
第一行一个整数n，表示二叉树的结点个数。
接下来2n行，每行描述一个栈操作，格式为：push X 表示将结点X压入栈中，pop 表示从栈中弹出一个结点。
(X用一个字符表示)
对于20%的数据，0<n<=10
对于40%的数据，0<n<=20
对于100%的数据，0<n<=83
从右上角下载并运行p37_data.cpp以生成随机测试数据

输出:
一行，后序遍历序列。

样例输入:
6
push a
push b
push c
pop
pop
push d
pop
pop
push e
push f
pop
pop

样例输出:
cdbfea
