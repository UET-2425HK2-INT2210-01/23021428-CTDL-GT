#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

const int INF = 1e9;

// Cấu trúc cạnh cho Bellman-Ford
struct Edge {
    int u, v, w;
};

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    int n, m, s, e;
    fin >> n >> m >> s >> e;

    vector<Edge> edges;
    vector<vector<int>> distFW(n + 1, vector<int>(n + 1, INF)); // Ma trận Floyd-Warshall
    vector<vector<int>> next(n + 1, vector<int>(n + 1, -1));     // Dùng để truy vết đường đi trong Floyd

    // Đọc dữ liệu các cạnh
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        fin >> u >> v >> d;
        edges.push_back({ u, v, d });
        distFW[u][v] = d;
        next[u][v] = v;
    }

    for (int i = 1; i <= n; ++i)
        distFW[i][i] = 0, next[i][i] = i;

    // 1. Bellman-Ford từ s đến e
    vector<int> dist(n + 1, INF);
    vector<int> trace(n + 1, -1);
    dist[s] = 0;

    // Relax tất cả các cạnh n-1 lần
    for (int i = 1; i < n; ++i) {
        for (auto edge : edges) {
            if (dist[edge.u] < INF && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
                trace[edge.v] = edge.u;
            }
        }
    }

    // Truy vết đường đi từ s → e
    vector<int> path;
    int cur = e;
    while (cur != -1) {
        path.insert(path.begin(), cur);
        cur = trace[cur];
    }

    if (path[0] != s) {
        fout << "INF\n";
        fout << "NO PATH\n";
    }
    else {
        fout << dist[e] << endl;
        for (int i = 0; i < path.size(); ++i) {
            fout << path[i];
            if (i < path.size() - 1) fout << " ";
        }
        fout << endl;
    }

    // 2. Floyd-Warshall cho all-pairs
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (distFW[i][k] < INF && distFW[k][j] < INF && distFW[i][k] + distFW[k][j] < distFW[i][j]) {
                    distFW[i][j] = distFW[i][k] + distFW[k][j];
                    next[i][j] = next[i][k];
                }

    // Xuất ma trận khoảng cách ngắn nhất
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (distFW[i][j] >= INF) cout << "INF";
            else cout << distFW[i][j];
            if (j < n) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
