#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* next;
};
typedef Node* Ref;

struct Bin {
    int key;
    Ref head;
    Ref tail;
    Bin* next;

    Bin() {
        key = -1;
        head = tail = nullptr;
        next = nullptr;
    }
};
typedef Bin* RBin;

int findMaxDigits(Ref head) {
    int maxElement = INT_MIN;

    for (Ref p = head; p; p = p->next)
        if (p->data > maxElement)
            maxElement = p->data;

    return (int)log10(maxElement) + 1;
}

void addTail(Ref &head, Ref &tail, Ref &p) {
    if (head == nullptr)
        head = tail = p;
    else {
        tail->next = p;
        tail = p;
    }
}

RBin createBin(int key) {
    RBin bin = new Bin;
    bin->key = key;
    bin->head = bin->tail = nullptr;
    bin->next = nullptr;

    return bin;
}

void add(RBin &bins, Ref &p, int key) {
    RBin q1 = bins;
    RBin q2 = bins->next;

    while (q2 && q2->key < key) {
        q1 = q2;
        q2 = q2->next;
    }

    if (q2 == nullptr) {
        q1->next = createBin(key);
        q1->next->head = q1->next->tail = p;
    } else if (q2->key == key) {
        q2->tail->next = p;
        q2->tail = p;
    } else {
        q1->next = createBin(key);
        q1->next->head = q1->next->tail = p;
        q1->next->next = q2;
    }
}

void RadixSort(Ref &head, Ref &tail, int t) {
    if (head == nullptr)
        return;

    int countDigit = findMaxDigits(head);
    RBin bins = createBin(-1);
    int temp1 = 1;
    int temp2 = pow(10, t);
    int n = (countDigit + t - 1) / t;

    while (n-- >= 0) {
        // Distribution.
        while (head) {
            Ref p = head;
            head = head->next;
            p->next = nullptr;

            int key = (p->data / temp1) % temp2;
            add(bins, p, key);
        }

        tail = nullptr;

        // Combination.
        RBin p = bins->next;
        while (p) {
            if (head)
                tail->next = p->head;
            else
                head = p->head;

            tail = p->tail;

            RBin temp = p;
            p = p->next;
            delete temp;
        }

        bins->next = nullptr;
        temp1 *= temp2;
    }

    delete bins;
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

    cout << "Random: ";
    for (int i = 0; i < n; i++) {
        int x = rand() % 1000;
        cout << x << " ";

        Node* p = createNode(x);
        addTail(head, tail, p);
    }
    cout << endl;
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
    srand((int) time(nullptr));
    Ref head = nullptr;
    Ref tail = nullptr;

    createList(head, tail);
    cout << "List before sorting: ";
    showList(head);

    int t;
    cout << "Enter the number of digits to separated: ";
    cin >> t;
    RadixSort(head, tail, t);

    cout << "List after sorting: ";
    showList(head);

    freeList(head, tail);

    return 0;
}
