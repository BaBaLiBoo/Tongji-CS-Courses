#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <queue>
#include <unordered_set>
using namespace std;
 
struct Treenode {
    int val;
    Treenode* left;
    Treenode* right;
    Treenode(int x) : val(x), left(nullptr), right(nullptr) {};
};
 
class Solution {
public:
    //构造树
    Treenode* buildtree(vector<string> line, int n) {
        vector<Treenode*> node(n);
        for (int j = 0; j < n; ++j) {
            node[j] = new Treenode(j);  // 用数字编号节点
        }
        vector<bool> hasBeenChild(n, false);
        for (int i = 0; i < n; ++i) {
            istringstream stream(line[i]);
            string leftnode, rightnode;
            stream >> leftnode >> rightnode;
            if (leftnode != "-1") {
                node[i]->left = node[stoi(leftnode)];
                hasBeenChild[stoi(leftnode)] = true;
            }
            if (rightnode != "-1") {
                node[i]->right = node[stoi(rightnode)];
                hasBeenChild[stoi(rightnode)] = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!hasBeenChild[i]) {
                return node[i];  
            }
        }
        return nullptr; 
    }
    //计算感染二叉树时间
    int amountOfTime(Treenode* root, int start) {
        int ans = 0;
        function<int(Treenode* node)> dfs = [&](Treenode* node) {
            if (!node)
                return 0;
            int l = dfs(node->left), r = dfs(node->right);
            if (node->val == start) {
                ans = max(l, r);
                return -1;
            }
            if (l >= 0 && r >= 0) {
                return max(l, r) + 1;
            }
            if (l < 0) {
                ans = max(ans, -l + r);
                return l - 1;
            }
            else {
                ans = max(ans, l - r);
                return r - 1;
            }
            };
        dfs(root);
        return ans;
    }
};
 
int main() {
    int n, start;
    Solution sol;
    cin >> n >> start;
    cin.ignore();
    vector<string> line(n);
    for (int i = 0; i < n; ++i)
        getline(cin, line[i]);
    Treenode* root = sol.buildtree(line, n);
    cout << sol.amountOfTime(root, start) << endl;
    return 0;
}
