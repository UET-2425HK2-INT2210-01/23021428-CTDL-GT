// Ban đầu:
//         2
//        / \
//       1   10
//      /   /  \
//     0   6    13
//        / \    \
//       3   8    20
//          /    /  \
//         7    14   35
// Cuối cùng: 
//         2
//        / \
//       1   10
//      /   /  \
//     0   7    20
//        / \   / 
//       3   8 14

/* Binary and Heap trees
   1. Given a list of integer numbers: 2, 1, 10, 6, 3, 8, 7, 13, 20.
    - Draw the binary search tree after deleting: 6, 13, 35
*/
#include <iostream>
using namespace std;
struct Node {
    int data;       // Giá trị của node
    Node* left;     // Con trỏ trỏ tới node con bên trái
    Node* right;    // Con trỏ trỏ tới node con bên phải
    Node(int val) : data(val), left(nullptr), right(nullptr) {} // Hàm khởi tạo
};

class BST {
private:
    Node* root;  // Con trỏ trỏ tới node gốc của cây
        Node* insertHelper(Node* node, int val) {
        if (!node) return new Node(val); // Nếu node null thì tạo node mới
        if (val < node->data) 
            node->left = insertHelper(node->left, val); // Nếu giá trị nhỏ hơn -> chèn sang trái
        else 
            node->right = insertHelper(node->right, val); // Ngược lại chèn sang phải
        return node;
    }
        Node* findMin(Node* node) {
        while (node && node->left) node = node->left; // Đi tới node tận cùng bên trái
        return node;
    }
        Node* deleteHelper(Node* node, int val) {
        if (!node) return nullptr; // Nếu node null thì trả về null
        // Tìm node cần xóa
        if (val < node->data) {
            node->left = deleteHelper(node->left, val); // Tìm bên trái
        } else if (val > node->data) {
            node->right = deleteHelper(node->right, val); // Tìm bên phải
        } else {
            // Node có 1 con hoặc không có con
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp; // Trả về node con phải
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp; // Trả về node con trái
            }
            // Node có 2 con: Tìm node kế tiếp (node nhỏ nhất bên phải)
            Node* temp = findMin(node->right);
            node->data = temp->data; // Thay thế giá trị
            node->right = deleteHelper(node->right, temp->data); // Xóa node kế tiếp
        }
        return node;
    }
        void printTreeHelper(Node* node, int space = 0, int height = 10) {
        if (!node) return;
        space += height; // Tăng khoảng cách theo mức
        printTreeHelper(node->right, space); // In cây con phải trước
        cout << endl;
        for (int i = height; i < space; i++) cout << ' '; // In khoảng trắng
        cout << node->data << "\n"; // In giá trị node
        printTreeHelper(node->left, space); // In cây con trái sau
    }
    
public:
    BST() : root(nullptr) {} // Khởi tạo cây rỗng
    void insert(int val) {
        root = insertHelper(root, val); // Chèn giá trị vào cây
    }
    void remove(int val) {
        root = deleteHelper(root, val); // Xóa giá trị khỏi cây
    }
    void printTree() {
        printTreeHelper(root); // In cấu trúc cây
        cout << endl;
    }
};

int main() {
    BST tree; // Tạo cây BST
    // Xây dựng cây ban đầu
    tree.insert(2);
    tree.insert(1);
    tree.insert(0);  // Node thêm vào từ bài Task1b
    tree.insert(10);
    tree.insert(6);
    tree.insert(3);
    tree.insert(8);
    tree.insert(7);
    tree.insert(13);
    tree.insert(20);
    tree.insert(14);  // Node thêm vào từ bài Task1b
    tree.insert(35);  // Node thêm vào từ bài Task1b
    cout << "Initial BST structure:\n";
    tree.printTree(); // In cấu trúc cây ban đầu
    // Xóa các node theo yêu cầu
    tree.remove(6);
    tree.remove(13);
    tree.remove(35); // Node này tồn tại trong cây mở rộng
    cout << "\nFinal BST structure after deletions:\n";
    tree.printTree(); // In cấu trúc cây sau khi xóa
    return 0;
}
