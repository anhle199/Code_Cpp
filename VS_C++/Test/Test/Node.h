#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include "Node.h"


// Declaration.

template <class T>
class BinarySearchTree {
private:
	Node<T>* tree;
	size_t numberOfNodes;

public:
	BinarySearchTree();
	BinarySearchTree(const Node<T>*& tree);
	BinarySearchTree(const BinarySearchTree<T>& bTree);

	size_t size() const;
	bool empty() const;

	void add(const T& data);
	void add(const Node<T>* p);
	Node<T>* insert(const T& data);
	Node<T>* insert(const Node<T>* p);

	void remove(const T& data);
	void remove(const Node<T>* p);
	void removeAll();

	Node<T>* find(const T& data) const;
	Node<T>* find(const Node<T>* p) const;

	BinarySearchTree& operator=(const BinarySearchTree<T>& bTree);

	bool operator==(const BinarySearchTree<T>& bTree) const;
	bool operator!=(const BinarySearchTree<T>& bTree) const;

	~BinarySearchTree();
};



// Implementation.

template <class T>
BinarySearchTree<T>::BinarySearchTree() : tree(nullptr), numberOfNodes(0) {}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const Node<T>*& tree) {
	this->numberOfNodes = 0;
	this->tree = Node<T>::clone(tree, this->numberOfNodes);
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& bTree) {
	*this = bTree;
}

template <class T>
size_t BinarySearchTree<T>::size() const {
	return numberOfNodes;
}

template <class T>
bool BinarySearchTree<T>::empty() const {
	return (this->tree == nullptr);
}

template <class T>
void BinarySearchTree<T>::add(const T& data) {
	Node<T>* temp = this->insert(data);
}

template <class T>
void BinarySearchTree<T>::add(const Node<T>* p) {
	Node<T>* temp = this->insert(p->data);
}

template <class T>
Node<T>* BinarySearchTree<T>::insert(const T& data) {
	Node<T>* p = Node<T>::insert(this->tree, data);

	if (p)
		++this->numberOfNodes;

	return p;
}

template <class T>
Node<T>* BinarySearchTree<T>::insert(const Node<T>* p) {
	return this->insert(p->data);
}

template <class T>
void BinarySearchTree<T>::remove(const T& data) {
	bool removed = false;

	Node<T>::remove(this->tree, data, removed);

	if (removed)
		--this->numberOfNodes;
}

template <class T>
void BinarySearchTree<T>::remove(const Node<T>* p) {
	this->remove(this->tree, p->data);
}

template <class T>
void BinarySearchTree<T>::removeAll() {
	Node<T>::removeAll(this->tree);
	this->numberOfNodes = 0;
}

template <class T>
Node<T>* BinarySearchTree<T>::find(const T& data) const {
	return Node<T>::find(this->tree, data);
}

template <class T>
Node<T>* BinarySearchTree<T>::find(const Node<T>* p) const {
	if (p == nullptr)
		return nullptr;

	return Node<T>::find(this->tree, p->data);
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& bTree) {
	this->numberOfNodes = 0;
	this->tree = Node<T>::clone(bTree.tree, this->numberOfNodes);

	return *this;
}

template <class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree<T>& bTree) const {
	return (this == &bTree || Node<T>::isEqual(this->tree, bTree.tree));
}

template <class T>
bool BinarySearchTree<T>::operator!=(const BinarySearchTree<T>& bTree) const {
	return !(*this == bTree);
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
	this->removeAll();
}

#endif
