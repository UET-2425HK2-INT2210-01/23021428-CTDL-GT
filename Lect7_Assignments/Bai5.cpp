#include <iostream>
using namespace std;

// Hàm đệ quy đếm chữ số
int countDigits(int n) {
    if (n < 10) return 1;           // Nếu còn 1 chữ số thì return 1
    return 1 + countDigits(n / 10); // Mỗi lần chia 10 là bỏ 1 chữ số
}

int main() {
    int n ;
    cin >> n;
    cout  << countDigits(n) << endl;
    return 0;
}
