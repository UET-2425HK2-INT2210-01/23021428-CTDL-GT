#include <iostream>
using namespace std;

// Hàm kiểm tra xem có tập con nào có tổng bằng sum không
bool subsetSum(int a[], int n, int sum) {
    if (sum == 0) return true; // Nếu tổng cần tìm là 0 thì chắc chắn đúng (tập rỗng cũng được)
    if (n == 0) return false; // Nếu không còn phần tử nào mà tổng vẫn chưa đạt -> sai

    if (a[n - 1] > sum) // Nếu phần tử cuối lớn hơn tổng cần tìm, bỏ qua phần tử đó
        return subsetSum(a, n - 1, sum);

    // Kiểm tra hai khả năng:
    // 1. Bỏ qua phần tử cuối
    // 2. Chọn phần tử cuối và giảm tổng cần tìm đi a[n - 1]
    return subsetSum(a, n - 1, sum) || subsetSum(a, n - 1, sum - a[n - 1]);
}

int main() {
    int n, x;           // n là số phần tử, x là tổng cần tìm
    cin >> n >> x;

    int a[100];

    // Nhập mảng a gồm n số tự nhiên
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Gọi hàm kiểm tra tập con có tổng bằng x không
    if (subsetSum(a, n, x))
        cout << "YES";  // Nếu có thì in YES
    else
        cout << "NO";   // Nếu không thì in NO

    return 0;
}
