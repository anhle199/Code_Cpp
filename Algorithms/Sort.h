#ifndef SORT_ALGORITHMS_H_
#define SORT_ALGORITHMS_H_

#include <vector>

using namespace std;





// --------------------------------------------------------------------------------------
// |                                                                                    |
// |                                    Declaration                                     |
// |                                                                                    |
// --------------------------------------------------------------------------------------


template <class T>
class Sort {
    Sort() {} // private initialize.

    static void QuickSortImp(vector<T> &a, int left, int right);

public:
    static void InterchangeSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));
    static void SelectionSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));
    static void BubbleSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));
    static void ShakerSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));
    static void QuickSort(vector<T> &a, int (*order)(const T &lhs, const T &rhs));
    static void MergeSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));
    static void HeapSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));
    static void RadixSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));
    static void CountingSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));
    static void ShellSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));
};

// End of declaration.
// --------------------------------------------------------------------------------------





// --------------------------------------------------------------------------------------
// |                                                                                    |
// |                                Implementation                                      |
// |                                                                                    |
// --------------------------------------------------------------------------------------


template <class T>
void Sort<T>::InterchangeSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs)) {
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (!order(a[i], a[j]))
                swap(a[i], a[j]);
}

template <class T>
void Sort<T>::SelectionSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs)) {
    int n = a.size();
    int pos = 0;

    for (int i = 0; i < n - 1; i++) {
        pos = i;

        for (int j = i + 1; j < n; j++)
            if (!order(a[pos], a[j]))
                pos = j;

        swap(a[pos], a[pos]);
    }
}

template <class T>
void Sort<T>::BubbleSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs)) {
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (!order(a[j - 1], a[j]))
                swap(a[j - 1], a[j]);
}

template <class T>
void Sort<T>::ShakerSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs)) {
    int left = 0;
    int right = a.size() - 1;
    int lastPosition = 0;

    do {
        for (int j = right; j > left; j--)
            if (!order(a[j - 1], a[j])) {
                swap(a[j - 1], a[j]);
                lastPosition = j;
            }

        left = lastPosition + 1;

        for (int j = left; j < right; j++)
            if (!order(a[j - 1], a[j]))
                swap(a[j - 1], a[j]);

        right = lastPosition - 1;
    } while (left < right);
}

template <class T>
void QuickSortImp(vector<T> &a, int left, int right) {
    int i = left;
    int j = right;
    int x = a[(left + right) / 2];

    do {
        while (order(a[i], x) <= 0) ++i;
        while (order(x, a[j]) <= 0) --j;

        if (i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }

    } while (i <= j);

    if (left <= j) QuickSortImp(a, left, j);
    if (i <= right) QuickSortImp(a, i, right);
}

template <class T>
void QuickSort(vector<T> &a, int (*order)(const T &lhs, const T &rhs)) {
    if (!a.empty())
        QuickSortImp(a, 0, a.size() - 1);
}

// End of implementation.
// --------------------------------------------------------------------------------------


#endif