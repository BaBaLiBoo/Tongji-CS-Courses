#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
using namespace std;
 
class Solution {
 
    //拓扑排序
    vector<int> topo_sort(int k, vector<vector<int>>& edges) {
        vector<vector<int>> g(k);   // 邻接表
        vector<int> in_deg(k);  // 每个节点入度值
        for (auto& e : edges) {
            int x = e[0] - 1, y = e[1] - 1; 
            g[x].push_back(y);
            ++in_deg[y];
        }
 
        vector<int> order;  // 拓扑排序结果
        queue<int> q;  // 队列用于BFS
        for (int i = 0; i < k; ++i)
            if (in_deg[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            order.push_back(x);
            for (int y : g[x])
                if (--in_deg[y] == 0)
                    q.push(y);
        }
        return order;
    }
 
public:
    // 构建矩阵
    void buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        auto row = topo_sort(k, rowConditions), col = topo_sort(k, colConditions);
        if (row.size() < k || col.size() < k)
        {
            cout << "-1";
            return;
        }
        vector<int> pos(k);
        for (int i = 0; i < k; ++i)
            pos[col[i]] = i;
        vector<vector<int>> ans(k, vector<int>(k));
        for (int i = 0; i < k; ++i)
            ans[i][pos[row[i]]] = row[i] + 1;
        for (int i = 0; i < k; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
};
 
int main()
{
    int k, n, m; // 节点个数、行拓扑、列拓扑
    cin >> k >> n >> m;
 
    Solution sol;
    vector<vector<int>> edgesRow(n);
    vector<vector<int>> edgesCol(m);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        edgesRow[i].push_back(a);
        edgesRow[i].push_back(b);
    }
    for (int i = 0; i < m; ++i)
    {
        int c, d;
        cin >> c >> d;
        edgesCol[i].push_back(c);
        edgesCol[i].push_back(d);
    }
    sol.buildMatrix(k, edgesRow, edgesCol);
    return 0;
}
×
