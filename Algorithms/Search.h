#ifndef SEARCH_ALGORITHMS_H_
#define SEARCH_ALGORITHMS_H_

#include <vector>

using namespace std;





// --------------------------------------------------------------------------------------
// |                                                                                    |
// |                                    Declaration                                     |
// |                                                                                    |
// --------------------------------------------------------------------------------------


template <class T>
class Search {
    Search() {} // private initialize.

public:
    static const int NOT_FOUND;

    static int LinearSearch(const vector<T> &a, const T &key);
    static int SentinelLinearSearch(const vector<T> &a, const T &key);
    static int BinarySearch(const vector<T> &a, const T &key);
    static int InterpolationSearch(const vector<T> &a, const T &key);
};

// End of declaration.
// --------------------------------------------------------------------------------------





// --------------------------------------------------------------------------------------
// |                                                                                    |
// |                                Implementation                                      |
// |                                                                                    |
// --------------------------------------------------------------------------------------


template <class T>
const int Search<T>::NOT_FOUND = -1;

template <class T>
int LinearSearch(const vector<T> &a, const T &key) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] == key)
            return i;

    return Search<T>::NOT_FOUND;
}

template <class T>
int SentinelLinearSearch(const vector<T> &a, const T &key) {
    vector<int> copy = a;
    copy.push_back(key);
    int i = 0;

    while (copy[i++] != key);

    return (i == copy.size() ? Search<T>::NOT_FOUND : i);
}

template <class T>
int BinarySearch(const vector<T> &a, const T &key) {
    int left = 0;
    int right = a.size() - 1;
    int mid = 0;

    while (left <= right) {
        mid = (left + right) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            left = mid + 1;
        else 
            right = mid - 1;
    }

    return Search<T>::NOT_FOUND;
}

template <class T>
int InterpolationSearch(const vector<T> &a, const T &key) {
    int left = 0;
    int right = a.size() - 1;
    int mid = 0;

    while (a[left] != a[right] && key >= a[left] && key <= a[right]) {
        mid = left + (((right - left) * (key - a[left])) / (a[right] - a[left]));

        if (a[mid] < key)
            left = mid + 1;
        else if (a[mid] > key)
            right = mid - 1;
        else
            return mid;
    }

    if (a[left] == key)
        return left;

    return Search<T>::NOT_FOUND;
}

// End of implementation.
// --------------------------------------------------------------------------------------


#endif