#include <iostream>
#define HASH_SIZE 11
using namespace std;
// Node dung cho phương pháp chaining (Linked List)
struct Node {
    int val;  
    Node* next;  
};
// Hàm make_node tạo một node mới với giá trị x, mục đích là để tạo ra 1 node mới với các giá trị đầu
// vào và trả về con trỏ tới cái Node đó
Node* make_node(int x) {
    Node* tmp = new Node;
    tmp->val = x; // con trỏ val là x
    tmp->next = NULL;  // Ban đầu con trỏ next là NULL
    return tmp;
}
// Mảng chứa các phần tử của bảng băm (mỗi phần tử là con trỏ tới Linked List)
Node* hash_table[HASH_SIZE];
// int hàm băm: h(i) = (2i + 5) % 11. Với cả hàm hash_func này thực hiện phép toán băm để tính
// toán CHỈ SỐ CỦA PHẦN TỬ trong bảng băm với công thức h(i)
int hash_func(int x) {
    return (2 * x + 5) % 11;
}
// Hàm chèn một giá trị vào bảng băm sử dụng phương pháp chaining. Hàm này chèn một phần tử vào 
//bảng băm theo phương pháp chaining. Nếu vị trí tính toán từ hàm băm trống, nó sẽ gán phần tử vào đó. Nếu không, phần tử mới sẽ được chèn vào đầu danh sách liên kết.
void chaining(int x) {
    int index = hash_func(x);  // Tính chỉ số vị trí trong bảng băm
    Node* tmp = make_node(x);  // Tạo một node mới với giá trị x
    // Nếu vị trí đó vẫn chưa có phần tử nào thì gán node mới vào đó
    if (hash_table[index] == NULL) {
        hash_table[index] = tmp;
    }
    else {
        // Nếu đã có phần tử trước đó rồi thì thêm node mới vào đầu Linked List
        tmp->next = hash_table[index];
        hash_table[index] = tmp;
    }
}
// Hàm này thì chỉ cần in ra các phần tử của bảng băm tại chỉ số index
void print(int index) {
    Node* tmp = hash_table[index];
    if (tmp == NULL) {
        cout << "NULL";  // Nếu vị trí đó không có phần tử nào thì in ra NULL
    }
    else {
        // Nếu có phần tử thì in các giá trị liên tiếp trong danh sách
        while (tmp != NULL) {
            cout << tmp->val << " -> ";
            tmp = tmp->next;
        }
        cout << "NULL";  // Thoát vòng lặp while và kết thúc Linked List
    }
}
int main() {
    for (int i = 0; i < HASH_SIZE; i++) {
        hash_table[i] = NULL;
    }
    // Chèn các khóa 12 44 13 88 23 94 11 39 20 16 5 vào bảng băm
    chaining(12);
    chaining(44);
    chaining(13);
    chaining(88);
    chaining(23);
    chaining(94);
    chaining(11);
    chaining(39);
    chaining(20);
    chaining(16);
    chaining(5);
    // Cuối cùng là in toàn bộ bảng băm
    cout << "Hash table:" << endl;
    for (int i = 0; i < HASH_SIZE; i++) {
        cout << "Index " << i << ": ";
        print(i);  // In các phần tử tại vị trí index
        cout << endl;
    }
    return 0;
}
