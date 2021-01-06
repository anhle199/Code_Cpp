#ifndef _LIST_H_
#define _LIST_H_

#include "Container.h"
#include "Node.h"

// ------------------------------------------------------
// Declaration.

template <class T>
class List : public Container<T> {
private:
	T dummy;
	Node<T>* head, * tail;

	Node<T>* getNode(const int& pos);
	Node<T>* insertBefore(Node<T>*& p, const T& val);
	Node<T>* removeMid(Node<T>*& p);
public:
	List();
	List(const int& n, const T& val);
	List(const List<T>& lst);

	// operator=

	void resize(int newSize, const T& val);
	int count(const T& val, bool (*cmp)(const T&, const T&) = Container<T>::equal) const;

	T& front();
	T& back();
	const T& front() const;
	const T& back() const;

	void pushFront(const T& val);
	void pushBack(const T& val);
	void popFront();
	void popBack();
	Node<T>* insert(const T& val, const int& pos);

	Node<T>* erase(const int& pos);
	void remove(const T& val);

	void swap(List<T> &lst);
	// unique
	// merge list
	void reverse();

	void clear();
	~List();
};

// End of class List declaration.
// ------------------------------------------------------



// ------------------------------------------------------
// Implementation

template <class T>
List<T>::List() {
	this->numOfElements = 0;
	head = nullptr;
	tail = nullptr;
}

template <class T>
List<T>::List(const int& n, const T& val) {
	List<T>::List();
	this->resize(n, val);
}

template <class T>
List<T>::List(const List<T>& lst) {
	List<T>::List();

	for (Node<T>* p = lst.head; p; p = p->nextNode())
		pushBack(p->getData());

	this->numOfElements = lst.size();
}

template <class T>
void List<T>::resize(int newSize, const T& val) {
	int oldSize = this->numOfElements;

	if (newSize < 0)
		newSize = 0;

	if (newSize < oldSize) {
		while (newSize++ < oldSize)
			popBack();
	}
	else {
		while (oldSize++ < newSize)
			pushBack(val);
	}
}

template <class T>
int List<T>::count(const T& val, bool (*cmp)(const T&, const T&)) const {
	int cnt = 0;

	for (Node<T>* p = head; p; p = p->nextNode())
		if (cmp(p->getData(), val))
			++cnt;

	return cnt;
}

template <class T>
T& List<T>::front() {
	if (List<T>::empty())
		return dummy;

	return head->getData();
}

template <class T>
T& List<T>::back() {
	if (List<T>::empty())
		return dummy;

	return tail->getData();
}

template <class T>
const T& List<T>::front() const {
	return (const_cast<List<T>*> (this))->front();
}

template <class T>
const T& List<T>::back() const {
	return (const_cast<List<T>*> (this))->back();
}

template <class T>
Node<T>* List<T>::getNode(const int& pos) {
	Node<T>* p = nullptr;

	if (0 <= pos && pos < this->numOfElements) {
		int count = 0;

		for (p = head; p; p = p->nextNode(), count++)
			if (pos == count)
				break;
	}

	return p;
}

template <class T>
Node<T>* List<T>::insertBefore(Node<T>*& p, const T& val) {
	Node<T>* tmp = nullptr;

	if (p != nullptr) {
		tmp = new Node<T>(val);
		Node<T>* pPrev = p->prevNode();

		tmp->prevNode() = pPrev;
		pPrev->nextNode() = tmp;

		tmp->nextNode() = p;
		p->prevNode() = tmp;
	}

	return tmp;
}

template <class T>
void List<T>::pushFront(const T& val) {
	Node<T>* p = Node<T>::createNode(val);

	if (List<T>::empty())
		head = tail = p;
	else {
		p->nextNode() = head;
		head->prevNode() = p;
		head = p;
	}

	++this->numOfElements;
}

template <class T>
void List<T>::pushBack(const T& val) {
	Node<T>* p = Node<T>::createNode(val);

	if (List<T>::empty())
		head = tail = p;
	else {
		tail->nextNode() = p;
		p->prevNode() = tail;
		tail = p;
	}

	++this->numOfElements;
}

template <class T>
void List<T>::popFront() {
	if (List<T>::empty())
		return;

	Node<T>* p = head;
	head = head->nextNode();

	delete p;
	p = nullptr;
	--this->numOfElements;
}

template <class T>
void List<T>::popBack() {
	if (List<T>::empty())
		return;

	if (head == tail) {
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node<T>* p = getNode(List<T>::numOfElements - 2);
		delete tail;
		tail = nullptr;
		p->nextNode() = nullptr;
	}

	--this->numOfElements;
}

template <class T>
Node<T>* List<T>::insert(const T& val, const int& pos) {
	Node<T>* p = nullptr;

	if (pos == 0) {
		pushFront(val);
		p = head;
	}
	else if (pos == this->numOfElements) {
		pushBack(val);
		p = tail;
	}
	else if (0 < pos && pos < this->numOfElements) {
		p = getNode(pos);
		p = insertBefore(p, val);
		++this->numOfElements;
	}

	return p;
}

template <class T>
Node<T>* List<T>::erase(const int& pos) {
	Node<T>* p = nullptr;

	if (!List<T>::empty()) {
		if (pos == 0) {
			popFront();
			p = head;
			this->numOfElements--;
		}
		else if (pos == List<T>::numOfElements - 1) {
			popBack();
			p = tail;
			this->numOfElements--;
		}
		else if (0 < pos && pos < List<T>::numOfElements - 1) {
			p = getNode(pos);
			removeMid(p);
			this->numOfElements--;
		}
	}

	return p;
}

template <class T>
Node<T>* List<T>::removeMid(Node<T>*& p) {
	if (p != nullptr) {
		Node<T>* pPrev, * pNext;

		pPrev = p->prevNode();
		pNext = p->nextNode();
		pPrev->nextNode() = pNext;
		pNext->prevNode() = pPrev;

		delete p;
		p = pNext;
	}

	return p;
}

template <class T>
void List<T>::remove(const T& val) {
	if (List<T>::empty())
		return;

	Node<T>* p;

	for (p = head->nextNode(); (p != nullptr && p->nextNode() != nullptr); ) {
		if (p->getData() == val) {
			p = removeMid(p);
			--this->numOfElements;
		}
		else
			p = p->nextNode();
	}

	if (head->getData() == val)
		popFront();
	if (p != nullptr && p->getData() == val) // p = tail
		popBack();
}

template <class T>
void List<T>::swap(List<T> &lst) {
	List<T> tmp(lst);

	lst = *this;
	*this = tmp;
}

template <class T>
void List<T>::reverse() {
	Node<T>* p = head;
	head = tail;
	tail = p;

	for (p = head; p; p = p->nextNode())
		std::swap(p->prevNode(), p->nextNode());
}

template <class T>
void List<T>::clear() {
	Node<T>* p;

	while (head != nullptr) {
		p = head;
		head = head->nextNode();

		delete p;
		p = nullptr;
	}

	tail = nullptr;
	this->numOfElements = 0;
}

template <class T>
List<T>::~List() {
	this->clear();
}

#endif // !_LIST_H_