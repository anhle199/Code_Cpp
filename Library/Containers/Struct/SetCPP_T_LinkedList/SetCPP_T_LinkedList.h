// File: SetCPP_T_LinkedList.h
// Use C++ template.

#ifndef SET_CPP_T_H_
#define SET_CPP_T_H_

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

// Return a reference to the first element in the set.
template <class T>
T& front(Set<T> &set);

// Return a reference to the last element in the set.
template <class T>
T& back(Set<T> &set);

// Return true if , false otherwise.
template <class T>
bool findValue(Set<T> &set, const T &value);

// Insert a new element to the set.
// The elements are always inserted in its respective position following this ordering.
template <class T>
void insertElement(Set<T> &set, const T &value);

// Remove element with value.
template <class T>
void removeElement(Set<T> &set, const T &value);

#endif // End of file SetCPP_T_LinkedList.h