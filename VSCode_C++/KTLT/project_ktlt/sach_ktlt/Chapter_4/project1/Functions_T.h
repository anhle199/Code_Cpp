#ifndef FUNCTIONS_T_H_
#define FUNCTIONS_T_H_

#include "SingleLinkedListCPP_T.h"

/*
 * -------------------------------------------------------
 * Phần khai báo
 * -------------------------------------------------------
 */

template <class T>
void inputList(List<T> &list);

template <class T>
void removeElementsDuplicateInArray(vector<T> &arr);

template <class T>
void removeElementsDuplicateInList(List<T> &list);

template <class T>
void splitIntoTwoLists(List<T> &ist, List<T> &list_even_position, List<T> &list_odd_position);

template <class T>
void reverseList(List<T> &list);

/*
 * -------------------------------------------------------
 * Phần cài đặt 
 * -------------------------------------------------------
 */

template <class T>
void inputList(List<T> &list) {
    T data;

    cout << "Enter value of element (press Ctrl + Z to stop): ";
    while (cin >> data) {
        insertAtLast(list, data);
        cout << "Enter value of element (press Ctrl + Z to stop): ";
    }
}

template <class T>
void removeElementsDuplicateInArray(vector<T> &arr) {
    int n = arr.size(), m = 0;
    bool is_duplicate = false;

    for (int i = 0; i < n; i++) {
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

template <class T>
void removeElementsDuplicateInList(List<T> &list) {
    vector<T> array_list = toArray(list);
    List<T> result;

    removeElementsDuplicateInArray(array_list);
    deleteList(list);

    for (const T &item : array_list)
        insertAtLast(result, item);

    list = result;
}

template <class T>
void splitIntoTwoLists(List<T> &list, List<T> &list_even_position, List<T> &list_odd_position) {
    for (Node<T> *node = list.head; node != nullptr; node = node->next) {
        insertAtLast(list_odd_position, node->data); // Phần tử đầu tiên là vị trí lẻ.
        
        node = node->next;
        if (node == nullptr) // Trường hợp node là phần tử phía sau list->tail.
            break;
        
        insertAtLast(list_even_position, node->data); // Phần tử kế tiếp là vị trí chẵn.
    }
}

template <class T>
void reverseList(List<T> &list) {
    List<T> list_reverse;

    for (Node<T> *node = list.head; node != nullptr; node = node->next)
        insertAtFirst(list_reverse, node->data);
    
    deleteList(list);
    list = list_reverse;
}

#endif