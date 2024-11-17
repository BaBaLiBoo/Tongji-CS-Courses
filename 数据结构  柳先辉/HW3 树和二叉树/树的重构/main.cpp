#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
class TreeNode {
public:
    int val;
    vector<TreeNode*> children;
 
    TreeNode(int _val) {
        val = _val;
    }
};
 
class Solution {
public:
    // 查找多叉树中两个节点的最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
 
        int count = 0;
        TreeNode* temp = nullptr;
 
        // 遍历所有子节点，递归查找
        for (auto child : root->children) {
            TreeNode* res = lowestCommonAncestor(child, p, q);
            if (res != nullptr) {
                count++;
                temp = res;
            }
        }
 
        // 如果有两个或以上子节点返回了非空值，说明当前节点是最近公共祖先
        if (count > 1) {
            return root;
        }
 
        return temp;
    }
};
 
// 辅助函数：将输入数据构建成树结构
TreeNode* buildTree(int N, vector<pair<int, int>>& edges, unordered_map<int, TreeNode*>& nodeMap) {
    unordered_set<int> childSet;
 
    for (int i = 1; i <= N; ++i) {
        nodeMap[i] = new TreeNode(i);
    }
 
    for (const auto& edge : edges) {
        int parent = edge.first;
        int child = edge.second;
        nodeMap[parent]->children.push_back(nodeMap[child]);
        childSet.insert(child);
    }
 
    // 找到根节点（未在 childSet 中出现的节点）
    int rootVal = -1;
    for (int i = 1; i <= N; ++i) {
        if (childSet.find(i) == childSet.end()) {
            rootVal = i;
            break;
        }
    }
 
    return nodeMap[rootVal];
}
 
int main() {
    int T;
    cin >> T;
 
    while (T--) {
        int N, M;
        cin >> N >> M;
 
        vector<pair<int, int>> edges(N - 1);
        unordered_map<int, TreeNode*> nodeMap;
 
        for (int i = 0; i < N - 1; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }
 
        TreeNode* root = buildTree(N, edges, nodeMap);
        Solution solution;
 
        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;
 
            TreeNode* p = nodeMap[x];
            TreeNode* q = nodeMap[y];
 
            TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
            if (lca != nullptr) {
                cout << lca->val << endl;
            }
        }
    }
 
    return 0;
}
×
