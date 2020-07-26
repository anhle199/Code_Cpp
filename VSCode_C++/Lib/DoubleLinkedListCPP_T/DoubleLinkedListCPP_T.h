// File: DoubleLinkedListCPP_T.h
// Use C++ template.

#ifndef DOUBLE_LINKED_LIST_CPP_T_H_
#define DOUBLE_LINKED_LIST_CPP_T_H_

#pragma pack(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
struct Node {
    T data;
    Node<T> *next, *prev;

    Node();
};

template <class T>
struct DoubleList {
    Node<T> *head, *tail;

    DoubleList();
};

// - Sắp xếp tăng dần.
template <class T>
bool ascending(const T &a, const T &b);

// - Sắp xếp giảm dần.
template <class T>
bool descending(const T &a, const T &b);

// - So sánh mặc định (a == b).
// - Nếu không truyền kiểu so sánh khi tìm phần tử trong list.
template <class T>
bool defaultCompare(const T &a, const T &b);

// - Chuyển list<T> sang mảng kiểu vector<T>.
template <class T>
vector<T> toArray(DoubleList<T> &double_list);

// - Tính độ dài list.
template <class T>
int length(DoubleList<T> &double_list);

// - In các phần tử của list.
template <class T>
void printDoubleList(DoubleList<T> &double_list);

// - Kiểm tra list có rỗng không.
template <class T>
bool isEmpty(DoubleList<T> &double_list);

// - Sắp xếp lại list với thuật toán selection sort.
template <class T>
void sortDoubleList(DoubleList<T> &double_list, bool (*typeSort)(const T &, const T &) = ascending);

/*
 - Trả về con trỏ đến phần tử đầu list.
 - Nếu mảng rỗng thì trả về con trỏ null.
 */
template <class T>
Node<T> *begin(DoubleList<T> &double_list);

/*
 - Trả về con trỏ đến phần tử cuối list.
 - Nếu mảng rỗng thì trả về con trỏ null.
 */
template <class T>
Node<T> *end(DoubleList<T> &double_list);

/*
 - Tìm phần tử đầu tiên có giá trị value.
 - Nếu tìm thấy thì trả về 1 con trỏ đến phần tử đó.
 - Ngược lại trả về 1 con trỏ null.
 */
template <class T>
Node<T> *findValue(DoubleList<T> &double_list, const T &data, bool (*cmp)(const T &, const T &) = defaultCompare);

// - Trả về 1 con trỏ đến phần tử đầu tiên lớn nhất trong list.
// - Nếu mảng rỗng thì trả về con trỏ null.
template <class T>
Node<T> *maxElement(DoubleList<T> &double_list);

// - Trả về 1 con trỏ đến phần tử đầu tiên nhỏ nhất trong list.
// - Nếu mảng rỗng thì trả về con trỏ null.
template <class T>
Node<T> *minElement(DoubleList<T> &double_list);

// - Trả về số lượng phần tử có giá trị value.
template <class T>
int countValue(DoubleList<T> &double_list, const T &value);

// - Khởi tạo 1 phần tử của list.
template <class T>
Node<T> *makeNode(const T &data);

// - Chèn vào đầu list.
template <class T>
void insertAtFirst(DoubleList<T> &double_list, const T &data);

// - Chèn vào cuối list.
template <class T>
void insertAtLast(DoubleList<T> &double_list, const T &data);

// - Chèn vào trước p.
template <class T>
void insertBefore(Node<T> *&node, const T &data);

// - Chèn vào vị trí pos.
template <class T>
void insertAtPositon(DoubleList<T> &double_list, const int &pos, const T &data);

// - Xoá phần tử đầu list.
template <class T>
void removeFirst(DoubleList<T> &double_list);

// - Xoá phần tử cuối list.
template <class T>
void removeLast(DoubleList<T> &double_list);

// - Xóa phần tử node.
template <class T>
void removeMid(Node<T> *&node);

// - Xóa phần tử ở vị trí pos.
template <class T>
void removeAt(DoubleList<T> &double_list, const int &pos);

// - Xóa toàn bộ list ra khỏi heap.
template <class T>
void deleteDoubleList(DoubleList<T> &double_list);

/* 
 * ------------------------------------------------------------------------
 * Cài đặt hàm
 * ------------------------------------------------------------------------
 */

template <class T>
bool ascending(const T &a, const T &b) {
    return (a > b);
}

template <class T>
bool descending(const T &a, const T &b) {
    return (a < b);
}

template <class T>
bool defaultCompare(const T &a, const T &b) {
    return (a == b);
}

template <class T>
Node<T>::Node() {
    next = prev = nullptr;
}

template <class T>
DoubleList<T>::DoubleList() {
    head = tail = nullptr;
}

template <class T>
vector<T> toArray(DoubleList<T> &double_list) {
    Node<T> *temp = double_list.head;
    int n = length(double_list);
    vector<T> arr(n);

    for (T &element : arr) {
        element = temp->data;
        temp = temp->next;
    }

    return arr;
}

template <class T>
int length(DoubleList<T> &double_list) {
    int len = 0;

    for (Node<T> *node = double_list.head; node != nullptr; node = node->next)
        len++;

    return len;
}

template <class T>
void printDoubleList(DoubleList<T> &double_list) {
    for (Node<T> *node = double_list.head; node != nullptr; node = node->next)
        cout << node->data << " ";
    cout << endl;
}

template <class T>
bool isEmpty(DoubleList<T> &double_list) {
    if (double_list.head == nullptr)
        return true;
    return false;
}

template <class T>
void sortDoubleList(DoubleList<T> &double_list, bool (*typeSort)(const T &, const T &)) {
    Node<T> *temp;

    for (Node<T> *p = double_list.head; p != double_list.tail; p = p->next)
    {
        temp = p;

        for (Node<T> *r = p; r != nullptr; r = r->next)

            if (typeSort(temp->data, r->data))
                temp = r;

        swap(p->data, temp->data);
    }
}

template <class T>
Node<T> *front(DoubleList<T> &double_list) {
    if (double_list.head == nullptr)
        cout << "List is empty." << endl;

    return double_list.head;
}

template <class T>
Node<T> *back(DoubleList<T> &double_list) {
    if (double_list.tail == nullptr)
        cout << "List is empty." << endl;

    return double_list.tail;
}

template <class T>
Node<T> *findValue(DoubleList<T> &double_list, const T &data, bool (*cmp)(const T &, const T &)) {
    Node<T> *node = double_list.head;

    while (node) {
        if (cmp(node->data, data))
            break; // Tìm thấy thì dừng lại.

        node = node->next;
    }

    return node;
}

template <class T>
Node<T> *maxElement(DoubleList<T> &double_list) {
    Node<T> *node = double_list.head;
    Node<T> *result = nullptr;
    T max_value = node->data, value, dummy;

    if (double_list.head == nullptr)
        cout << "List is empty." << endl;

    node = node->next;
    while (node) {
        value = node->data;

        if (value > max_value) {
            max_value = value;
            result = node;
        }

        node = node->next;
    }

    return result;
}

template <class T>
Node<T> *minElement(DoubleList<T> &double_list) {
    Node<T> *node = double_list.head;
    Node<T> *result = nullptr;
    T min_value = node->data, value, dummy;

    if (double_list.head == nullptr)
        cout << "List is empty." << endl;

    node = node->next;
    while (node) {
        value = node->data;

        if (value < min_value) {
            min_value = value;
            result = node;
        }

        node = node->next;
    }

    return result;
}

template <class T>
int countValue(DoubleList<T> &double_list, const T &value) {
    int count = 0;

    while (double_list.head)
        if (double_list.head->data == value)
            count++;

    return count;
}

template <class T>
Node<T> *makeNode(const T &data) {
    Node<T> *node = new Node<T>;

    if (node == nullptr)
        cout << "Not enough memory." << endl;
    else {
        node->data = data;
        node->next = node->prev = nullptr;
    }

    return node;
}

template <class T>
void insertAtFirst(DoubleList<T> &double_list, const T &data) {
    Node<T> *node = makeNode(data);

    if (double_list.head == nullptr)
        double_list.head = double_list.tail = node;
    else {
        node->next = double_list.head;
        double_list.head->prev = node;
        double_list.head = node;
    }
}

template <class T>
void insertAtLast(DoubleList<T> &double_list, const T &data) {
    Node<T> *node = makeNode(data);

    if (double_list.head == nullptr)
        double_list.head = double_list.tail = node;
    else {
        double_list.tail->next = node;
        node->prev = double_list.tail;
        double_list.tail = node;
    }
}

template <class T>
void insertBefore(Node<T> *&node, const T &data) {
    Node<T> *temp = makeNode(data);
    Node<T> *p_node = node->prev;

    if (temp == nullptr) {
        cout << "Not enough memory." << endl;
        return;
    }

    // Link p_node and temp.
    p_node->next = temp;
    temp->prev = p_node;

    // Link temp and node.
    temp->next = node;
    node->prev = temp;
}

template <class T>
void insertAt(DoubleList<T> &double_list, const int &pos, const T &data) {
    int n = length(double_list.head);

    if (pos < 0 || pos > n) {
        cout << "Position is not valid." << endl;
        return;
    } else if (pos == 0) {
        insertAtFirst(double_list, data);
    } else if (pos == n) {
        insertAtLast(double_list, data);
    } else { // 0 < pos < n
        Node<T> *p = double_list.head;

        for (int i = 0; i < pos; i++, p = p->next);

        insertBefore(p, data);
    }
}

template <class T>
void removeFirst(DoubleList<T> &double_list) {
    Node<T> *p;

    if (double_list.head == nullptr) {
        return;
    } else if (double_list.head == double_list.tail) {
        delete double_list.head;
        double_list.head = double_list.tail = nullptr;
    } else {
        p = double_list.head;
        double_list.head = double_list.head->next;
        delete p;
        
        double_list.head->prev = nullptr;
    }
}

template <class T>
void removeLast(DoubleList<T> &double_list) {
    Node<T> *p;

    if (double_list.head == nullptr) {
        return;
    } else if (double_list.head == double_list.tail) {
        delete double_list.head;
        double_list.head = double_list.tail = nullptr;
    } else {
        p = double_list.tail->prev;
        delete double_list.tail;

        double_list.tail = p;
        p->next = nullptr;
    }
}

template <class T>
void removeMid(Node<T> *&node) {
    Node<T> *p_node = node->prev;
    Node<T> *n_node = node->next;

    p_node->next = n_node;
    n_node->prev = p_node;
    delete node;
}

template <class T>
void removeAt(DoubleList<T> &double_list, const int &pos) {
    int n = length(double_list.head);

    if (pos < 0 || pos >= n) {
        cout << "Position is not valid." << endl;
        return;
    } else if (pos == 0) {
        removeFirst(double_list);
    } else if (pos == n - 1) {
        removeLast(double_list);
    } else { // 0 < pos < n - 1
        Node<T> *p = double_list.head;

        for (int i = 0; i <= pos; i++, p = p->next);

        removeMid(p);
    }
}

template <class T>
void deleteDoubleList(DoubleList<T> &double_list) {
    Node<T> *node;

    while (double_list.head != nullptr)
    {
        node = double_list.head;
        double_list.head = double_list.head->next;
        delete node;
    }
}

#endif // End of file DoubleLinkedListCPP_T.h