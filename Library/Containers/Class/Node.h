#ifndef _NODE_H_
#define _NODE_H_

template <class T>
class Node {
	T data;
	Node<T>* next, *prev;

public:
	Node() : data(0), next(nullptr), prev(nullptr) {}
	Node(const T& val) : data(val), next(nullptr), prev(nullptr) {}

	T& getData() { return data; }
	const T& getData() const { return data; }
	void setData(const T& val) { data = val; }
	Node<T>*& nextNode() { return this->next; }
	Node<T>*& prevNode() { return this->prev; }
	
	static Node<T>* createNode(const T& val) {
		Node<T>* p = new Node<T>(val);
		return p;
	}
};

#endif // !_NODE_H_