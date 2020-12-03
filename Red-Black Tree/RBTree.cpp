#include "RBTree.h"

template <class T>
void swap(const T &a, const T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Initialize a Node from a given number.
Node* createNode(int data, Color color) {
    Node* node = new Node;

    if (node) {
        node->key = data;
        node->parent = node->left = node->right = nullptr;
        node->color = color;
    }

    return node;
}

// Initialize a red-black tree from a given number.
Node* createTree(int data) {
    return createNode(data, BLACK);
}

Node* search(Node* root, int key) {
    while (root) {
        if (root->key == key)
            return root;
        if (root->key > key)
            root = root->left;
        else
            root = root->right;
    }

    return nullptr;
}

Node* insertImp(Node* &root, int key) {
    if (root == nullptr) {
        root = createNode(key, RED);
        return root;
    }

    if (root->key == key)
        return nullptr;
    if (root->key > key) 
        return insertImp(root->left, key);
    return insertImp(root->right, key);
}

void rotateLeft(Node* &root, Node* &p) {
    Node* right = p->right;
    
    p->right = right->left;
    if (p->right != nullptr)
        p->right->parent = p;

    right->parent = p->parent;
    if (p->parent == nullptr)
        root = right;
    else if (p->parent->left == p)
        p->parent->left = right;
    else 
        p->parent->right = right;
    
    right->left = p;
    p->parent = right;
}

void rotateRight(Node* &root, Node* &p) {
    Node* left = p->left;
    
    p->left = left->right;
    if (p->left != nullptr)
        p->left->parent = p;

    left->parent = p->parent;
    if (p->parent == nullptr)
        root = left;
    else if (p->parent->right == p)
        p->parent->right = left;
    else 
        p->parent->left = left;
    
    left->right = p;
    p->parent = left;
}

void fixViolation(Node* &root, Node* &p) {
    if (root && p) {
        Node* parent = nullptr;
        Node* grandParent = nullptr;

        while (p != root && p->color != BLACK && p->parent->color == RED) {
            parent = p->parent;
            grandParent = parent->parent;
            
            if (grandParent) {
                Node* uncle = nullptr;

                if (grandParent->left == parent) {
                    uncle = grandParent->right;

                    if (uncle && uncle->color == RED) {
                        uncle->color = parent->color = BLACK;
                        grandParent->color = RED;
                        p = grandParent;
                    } else {
                        if (p == parent->right) {
                            rotateLeft(root, parent);
                            p = parent;
                            parent = p->parent;
                        }

                        rotateRight(root, grandParent);
                        swap(parent->color, grandParent->color);
                        p = parent;
                    }
                } else {
                    uncle = grandParent->left;

                    if (uncle && uncle->color == RED) {
                        uncle->color = parent->color = BLACK;
                        grandParent->color = RED;
                        p = grandParent;
                    } else {
                        if (p == parent->left) {
                            rotateRight(root, parent);
                            p = parent;
                            parent = p->parent;
                        }

                        rotateLeft(root, grandParent);
                        swap(parent->color, grandParent->color);
                        p = parent;
                    }
                }
            }
        }

        root->color = BLACK;    
    }
}

// Reference:
// 1. https://www.geeksforgeeks.org/red-black-tree-set-2-insert/?ref=lbp
// 2. https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/ 
void insert(Node* &root, int key) {
    Node* p = insertImp(root, key);
    fixViolation(root, p);
}

void remove(Node* &root, int key) {

}

void removeTree(Node* &root) {
    if (root) {
        removeTree(root->left);
        removeTree(root->right);
        delete root;
        root = nullptr;
    }
}