#include <iostream>
using namespace std;

// Hàm partition_lomuto
int partition_lomuto(int a[], int l, int r)
{
    int pivot = a[r];  // Chọn pivot là phần tử cuối cùng
    int i = l - 1;  // Chỉ số của phần tử nhỏ hơn pivot (ban đầu là -1)
    // Duyệt qua tất cả các phần tử từ l đến r-1 (tất cả trừ pivot)
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {  // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
            i++;  // Tăng chỉ số của phần tử nhỏ hơn pivot
            swap(a[i], a[j]);  // Hoán đổi phần tử nhỏ hơn pivot với phần tử hiện tại
        }
    }
    swap(a[i + 1], a[r]);  // Đặt pivot vào đúng vị trí của nó (sau khi phần tử nhỏ hơn pivot đã được hoán đổi)
    return i + 1;  // Trả về vị trí của pivot trong mảng đã phân chia
}

// Hàm quickSort sử dụng phân vùng Lomuto để sắp xếp mảng
void quickSort_lomuto(int a[], int l, int r)
{
    if (l < r) {  // Nếu chỉ số trái nhỏ hơn chỉ số phải
        int p = partition_lomuto(a, l, r);  // Phân chia mảng và nhận chỉ số của pivot
        quickSort_lomuto(a, l, p - 1);  // Đệ quy sắp xếp mảng con bên trái pivot
        quickSort_lomuto(a, p + 1, r);  // Đệ quy sắp xếp mảng con bên phải pivot
    }
}

int main () {
    int n;
    cin >> n;
    int a[10000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quickSort_lomuto(a, 0, n - 1);  // Gọi hàm quickSort để sắp xếp mảng từ chỉ số 0 đến n-1
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
