#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_


typedef bool    Color;
#define RED     true
#define BLACK   false


struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;
    Color color;
};


// Initialize a Node from a given number.
Node* createNode(int data, Color color);

// Initialize a red-black tree from a given number.
Node* createTree(int data);

Node* search(Node* root, int key);

void insert(Node* &root, int key);

void remove(Node* &root, int key);

void removeTree(Node* &root);

void rotate(Node* &root);

#endif
