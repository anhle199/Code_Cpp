// File: SetCPP_T_Array.h
// Use C++ template.

#ifndef SET_CPP_T_ARRAY_H_
#define SET_CPP_T_ARRAY_H_

#include "D:/tools/VSCode_C++/lib/Array1D_T/Array1D_T.h"
#include "D:/tools/VSCode_C++/lib/Array1D_T/Array1D_T_Imp.h"

template <class T>
struct Set {
    void *data;
};

// Print all elements of set.
template <class T>
void printSet(Set<T> &set);

// Initialize a set.
template <class T>
void initSet(Set<T> &set);

// Delete a set.
template <class T>
void closeSet(Set<T> &set);

// Delete all elements of set.
template <class T>
void clearSet(Set<T> &set);

// Return number of elements in the set.
template <class T>
int sizeSet(Set<T> &set);

// Return true if the set size is 0, false otherwise.
template <class T>
bool isEmpty(Set<T> &set);

// Return a const pointer to the element in the set, null pointer otherwise.
template <class T>
T* const findElement(Set<T> &set, const T &value);

// Return a const pointer to the first element in the set.
template <class T>
T* const beginSet(Set<T> &set);

// Return a const pointer to the last element in the set.
template <class T>
T* const endSet(Set<T> &set);

// Insert a new element to the set.
// The elements are always inserted in its respective position following this ordering.
template <class T>
void insertElement(Set<T> &set, const T &value);

// Remove element with value.
template <class T>
void removeElementWithValue(Set<T> &set, const T &value);

// Remove element with position.
template <class T>
void removeElementWithPosition(Set<T> &set, T *&pos);

#endif // End of file SetCPP_T_Array.h