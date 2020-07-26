#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> arr, const int &n) {
    for (int i = 1; i <= n; i++)
        cout << arr[i];
    cout << " ";
}

void HoanVi(vector<int> &arr, vector<bool> &check, const int &k, const int &n) {
    for (int i = 1; i <= n; i++) {
        if (check[i]) {
            arr[k] = i;

            if (k == n)
                printArray(arr, n);
            else {
                check[i] = false;
                HoanVi(arr, check, k + 1, n);
                check[i] = true;
            }
        }
    }
}

int main() {
    int n = 4;
    vector<int> arr(n + 1, true);
    vector<bool> check(n + 1, true);
    
    HoanVi(arr, check, 1, n);

    return 0;
}