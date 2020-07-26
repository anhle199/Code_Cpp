#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

vector<int> longestIncreasingSubsequenceV1(vector<int> arr) {
    int n = arr.size(), i, j, pos_max;
    vector<int> length(n + 2, 0), position(n + 2), result;

    arr.insert(arr.begin(), INT_MIN);

    for (int i = n; i >= 0; i--)
    {
        pos_max = n + 1;

        for (j = i + 1; j <= n; j++)
            if (arr[i] < arr[j] && length[j] > length[pos_max])
                pos_max = j;

        length[i] = length[pos_max] + 1;
        position[i] = pos_max;
    }

    i = position[0];
    while (i != n + 1)
    {
        result.push_back(arr[i]);
        i = position[i];
    }

    return result;
}

int longestIncreasingSubsequenceV2(vector<int> arr) {
    int n = arr.size();
    vector<int> length(n);

    length[0] = 1;

    for (int i = 1; i < n; i++) {
        length[i] = 1;

        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && length[i] < length[j] + 1)
                length[i] = length[j] + 1;
    }

    return *max_element(length.begin(), length.end());
}

int main() {
    vector<int> arr = {5, 2, 3, 4, 9, 10, 5, 6, 7, 5};
    vector<int> arr1 = {10, 22, 9, 33, 21, 50, 41, 60, 80};

    cout << "Length of subsequence: " << longestIncreasingSubsequenceV2(arr) << endl;

    arr1 = longestIncreasingSubsequenceV1(arr1);
    cout << "Length of subsequence: " << arr1.size() << endl;
    for (const int &item : arr1) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}