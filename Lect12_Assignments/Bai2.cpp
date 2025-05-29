#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { // Cấu trúc cạnh
    int u, v, d;
    
    bool operator<(const Edge& other) const {
        return d < other.d; // Khởi tạo phép so sánh chi phí
    }
};

class UnionFind {
private:
    vector<int> parent; // Mảng lưu cha mỗi phần tử
    vector<int> rank; // Mảng lưu độ sâu mỗi cây
    
public:
    UnionFind(int size) { // Hàm khởi tạo lớp UnionFind
        parent.resize(size+1);
        rank.resize(size+1, 0);
        for (int i = 0; i <= size; ++i) {
            parent[i] = i; // Ban đầu nút là cha của chính nó
        }
    }
    
    int find(int x) { // Hàm tìm kiếm gốc
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) { // Hàm nhập 2 đường đi
        int x_root = find(x); 
        int y_root = find(y); // Tìm kiếm gốc của x và y
        
        if (x_root == y_root) {
            return false;
        }
        
        if (rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        } else {
            parent[y_root] = x_root;
            if (rank[x_root] == rank[y_root]) {
                rank[x_root]++; // Cập nhật lại độ sâu của đường đi
            }
        }
        return true;
    }
};

pair<int, vector<Edge>> kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end()); // Sắp xếp các cạnh theo trọng số
    UnionFind uf(n);
    vector<Edge> mst; // Danh sách cạnh
    int total_cost = 0; // Trọng số nhỏ nhất
    
    for (Edge& edge : edges) { // Duyệt từng cạnh
        if (uf.unite(edge.u, edge.v)) { // Hợp nhất các cạnh 
            mst.push_back(edge);
            total_cost += edge.d; // Cập nhật danh sách cạnh và trọng số trong cây khung nhỏ nhất
            if (mst.size() == n-1) {
                break; // Đủ số cạnh thì thoát
            }
        }
    }
    
    return {total_cost, mst};
}

int main() {
    ifstream fin("connection.txt");
    ofstream fout("connection.out");
    
    int n, m;
    fin >> n >> m;
    
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        fin >> edges[i].u >> edges[i].v >> edges[i].d;
    }
    
    auto result = kruskal(n, edges);
    
    fout << result.first << "\n";
    for (Edge& edge : result.second) {
        fout << edge.u << " " << edge.v << " " << edge.d << "\n";
    }
    
    fin.close();
    fout.close();
    return 0;
}
