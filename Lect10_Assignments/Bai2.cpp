#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    vector<vector<int>> adj(n + 1);
    // Tạo danh sách kề với chỉ số từ 1 đến n (n+1 phần tử)
    // adj[u] chứa danh sách các đỉnh mà u có cạnh đi tới (đồ thị có hướng)

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;              // Nhập cạnh có hướng từ u đến v
        adj[u].push_back(v);        // Thêm v vào danh sách kề của u
    }

    vector<int> dist(n + 1, -1);
    // Mảng lưu khoảng cách (số cạnh) từ đỉnh X đến các đỉnh khác
    // Khởi tạo tất cả bằng -1, tức là chưa được thăm

    queue<int> q;   // Hàng đợi để thực hiện thuật toán BFS
    q.push(X);      // Đưa đỉnh bắt đầu X vào hàng đợi
    dist[X] = 0;    // Khoảng cách từ X đến chính nó là 0

    // Bắt đầu thuật toán BFS
    while (!q.empty()) {
        int u = q.front(); q.pop(); // Lấy đỉnh đầu hàng đợi và loại bỏ nó

        for (int v : adj[u]) {      // Duyệt tất cả đỉnh kề v của đỉnh u
            if (dist[v] == -1) {    // Nếu đỉnh v chưa được thăm
                dist[v] = dist[u] + 1; // Cập nhật khoảng cách từ X đến v
                q.push(v);             // Đưa v vào hàng đợi để xử lý tiếp
            }
        }
    }

    cout << dist[Y] << endl;
    return 0;
}
