// - Không dùng cho các kiểu dữ liệu có cấp phát động ở thành phần data của Node
// - Tập tin singleLinkedList.h
#ifndef SINGLE_LINKED_LIST_CPP_T_H_
#define SINGLE_LINKED_LIST_CPP_T_H_

#pragma pack(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;

    Node();
};

template <class T>
struct List
{
    Node<T> *head, *tail;

    List();
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
vector<T> toArray(List<T> &list);

// - Tính độ dài list.
template <class T>
int length(List<T> &list);

// - In các phần tử của list.
template <class T>
void printList(List<T> &list);

// - Kiểm tra list có rỗng không.
template <class T>
bool isEmpty(List<T> &list);

// - Sắp xếp lại list với thuật toán selection sort.
template <class T>
void sortList(List<T> &list, bool (*typeSort)(const T &, const T &) = ascending);

/*
 - Trả về con trỏ đến phần tử đầu list.
 - Nếu mảng rỗng thì trả về con trỏ null.
 */
template <class T>
Node<T> *begin(List<T> &list);

/*
 - Trả về con trỏ đến phần tử cuối list.
 - Nếu mảng rỗng thì trả về con trỏ null.
 */
template <class T>
Node<T> *end(List<T> &list);

/*
 - Tìm phần tử đầu tiên có giá trị value.
 - Nếu tìm thấy thì trả về 1 con trỏ đến phần tử đó.
 - Ngược lại trả về 1 con trỏ null.
 */
template <class T>
Node<T> *findValue(List<T> &list, const T &data, bool (*cmp)(const T &, const T &) = defaultCompare);

// - Trả về 1 con trỏ đến phần tử đầu tiên lớn nhất trong list.
// - Nếu mảng rỗng thì trả về con trỏ null.
template <class T>
Node<T> *maxElement(List<T> &list);

// - Trả về 1 con trỏ đến phần tử đầu tiên nhỏ nhất trong list.
// - Nếu mảng rỗng thì trả về con trỏ null.
template <class T>
Node<T> *minElement(List<T> &list);

// - Trả về số lượng phần tử có giá trị value.
template <class T>
int countValue(List<T> &list, const T &value);

// - Khởi tạo 1 phần tử của list.
template <class T>
Node<T> *makeNode(const T &data);

// - Chèn vào đầu list.
template <class T>
void insertAtFirst(List<T> &list, const T &data);

// - Chèn vào cuối list.
template <class T>
void insertAtLast(List<T> &list, const T &data);

// - Chèn vào trước p.
template <class T>
void insertBefore(Node<T> *&node, const T &data);

// - Chèn vào vị trí pos.
template <class T>
void insertAt(List<T> &list, const int &pos, const T &data);

// - Xoá phần tử đầu list.
template <class T>
void removeFirst(List<T> &list);

// - Xoá phần tử cuối list.
template <class T>
void removeLast(List<T> &list);

// - Xóa phần tử node.
template <class T>
void removeMid(Node<T> *&node);

// - Xóa phần tử ở vị trí pos.
template <class T>
void removeAt(List<T> &list, const int &pos);

// - Xóa toàn bộ list ra khỏi heap.
template <class T>
void deleteList(List<T> &list);

/* 
 * ------------------------------------------------------------------------
 * Cài đặt hàm
 * ------------------------------------------------------------------------
 */

template <class T>
bool ascending(const T &a, const T &b)
{
    return (a > b);
}

template <class T>
bool descending(const T &a, const T &b)
{
    return (a < b);
}

template <class T>
bool defaultCompare(const T &a, const T &b)
{
    return (a == b);
}

template <class T>
Node<T>::Node()
{
    next = nullptr;
}

template <class T>
List<T>::List()
{
    head = tail = nullptr;
}

template <class T>
vector<T> toArray(List<T> &list)
{
    Node<T> *temp = list.head;
    int n = length(list);
    vector<T> arr(n);

    for (T &element : arr)
    {
        element = temp->data;
        temp = temp->next;
    }

    return arr;
}

template <class T>
int length(List<T> &list)
{
    int len = 0;

    for (Node<T> *node = list.head; node != nullptr; node = node->next)
        len++;

    return len;
}

template <class T>
void printList(List<T> &list)
{
    for (Node<T> *node = list.head; node != nullptr; node = node->next)
        cout << node->data << " ";
    cout << endl;
}

template <class T>
bool isEmpty(List<T> &list)
{
    if (list.head == nullptr)
        return true;
    return false;
}

template <class T>
void sortList(List<T> &list, bool (*typeSort)(const T &, const T &) = ascending)
{
    Node<T> *temp;

    for (Node<T> *p = list.head; p != list.tail; p = p->next)
    {
        temp = p;

        for (Node<T> *r = p; r != nullptr; r = r->next)

            if (typeSort(temp->data, r->data))
                temp = r;

        swap(p->data, temp->data);
    }
}

template <class T>
Node<T> *front(List<T> &list)
{
    if (list.head == nullptr)
        cout << "List is empty." << endl;

    return list.head;
}

template <class T>
Node<T> *back(List<T> &list)
{
    if (list.tail == nullptr)
        cout << "List is empty." << endl;

    return list.tail;
}

template <class T>
Node<T> *findValue(List<T> &list, const T &data, bool (*cmp)(const T &, const T &))
{
    Node<T> *node = list.head;

    while (node)
    {
        if (cmp(node->data, data))
            break; // Tìm thấy thì dừng lại.

        node = node->next;
    }

    return node;
}

template <class T>
Node<T> *maxElement(List<T> &list)
{
    Node<T> *node = list.head;
    Node<T> *result = nullptr;
    T max_value = node->data, value, dummy;

    if (list.head == nullptr)
        cout << "List is empty." << endl;

    node = node->next;
    while (node)
    {
        value = node->data;

        if (value > max_value)
        {
            max_value = value;
            result = node;
        }

        node = node->next;
    }

    return result;
}

template <class T>
Node<T> *minElement(List<T> &list)
{
    Node<T> *node = list.head;
    Node<T> *result = nullptr;
    T min_value = node->data, value, dummy;

    if (list.head == nullptr)
        cout << "List is empty." << endl;

    node = node->next;
    while (node)
    {
        value = node->data;

        if (value < min_value)
        {
            min_value = value;
            result = node;
        }

        node = node->next;
    }

    return result;
}

template <class T>
int countValue(List<T> &list, const T &value)
{
    int count = 0;

    while (list.head)
        if (list.head->data == value)
            count++;

    return count;
}

template <class T>
Node<T> *makeNode(const T &data)
{
    Node<T> *p = new Node<T>;

    if (p == nullptr)
        cout << "Not enough memory." << endl;
    else
    {
        p->data = data;
        p->next = nullptr;
    }

    return p;
}

template <class T>
void insertAtFirst(List<T> &list, const T &data)
{
    Node<T> *p = makeNode(data);

    if (list.head == nullptr)
        list.head = list.tail = p;
    else
    {
        p->next = list.head;
        list.head = p;
    }
}

template <class T>
void insertAtLast(List<T> &list, const T &data)
{
    Node<T> *node = makeNode(data);

    if (list.head == nullptr)
        list.head = list.tail = node;
    else
    {
        list.tail->next = node;
        list.tail = node;
    }
}

template <class T>
void insertBefore(Node<T> *&node, const T &data)
{
    Node<T> *temp = new Node<T>;

    if (temp == nullptr)
    {
        cout << "Not enough memory." << endl;
        return;
    }

    *temp = *node; // copy giá trị của q sang p;
    node->next = temp;
    node->data = data;
}

template <class T>
void insertAt(List<T> &list, const int &pos, const T &data)
{
    int n = length(list.head);

    if (pos < 0 || pos > n)
    {
        cout << "Position is not valid." << endl;
        return;
    }
    else if (pos == 0)
        insertAtFirst(list, data);
    else if (pos == n)
        insertAtLast(list, data);
    else
    { // 0 < pos < n
        Node<T> *p = list.head;

        for (int i = 0; i < pos; i++, p = p->next);

        insertBefore(p, data);

        // Nếu trường hợp pos = n - 1 thì phần tử cuối bị dời ra 1 vị trí làm cho tail = p (vị trí n - 2 sau khi chèn);
        if (list.tail->next != nullptr)
            list.tail = list.tail->next;
    }
}

template <class T>
void removeFirst(List<T> &list)
{
    Node<T> *p;

    if (list.head == list.tail)
    {
        delete list.head;
        list.head = list.tail = nullptr;
    }
    else
    {
        p = list.head;
        list.head = list.head->next;
        delete p;
    }
}

template <class T>
void removeLast(List<T> &list)
{
    Node<T> *p;

    if (list.head == list.tail)
    {
        delete list.head;
        list.head = list.tail = nullptr;
    }
    else
    {
        for (p = list.head; p->next != list.tail; p = p->next);
        
        delete list.tail;
        list.tail = p;
        p->next = nullptr;
    }
}

template <class T>
void removeMid(Node<T> *&node)
{
    Node<T> *temp;

    temp = node->next;
    *node = *temp;
    delete temp;
}

template <class T>
void removeAt(List<T> &list, const int &pos)
{
    int n = length(list.head);

    if (pos < 0 || pos >= n)
    {
        cout << "Position is not valid." << endl;
        return;
    }
    else if (pos == 0)
        removeFirst(list);
    else if (pos == n - 1)
        removeLast(list);
    else
    { // 0 < pos < n - 1
        Node<T> *p = list.head;

        for (int i = 0; i <= pos; i++, p = p->next)
            ;

        // Trường hợp xóa phần tử ở kế cuối của list thì biến tail sẽ chưa cập nhật lại được vị trí hợp lệ.
        // Vì sau khi xóa sẽ dời phần tử phía sau p lên ngay p.
        if (p->next == list.tail)
            list.tail = p;

        removeMid(p);
    }
}

template <class T>
void deleteList(List<T> &list)
{
    Node<T> *node;

    while (list.head != nullptr)
    {
        node = list.head;
        list.head = list.head->next;
        delete node;
    }
}

#endif // - Kết thúc tập tin singleLinkedList.h