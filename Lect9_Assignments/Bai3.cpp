#include <iostream>      // Thư viện nhập xuất
#include <vector>        // Thư viện vector
#include <algorithm>     // Thư viện hỗ trợ hàm max
using namespace std;

int main() {
    int n, X;
    cin >> n >> X; // Nhập số lượng vật và trọng lượng tối đa

    vector<int> weight(n); // Mảng lưu trọng lượng
    vector<int> value(n);  // Mảng lưu giá trị

    // Nhập dữ liệu cho từng vật
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    // Tạo bảng dp lưu giá trị lớn nhất có thể đạt được với trọng lượng j
    vector<int> dp(X + 1, 0);

    // Duyệt qua từng vật
    for (int i = 0; i < n; i++) {
        // Duyệt ngược từ X về trọng lượng vật hiện tại
        for (int j = X; j >= weight[i]; j--) {
            // Chọn hoặc không chọn vật i
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    // In ra giá trị lớn nhất có thể đạt được với trọng lượng X
    cout << dp[X] << endl;

    return 0;
}
