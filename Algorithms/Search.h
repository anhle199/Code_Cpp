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

    static void makeValidIndex(vector<T> &a, int &start, int &end);

public:
    static const int NOT_FOUND;

    static int LinearSearch(const vector<T> &a, const T &key, int start, int end);
    static int SentinelLinearSearch(const vector<T> &a, const T &key, int start, int end);
    static int BinarySearch(const vector<T> &a, const T &key, int start, int end);
    static int InterpolationSearch(const vector<T> &a, const T &key, int start, int end);
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
void Search<T>::makeValidIndex(vector<T> &a, int &start, int &end) {
    if (start < 0)
        start = 0;
    
    if (end > a.size())
        end = a.size();
}

template <class T>
int Search<T>::LinearSearch(const vector<T> &a, const T &key, int start, int end) {
    Search<T>::makeValidIndex(a, start, end);

    for (int i = start; i < end; i++)
        if (a[i] == key)
            return i;

    return Search<T>::NOT_FOUND;
}

template <class T>
int Search<T>::SentinelLinearSearch(const vector<T> &a, const T &key, int start, int end) {
    if (a.empty())
        return Search<T>::NOT_FOUND;

    Search<T>::makeValidIndex(a, start, end);

    if (end < a.size()) {
        a[end] = key;
        while (a[start++] != key);
    } else {
        vector<int> copy = a;
        copy.push_back(key);
        ++end;

        while (copy[start++] != key);
    }

    return (start == end ? Search<T>::NOT_FOUND : start);
}

template <class T>
int Search<T>::BinarySearch(const vector<T> &a, const T &key, int start, int end) {
    Search<T>::makeValidIndex(a, start, end);

    int left = start;
    int right = end - 1;
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
int Search<T>::InterpolationSearch(const vector<T> &a, const T &key, int start, int end) {
    Search<T>::makeValidIndex(a, start, end);

    int left = start;
    int right = end - 1;
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