#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

struct DList {
    Node* head;
    Node* tail;
};

Node* makeNode(const int& data) {
    Node* nod = new Node;

    nod->data = data;
    nod->prev = nullptr;
    nod->next = nullptr;

    return nod;
}

void addFirst(DList &dList, const int& data) {
    Node* temp = makeNode(data);

    dList.head->prev = temp;
    temp->next = dList.head;
    dList.head = temp;
}

void addLast(DList &dList, const int& data) {
    Node* temp = makeNode(data);

    dList.tail->next = temp;
    temp->prev = dList.tail;
    dList.tail = temp;
}

void addMid(Node*& nod, const int& data) {
    Node* p = makeNode(data);
    Node* pPrev;

    pPrev = nod->prev;
    pPrev->next = p;
    p->next = nod;
}

void removeFirst(DList &dList) {
    Node* nod = dList.head->next;
    
    delete dList.head;
    dList.head = nod;
    dList.head->prev = nullptr;
}

void removeLast(DList &dList) {
    Node* nod = dList.tail->prev;
    
    delete dList.tail;
    dList.tail = nod;
    dList.tail->next = nullptr;
}

void removeMid(Node*& nod) {
    Node* temp = nod->prev;
    
    temp->next = nod->next;
    nod->next->prev = temp;
    delete nod;
}

void printDoubleLinkedList(DList &dList) {
    Node* nod = dList.head;

    while (nod != nullptr) {
        cout << nod->data << " ";
        nod = nod->next;
    }
}

void releaseDoubleLinkedList(DList &dList) {
    while (dList.head != nullptr) {
        Node* temp = dList.head;
        dList.head = dList.head->next;
        delete temp;
    }
}

int main() {
    int n, k, x, item;
    DList dList;
    Node* p;

    cin >> n >> item;

    dList.head = makeNode(item);
    dList.tail = dList.head;
    p = dList.head;

    for (int i = 1; i < n; i++) {
        cin >> item;
        addLast(dList, item);
    }

    cin >> k >> x;

    if (k == 0)
        addFirst(dList, x);
    else if (k == n)
        addLast(dList, x);
    else
        addMid(dList, x, k);

    printDoubleLinkedList(dList);
    releaseDoubleLinkedList(dList);

    return 0;
}