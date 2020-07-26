#ifndef _ARRAY_COMPLEX_NUMBER_H_
#define _ARRAY_COMPLEX_NUMBER_H_

#include "ComplexNumber.h"
#define NOT_FOUND -1

class ArrayComplexNumber {
private:
    ComplexNumber* data;
    int numOfElements;

public:
    ArrayComplexNumber() : data(nullptr), numOfElements(0) {}
    ArrayComplexNumber(const ArrayComplexNumber &arr);

    // Returns the number of complex numbers.
    const int size() const;
    
    ComplexNumber& operator[](const int &pos);
    const ComplexNumber& operator[](const int &pos) const;

    /*
     * Find a complex number in an array of complex numbers.
     * Returns the first index whose complex number appears in the array;
     * otherwise returns NOT_FOUND (-1). 
     */
    int find(const ComplexNumber &c);
    
    /*
     * Add a complex number to the pos position.
     * If (pos < 0 or pos > number of complex numbers) then print "Index out of range."
     */
    void append(const ComplexNumber &c, const int &pos);
    
    /*
     * Remove a complex number at the pos position.
     * If (pos < 0 or pos >= number of complex numbers) then print "Index out of range."
     */
    void remove(const int &pos);

    friend istream& operator>>(istream &inDev, ArrayComplexNumber &arr);
    friend ostream& operator<<(ostream &outDev, const ArrayComplexNumber &arr);
};

#endif