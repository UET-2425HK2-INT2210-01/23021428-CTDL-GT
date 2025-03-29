// output expected: 3 39 94 16 5 23 13 88 44 11 12 

#include <iostream>
#define HASH_SIZE 11
using namespace std;
// Hàm băm tính chỉ số cho mỗi phần tử bằng công thức h(i) = (2i + 5) % 11
int hash_func(int x) {
    return (x * 2 + 5) % 11;
}
// Hàm chèn giá trị vào bảng băm với phương pháp linear probing, Khi chèn một giá trị, 
// ta tính toán chỉ số của vị trí trong bảng băm, nếu vị trí đó đã có giá trị, ta sử dụng linear probing để tìm vị trí trống tiếp theo. Đây là cách xử lý va chạm.
void insert(int hashTable[], int x) {
    int index = hash_func(x);  // Tính toán chỉ số vị trí trong bảng băm
    // Kiểm tra và thăm dò tuyến tính nếu có va chạm
    while(hashTable[index] != -1) {
        index = (index + 1) % HASH_SIZE;  // Thăm dò tiếp theo theo modulo HASH_SIZE
    }
    hashTable[index] = x;  // Chèn giá trị vào bảng tại vị trí tìm được
}
// Hàm in ra bảng băm
void print(int hashTable[]) {
    for(int i = 0; i < HASH_SIZE; i++) {
        cout << hashTable[i] << " ";  // In các giá trị trong bảng băm
    }
    cout << endl;
}
int main() {
    // Khởi tạo bảng băm hashTable với các giá trị là -1 (đối với các vị trí trống)
    int hashTable[HASH_SIZE];
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = -1;
    }
    // Chèn các khóa vào bảng băm
    insert(hashTable, 12);
    insert(hashTable, 44);
    insert(hashTable, 13);
    insert(hashTable, 88);
    insert(hashTable, 23);
    insert(hashTable, 94);
    insert(hashTable, 11);
    insert(hashTable, 39);
    insert(hashTable, 20);
    insert(hashTable, 16);
    insert(hashTable, 5);
    // In bảng băm
    print(hashTable);
    return 0;
}
