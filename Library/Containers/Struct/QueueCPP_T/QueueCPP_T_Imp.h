// File: QueueCPP_T_Imp.h
// Implement functions in the file QueueCPP_T.h

#ifndef QUEUE_CPP_T_IMP_H_
#define QUEUE_CPP_T_IMP_H_

#include "QueueCPP_T.h"
#include <iostream>

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
void printQueue(Queue<T> &queue) {
    List<T> *list = (List<T>*) queue.data;
    
    for (Node<T> *node = list->head; node != nullptr; node = node->next)
        std::cout << node->data << " ";
    std::cout << std::endl;
}

template <class T>
void initQueue(Queue<T> &queue) {
    List<T> *list = new List<T>;
    queue.data = list;

    if (list != nullptr)
        list->head = list->tail = nullptr;
}

template <class T>
void closeQueue(Queue<T> &queue) {
    List<T> *list = (List<T>*) queue.data;
    
    if (list != nullptr) {
        Node<T> *node, *temp;
        node = list->head;

        while (node->next != nullptr) {
            temp = node->next;
            delete node;
            node = temp;
        }
    }

    delete list;
}

template <class T>
int sizeQueue(Queue<T> &queue) {
    List<T> *list = (List<T>*) queue.data;
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
bool isEmpty(Queue<T> &queue) {
    List<T> *list = (List<T>*) queue.data;

    if (list == nullptr || list->head == nullptr)
        return true;
    
    return false;
}

template <class T>
T& firstQueue(Queue<T> &queue) {
    List<T> *list = (List<T>*) queue.data;
    static T dummy; // Dùng để trả về khi queue rỗng,
                    // sử dụng biến tĩnh vì hàm trả về giá trị tham chiếu.

    if (list != nullptr && list->head != nullptr)
        return list->head->data;
    
    return dummy;
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
void pushQueue(Queue<T> &queue, const T &value) {
    List<T> *list = (List<T>*) queue.data;

    if (list == nullptr)
        return;
    
    Node<T> *node = makeNode(value);
    
    if (list->head == nullptr) {
        list->head = list->tail = node;
    } else { // head == tail not null
        list->tail->next = node;
        list->tail = list->tail->next;
    }
}

template <class T>
void popQueue(Queue<T> &queue) {
    List<T> *list = (List<T>*) queue.data;
    
    if (list == nullptr || list->head == nullptr)
        return;
    
    Node<T> *node = list->head;
    list->head = list->head->next;
    
    // Size of queue is 1.
    if (list->head == nullptr) 
        list->tail = nullptr;

    delete node;
}

#endif // End of file QueueCPP_T_Imp.h