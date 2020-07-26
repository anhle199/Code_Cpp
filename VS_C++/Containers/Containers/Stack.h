#ifndef _STACK_H_
#define _STACK_H_

#include "List.h"

template <class T>
class Stack : public Container<T> {
	List<T>* lst;
public:
	Stack();
	Stack(const int& n, const T& val);

	void resize(int newSize, const T& val);

	T& top();
	const T& top() const;
	void push(const T& val);
	void pop();

	void clear();

	~Stack();
};

template <class T>
Stack<T>::Stack() {
	lst = nullptr;
	this->numOfElements = 0;
}

template <class T>
Stack<T>::Stack(const int& n, const T& val) {
	Stack<T>::Stack();

	for (int i = 0; i < n; i++)
		push(val);

	this->numOfElements = lst->size();
}

template <class T>
void Stack<T>::resize(int newSize, const T& val) {
	int oldSize = this->numOfElements;

	if (newSize < 0)
		newSize = 0;

	if (newSize < oldSize) {
		while (newSize++ < oldSize)
			pop();
	}
	else {
		while (oldSize++ < newSize)
			pushBack(val);
	}

	this->numOfElements = lst->size();
}

template <class T>
T& Stack<T>::top() {
	return lst->front();
}

template <class T>
const T& Stack<T>::top() const {
	return (const_cast<Stack<T>*> (this))->top();
}

template <class T>
void Stack<T>::push(const T& val) {
	if (this->empty())
		lst = new List<T>;

	lst->pushFront(val);
	this->numOfElements = lst->size();
}

template <class T>
void Stack<T>::pop() {
	lst->popFront();

	if (this->empty())
		delete lst;

	this->numOfElements = lst->size();
}

template <class T>
void Stack<T>::clear() {
	if (lst) {
		lst->clear();
		delete lst;

		this->numOfElements = 0;
	}
}

template <class T>
Stack<T>::~Stack() {
	this->clear();
}

#endif // !_STACK_H_