#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100005;

// Mảng danh sách kề: adj[u] chứa các đỉnh kề với đỉnh u
vector<int> adj[MAX];

// Mảng visited[] để đánh dấu các đỉnh đã được thăm trong quá trình DFS
bool visited[MAX];

// Hàm duyệt DFS bắt đầu từ đỉnh u
void dfs(int u) {
    visited[u] = true;  // Đánh dấu đỉnh u đã được thăm

    // Duyệt qua tất cả các đỉnh kề với u
    for (int v : adj[u]) {
        if (!visited[v]) { // Nếu đỉnh v chưa được thăm thì tiếp tục DFS từ v
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Nhập số đỉnh n và số cạnh m

    // Nhập m cạnh của đồ thị
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;           // Nhập cạnh nối giữa hai đỉnh u và v
        adj[u].push_back(v);     // Thêm v vào danh sách kề của u
        adj[v].push_back(u);     // Thêm u vào danh sách kề của v (vì là đồ thị vô hướng)
    }

    int connectedComponents = 0; // Biến đếm số thành phần liên thông

    // Duyệt qua tất cả các đỉnh từ 1 đến n
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // Nếu đỉnh i chưa được thăm, ta thực hiện DFS từ i
            dfs(i);
            connectedComponents++; // Mỗi lần DFS mới là một thành phần liên thông mới
        }
    }

    // In ra kết quả: số thành phần liên thông trong đồ thị
    cout << connectedComponents << endl;

    return 0;
}
