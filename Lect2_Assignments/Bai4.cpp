#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) { 
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            return; 
        }
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr; 
        }
    }

    void printQueue() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n; 
    Queue q; 
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (operation == "dequeue") {
            q.dequeue();
        }
    }
    q.printQueue(); 
    return 0;
}
