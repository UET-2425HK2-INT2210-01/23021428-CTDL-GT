#include <iostream>
using namespace std;

class Stack {
private:
    int *stack;  // Ngăn xếp phần tử
    int top;  // Chỉ số phần tử trên cùng
    int size;  // Số lượng phần tử hiện có

public:
    // Khởi tạo stack
    Stack(int size) {
        this->size = size;
        stack = new int[size];
        top = -1;
    }

    void push(int value) {
        if (top == size - 1) {
            return;  // Trả về nêu stack đầy
        }
        stack[++top] = value;  // Tăng top lên 1 và gán giá trị value vào stack[top]
    }  // Độ phức tạp O(1)

    int pop() {
        if (top == -1) {
            return -1;  // Trả về nêu stack rỗng
        }
        return stack[top--];  // Giảm top đi 1 và trả về giá trị stack[top]
    }  // Độ phức tạp O(1)
};
