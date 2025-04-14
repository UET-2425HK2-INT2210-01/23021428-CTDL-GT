// Ban đầu:
//          2                                                   
//         / \
//        1   10
//           /  \
//          6    13
//         / \    \                               
//        3   8    20
//           /
//          7
// Đã chèn 14 0 35:
//         2
//        / \
//       1   10
//      /   /  \
//     0   6    13
//          / \    \
//         3   8    20
//            /    /  \
//           7    14   35

/* Binary and Heap trees
   1. Given a list of integer numbers: 2, 1, 10, 6, 3, 8, 7, 13, 20.
    - Draw the binary search tree after inserting values: 14, 0, 35
*/
#include <iostream>
using namespace std;
struct Node {
    int data;       // Lưu giá trị của node
    Node* left;     // Con trỏ trỏ tới node con bên trái
    Node* right;    // Con trỏ trỏ tới node con bên phải
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    // khởi tạo node với giá trị val, left và right trỏ tới nullptr
};

void insert(Node* &root, int val) {
    if (root == nullptr) {          // Nếu cây rỗng (hoặc đến vị trí cần chèn)
        root = new Node(val);       // Tạo node mới với giá trị val
        return;                     // Kết thúc hàm
    }
    
    if (val < root->data) {         // Nếu giá trị cần chèn nhỏ hơn giá trị node hiện tại
        insert(root->left, val);    // Đệ quy chèn vào cây con bên trái
    } else {                        // Ngược lại (lớn hơn hoặc bằng)
        insert(root->right, val);   // Đệ quy chèn vào cây con bên phải
    }
}

void inorderTraversal(Node* root) {
    if (root == nullptr) return;    // Nếu node hiện tại rỗng thì dừng
    inorderTraversal(root->left);   // Đệ quy duyệt cây con bên trái
    cout << root->data << " ";      // In giá trị node hiện tại
    inorderTraversal(root->right);  // Đệ quy duyệt cây con bên phải
}

int main() {
    // Khởi tạo mảng chứa các giá trị ban đầu để xây dựng cây
    int numbers[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    // Khai báo con trỏ root, ban đầu trỏ tới nullptr (cây rỗng)
    Node* root = nullptr;
    // Duyệt qua từng phần tử trong mảng numbers
    for (int num : numbers) {
        // Chèn giá trị num vào cây BST
        insert(root, num);
    }
    insert(root, 14);
    // Khi chèn 14:
    // Bắt đầu từ root (2) → 10 → 13 → 20
    // 14 < 20 → trở thành con trái của 20
    insert(root, 0);
    // Khi chèn 0:
    // Bắt đầu từ root (2) → 1
    // 0 < 1 → trở thành con trái của 1
    insert(root, 35);
    // Khi chèn 35:
    // Bắt đầu từ root (2) → 10 → 13 → 20
    // 35 > 20 → trở thành con phải của 20
    cout << "Inorder traversal of the updated BST: ";
    // Duyệt cây theo thứ tự in-order (trái - gốc - phải)
    inorderTraversal(root);
    cout << endl;
    return 0;
}
