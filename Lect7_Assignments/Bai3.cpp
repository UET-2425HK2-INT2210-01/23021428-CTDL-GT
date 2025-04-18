#include <iostream>
using namespace std;

int fibonacci(int n) { // Hàm tính số fibonacci của n
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n - 2) + fibonacci(n - 1); // Trả về đệ quy của n - 1 và n - 2
}

int main() {
	int n;
	cin >> n;
	int x = fibonacci(n);
	cout << x << endl;
	return 0;
}
