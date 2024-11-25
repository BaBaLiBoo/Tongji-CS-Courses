#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
struct Course {
    int time;                // 修完课程所需时间
    vector<int> prerequisites; // 前置课程编号
};
 
int main() {
    int n;
    cin >> n;
 
    vector<Course> courses(n + 1);          // 所有课程
    vector<int> in_degree(n + 1, 0);        // 入度数组
    vector<int> in_degree_copy(n + 1, 0);   // 恢复入度数组
    vector<vector<int>> adj(n + 1);         // 邻接表
 
    for (int i = 1; i <= n; ++i) {
        int ti, ci;
        cin >> ti >> ci;
        courses[i].time = ti;
        for (int j = 0; j < ci; ++j) {
            int prerequisite;
            cin >> prerequisite;
            courses[i].prerequisites.push_back(prerequisite);
            adj[prerequisite].push_back(i); 
            in_degree[i]++;                
            in_degree_copy[i]++;             
        }
    }
 
    // 拓扑排序
    queue<int> q;
    vector<int> earliest(n + 1, 0); // 每门课程最早完成时间
 
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
            earliest[i] = courses[i].time; // 无前置课程，直接完成
        }
    }
 
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
 
        for (int next : adj[curr]) {
            earliest[next] = max(earliest[next], earliest[curr] + courses[next].time);
            if (--in_degree[next] == 0) {
                q.push(next);
            }
        }
    }
 
    // 计算毕业最短时间
    int min_graduation_time = *max_element(earliest.begin(), earliest.end());
 
    // 判断每门课程的影响
    vector<int> result(n + 1, 0); 
    for (int i = 1; i <= n; ++i) {
        for (int m = 1; m <= n; ++m)
            in_degree[m] = in_degree_copy[m];
        // 增加课程 i 的学时
        courses[i].time += 1;
 
        // 重新计算最早完成时间
        queue<int> q_new;
        vector<int> earliest_new(n + 1, 0);
 
        for (int j = 1; j <= n; ++j) {
            if (in_degree[j] == 0) {
                q_new.push(j);
                earliest_new[j] = courses[j].time;
            }
        }
 
        while (!q_new.empty()) {
            int curr_new = q_new.front();
            q_new.pop();
 
            for (int next : adj[curr_new]) {
                earliest_new[next] = max(earliest_new[next], earliest_new[curr_new] + courses[next].time);
                if (--in_degree[next] == 0) {
                    q_new.push(next);
                }
            }
        }
        int new_graduation_time = *max_element(earliest_new.begin(), earliest_new.end());
 
        if (new_graduation_time > min_graduation_time) {
            result[i] = 1; 
        }
        courses[i].time -= 1;
    }
 
    // 输出结果
    for (int i = 1; i <= n; ++i) {
        cout << earliest[i] << " " << result[i] << endl;
    }
 
    return 0;
}
