#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng các chữ số
int sumDigits(int n) {
    if (n == 0) return 0;               // Trường hợp cơ bản
    return n % 10 + sumDigits(n / 10);  // Lấy số cuối + đệ quy phần còn lại
}

int main() {
    int n;
    cin >> n;
    cout  << sumDigits(n) << endl;
    return 0;
}
