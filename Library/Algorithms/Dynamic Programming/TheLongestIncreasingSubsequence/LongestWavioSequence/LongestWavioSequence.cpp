#include <iostream>
#include <vector>

using namespace std;

int longestWavioSequence(const vector<int> &arr) {
    int n = arr.size(), max_length;
    vector<int> length_1(n, 1), length_2(n, 1);

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && length_1[i] < length_1[j] + 1)
                length_1[i] = length_1[j] + 1;
        
    for (int i = n - 2; i > -1; i--)
        for (int j = n - 1; j > i; j--)
            if (arr[i] > arr[j] && length_2[i] < length_2[j] + 1)
                length_2[i] = length_2[j] + 1;
    
    max_length = length_1[0] + length_2[0];
    if (length_1[0] == 1 || length_2[0] == 1)
        max_length = 2;
    
    for (int i = 1; i < n; i++)
        if ((length_1[i] + length_2[i]) > max_length) {
            if (length_1[i] > 1 && length_2[i] > 1)
                max_length = length_1[i] + length_2[i];
        }

    return max_length - 1;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 2, 1, 2, 3, 4, 3, 2, 1, 5, 4, 1, 2, 3, 2, 2, 1}; // 9
    vector<int> arr2 = {1, 2, 3, 4, 5, 4, 3, 2, 1, 10}; // 9
    vector<int> arr3 = {1, 2, 3, 4, 5}; // 1
    
    cout << "Length of wavio sequence: " << longestWavioSequence(arr1) << endl;
    cout << "Length of wavio sequence: " << longestWavioSequence(arr2) << endl;
    cout << "Length of wavio sequence: " << longestWavioSequence(arr3) << endl;

    return 0;
}