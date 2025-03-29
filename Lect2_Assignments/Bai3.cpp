#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* previous;
    Node* next;
    Node(int val) : data(val), previous(nullptr), next(nullptr) {}
};

class DoubleLinkList {
private:
    Node* head;
    Node* tail;
public:
    DoubleLinkList() : head(nullptr), tail(nullptr) {}
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }
    int count_triplets() {
        int count = 0;
        Node* temp = head;

        while (temp && temp->next && temp->next->next) {
            if (temp->previous->data + temp->data + temp->next->data == 0) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    DoubleLinkList list;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.append(val);
    }
    cout << list.count_triplets() << endl;
    return 0;
}
