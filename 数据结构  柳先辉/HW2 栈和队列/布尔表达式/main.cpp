#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
 
// 处理单个逻辑运算符的计算
char applyOp(char op, char a, char b) {
    if (op == '&') return (a == 'V' && b == 'V') ? 'V' : 'F';
    if (op == '|') return (a == 'V' || b == 'V') ? 'V' : 'F';
    return 'F';
}
 
// 处理连续的非（!）运算
char applyNot(int count, char value) {
    if (count % 2 == 1) return (value == 'V') ? 'F' : 'V';
    return value;
}
 
// 获取优先级
int precedence(char op) {
    if (op == '!') return 3;
    if (op == '&') return 2;
    if (op == '|') return 1;
    return 0;
}
 
// 计算给定的表达式
bool calculate(const vector<char>& expression) {
    stack<char> values;   
    stack<char> ops;      
 
    for (char token : expression) {
        // 空格
        if (token == ' ') continue;
 
        // 如果是操作数，直接入栈
        if (token == 'V' || token == 'F') {
            values.push(token);
        }
        // 如果是左括号，入运算符栈
        else if (token == '(') {
            ops.push(token);
        }
        // 如果是右括号，计算括号内的表达式
        else if (token == ')') {
            while (!ops.empty() && ops.top() != '(') {
                char op = ops.top();
                ops.pop();
 
                if (op == '!') {
 
                    char val = values.top();
                    values.pop();
                    values.push(applyNot(1, val));
                }
                else {
                    char val2 = values.top(); 
                    values.pop();
                    char val1 = values.top(); 
                    values.pop();
                    values.push(applyOp(op, val1, val2));
                }
            }
            ops.pop(); // 弹出 '('
        }
        // 如果是运算符，处理优先级
        else {
            if (token == '!') {
                // 连续处理多个 `!`
                int notCount = 1;
                while (!ops.empty() && ops.top() == '!') {
                    notCount++;
                    ops.pop();
                }
                if(notCount%2==1)
                    ops.push(token);  // 最后的一个 ! 入栈
                // 计算结果时在 applyNot 里累加处理次数
            }
            else {
                // 处理 `&` 或 `|`
                while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
                    char op = ops.top();
                    ops.pop();
 
                    if (op == '!') {
                        char val = values.top();
                        values.pop();
                        values.push(applyNot(1, val));
                    }
                    else {
                        char val2 = values.top(); values.pop();
                        char val1 = values.top(); values.pop();
                        values.push(applyOp(op, val1, val2));
                    }
                }
                ops.push(token);  // 当前运算符入栈
            }
        }
    }
 
    // 处理剩余的运算符
    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();
 
        if (op == '!') {
            char val = values.top();
            values.pop();
            values.push(applyNot(1, val));
        }
        else {
            char val2 = values.top(); values.pop();
            char val1 = values.top(); values.pop();
            values.push(applyOp(op, val1, val2));
        }
    }
 
    // 最终结果
    return values.top() == 'V';
}
 
int main() {
    vector<char> expression;
    string input;
    int count = 0;
    while (getline(cin, input))
    {
        count++;
        expression.assign(input.begin(), input.end());
        cout << "Expression " << count << ": ";
        if (calculate(expression))
            cout << "V" << endl;
        else
            cout << "F" << endl;
    }
}
