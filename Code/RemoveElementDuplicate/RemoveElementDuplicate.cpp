#include <vector>

template <class T>
void removeElementsDuplicate(vector<T> &arr) {
    int n = arr.size(), m = 0;
    bool is_duplicate = false;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++)
            if (arr[i] == arr[j]) {
                is_duplicate = true;
                break;
            }
        
        if (!is_duplicate) {
            arr[m] = arr[i];
            m++;
        }

        is_duplicate = false;
    }

    arr.resize(m);
}