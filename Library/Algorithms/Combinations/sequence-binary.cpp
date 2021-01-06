// Liệt kê tất cả dãy nhị phân có độ dài n

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void printArray(vector<int> arr, const int &n);
void lietKeDayNhiPhanV1(vector<int> &arr, const int &n);
void lietKeDayNhiPhanV2(const int &n, string str = "");

int main() {
    int n = 3;
    
    // vector<int> arr(n, 0);
    // lietKeDayNhiPhanV1(arr, n);
    return 0;
}

void printArray(vector<int> arr, const int &n) {
    for (int i = 1; i <= n; i++)
        cout << arr[i];
    cout << " ";
}

void lietKeDayNhiPhanV1(vector<int> &arr, const int &n) {
    int product, i;

    do {
        product = 1;
        i = n - 1;

        for (const int &item : arr) {
            cout << item;
            product *= item;
        }
        cout << endl;

        do {
            if (arr[i] == 0) {
                arr[i] = 1;

                for (int j = n - 1; j > i; j--) {
                    arr[j] = 0;
                }

                break;
            } else i--;
        } while (i >= 0);
    } while (product != 1);
}

void lietKeDayNhiPhanV2(const int &n, string str) {
    if (n == 0)
        cout << str << " ";
    else {
        for (int i = 0; i <= 1; i++)
            lietKeDayNhiPhanV2(n - 1, str + char(i + '0'));
    }
}