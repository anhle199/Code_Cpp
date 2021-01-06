#ifndef _ITERATOR_H_
#define _ITERATOR_H_

template <class T>
class Iterator {
protected:
	virtual void* getAddressOfData() const = 0;
public:
	virtual T& operator*() = 0;
	virtual const T& operator*() const = 0;
	virtual T& operator++() = 0;
	virtual T& operator++(int) = 0;
	virtual T& operator--() = 0;
	virtual T& operator--(int) = 0;
	virtual T& operator=(const Iterator&) = 0;
	virtual bool operator==(const Iterator& it) {
		return (getAddressOfData() == it.getAddressOfData());
	}
};

#endif // !_ITERATOR_H_