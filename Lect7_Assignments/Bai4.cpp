#include <iostream>
using namespace std;

int redundancy(int x, int n) { // Hàm tính luỹ thừa của x ^ n
	if (n == 0) return 1;
	return x * redundancy(x, n - 1); // Hàm trả về x nhân với đệ quy của nó
}

int main() {
	int x, n;
	cin >> x >> n;
	int result = redundancy(x, n);
	cout << result << endl;
	return 0;
}
