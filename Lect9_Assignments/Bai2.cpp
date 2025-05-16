#include <iostream>      // Thư viện nhập xuất
#include <vector>        // Thư viện sử dụng vector
using namespace std;     // Sử dụng không gian tên std

// Hàm đệ quy kiểm tra xem có tổ hợp nào có tổng bằng X không
bool isSubsetSum(const vector<int>& A, int n, int X) {
    // Tạo bảng dp với kích thước (n+1) x (X+1)
    vector<vector<bool>> dp(n + 1, vector<bool>(X + 1, false));

    // Nếu tổng là 0, luôn có thể tạo ra bằng cách không chọn phần tử nào
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Duyệt qua từng phần tử và từng tổng
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= X; j++) {
            if (j >= A[i - 1]) {
                // Có thể chọn hoặc không chọn phần tử thứ i-1
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
            } else {
                // Không thể chọn phần tử thứ i-1 vì lớn hơn j
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Kết quả cuối cùng nằm ở dp[n][X]
    return dp[n][X];
}

int main() {
    int n, X;
    cin >> n >> X; // Nhập số lượng học sinh và tổng cần tìm

    vector<int> A(n); // Khởi tạo vector A chứa độ tuổi
    for (int i = 0; i < n; i++) {
        cin >> A[i]; // Nhập từng độ tuổi
    }

    // Gọi hàm kiểm tra và in kết quả
    if (isSubsetSum(A, n, X)) {
        cout << "YES\n"; // Nếu tìm được nhóm có tổng bằng X
    } else {
        cout << "NO\n";  // Nếu không tìm được
    }

    return 0;
}
