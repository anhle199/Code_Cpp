// Thuật toán phát sinh chỉnh hợp không lặp chặp k của n phần tử.
// Mảng bất đầu từ vị trí 1, vị trí 0 không dùng đến.
// Đối với v1 thì mảng không cần khởi tạo giá trị, cần sử dụng thêm mảng bool.
// Đối với v2 thì mảng cần khởi tạo giá trị trước.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
void printArray(const vector<T> &arr, const int &k);
template <class T>
void phatSinhChinhHopV1(vector<T> &arr, vector<bool> &check, const int &n, const int &k, const int &i = 1);
template <class T>
void phatSinhChinhHopV2(vector<T> &arr, const int &n, const int &k, const int &i = 1);

int main() {
    int n = 3, k = 2;
    vector<int> arr1(n + 1);
    vector<bool> check(n + 1, false);
    phatSinhChinhHopV1(arr1, check, n, k);
    
    vector<int> arr2 = {0, 1, 2, 3};
    phatSinhChinhHopV2(arr2, n, k);

	return 0;
}

template <class T>
void printArray(const vector<T> &arr, const int &k) {
    for (int i = 1; i <= k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class T>
void phatSinhChinhHopV1(vector<T> &arr, vector<bool> &check, const int &n, const int &k, const int &i) {
    for (int j = 1; j <= n; j++) {
        if (check[j] == false) {
            arr[i] = j;
            if (i == k) {
                printArray(arr, k);
            } else {
                check[j] = true; // Đánh dầu phần tử đã được chọn.
                phatSinhChinhHopV1(arr, check, n, k, i + 1);
                check[j] = false; // Bỏ đánh dấu.
            }
        }
    }
}

template <class T>
void phatSinhChinhHopV2(vector<T> &arr, const int &n, const int &k, const int &i) {
    for (int j = i; j <= n; j++) {
        swap(arr[j], arr[i]);

        if (i < k) {
            phatSinhChinhHopV2(arr, n, k, i + 1);
        } else {
            printArray(arr, k);
        }

        swap(arr[j], arr[i]);
    }
}