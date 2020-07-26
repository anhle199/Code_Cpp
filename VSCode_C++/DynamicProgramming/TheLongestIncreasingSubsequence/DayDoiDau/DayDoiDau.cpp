#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int doiDau(const vector<int> &arr) {
    int n = arr.size();
    vector<int> L(n), P(n);

    L[0] = P[0] = 1;

    for (int i = 1; i < n; i++) {
        L[i] = P[i] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[i] > 0 && arr[j] < 0 && L[i] < P[j] + 1)
                L[i] = P[j] + 1;
            else if (arr[i] < 0 && arr[j] > 0 && P[i] < L[j] + 1)
                P[i] = L[j] + 1;
        }
    }

    return max(*max_element(L.begin(), L.end()), *max_element(P.begin(), P.end()));
}

int main() {
    vector<int> arr = {-4, -8, 7, 34, 3, -4, 6, -7, 46, 34, -3, -4, -6, -8};
    vector<int> arr1 = {-4, 8, 7, 34, 3, 4, 6, 7, 46, 34, 3, 4, 6, 8};

    cout << doiDau(arr) << endl;
    cout << doiDau(arr1) << endl;

    return 0;
}
