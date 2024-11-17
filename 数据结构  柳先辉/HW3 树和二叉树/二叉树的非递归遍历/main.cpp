#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace  std;
struct Treenode
{
    char val;
    Treenode* left;
    Treenode* right;
    Treenode(char x) :val(x), left(nullptr), right(nullptr) {};
};
Treenode* buildtree(vector<string>line)
{
    Treenode* root = nullptr;
    Treenode* current = nullptr;
    stack<Treenode*>nodeStack;
    for (string s : line)
    {
        if (s.substr(0, 4) == "push")
        {
            char value = s[5];
            Treenode* node = new Treenode(value);
            if (root == nullptr)
                root = node;
            if (current)
            {
                if (current->left == nullptr)
                    current->left = node;
                else
                    current->right = node;
            }
            current = node;
            nodeStack.push(node);
        }
        else if (s.substr(0, 3) == "pop")
        {
            if (!nodeStack.empty())
            {
                current = nodeStack.top();
                nodeStack.pop();
            }
        }
    }
    return root;
}
void postOrderTraversal(Treenode* root, string& result)
{
    if (root)
    {
        postOrderTraversal(root->left, result);
        postOrderTraversal(root->right, result);
        result += root->val;
    }
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<string>line(2 * n);
    for (int i = 0; i < 2 * n; ++i)
        getline(cin, line[i]);
    string result;
    postOrderTraversal(buildtree(line), result);
    cout << result << endl;
    return 0;
}
