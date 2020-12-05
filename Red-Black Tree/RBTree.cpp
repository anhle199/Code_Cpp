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

Node* BSTInsert(Node* &root, int key) {
    if (root == nullptr) {
        root = createNode(key, RED);
        return root;
    }

    if (root->key == key)
        return nullptr;
    if (root->key > key) 
        return BSTInsert(root->left, key);
    return BSTInsert(root->right, key);
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
    Node* p = BSTInsert(root, key);
    fixViolation(root, p);
}

Node* successor(Node* p) {
    while (p->left)
        p = p->left;

    return p;
}

Node* findNodeToReplace(Node* node) {
    if (node == nullptr)
        return nullptr;
    
    if (node->left == nullptr) // at most 1 child.
        return node->right;
    if (node->right == nullptr) // at most 1 child.
        return node->left;
    return successor(node->right); // 2 children.
}

bool isOnLeft(Node* p) {
    return (p && p->parent && p->parent->left == p);
}

Node* getSibling(Node* p) {
    if (p == nullptr)
        return nullptr;

    if (isOnLeft(p))
        return p->parent->right;
    return p->parent->left;
}

bool hasRedChild(Node* p) {
    if (p == nullptr)
        return false;    
    return (p->left && p->left->color == RED) || 
            (p->right && p->right->color == RED);
}

void fixDoubleBlack(Node* &root, Node* p) {
    if (p == root)
        return;

    Node* sibling = getSibling(p);
    Node* parent = p->parent;

    if (sibling == nullptr)
        fixDoubleBlack(root, parent);
    else {
        if (sibling->color == RED) {
            swap(parent->color, sibling->color);

            if (isOnLeft(sibling)) {    
                rotateRight(root, parent);
                sibling = parent->left;
            } else {
                rotateLeft(root, parent);
                sibling = parent->right;
            }

            fixDoubleBlack(root, p);
        } else {
            // at least 1 red children.
            if (hasRedChild(sibling)) {
                if (sibling->left && sibling->left->color == RED) {
                    if (isOnLeft(sibling)) { // left left.
                        rotateRight(root, parent);
                        swap(sibling->color, sibling->left->color);
                    } else { // right left.
                        rotateRight(root, sibling);
                        sibling = parent->right;
                        rotateLeft(root, parent);
                    }
                }
            } else { // 2 black children.

            }
        }
    }

    root->color = BLACK;
}

void removeImp(Node* &root, Node* v) {
    Node* u = findNodeToReplace(v);

    bool isBothBlack = ((u == nullptr || u->color == BLACK) && v->color == BLACK);
    Node* parent = v->parent;

    // v is leaf.
    if (u == nullptr) {
        if (root == v)
            root = nullptr;
        else {
            if (v->color == BLACK) // u and v both black.
                fixDoubleBlack(root, v);
            

            // delete v from the tree.
            if (isOnLeft(v)) 
                parent->left = nullptr;
            else 
                parent->right = nullptr;
        }

        delete v;
        return;
    }

    // v has only 1 child.
    if (v->left == nullptr || v->right == nullptr) {
        if (root == v) {
            swap(v->key, u->key);
            v->left = v->right = nullptr;
            delete u;
        } else {
            if (isOnLeft(v)) 
                parent->left = u;
            else 
                parent->right = u;

            delete v;
            u->parent = parent;

            if (isBothBlack)
                fixDoubleBlack(root, u);
            else
                u->color = BLACK;
        }

        return;
    }

    // node have two children.
    swap(v->key, u->key);
    removeImp(root, u);
}

void remove(Node* &root, int key) {
    Node* nodeToDelete = search(root, key);
    removeImp(root, nodeToDelete);
}

void removeTree(Node* &root) {
    if (root) {
        removeTree(root->left);
        removeTree(root->right);
        delete root;
        root = nullptr;
    }
}