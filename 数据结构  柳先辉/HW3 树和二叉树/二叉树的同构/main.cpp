#include <iostream>
#include <string>
#include <vector>
#include<sstream>
using namespace  std;
struct Treenode
{
    char val;
    Treenode* left;
    Treenode* right;
    Treenode(char x) :val(x), left(nullptr), right(nullptr) {};
};
//构造树
Treenode* buildTree(int i,vector<string>line)
{
    vector<Treenode*>node(i);
    vector<int>isChild;
    vector<bool>hasBeenChild(i);
    for (int m = 0; m < i; ++m)
        node[m] = new Treenode(line[m][0]);
 
    for (int j = 0; j < i; ++j)
    {
        string val,leftval, rightval;
        istringstream stream(line[j]);
        stream >> val >> leftval >> rightval;
        if (leftval != "-")
        {
            node[j]->left = node[stoi(leftval)];
            if (hasBeenChild[stoi(leftval)]== false)
            {
                hasBeenChild[stoi(leftval)] = true;
                isChild.push_back(stoi(leftval));
            }
        }
        if (rightval != "-")
        {
            node[j]->right = node[stoi(rightval)];
            if (hasBeenChild[stoi(rightval)] == false)
            {
                hasBeenChild[stoi(rightval)] = true;
                isChild.push_back(stoi(rightval));
            }
        }
    }
    int sum = 0;
    int sum_all = 0;
    for (int n = 0; n < i - 1; ++n)
        sum += isChild[n];
    for (int k = 0; k < i; ++k)
        sum_all += k;
    return node[sum_all - sum];
}
 
// 判断两棵树是否通过若干次左右子树互换可以变成相同的结构
bool isFlipEquivalent(Treenode* root1, Treenode* root2)
{
    if (!root1 && !root2) return true;
    if (!root1 || !root2 || root1->val != root2->val) return false;
 
    bool withoutSwap = isFlipEquivalent(root1->left, root2->left) && isFlipEquivalent(root1->right, root2->right);
    bool withSwap = isFlipEquivalent(root1->left, root2->right) && isFlipEquivalent(root1->right, root2->left);
 
    return withoutSwap || withSwap;
}
//最大深度
int maxDepth(Treenode* root) 
{
    if (root == nullptr) 
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
int main()
{
    int n1,n2;
    Treenode* root1 = nullptr;
    Treenode* root2 = nullptr;
 
    cin >> n1;
    cin.ignore();
    vector<string>line1(n1);
    for (int i = 0; i < n1; ++i)
        getline(cin, line1[i]);
    root1=buildTree(n1, line1);
 
    cin >> n2;
    cin.ignore();
    vector<string>line2(n2);
    for (int i = 0; i < n2; ++i)
        getline(cin, line2[i]);
    root2 = buildTree(n2, line2);
 
    bool same = isFlipEquivalent(root1,root2);
    if (same)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
 
    int depth1 = maxDepth(root1);
    int depth2 = maxDepth(root2);
    cout << depth1 << endl;
    cout << depth2 << endl;
 
    return 0;
}
