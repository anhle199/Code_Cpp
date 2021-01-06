// Liệt kê tất cả tập con gồm k phần tử của tập hợp từ 1,...,n (k <= n).
// Liệt kê tất cả tập con của tập hợp từ 1,...,n

#include <iostream>
#include <vector>

using namespace std;

// Liệt kê tất cả tập con có k phần tử.
template <class T>
void lietKeTapConV1(vector<T> &arr, const int &n, const int &k);
// Liệt kê tất cả tập con.
template <class T>
void lietKeTapConV2(vector<T> &arr, const int &n);


int main() {
    int n = 5, k = 3;
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Tap con co " << k << " phan tu: " << endl;
    lietKeTapConV1(arr, n, k);

    cout << "Tat ca tap con: " << endl;
    lietKeTapConV2(arr, n);

    return 0;
}

template <class T>
void lietKeTapConV1(vector<T> &arr, const int &n, const int &k) {
    vector<bool> check(n, false);
    int i, count;
    bool flag;

    do {
        i = n - 1;
        count = 0;
        flag = false;

        for (int j = 0; j < n; j++) {
            if (check[j] == true) count++;
            else flag = true;
        }

        if (count == k) {
            for (int j = 0; j < n; j++)
                if (check[j] == true)
                    cout << arr[j] << " ";
            cout << endl;
        }
    
        do {
            if (check[i] == false) {
                check[i] = true;

                for (int j = n - 1; j > i; j--) {
                    check[j] = false;
                }

                break;
            } else i--;
        } while (i >= 0);
    } while (flag);
}

template <class T>
void lietKeTapConV2(vector<T> &arr, const int &n) {
    vector<bool> check(n, false);
    int i;
    bool flag, is_empty;

    do {
        i = n - 1;
        flag = false;
        is_empty = true;

        for (int j = 0; j < n; j++) {
            if (check[j] == true) {
                cout << arr[j] << " ";
                is_empty = false;
            }
            else flag = true;
        }

        if (is_empty)
            cout << "Empty";
            
        cout << endl;
    
        do {
            if (check[i] == false) {
                check[i] = true;

                for (int j = n - 1; j > i; j--) {
                    check[j] = false;
                }

                break;
            } else i--;
        } while (i >= 0);
    } while (flag);
}