#include <iostream>
using namespace std;

// Hàm phụ trợ đệ quy để đảo ngược số, revNum là số đảo tạm thời
int reverseHelper(int n, int revNum) {
    if (n == 0) return revNum;                          // Khi n = 0 thì xong
    return reverseHelper(n / 10, revNum * 10 + n % 10); // Thêm chữ số cuối vào đầu
}

// Hàm chính để gọi đệ quy
int reverseNumber(int n) {
    return reverseHelper(n, 0);
}

int main() {
    int n ;
    cin >> n;
    cout << reverseNumber(n) << endl;
    return 0;
}
