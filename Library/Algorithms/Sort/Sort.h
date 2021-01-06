#ifndef SORT_ALGORITHMS_H_
#define SORT_ALGORITHMS_H_

#include <vector>
#include "Search.h"

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

    // Additional functions for merge sort algorithm.
    static void merge(vector<T> &a, int left, int mid, int right, bool (*order)(const T &lhs, const T &rhs));
    static void MergeSortImp(vector<T> &a, int left, int right, bool (*order)(const T &lhs, const T &rhs));

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

    // static void RadixSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));

    // static void CountingSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));

    static void ShellSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));

    // static void FlashSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs));
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
void Sort<T>::InsertionSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs)) {
    T x;
    int n = a.size();
    int j;

    for (int i = 1; i < n; i++) {
        x = a[i];

        j = i - 1;
        while (j >= 0 && !order(a[j], x)) {
            a[j + 1] = a[j];
            --j;
        }

        a[j + 1] = x;
    }
}

template <class T>
void Sort<T>::BinaryInsertionSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs)) {
    T x;
    int n = a.size();
    int left, right, mid;

    for (int i = 1; i < n; i++) {
        x = a[i];

        left = 0;
        right = i - 1;
    
        while (left <= right) {
            mid = (left + right) / 2;

            if (!order(a[mid], x))
                right = mid - 1;
            else
                left = mid + 1;
        }

        for (int j = i; j > left; j--)
            a[j] = a[j - 1];

        a[left] = x;
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
    int lastPosition = right;

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
    T x = a[(left + right) / 2];

    do {
        while (order(a[i], x) > 0) ++i;
        while (order(x, a[j]) > 0) --j;

        if (i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }

    } while (i <= j);

    if (left < j) QuickSortImp(a, left, j, order);
    if (i < right) QuickSortImp(a, i, right, order);
}

template <class T>
void Sort<T>::QuickSort(vector<T> &a, int (*order)(const T &lhs, const T &rhs)) {
    if (!a.empty())
        QuickSortImp(a, 0, a.size() - 1, order);
}

template <class T>
void Sort<T>::merge(vector<T> &a, int left, int mid, int right, bool (*order)(const T &lhs, const T &rhs)) {
    vector<T> arrayLeft(a.begin() + left, a.begin() + mid + 1); // contains from a[left] to a[mid].
    vector<T> arrayRight(a.begin() + mid + 1, a.begin() + right + 1); // contains from a[mid + 1] to a[right].
    int sizeLeft = arrayLeft.size();
    int sizeRight = arrayRight.size();
    int indexLeft = 0;
    int indexRight = 0;
    int index = left;

    while (indexLeft < sizeLeft && indexRight < sizeRight) {
        if (order(arrayLeft[indexLeft], arrayRight[indexRight]))
            a[index++] = arrayLeft[indexLeft++];
        else 
            a[index++] = arrayRight[indexRight++];
    }

    while (indexLeft < sizeLeft)
        a[index++] = arrayLeft[indexLeft++];

    while (indexRight < sizeRight)
        a[index++] = arrayRight[indexRight++];
}

template <class T>
void Sort<T>::MergeSortImp(vector<T> &a, int left, int right, bool (*order)(const T &lhs, const T &rhs)) {
    if (left < right) {
        int mid = (left + right) / 2;

        MergeSortImp(a, left, mid, order);
        MergeSortImp(a, mid + 1, right, order);
        merge(a, left, mid, right, order);
    }
}

template <class T>
void Sort<T>::MergeSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs)) {
    if (!a.empty())
        MergeSortImp(a, 0, a.size() - 1, order);
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
    T x = a[i];

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

template <class T>
void Sort<T>::ShellSort(vector<T> &a, bool (*order)(const T &lhs, const T &rhs)) {
    int n = a.size();
    int k = (int)log2(n) - 1;
    vector<int> lengths(k);
    lengths[k - 1] = 1;

    for (int i = k - 2; i >= 0; i--)
        lengths[i] = (2 * lengths[i + 1]) + 1;

    for (int step = 0; step < k; step++) {
        int length = lengths[step];

        for (int i = length; i < n; i++) {
            T x = a[i];
            int j = i - length;
            while (j >= 0 && !order(a[j], x)) {
                a[j + length] = a[j];
                j -= length;
            }

            a[j + length] = x;
        }
    }
}

// End of implementation.
// --------------------------------------------------------------------------------------


#endif
