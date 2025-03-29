#include <iostream>
using namespace std;

struct Node {
    int data;           // Giá trị lưu tại node
    Node* firstChild;   // Con trỏ đến con đầu tiên của node
    Node* nextSibling;  // Con trỏ đến anh chị em kế tiếp của node
    Node(int val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
};

class Tree {
private:
    int height;         // Chiều cao của cây
    Node* root;         // Gốc của cây
    Node** nodes;       // Mảng con trỏ đến các node
    bool* isChild;      // Mảng đánh dấu node có phải là con của node khác không
    Node* newNode(int val) {
        return new Node(val);  // Cấp phát bộ nhớ và khởi tạo node mới
    }

    void AddChild(int u, int v) {
        // Nếu node u chưa tồn tại, tạo mới
        if (nodes[u] == nullptr) {
            nodes[u] = newNode(u);
        }
        // Nếu node v chưa tồn tại, tạo mới
        if (nodes[v] == nullptr) {
            nodes[v] = newNode(v);
        }
    
        Node* parent = nodes[u];
        Node* child = nodes[v];
    
        // Nếu parent chưa có con, thêm làm con đầu tiên
        if (parent->firstChild == nullptr) {
            parent->firstChild = child;
        } else {
            // Ngược lại, thêm vào cuối danh sách con
            Node* temp = parent->firstChild;
            while (temp->nextSibling != nullptr) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = child;
        }
    
        isChild[v] = true; // Đánh dấu v là con của node khác
    }

    void UpdateRoot(int n) {
        // Duyệt tìm node không là con của node nào -> đó là gốc
        for (int i = 1; i <= n; i++) {
            if (nodes[i] != nullptr && !isChild[i]) {
                root = nodes[i];
                break;
            }
        }
    }

    int calculateHeight(Node* node) {
        if (!node) return 0;
        int maxHeight = 0;
        Node* child = node->firstChild;
        // Duyệt qua tất cả con của node hiện tại
        while (child) {
            maxHeight = max(maxHeight, 1 + calculateHeight(child));
            child = child->nextSibling;
        }
        return maxHeight;
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";  // Thăm node gốc trước
        Node* child = node->firstChild;
        while (child) {
            preorder(child);        // Sau đó thăm các con từ trái sang phải
            child = child->nextSibling;
        }
    }

    void postorder(Node* node) {
        if (!node) return;
        Node* child = node->firstChild;
        while (child) {
            postorder(child);       // Thăm các con trước
            child = child->nextSibling;
        }
        cout << node->data << " ";  // Thăm node gốc sau
    }

    bool isBinary(Node* node) {
        if (!node) return true;
        int childCount = 0;
        Node* child = node->firstChild;
        while (child) {
            childCount++;
            if (childCount > 2) return false; // Quá 2 con -> không phải nhị phân
            if (!isBinary(child)) return false; // Kiểm tra đệ quy các cây con
            child = child->nextSibling;
        }
        return true;
    }

    void inorder(Node* node) {
        if (!node) return;
        Node* child = node->firstChild;
        if (child) {
            inorder(child);         // Thăm con trái trước
            child = child->nextSibling;
        }
        cout << node->data << " ";  // Thăm node gốc
        if (child) {
            inorder(child);         // Thăm con phải sau
        }
    }

    void deleteTree(Node* node) {
        if (!node) return;
        Node* child = node->firstChild;
        while (child) {
            Node* next = child->nextSibling;
            deleteTree(child);  // Xóa đệ quy các cây con
            child = next;
        }
        delete node; // Xóa node hiện tại
    }

public:
Tree(int n, int m) : height(0), root(nullptr) {
    // Cấp phát bộ nhớ cho mảng nodes và isChild
    nodes = new Node*[n + 1];
    isChild = new bool[n + 1];
    // Khởi tạo tất cả nodes là nullptr và isChild là false
    for (int i = 0; i <= n; i++) {
        nodes[i] = nullptr;
        isChild[i] = false;
    }
    // Đọc m cặp quan hệ cha-con và thêm vào cây
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        AddChild(u, v);
    }
    // Cập nhật gốc và tính chiều cao cây
    UpdateRoot(n);
    height = calculateHeight(root);
}

void process() {
    cout << height << endl;     // In chiều cao cây
    preorder(root);             // Duyệt preorder
    cout << endl;
    postorder(root);            // Duyệt postorder
    cout << endl;
    // Kiểm tra và in duyệt inorder nếu là cây nhị phân
    if (isBinary(root)) {
        inorder(root);
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl;
    }
}

    ~Tree() {
        for (int i = 1; nodes[i] != nullptr; i++) {
            deleteTree(nodes[i]);
        }
        delete[] nodes;   // Giải phóng mảng nodes
        delete[] isChild; // Giải phóng mảng isChild
    }
};

int main() {
    int n, m;
    cin >> n >> m;          // Đọc số lượng node và số quan hệ
    Tree tree(n, m);        // Khởi tạo cây
    tree.process();         // Xử lý và in kết quả
    return 0;
}
