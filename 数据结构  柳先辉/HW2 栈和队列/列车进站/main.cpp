#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool Judge(vector<char> putIn, vector<char> putOut)
{
    //输入abc
    //输出bac 正确
    //输出cab 错误
    stack<char> stk;
    int j = 0;
    for (int i = 0; i < putIn.size(); ++i)
    {
        stk.push(putIn[i]); //入栈
        while (!stk.empty() && stk.top() == putOut[j])
        {
            stk.pop();
            j++;
        }
    }
    return stk.empty();
}
 
int main()
{
    string input;
    vector<char> putIn;
    vector<char> putOut;
    cin >> input;
    putIn.assign(input.begin(), input.end());
    while (cin >> input)
    {
        putOut.assign(input.begin(), input.end());
        if (Judge(putIn, putOut))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
