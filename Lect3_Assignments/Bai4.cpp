#include <iostream>
#include <string>
using namespace std;

struct Node{ // Cấu trúc Node
        int data;
        Node* next;
        Node(int x){ // Khởi tạo Node
            this->data = x;
            this->next = nullptr;
        }
}; // Độ phức tạp O(1)

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr; // Khởi tạo hàng chờ rỗng
    } // Độ phức tạp O(1)

    void enqueue(int x){
        Node* newNode = new Node(x); // Tạo 1 Node mới
        if (rear == nullptr) { 
            front = rear = newNode;
            return;
        } // Nếu hàng chờ rỗng thì gán front và rear vào Node
        rear->next = newNode; // Liên kết Node mới tới cuối
        rear = newNode; // Đặt Node mới thành rear
    } // Độ phức tạp O(1)

    void deleteNode(){
        if (front == nullptr) return; // Nếu hàng chờ rỗng thì trả về
        Node* temp = front; // Tạo con trỏ tới front 
        front = front->next; // Đẩy front tới Node tiếp theo 
        if (front == nullptr) { 
            rear = nullptr;
        } // Nếu front = NULL thì đặt rear = NULL 
        delete temp; // Xoá node mà temp trỏ vào
    } // Độ phức tạp O(1)
}
