#include <iostream>
using namespace std;

int factorial(int n) { // Hàm tính giai thừa của n
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1); // Hàm trả về n nhân với đệ quy của nó
}

int main() {
	int n;
	cin >> n;
	int x = factorial(n);
	cout << x << endl;
	return 0;
}
