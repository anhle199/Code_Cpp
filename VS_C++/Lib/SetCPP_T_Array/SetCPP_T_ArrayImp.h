#ifndef SET_CPP_T_ARRAY_IMP_H_
#define SET_CPP_T_ARRAY_IMP_H_

#include "D:/tools/VSCode_C++/lib/Array1D_T/Array1D_T.h"
#include "D:/tools/VSCode_C++/lib/Array1D_T/Array1D_T_Imp.h"
#include "SetCPP_T_Array.h"
#include <iostream>

using namespace std;

template <class T>
void printSet(Set<T> &set) {
    Array1D<T> &arr = *(Array1D<T>*) set.data;
    printArray(arr);
}

template <class T>
void initSet(Set<T> &set) {
    static Array1D<T> arr;

    arr.data = nullptr;
    arr.number_of_elements = 0;
    set.data = &arr;
}

template <class T>
void closeSet(Set<T> &set) {
    Array1D<T> &arr = *(Array1D<T>*) set.data;
    deleteArray(arr);
}

template <class T>
void clearSet(Set<T> &set) {
    Array1D<T> &arr = *(Array1D<T>*) set.data;
    resizeArray(arr, 0);
}

template <class T>
int sizeSet(Set<T> &set) {
    Array1D<T> &arr = *(Array1D<T>*) set.data;
    return sizeArray(arr);
}

template <class T>
bool isEmpty(Set<T> &set) {
    Array1D<T> &arr = *(Array1D<T>*) set.data;
    
    if (sizeArray(arr) == 0)
        return true;
    return false;
}

template <class T>
T* const findElement(Set<T> &set, const T &value) {
    Array1D<T> &arr = *(Array1D<T>*) set.data;
    return binarySearch(arr, value, true);
}

template <class T>
T* const beginSet(Set<T> &set) {
    Array1D<T> &arr = *(Array1D<T>*) set.data;
    return beginArray(arr);
}

template <class T>
T* const endSet(Set<T> &set) {
    Array1D<T> &arr = *(Array1D<T>*) set.data;
    return endArray(arr);
}

template <class T>
void insertElement(Set<T> &set, const T &value) {
    Array1D<T> &arr = *(Array1D<T>*) set.data;

    if (findElement(set, value) == nullptr)
        binaryInsertWithAscending(arr, value, true);
}

template <class T>
void removeElementWithValue(Set<T> &set, const T &value) {
    Array1D<T> &arr = *(Array1D<T>*) set.data;
    T* ptr_pos = findElement(set, value);
    
    if (sizeArray(arr) == 0 || ptr_pos == nullptr) {
        return;
    } else {
        removeAtPosition(ptr_pos);
    }
}

template <class T>
void removeElementWithPosition(Set<T> &set, T *&pos) {
    Array1D<T> &arr = *(Array1D<T>*) set.data;
    
    if (sizeArray(arr) == 0 || pos == nullptr)
        return;

    removeAtPosition(arr, pos - beginArray(arr));
}

#endif