#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;              // Nhập số đồ vật và trọng lượng tối đa
    int w[100], v[100];         // Mảng lưu trọng lượng và giá trị (giả sử tối đa 100 đồ vật)

    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];    // Nhập trọng lượng và giá trị từng đồ vật

    int dp[1001] = {0};         // dp[i] là giá trị lớn nhất với tổng trọng lượng i

    // Quy hoạch động: Duyệt từng đồ vật
    for (int i = 0; i < n; i++) {
        // Duyệt ngược để không sử dụng lại đồ vật đó 2 lần
        for (int j = x; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[x];              // In ra giá trị lớn nhất đạt được
    return 0;
}
