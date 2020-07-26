// File: SetCPP_T_LinkedListImp.h
// Implement functions in the file SetCPP_T_LinkedListImp.h

#ifndef SET_CPP_T_IMP_H_
#define SET_CPP_T_IMP_H_

#include "SetCPP_T_LinkedList.h"
#include <iostream> // Use std::cout, std::endl.
#include <algorithm> // Use function std::swap().

template <class T>
struct Node {
    T data;
    Node<T> *next;
};

template <class T>
struct List {
    Node<T> *head, *tail;
};

template <class T>
void printSet(Set<T> &set) {
    List<T> *list = (List<T>*) set.data;

    for (Node<T> *node = list->head; node != nullptr; node = node->next)
        std::cout << node->data << " ";
    std::cout << std::endl;
}

template <class T>
void initSet(Set<T> &set) {
    List<T> *list = new List<T>;
    set.data = list;

    if (list != nullptr)
        list->head = list->tail = nullptr;
}

template <class T>
void closeSet(Set<T> &set) {
    List<T> *list = (List<T>*) set.data;

    clearSet(set);
    delete list;
}

template <class T>
void clearSet(Set<T> &set) {
    List<T> *list = (List<T>*) set.data;

    if (list != nullptr) {
        Node<T> *node = list->head;
        Node<T> *temp;

        while (node != nullptr) {
            temp = node->next;
            delete node;
            node = nullptr;
            node = temp;
        }
    }
}

template <class T>
int sizeSet(Set<T> &set) {
    List<T> *list = (List<T>*) set.data;
    int size = 0;

    if (list != nullptr) {
        Node<T> *node = list->head;

        while (node != nullptr) {
            size++;
            node = node->next;
        }
    } 

    return size;
}

template <class T>
bool isEmpty(Set<T> &set) {
    List<T> *list = (List<T>*) set.data;

    if (list == nullptr || list->head == nullptr)
        return true;
    return false;
}

template <class T>
T& front(Set<T> &set) {
    List<T> *list = (List<T>*) set.data;
    static T dummy;

    if (list == nullptr || list->head == nullptr)
        return dummy;
    
    return list->head->data;
}

template <class T>
T& back(Set<T> &set) {
    List<T> *list = (List<T>*) set.data;
    static T dummy;

    if (list == nullptr || list->head == nullptr)
        return dummy;
    
    return list->tail->data;
}

template <class T>
bool findValue(Set<T> &set, const T &value) {
    List<T> *list = (List<T>*) set.data;
    Node<T> *node = list->head;

    while (node != nullptr) {
        if (node->data == value)
            return true;
        
        node = node->next;
    }

    return false;
}

template <class T>
Node<T>* makeNode(const T &value) {
    Node<T> *node = new Node<T>;

    if (node != nullptr) {
        node->data = value;
        node->next = nullptr;
    }

    return node;
}

template <class T>
void insertAtFirst(List<T> *&list, Node<T> *&node) {
    if (list->head == nullptr) { // Không cần kiểm tra list == nullptr vì đã kiểm tra trước khi gọi hàm này.
        list->head = list->tail = node;
    } else { // head = tail not null
        node->next = list->head;
        list->head = node;
    }
}

template <class T>
void insertElement(Set<T> &set, const T &value) {
    List<T> *list = (List<T>*) set.data;
    Node<T> *node = makeNode(value);
    Node<T> *temp = nullptr;

    if (list == nullptr || node == nullptr)
        return;

    insertAtFirst(list, node);

    temp = node->next; // node = head.
    while (temp != nullptr) {
        if (node->data > temp->data) {
            std::swap(node->data, temp->data);
        } else if (node->data == temp->data) {
            removeNodeInList(list, node);
            return;
        }

        node = node->next;
        temp = temp->next;
    }
}

template <class T>
void removeNodeInList(List<T> *&list, Node<T> *&node) {
    Node<T> *temp = node->next;

    if (list->head == nullptr) { // head = tail = null.
        return;
    
    } else if (list->head == list->tail) { // head = tail not null.
        delete list->head;
        list->head = nullptr;
    
    } else if (list->head == node) { // size of set greater than one and head = node.
        list->head = temp;
        delete node;
        
    } else if (list->tail == node) { // size of set greater than one and tail = node.
        for (temp = list->head; temp->next != list->tail; temp = temp->next);
        
        delete list->tail;
        list->tail = temp;
        temp->next = nullptr;
    
    } else { // size of set greater than one and head != node and tail != node.
        if (node->next == list->tail) {
            list->tail = node;
        }

        *node = *temp;
        delete temp;
        temp = nullptr;
    }
}

template <class T>
void removeElement(Set<T> &set, const T &value) {
    List<T> *list = (List<T>*) set.data;
    Node<T> *node = list->head;

    if (list == nullptr)
        return;

    while ((node != nullptr) && (node->data != value))
        node = node->next;

    if (node == nullptr)
        return;

    removeNodeInList(list, node);
}

#endif // End of file SetCPP_T_LinkedListImp.h