#ifndef _VECTOR_1D_H_
#define _VECTOR_1D_H_

#include "Container.h"
#define NOT_FOUND -1

template <class T>
class Vector1D : public Container<T> {
	T* arr;
	T dummy;

	
	void QuickSort(const int& left, const int& right, int (*cmp)(const T&, const T&));
public:
	Vector1D();
	Vector1D(const int& n);
	Vector1D(const int& n, const T& val);
	Vector1D(const Vector1D<T>& vec1D);

	void resize(const int& newSize);
	int count(const T& val, bool (*cmp)(const T&, const T&) = Container<T>::equal) const;

	// begin
	// end

	int find(const T& val);
	Vector1D<T>& operator=(const Vector1D<T>& vec1D);
	bool operator==(const Vector1D<T>& vec1D);

	T& operator[](int pos);
	const T& operator[](int pos) const;
	T& front();
	T& back();
	const T& front() const;
	const T& back() const;

	void pushBack(const T& val);
	void popBack();
	void insert(const T& val, int pos);
	void erase(int pos);

	void sort(int (*cmp)(const T&, const T&) = Container<T>::ascending);

	void reverse();
	void swap(Vector1D<T>& vec1D);
	void clear();

	~Vector1D();
};

template <class T>
void Vector1D<T>::QuickSort(const int& left, const int& right, int (*cmp)(const T&, const T&)) {
	int i = left, j = right, x;
	x = arr[left + (right - left) / 2];

	do {
		while (cmp(arr[i], x) < 0) i++;
		while (cmp(x, arr[j]) < 0) j--;

		if (i <= j) {
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}

	} while (i <= j);

	if (left < j) QuickSort(left, j, cmp);
	if (i < right) QuickSort(i, right, cmp);
}

template <class T>
Vector1D<T>::Vector1D() {
	arr = nullptr;
	this->numOfElements = 0;
}

template <class T>
Vector1D<T>::Vector1D(const int& n) {
	arr = new T[n];
	memset(arr, 0, n * sizeof(T));
	this->numOfElements = n;
}

template <class T>
Vector1D<T>::Vector1D(const int& n, const T& val) {
	arr = new T[n];

	for (int i = 0; i < n; i++)
		arr[i] = val;
}

template <class T>
Vector1D<T>::Vector1D(const Vector1D<T>& vec1D) {
	this->operator=(vec1D);
}

template <class T>
void Vector1D<T>::resize(const int& newSize) {
	if (newSize <= 0)
		this->clear();
	else {
		T* newArray = new T[newSize];
		memset(newArray, newSize * sizeof(T), 0);

		if (arr != nullptr) {
			int n = min(newSize, this->numOfElements);

			for (int i = 0; i < n; i++)
				newArray[i] = arr[i];

			delete[] arr;
			arr = nullptr;
		}

		arr = newArray;
		this->numOfElements = newSize;
	}
}

template <class T>
int Vector1D<T>::count(const T& val, bool (*cmp)(const T&, const T&)) const {
	int cnt = 0;

	for (int i = 0; i < this->numOfElements; i++)
		if (cmp(arr[i], val))
			++cnt;
	
	return cnt;
}

template <class T>
int Vector1D<T>::find(const T& val) {
	for (int i = 0; i < this->numOfElements; i++)
		if (this->equal(val, data[i]))
			return i;

	return NOT_FOUND;
}

template <class T>
Vector1D<T>& Vector1D<T>::operator=(const Vector1D<T>& vec1D) {
	this->resize(vec1D.size());

	for (int i = 0; i < this->numOfElements; i++)
		arr[i] = vec1D[i];

	return *this;
}

template <class T>
bool Vector1D<T>::operator==(const Vector1D<T>& vec1D) {
	if (this->numOfElements != vec1D.size())
		return false;

	for (int i = 0; i < this->numOfElements; i++)
		if (!this->equal(arr[i], vec1D[i]))
			return false;

	return true;
}

template <class T>
T& Vector1D<T>::operator[](int pos) {
	if (pos < 0) pos = 0;
	else if (pos >= this->numOfElements) pos = this->numOfElements - 1;

	return arr[pos];
}

template <class T>
const T& Vector1D<T>::operator[](int pos) const {
	return (const_cast<Vector1D*> (this))->operator[](pos);
}

template <class T>
T& Vector1D<T>::front() {
	if (this->empty())
		return dummy;

	return arr[0];
}

template <class T>
T& Vector1D<T>::back() {
	if (this->empty())
		return dummy;

	return arr[this->numOfElements - 1];
}

template <class T>
const T& Vector1D<T>::front() const {
	return (const_cast<Vector1D<T>*> (this))->front();
}

template <class T>
const T& Vector1D<T>::back() const {
	return (const_cast<Vector1D<T>*> (this))->back();
}

template <class T>
void Vector1D<T>::pushBack(const T& val) {
	this->resize(this->numOfElements + 1);
	arr[this->numOfElements - 1] = val;
}

template <class T>
void Vector1D<T>::popBack() {
	this->resize(this->numOfElements - 1);
}

template <class T>
void Vector1D<T>::insert(const T& val, int pos) {
	if (pos >= this->numOfElements) {
		pushBack(val);
		return;
	}

	if (pos < 0) pos = 0;

	T* newArray = new T[this->numOfElements + 1];

	if (arr != nullptr) {
		int j = 0;
		for (int i = 0; i < pos; i++)
			newArray[i] = arr[j++];

		for (int i = pos + 1; i <= this->numOfElements; i++)
			newArray[i] = arr[j++];

		delete[] arr;
		arr = nullptr;
	}

	newArray[pos] = val;
	arr = newArray;
	++this->numOfElements;

}

template <class T>
void Vector1D<T>::erase(int pos) {
	if (pos >= this->numOfElements - 1) {
		popBack();
		return;
	}
	else if (!this->empty()) { // size > 1
		if (pos < 0) pos = 0;

		T* newArray = new T[this->numOfElements - 1];

		int j = 0;
		for (int i = 0; i < pos; i++)
			newArray[j++] = arr[i];

		for (int i = pos + 1; i < this->numOfElements; i++)
			newArray[j++] = arr[i];

		delete[] arr;
		arr = nullptr;

		arr = newArray;
		--this->numOfElements;
	}
}

template <class T>
void Vector1D<T>::sort(int (*cmp)(const T&, const T&)) {
	if (!this->empty())
		QuickSort(0, this->numOfElements - 1, cmp);
}

template <class T>
void Vector1D<T>::reverse() {
	int n = this->numOfElements;

	for (int i = 0; i < n / 2; i++)
		std::swap(arr[i], arr[n - 1 - i]);
}

template <class T>
void Vector1D<T>::swap(Vector1D<T>& vec1D) {
	if (this != &vec1D) {
		Vector1D<T> tmp(vec1D);

		vec1D = *this;
		*this = tmp;
	}
}

template <class T>
void Vector1D<T>::clear() {
	if (arr != nullptr) {
		delete[] arr;
		arr = nullptr;
		this->numOfElements = 0;
	}
}

template <class T>
Vector1D<T>::~Vector1D() {
	this->clear();
}

#endif // _VECTOR_1D_H_