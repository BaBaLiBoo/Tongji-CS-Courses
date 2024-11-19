#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
 
struct Vertex
{
    int val;
    vector<Vertex*> adjList;
    Vertex(int x) : val(x) {}
};
 
vector<Vertex*> buildGraph(int n, int m, vector<pair<int, int>> vertex_vertex)
{
    vector<Vertex*> graph(n);
    for (int i = 0; i < n; ++i)
    {
        graph[i] = new Vertex(i);
    }
    for (int j = 0; j < m; ++j)
    {
        int u = vertex_vertex[j].first;
        int v = vertex_vertex[j].second;
        graph[u]->adjList.push_back(graph[v]);
        graph[v]->adjList.push_back(graph[u]); 
    }
    return graph;
}
 
void graphBFS(vector<Vertex*> graph)
{
    unordered_set<Vertex*> visited;
    queue<Vertex*> que;
    for (int i = 0; i < graph.size(); ++i)
    {
        if (visited.count(graph[i]))  // 如果这个节点已经访问过，跳过
            continue;
 
        // 记录当前连通分量
        vector<int> res;
 
        visited.insert(graph[i]);  // 标记为已访问
        que.push(graph[i]);
 
        while (!que.empty())
        {
            Vertex* current = que.front();
            que.pop();
 
            res.push_back(current->val);  // 访问当前节点
 
            // 将未访问过的邻接点加入队列
            for (Vertex* k : current->adjList)
            {
                if (visited.count(k))
                    continue;
                visited.insert(k);  // 标记为已访问
                que.push(k);
            }
        }
 
        // 输出当前连通分量
        cout << "{";
        for (int i = 0; i < res.size(); ++i)
        {
            cout << res[i];
            if (i != res.size() - 1) cout << " "; 
        }
        cout << "}";
    }
}
void dfs(Vertex* vet,unordered_set<Vertex*> &visited,vector<int> &res)
{
    res.push_back(vet->val);
    visited.insert(vet);
    for (Vertex* k : vet->adjList)
    {
        if (visited.count(k))
            continue;
        dfs(k, visited, res);
    }
}
void graphDFS(vector<Vertex*> graph)
{
    unordered_set<Vertex*> visited;
    for (int i = 0; i < graph.size(); ++i)
    {
        if (visited.count(graph[i]))
            continue;
        vector<int> res;
        dfs(graph[i], visited, res);
        cout << "{";
        for (int i = 0; i < res.size(); ++i)
        {
            cout << res[i];
            if (i != res.size() - 1) cout << " ";
        }
        cout << "}";
    }
     cout << endl;
}
 
int main()
{
    int n, m;
    cin >> n >> m;
 
    vector<pair<int, int>> vertex_vertex(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> vertex_vertex[i].first >> vertex_vertex[i].second;
    }
 
    vector<Vertex*> graph = buildGraph(n, m, vertex_vertex);
    graphDFS(graph);
    graphBFS(graph);
    return 0;
}
