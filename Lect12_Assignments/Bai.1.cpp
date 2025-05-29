#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n+1); // Danh sách kề
    vector<int> in_degree(n+1, 0); // Mảng lưu bậc vào
    
    for (auto& edge : edges) { // Duyệt từng cạnh 
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v); // Cập nhật danh sách kề
        in_degree[v]++; // Cập nhật bậc vào
    }
    
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i); // Đẩy các đỉnh có bậc vào bằng 0 vào
        }
    }
    
    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u); // Lấy từng đỉnh trong queue thêm vào mảng trả về

        for (int v : graph[u]) { // Duyệt từng đỉnh kề của u
            in_degree[v]--; // Giảm bậc vào của v
            if (in_degree[v] == 0) {
                q.push(v); // Nếu bậc vào bằng 0 thì đẩy vào queue
            }
        }
    }
    
    if (result.size() != n) {
        return {}; // Trả về rỗng nếu kh có chu trình
    }
    return result;
}

int main() {
    ifstream fin("jobs.txt");
    ofstream fout("jobs.out");
    
    int n, m;
    fin >> n >> m;
    
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        fin >> edges[i].first >> edges[i].second;
    }
    
    vector<int> sorted_jobs = topologicalSort(n, edges);
    
    if (!sorted_jobs.empty()) {
        for (int job : sorted_jobs) {
            fout << job << " ";
        }
    }
    
    fin.close();
    fout.close();
    return 0;
}
