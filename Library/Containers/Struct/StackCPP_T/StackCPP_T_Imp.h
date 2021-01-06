// File: StackCPP_T_Imp.h
// Implement functions in the file StackCPP_T.h

#ifndef STACK_CPP_T_IMP_H_
#define STACK_CPP_T_IMP_H_

#include "StackCPP_T.h"
#include <iostream>

template <class T>
struct Node {
    T data;
    Node<T> *next;
};

template <class T>
struct List {
    Node<T> *head;
};

template <class T>
void printStack(Stack<T> &stack) {
    List<T> *list = (List<T>*) stack.data;

    for (Node<T> *node = list->head; node != nullptr; node = node->next)
        std::cout << node->data << " ";
    std::cout << std::endl;
}

template <class T>
void initStack(Stack<T> &stack) {
    List<T> *list = new List<T>;
    stack.data = list;
    
    if (list != nullptr)
        list->head = nullptr;
}

template <class T>
void closeStack(Stack<T> &stack) {
    List<T> *list = (List<T>*) stack.data;

    if (list != nullptr && list->head != nullptr) {
        Node<T> *node = list->head;
        Node<T> *temp = nullptr;

        while (node != nullptr) {
            temp = node->next;
            delete node;
            node = temp;
        }
    }

    delete list;
}

template <class T>
int sizeStack(Stack<T> &stack) {
    List<T> *list = (List<T>*) stack.data;
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
bool isEmpty(Stack<T> &stack) {
    List<T> *list = (List<T>*) stack.data;

    if (list != nullptr && list->head != nullptr)
        return true;
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
T& topStack(Stack<T> &stack) {
    List<T> *list = (List<T>*) stack.data;
    static T dummy;

    if (list != nullptr && list->head != nullptr)
        return list->head->data;
    return dummy;
}

template<class T>
void pushStack(Stack<T> &stack, const T &value) {
    List<T> *list = (List<T>*) stack.data;

    if (list == nullptr)
        return;
    
    Node<T> *node = makeNode(value);
    node->next = list->head;
    list->head = node;
} 

template <class T>
void popStack(Stack<T> &stack) {
    List<T> *list = (List<T>*) stack.data;

    if (list == nullptr || list->head == nullptr)
        return;

    Node<T> *node = list->head;
    list->head = list->head->next;
    delete node;
}

#endif // End of file StackCPP_T_Imp.h