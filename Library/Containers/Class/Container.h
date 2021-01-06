#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include <memory>
#include <algorithm>

using namespace std;

template <class T>
class Container {
protected: 
	int numOfElements;
	
	static bool equal(const T& val1, const T& val2);
public:
	static int ascending(const T& left_element, const T& right_element);
	static int descending(const T& left_element, const T& right_element);
	virtual bool empty() const;

	virtual int size() const;
	//virtual void resize(int) = 0;
	virtual void clear() = 0;
};

template <class T>
int Container<T>::ascending(const T& left_element, const T& right_element) {
	if (left_element > right_element)
		return 1;
	else if ((left_element == right_element))
		return 0;
	return -1;
}

template <class T>
int Container<T>::descending(const T& left_element, const T& right_element) {
	if (left_element < right_element)
		return 1;
	else if ((left_element == right_element))
		return 0;
	return -1;
}

template <class T>
bool Container<T>::equal(const T& val1, const T& val2) {
	return (val1 == val2);
}

template <class T>
bool Container<T>::empty() const {
	return (numOfElements == 0);
}

template <class T>
int Container<T>::size() const {
	return numOfElements;
}

#endif // !_CONTAINER_H_