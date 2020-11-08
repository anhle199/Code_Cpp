#include <iostream>
#include "Sort.h"

using namespace std;

 bool ascending(const int &lhs, const int &rhs) {
     return lhs <= rhs;
 }

int ascendingInt(const int &lhs, const int &rhs) {
    if (lhs == rhs)
        return 0;
    if (lhs < rhs)
        return 1;
    return -1;
}

int main() {
    vector<int> a = {38, 4, 6, 8, 72, 3, 5, 6, 8, 2, 3, 49, 23};

//    Sort<int>::SelectionSort(a, ascending);
//    Sort<int>::InterchangeSort(a, ascending);
//    Sort<int>::InsertionSort(a, ascending); // chua test.
//    Sort<int>::BubbleSort(a, ascending);
//    Sort<int>::ShakerSort(a, ascending);
//    Sort<int>::QuickSort(a, ascendingInt);
//    Sort<int>::HeapSort(a, ascendingInt);

    for (const int &item : a) 
        cout << item << " ";
    cout << endl;

    return 0;
}
