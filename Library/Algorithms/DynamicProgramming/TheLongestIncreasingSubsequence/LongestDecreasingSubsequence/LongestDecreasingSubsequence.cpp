#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> longestDecreasingSubsequenceV1(vector<int> arr) {
    int n = arr.size(), i, j, pos_max;
    vector<int> length(n + 2, 0), position(n + 2), result;

    arr.insert(arr.begin(), INT_MAX);

    for (i = n; i >= 0; i--) {
        pos_max = n + 1;
        for (j = i + 1; j <= n; j++)
            if (arr[i] > arr[j] && length[j] > length[pos_max])
                pos_max = j;

        length[i] = length[pos_max] + 1;
        position[i] = pos_max;
    }

    i = position[0];
    while (i != n + 1) {
        result.push_back(arr[i]);
        i = position[i];
    }

    return result;
}

int lDS2(std::vector<int> arr)
{
    int n = arr.size();
    vector<int> length(n, 1);

    for (int i = 1; i < n; i++) 
        for (int j = 0; j < i; j++) 
            if (arr[j] > arr[i] && length[i] < length[j] + 1)
                length[i] = length[j] + 1;

    return *max_element(length.begin(), length.end());
}

int main() {
    vector<int> arr = {-12, -30, 50, 61, 30};
    
    cout << "Length of subsequence: " << longestDecreasingSubsequenceV2(arr) << endl;
    
    arr = longestDecreasingSubsequenceV1(arr);
    cout << "Length of subsequence: " << arr.size() << endl;
    for (const int &item : arr) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}