#include <iostream>
using namespace std;
int SumN(int n) { // Hàm tính tổng từ 1 đến n
	if (n == 0 || n == 1) return 1;
	return n + SumN(n - 1); // Hàm trả về n cộng với đệ quy của nó
}

int main() {
	int n;
	cin >> n;
	int sum = SumN(n);
	cout << sum << endl;
	return 0;
}
