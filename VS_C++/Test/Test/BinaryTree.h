#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include "Node.h"
#include <iostream>

using namespace std;


// Declaration.

template <class T>
class BinaryTree {
private:
	Node<T>* tree;

public:
	BinaryTree();
	BinaryTree(const Node<T>*& tree);
	BinaryTree(const BinaryTree<T>& bTree);

	void add(const T& data);
	void add(const Node<T>* p);
	const Node<T>* insert(const T& data);
	const Node<T>* insert(const Node<T>* p);

	void remove(const T& data);
	void remove(const Node<T>* p);
	void removeAll();

	const Node<T>* find(const T& data) const;
	const Node<T>* find(const Node<T>* p) const;

	BinaryTree& operator=(const BinaryTree<T>& bTree);

	bool operator==(const BinaryTree<T>& bTree) const;
	bool operator!=(const BinaryTree<T>& bTree) const;

	~BinaryTree();
};



// Implementation.

template <class T>
BinaryTree<T>::BinaryTree() : tree(nullptr) {}

template <class T>
BinaryTree<T>::BinaryTree(const Node<T>*& tree) {
	this->tree = Node<T>::clone(tree);
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& bTree) {
	*this = bTree;
}

template <class T>
void BinaryTree<T>::add(const T& data) {
	Node<T>* temp = Node<T>::insert(this->tree, data);
}

template <class T>
void BinaryTree<T>::add(const Node<T>* p) {
	Node<T>* temp = Node<T>::insert(this->tree, p->data);
}

template <class T>
const Node<T>* BinaryTree<T>::insert(const T& data) {
	return Node<T>::insert(this->tree, data);
}

template <class T>
const Node<T>* BinaryTree<T>::insert(const Node<T>* p) {
	return Node<T>::insert(this->tree, p->data);
}

template <class T>
void BinaryTree<T>::remove(const T& data) {
	Node<T>::remove(this->tree, data);
}

template <class T>
void BinaryTree<T>::remove(const Node<T>* p) {
	Node<T>::remove(this->tree, p->data);
}

template <class T>
void BinaryTree<T>::removeAll() {
	Node<T>::removeAll(this->tree);
}

template <class T>
const Node<T>* BinaryTree<T>::find(const T& data) const {
	return this->tree->find(data);
}

template <class T>
const Node<T>* BinaryTree<T>::find(const Node<T>* p) const {
	if (p == nullptr)
		return nullptr;

	return this->find(p->data);
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& bTree) {
	this->tree = Node<T>::clone(bTree->tree);
}

template <class T>
bool BinaryTree<T>::operator==(const BinaryTree<T>& bTree) const {
	return (this == &bTree || Node<T>::isEqual(this->tree, bTree->tree));
}

template <class T>
bool BinaryTree<T>::operator!=(const BinaryTree<T>& bTree) const {
	return !(*this == bTree);
}

template <class T>
BinaryTree<T>::~BinaryTree() {
	this->removeAll();
}

#endif