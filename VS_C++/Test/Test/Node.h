#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include <memory.h>
#include <iostream>

using namespace std;

// Declaration.

template <class T>
class Node {
public:
	T data;
	Node* left, * right;

	static bool isEqual(Node<T>* p1, Node<T>* p2);
	static Node<T>* clone(Node<T>* const tree, size_t& numberOfNodes);
	static void searchStandFor(Node<T>*& p1, Node<T>*& p2);
	static Node<T>* insert(Node<T>*& tree, const T& data);
	static void remove(Node<T>*& tree, const T& data, bool& removed);
	static void removeAll(Node<T>*& tree);
	static Node<T>* find(Node<T>* tree, const T& data);

public:
	Node();
	Node(const T& data, Node<T>* left = nullptr, Node<T>* right = nullptr);

	template <class T>
	friend class BinaryTree;

	template <class T>
	friend ostream& operator<<(ostream& outDev, const Node<T>* const p);
};



// Implementation.

template <class T>
Node<T>::Node() {
	memset((char*)data, 0, sizeof(T));
	left = right = nullptr;
}

template <class T>
Node<T>::Node(const T& data, Node<T>* left, Node<T>* right) {
	this->data = data;
	this->left = left;
	this->right = right;
}

template <class T>
bool check(Node<T>*& p1, Node<T>*& p2) {
	return !((p1 == nullptr && p2 != nullptr) || (p1 != nullptr && p2 == nullptr));
}

template <class T>
bool Node<T>::isEqual(Node<T>* p1, Node<T>* p2) {
	if (check(p1, p2))
		return false;

	if (p1 != nullptr && p2 != nullptr) {
		if (p1->data != p2->data)
			return false;


		bool checkLeft = check(p1->left, p2->left);
		bool checkRight = check(p1->right, p2->right);

		if (checkLeft || checkRight)
			return false;

		if (checkLeft == false && Node<T>::isEqual(p1->left, p2->left) == false)
			return false;
		if (checkRight == false && Node<T>::isEqual(p1->right, p2->right) == false)
			return false;
	}

	return true;
}

template <class T>
Node<T>* Node<T>::clone(Node<T>* const tree, size_t& numberOfNodes) {
	Node<T>* p = nullptr;

	if (tree) {
		p = new Node<T>(tree->data);
		++numberOfNodes;

		p->left = Node<T>::clone(tree->left, numberOfNodes);
		p->right = Node<T>::clone(tree->right, numberOfNodes);
	}

	return p;
}

template <class T>
void Node<T>::searchStandFor(Node<T>*& p1, Node<T>*& p2) {
	if (p2->left)
		Node<T>::searchStandFor(p1, p2->left);
	else {
		p1->data = p2->data;
		p1 = p2;
		p2 = p2->right;
	}
}

template <class T>
Node<T>* Node<T>::insert(Node<T>*& tree, const T& data) {
	if (tree) {
		if (tree->data == data)
			return nullptr;
		else if (tree->data > data)
			return Node<T>::insert(tree->left, data);
		else
			return Node<T>::insert(tree->right, data);
	}

	tree = new Node(data);

	// Not enough memory.
	if (tree == nullptr)
		return nullptr;

	return tree;
}

template <class T>
void Node<T>::remove(Node<T>*& tree, const T& data, bool& removed) {
	if (tree) {
		if (tree->data > data)
			Node<T>::remove(tree->left, data, removed);
		if (tree->data < data)
			Node<T>::remove(tree->right, data, removed);
		else {
			Node<T>* p = tree;

			if (tree->left == nullptr)
				tree = tree->right;
			else if (tree->right == nullptr)
				tree = tree->left;
			else
				Node<T>::searchStandFor(p, tree->right);

			delete p;
			removed = true;
		}
	}
}

template <class T>
void Node<T>::removeAll(Node<T>*& tree) {
	if (tree) {
		Node<T>::removeAll(tree->left);
		Node<T>::removeAll(tree->right);

		delete tree;
		tree = nullptr;
	}
}

template <class T>
Node<T>* Node<T>::find(Node<T>* tree, const T& data) {
	while (tree) {
		if (tree->data == data)
			return tree;
		else if (tree->data > data)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return nullptr;
}

template <class T>
ostream& operator<<(ostream& outDev, const Node<T>* const p) {
	if (p == nullptr)
		cout << "(null)";
	else
		cout << p->data;

	return outDev;
}

#endif
