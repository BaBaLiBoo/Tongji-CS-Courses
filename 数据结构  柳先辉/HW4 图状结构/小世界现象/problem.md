# 小世界现象（六度空间） 
## 描述
六度空间理论又称小世界理论。理论通俗地解释为：“你和世界上任何一个陌生人之间所间隔的人不会超过6个人，也就是说，最多通过五个人你就能够认识任何一个陌生人。”如图1所示。



假如给你一个社交网络图，请你对每个节点计算符合“六度空间”理论的结点占结点总数的百分比。

说明：由于浮点数精度不同导致结果有误差，请按float计算。

## 输入
第1行给出两个正整数，分别表示社交网络图的结点数N（1<N≤2000​​ ，表示人数）、边数M（≤33×N，表示社交关系数）。

随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个结点的编号（节点从1到N编号）。

## 输出
对每个结点输出与该结点距离不超过6的结点数占结点总数的百分比，精确到小数点后2位。每个结节点输出一行，格式为“结点编号:（空格）百分比%”。

## 输入样例1

10 9

1 2 

2 3 

3 4 

4 5 

5 6 

6 7 

7 8 

8 9 

9 10  

## 输出样例1

1: 70.00%

2: 80.00%

3: 90.00%

4: 100.00%

5: 100.00%

6: 100.00%

7: 100.00%

8: 90.00%

9: 80.00%

10: 70.00%
