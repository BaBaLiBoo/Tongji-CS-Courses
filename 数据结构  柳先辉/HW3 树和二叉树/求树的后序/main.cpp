#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
 
struct TreeNode {
    char val;
    TreeNode* left, * right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};
 
// 后序遍历
void postorder(TreeNode* root, string& result) {
    if (!root) return;
    postorder(root->left, result);
    postorder(root->right, result);
    result += root->val;
}
 
// 构建二叉树
TreeNode* buildTree(const string& preorder, const string& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<char, int>& inMap, bool& isError) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;
 
    // 前序遍历的第一个节点是根节点
    char rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);
 
    // 根节点在中序遍历中的位置
    int rootIndex = inMap[rootVal];
    if (rootIndex == -1 || rootIndex < inStart || rootIndex > inEnd) {
        isError = true;
        return nullptr;
    }
 
    // 计算左子树的大小
    int leftSize = rootIndex - inStart;
 
    // 左子树和右子树的划分
    root->left = buildTree(preorder, inorder, preStart + 1, preStart + leftSize, inStart, rootIndex - 1, inMap, isError);
    root->right = buildTree(preorder, inorder, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd, inMap, isError);
 
    return root;
}
 
// 检查树是否合理
bool isValidTree(const string& preorder, const string& inorder) {
    if (preorder.size() != inorder.size()) return false;
 
    unordered_map<char, int> inMap;
    for (int i = 0; i < inorder.size(); ++i) {
        inMap[inorder[i]] = i;
    }
 
    bool isError = false;
    TreeNode* root = buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inMap, isError);
 
    return !isError && root != nullptr;
}
 
int main() {
    string preorder, inorder;
 
    while (cin >> preorder >> inorder) {
        if (!isValidTree(preorder, inorder)) {
            cout << "Error" << endl;
            continue;
        }
 
        unordered_map<char, int> inMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }
 
        bool isError = false;
        TreeNode* root = buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inMap, isError);
 
        if (isError || !root) {
            cout << "Error" << endl;
        }
        else {
            string result = "";
            postorder(root, result);
            cout << result << endl;
        }
    }
 
    return 0;
}
