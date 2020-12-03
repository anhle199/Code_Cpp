#include <iostream>
#include <cmath>

using namespace std;

typedef struct Node * Ref;
struct Node {
    int data;
    Node* next;
};

typedef struct Bin * RBin;
struct Bin {
    Ref head;
    Ref tail;

    Bin() {
        head = tail = nullptr;
    }
};

int findMax(Ref head) {
    int maxElement = INT_MIN;

    for (Ref p = head; p; p = p->next)
        if (p->data > maxElement)
            maxElement = p->data;

    return maxElement;
}

void addTail(Ref &head, Ref &tail, Ref &p) {
    if (head == nullptr)
        head = tail = p;
    else {
        tail->next = p;
        tail = p;
    }
}

void addTail(Ref &head, Ref &tail, Bin &bin) {
    addTail(head, tail, bin.head);
    tail = bin.tail;
}

void RadixSort(Ref &head, Ref &tail) {
    if (head == nullptr)
        return;

    int maxElement = findMax(head);
    int countDigit = (int)log10(maxElement) + 1;

    RBin bins = new Bin[10];
    int temp = 1;
    while (countDigit-- >= 0) {
        while (head) {
            int digit = (head->data / temp) % 10;

            Ref p = head;
            head = head->next;
            p->next = nullptr;
            addTail(bins[digit].head, bins[digit].tail, p);
        }

        tail = nullptr;
        for (int i = 0; i < 10; i++)
            if (bins[i].head) {
                addTail(head, tail, bins[i]);
                bins[i].head = nullptr;
                bins[i].tail = nullptr;
            }

        temp *= 10;
    }
}

Node* createNode(int value) {
    Node* p = new Node;
    p->data = value;
    p->next = nullptr;

    return p;
}

void createList(Ref &head, Ref &tail) {
    int n;
    cout << "Enter the number of element: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "Enter the value of element: ";
        cin >> x;

        Node* p = createNode(x);
        addTail(head, tail, p);
    }
}

void showList(Ref head) {
    for (Ref p = head; p; p = p->next)
        cout << p->data << " ";
    cout << endl;
}

void freeList(Ref &head, Ref &tail) {
    while (head) {
        Ref p = head;
        head = head->next;
        delete p;
    }

    head = nullptr;
    tail = nullptr;
}

int main() {
    Ref head = nullptr;
    Ref tail = nullptr;

    createList(head, tail);
    cout << "List before sorting: ";
    showList(head);

    RadixSort(head, tail);

    cout << "List after sorting: ";
    showList(head);

    freeList(head, tail);

    return 0;
}
