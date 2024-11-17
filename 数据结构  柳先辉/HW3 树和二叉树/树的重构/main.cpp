#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
 
struct Treenode {
    int val;
    vector<Treenode*> child;  //存放原始子节点
    Treenode* dad;  //存放原始父节点
    Treenode(int x) : val(x), child(), dad(nullptr) {};
};
struct Treenode_new {
    int val;
    Treenode_new* left;
    Treenode_new* right;
    Treenode_new(int x) : val(x), left(nullptr), right(nullptr) {};
};
Treenode* buildtree(string tree, vector<Treenode*>&nodes)
{
    nodes.clear();
    int node_total = 0;
    Treenode* root = new Treenode(0);
    nodes.push_back(root);
    Treenode* current = nullptr;
    Treenode* current_dad = root;
    //dudduduudu
    for (int i = 0; i < tree.size(); ++i)
    {
        if (tree[i] == 'd')
        {
            ++node_total;
            current = new Treenode(node_total);
            nodes.push_back(current);
            current_dad->child.push_back(current);
            current->dad = current_dad;
            current_dad = current;
        }
        if (tree[i] == 'u')
        {
            if (current != nullptr)
            {
                current_dad = current->dad;
                current = current_dad;
            }
        }
    }
    return root;
}
int findbrother(Treenode* node)
{
    if (node == nullptr || node->dad == nullptr)
        return -1;
    if (node->dad->child.size() < 2)
        return -1;
    else
    {
        for (int i = 0; i < node->dad->child.size(); ++i)
            if ((node == node->dad->child[i]) && (node->dad->child.size() > i + 1))
                return i + 1;
    }
    return -1;
}
Treenode_new* rebuildtree(Treenode* root, vector<Treenode*>&nodes)
{
    vector<Treenode_new*>nodes_n(nodes.size());
    for (int i = 0; i < nodes.size(); ++i)
    {
        nodes_n[i] = new Treenode_new(nodes[i]->val);
    }
    for (int i = 0; i < nodes.size(); ++i)
    {
        if (!nodes[i]->child.empty())
            nodes_n[i]->left = nodes_n[nodes[i]->child[0]->val];
        if (findbrother(nodes[i]) > 0)
            nodes_n[i]->right = nodes_n[nodes[i]->dad->child[findbrother(nodes[i])]->val];
    }
    return nodes_n[0];
}
int maxDepth(Treenode_new* root)
{
    if (root == nullptr)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
// 递归释放原始树节点的内存
void deleteTree(Treenode* root) {
    if (root == nullptr)
        return;
    for (Treenode* child : root->child) {
        deleteTree(child);
    }
    delete root;
}
// 递归释放新树节点的内存
void deleteTreeNew(Treenode_new* root) {
    if (root == nullptr)
        return;
    deleteTreeNew(root->left);
    deleteTreeNew(root->right);
    delete root;
}
int main()
{
    vector<Treenode*>nodes;
    int count = 0;
    while (true)
    {
        string tree;
        getline(cin, tree);
        if (tree == "#")
            break;
        count++;
        int depth_current = 0;
        int depth = 0;
        int depth_new = 0;
        for (char x : tree)
        {
            if (x == 'd')
            {
                ++depth_current;
                if (depth_current > depth)
                    depth = depth_current;
            }
            else
                --depth_current;
        }
        
        Treenode* root=buildtree(tree, nodes);
        //cout << "Tree " << count << ": " << depth << endl;
        Treenode_new* root_n = rebuildtree(root, nodes);
        depth_new = maxDepth(root_n) - 1;
        cout << "Tree " << count << ": " << depth << " => " << depth_new << endl;
        // 释放内存
        deleteTree(root);
        deleteTreeNew(root_n);
    }
    return 0;
}
