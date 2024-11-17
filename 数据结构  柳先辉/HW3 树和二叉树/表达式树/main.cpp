#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include<stack>
using namespace std;
 
class TreeNode {
public:
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};
//处理树形结构
class Solution {
public:
    int calDepth(TreeNode* root) {
        int h = 0;
        if (root->left) {
            h = max(h, calDepth(root->left) + 1);
        }
        if (root->right) {
            h = max(h, calDepth(root->right) + 1);
        }
        return h;
    }
 
    void dfs(vector<vector<string>>& res, vector<vector<int>>& haveChild, TreeNode* root, int r, int c, const int& height) {
        res[r][c] = root->val;
        if (root->left && root->right)
            haveChild[r][c] = 3;
        else if(root->left)
            haveChild[r][c] = 1;
        else if (root->right)
            haveChild[r][c] = 2;
        if (root->left) {
            dfs(res, haveChild, root->left, r + 1, c - (1 << (height - r - 1)), height);
        }
        if (root->right) {
            dfs(res, haveChild, root->right, r + 1, c + (1 << (height - r - 1)), height);
        }
    }
};
 
// 输出树的结构
void printTreeStructure(const vector<vector<string>>& tree, vector<vector<int>>& haveChild) {
    vector<int> maxWidth(tree.size());
    int count = 0;
 
    //储存每行长度
    for (int i = 0; i < tree.size(); ++i) {
        count = 0;
        for (int j = 0; j < tree[i].size(); ++j) {
            count++;
            if (tree[i][j] != "")
                maxWidth[i] = count;
        }
    }
    for (int i = 0; i < tree.size(); ++i){
 
        for (int j = 0; j < maxWidth[i]; ++j) {
            if (tree[i][j] == "") {
                cout << " "; // 输出空格
            }
            else {
                cout << tree[i][j]; // 输出节点值
            }
        }    
        cout << endl;
        if (i < tree.size() - 1)
        {
            for (int j = 0; j < maxWidth[i]; ++j) {
                if (haveChild[i][j] == 0 && haveChild[i][j + 1] == 0) {
                    cout << " "; // 输出空格
                }
                else if (haveChild[i][j] == 1) {
                    cout << "/";
                }
                else if (haveChild[i][j] == 2) {
                    cout << " ";
                    cout << "\\";
                }
                else if (haveChild[i][j] == 3) {
                    cout << "/" << " " << "\\";
                }
            }
            cout << endl;
        }
    }
 
}
 
 
// 判断操作符优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
// 转换为后缀表达式
string infixToPostfix(const string& expression) {
    stack<char> s;
    string result;
 
    for (char ch : expression) {
        if (isalpha(ch)) {  // 如果是字母，直接加入结果
            result += ch;
        }
        else if (ch == '(') {  // 左括号
            s.push(ch);
        }
        else if (ch == ')') {  // 右括号
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop();  // 弹出 '('
        }
        else {  // 操作符
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                result += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
 
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
 
    return result;
}
 
// 根据后缀表达式构建表达式树
TreeNode* buildExpressionTree(const string& postfix) {
    stack<TreeNode*> s;
 
    for (char ch : postfix) {
        if (isalpha(ch)) {
            s.push(new TreeNode(ch));
        }
        else {
            TreeNode* right = s.top(); s.pop();
            TreeNode* left = s.top(); s.pop();
            TreeNode* node = new TreeNode(ch);
            node->left = left;
            node->right = right;
            s.push(node);
        }
    }
 
    return s.top();
}
 
// 计算表达式树的值
int evaluateTree(TreeNode* node, const map<char, int>& values) {
    if (!node) return 0;
    if (isalpha(node->val)) return values.at(node->val);
 
    int leftVal = evaluateTree(node->left, values);
    int rightVal = evaluateTree(node->right, values);
 
    if (node->val == '+') return leftVal + rightVal;
    if (node->val == '-') return leftVal - rightVal;
    if (node->val == '*') return leftVal * rightVal;
    if (node->val == '/') return leftVal / rightVal;
 
    return 0;
}
 
int main() {
 
    // 输入
    string expression;
    cin >> expression;
    int k;
    cin >> k;
    map<char, int> values;
    for (int i = 0; i < k; ++i) {
        char var;
        int val;
        cin >> var >> val;
        values[var] = val;
    }
    // 转换为后缀表达式
    string postfix = infixToPostfix(expression);
    // 构建表达式树
    TreeNode* root = buildExpressionTree(postfix);
    // 计算树的值
    int resultValue = evaluateTree(root, values);
    // 打印后缀表达式
    cout << postfix << endl;
 
    Solution solution;
    // 打印树的结构
    int height = solution.calDepth(root);
    int m = height + 1;
    int n = (1 << (height + 1)) - 1;
    vector<vector<string>> res(m, vector<string>(n, ""));
    vector<vector<int>> haveChild(m,vector<int>(n, 0));
    solution.dfs(res, haveChild, root, 0, (n - 1) / 2, height);
    printTreeStructure(res, haveChild);
    cout << resultValue << endl;
    return 0;
}
