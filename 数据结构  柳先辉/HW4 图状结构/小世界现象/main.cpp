#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Vertex
{
    int val;
    vector<Vertex*> adjList;
    Vertex(int x) : val(x) {}
};

// 构建图
vector<Vertex*> buildGraph(int n, int m, vector<pair<int, int>> vertex_vertex)
{
    vector<Vertex*> graph(n);
    for (int i = 0; i < n; ++i)
    {
        graph[i] = new Vertex(i + 1);
    }
    for (int j = 0; j < m; ++j)
    {
        int u = vertex_vertex[j].first;
        int v = vertex_vertex[j].second;
        graph[u - 1]->adjList.push_back(graph[v - 1]);
        graph[v - 1]->adjList.push_back(graph[u - 1]);
    }
    return graph;
}

// BFS，计算每个节点到其他节点的距离
vector<int> bfs(Vertex* start, vector<Vertex*> graph)
{
    queue<Vertex*> que;
    vector<int> dist(graph.size(), -1);  // 用-1表示节点未被访问
    dist[start->val - 1] = 0; 
    que.push(start);

    while (!que.empty())
    {
        Vertex* current = que.front();
        que.pop();

        for (Vertex* neighbor : current->adjList)
        {
            if (dist[neighbor->val - 1] == -1)  // 如果未访问过该节点
            {
                dist[neighbor->val - 1] = dist[current->val - 1] + 1;
                que.push(neighbor);
            }
        }
    }
    return dist;
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

    // 对每个节点执行BFS
    for (int i = 0; i < n; ++i)
    {
        vector<int> dist = bfs(graph[i], graph); 

        int count = 0;
        for (int j = 0; j < n; ++j)
        {
            if (dist[j] <= 6 && dist[j] != -1) 
            {
                count++;
            }
        }

        // 输出当前节点的百分比
        float percentage = (float)count / n * 100;
        cout << graph[i]->val << ": " << fixed << setprecision(2) << percentage << "%" << endl;
    }

    return 0;
}
