#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <utility>
 
using namespace std;
 
// 自定义哈希函数
struct pair_hash {
    template <class T1, class T2>
    size_t operator ()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);  
    }
};
// 自定义比较函数
struct pair_equal {
    template <class T1, class T2>
    bool operator()(const pair<T1, T2>& p1, const pair<T1, T2>& p2) const {
        return p1.first == p2.first && p1.second == p2.second;
    }
};
struct Edge
{
    int u, v; //左右连接的值
    int weight; //权重
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
    Edge(int a, int b, int c) :u(a), v(b), weight(c) {};
};
 
// 并查集类
class UnionFind
{
private:
    vector<int> parent; // 每个节点的父节点
    vector<int> rank; // 每个节点按秩合并后树的高度
public:
    // 初始化并查集
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // 每个节点初始化为自己的父节点
        }
    }
    // 查找节点的根节点，并进行路径压缩
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // 路径压缩
        }
        return parent[x];
    }
    // 合并两个集合
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
 
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    // 检查两个节点是否连通
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
 
int main()
{
    int n; // 节点数
    cin >> n;
    UnionFind uf(n);
    vector<Edge> edges;
    int weight;
    int minLength = 0;
    // 读取所有边
    for(int i=0;i<n;++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> weight;
            if (j > i)
            {
                edges.emplace_back(i, j, weight); // 直接使用构造参数
            }
        }
    sort(edges.begin(), edges.end());
    // 处理已经修建的路
    unordered_set<pair<int, int>, pair_hash, pair_equal> built;
    int m;
    cin >> m;
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        --a;
        --b;
        built.insert({ a, b });
        uf.unionSets(a, b);
    }
 
    // 修建新的路
    for (Edge edge : edges)
    {
        if (!built.count({ edge.u,edge.v })&& !built.count({ edge.v,edge.u }))
        {
            if (!uf.connected(edge.u, edge.v)) { // 检查是否成环
                uf.unionSets(edge.u, edge.v);    // 合并两个节点
                minLength += edge.weight;       // 累加权值
            }
        }
    }
    cout << minLength;
    return 0;
 
}
