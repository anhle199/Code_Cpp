#include <iostream>
#include <vector>

using namespace std;

// Cách này tự suy nghĩ làm theo gợi ý bảng phương án 2 chiều nên hơi dài.
// bool sumSubsequenceEqualS(const vector<int> &arr, int n, int limit_sum) {
//     vector<vector<bool>> L(n + 1, vector<bool> (limit_sum + 1)); // Default value is false.

//     for (int i = 0; i <= n; i++)
//         L[i][0] = true;

//     for (int i = 1; i <= n; i++) {
//         for (int j = limit_sum; j >= arr[i - 1]; j--) {
//             if (L[i - 1][j] == true || L[i - 1][j - arr[i - 1]] == true)
//                 for (int k = i; k <= n; k++)
//                     L[k][j] = true;
//             else L[i][j] = false;
//         }
//     }

//     return L[n][limit_sum];
// }

// Cách này dùng bản phương án 1 chiều hay hơn.
bool sumSubsequenceEqualS(const vector<int> &arr, int n, int limit_sum) {
    vector<bool> L(limit_sum + 1); // Default value is false.

    L[0] = 1;
    L[limit_sum] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = limit_sum; j >= arr[i - 1]; j--)
            if (L[j] == 0 && L[j - arr[i - 1]] == 1)
                L[j] = 1;

    return L[limit_sum];
}

int main() {
    vector<int> arr = {4, 2, 2, 4, 3};
    cout << sumSubsequenceEqualS(arr, 5, 0) << endl;
    
    return 0;
}