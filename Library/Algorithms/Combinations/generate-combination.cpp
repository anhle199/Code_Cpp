#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<bool> &arr) {
    for (int i = 0; i < arr.size(); i++)
        if (arr[i])
            cout << i + 1;
    
    cout << " ";
}

void printAllCombination(vector<bool> &arr, const int& n, const int& k, const int& pos) {
    if (k == 0)
        return;

    for (int i = pos; i < n; i++) {
        if (arr[i] == false) {
            arr[i] = true;

            if (k - 1 == 0)
                printArray(arr);
            else 
                printAllCombination(arr, n, k - 1, i + 1);

            arr[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<bool> arr(n, false);
    for (int i = 0; i <= n; i++)
        printAllCombination(arr, n, i, 0);

    return 0;
}