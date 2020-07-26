struct Node {
    int data;
    Node* next;
};

Node* makeNode(const int &data) {
    Node *nod = new Node;
    
    nod->data = data;
    nod->next = nullptr;
    
    return nod;
}

Node* getNode(Node*& head, const int& k) {
    Node* p = head;

    for (int i = 0; i < k; i++)
        p = p->next;
    
    return p;
}

void addNode(Node *&nod, const int &data) {
    Node *p = makeNode(data);
    nod->next = p;
    nod = p;
}

void insertFirst(Node *&head, const int &data) {
    Node *nod = makeNode(data);

    if (head == nullptr) {
        head = nod;
    } else {
        nod->next = head;
        head = nod;
    }
}

void insertLast(Node *&tail, const int &data) {
    Node *nod = makeNode(data);

    if (tail == nullptr) {
        tail = nod;
    } else {
        tail->next = nod;
        tail = nod;
    }
}

void insertBefore(Node *&nod, const int &data) {
    Node* temp = nod->next;
    Node *p = makeNode(data);

    p->next = temp;
    nod->next = p;
}

void insert(Node*& head, const int& pos, const int& data) {
    Node* temp = makeNode(data);
    Node* p;

    if (pos == 0) {
        temp->next = head;
        head = temp;
    }

    p = head;
    for (int i = 0; i < pos; i++, p = p->next);

    *temp = *p;
    p->next = temp;
    p->data = data;
}

void removeFirst(Node*& head) {
    Node* temp = head->next;
    delete head;
    head = temp;
}

void removeLast(Node*& head) {
    Node* p = head;
    Node* temp;

    while (p->next->next != nullptr)
        p = p->next;

    temp = p->next;
    delete temp;
    p->next = nullptr;
}

void removeMid(Node*& nod) {
    Node* temp = nod->next;
    
    *nod = *temp;
    delete temp;
}

void printList(Node *&head) {
    Node *p = head;

    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
}

void releaseList(Node *&head) {
    Node *p;

    while (head != nullptr) {
        p = head;
        head = head->next;
        delete p;
    }
}



int main() {
    int n;
    Node* head, *p;

    cin >> n >> item;
    head = makeNode(item);
    p = head;

    for (int i = 1; i < n; i++) {
        cin >> item;
        addNode(p, item);
    }

    printList(head);
    releaseList(head);

    return 0;
}