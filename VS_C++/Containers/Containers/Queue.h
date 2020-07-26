#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "List.h"

template <class T>
class Queue : public Container<T> {
	List<T>* lst;
public:
	Queue();
	Queue(const int& n, const T& val);

	void resize(int newSize, const T& val);

	T& front();
	T& back();
	const T& front() const;
	const T& back() const;
	void push(const T& val);
	void pop();

	void clear();

	~Queue();
};

template <class T>
Queue<T>::Queue() {
	lst = nullptr;
	this->numOfElements = 0;
}

template <class T>
Queue<T>::Queue(const int& n, const T& val) {
	lst = new List<T>(n, val);
	this->numOfElements = lst->size();
}

template <class T>
void Queue<T>::resize(int newSize, const T& val) {
	int oldSize = this->numOfElements;

	if (newSize < 0)
		newSize = 0;

	if (newSize < oldSize) {
		while (newSize++ < oldSize)
			pop();
	}
	else {
		while (oldSize++ < newSize)
			push(val);
	}

	this->numOfElements = lst->size();
}

template <class T>
T& Queue<T>::front() {
	return lst->front();
}

template <class T>
T& Queue<T>::back() {
	return lst->back();
}

template <class T>
const T& Queue<T>::front() const {
	return (const_cast<Queue<T>*> (this))->front();
}

template <class T>
const T& Queue<T>::back() const {
	return (const_cast<Queue<T>*> (this))->back();
}

template <class T>
void Queue<T>::push(const T& val) {
	if (this->empty())
		lst = new List<T>;

	lst->pushBack(val);
	this->numOfElements = lst->size();
}

template <class T>
void Queue<T>::pop() {
	lst->popFront();

	if (this->empty())
		delete lst;

	this->numOfElements = lst->size();
}

template <class T>
void Queue<T>::clear() {
	if (lst) {
		lst->clear();
		delete lst;

		this->numOfElements = 0;
	}
}

template <class T>
Queue<T>::~Queue() {
	this->clear();
}

#endif // !_QUEUE_H_