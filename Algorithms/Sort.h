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

    // Additional functions for quick sort algorithm.
    static void QuickSortImp(vector<T> &a, int left, int right, int (*order)(const T &lhs, const T &rhs));

    // Additional functions for heap sort algorithm.
    static void createHeap(vector<T> &a, int (*order)(const T &lhs, const T &rhs));
    static void shift(vector<T> &a, int left, int right, int (*order)(const T &lhs, const T &rhs));

public:
    static void InterchangeSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));

    static void SelectionSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));

    static void InsertionSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));
    static void BinaryInsertionSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));

    static void BubbleSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));
    static void ShakerSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));

    static void QuickSort(vector<T> &a, int (*order)(const T &lhs, const T &rhs));

    static void MergeSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));

    static void HeapSort(vector<T> &a, int (*order)(const T &lhs, const T &rhs));

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

        swap(a[i], a[pos]);
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
    int left = 1;
    int right = a.size() - 1;
    int lastPosition = 0;

    do {
        for (int i = right; i >= left; i--)
            if (!order(a[i - 1], a[i])) {
                swap(a[i - 1], a[i]);
                lastPosition = i;
            }

        left = lastPosition + 1;

        for (int i = left; i <= right; i++)
            if (!order(a[i - 1], a[i])) {
                swap(a[i - 1], a[i]);
                lastPosition = i;
            }

        right = lastPosition - 1;
    } while (left <= right);
}

template <class T>
void Sort<T>::QuickSortImp(vector<T> &a, int left, int right, int (*order)(const T &lhs, const T &rhs)) {
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

    if (left <= j) QuickSortImp(a, left, j, order);
    if (i <= right) QuickSortImp(a, i, right, order);
}

template <class T>
void Sort<T>::QuickSort(vector<T> &a, int (*order)(const T &lhs, const T &rhs)) {
    if (!a.empty())
        QuickSortImp(a, 0, a.size() - 1, order);
}

template <class T>
void Sort<T>::createHeap(vector<T> &a, int (*order)(const T &lhs, const T &rhs)) {
    int i = a.size() / 2;

    while (i >= 0) {
        Sort<T>::shift(a, i, a.size() - 1, order);
        --i;
    }
}

template <class T>
void Sort<T>::shift(vector<T> &a, int left, int right, int (*order)(const T &lhs, const T &rhs)) {
    int i = left;
    int j = 2 * i;
    int x = a[i];

    while (j <= right) {
        if ((j < right) && (order(a[j], a[j + 1]) > 0))
            ++j;
        
        if (order(a[j], x) >= 0) 
            break;
    
        a[i] = a[j];
        i = j;
        j  = 2 * i;
    }

    a[i] = x;
}

template <class T>
void Sort<T>::HeapSort(vector<T> &a, int (*order)(const T &lhs, const T &rhs)) {
    Sort<T>::createHeap(a, order);
    int right = a.size() - 1;

    while (right > 0) {
        swap(a[0], a[right]);
        --right;
        shift(a, 0, right, order);
    }
}

// End of implementation.
// --------------------------------------------------------------------------------------


#endif
