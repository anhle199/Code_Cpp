#include "ArrayComplexNumber.h"

ArrayComplexNumber::ArrayComplexNumber(const ArrayComplexNumber &arr) {
    numOfElements = arr.size();
    data = new ComplexNumber[numOfElements];

    for (int i = 0; i < numOfElements; i++)
        data[i] = arr[i];
}

const int ArrayComplexNumber::size() const {
    return numOfElements;
}

ComplexNumber& ArrayComplexNumber::operator[](const int &pos) {
    static ComplexNumber dummy;

    if (pos < 0 || pos >= numOfElements)
        return dummy;
    return data[pos];
}

const ComplexNumber& ArrayComplexNumber::operator[](const int &pos) const {
    return const_cast<ArrayComplexNumber*>(this)->operator[](pos);
}

int ArrayComplexNumber::find(const ComplexNumber &c) {
    int pos = NOT_FOUND;
    
    for (int i = 0; i < numOfElements; i++)
        if (data[i] == c) {
            pos = i;
            break;
        }

    return pos;
}

void ArrayComplexNumber::append(const ComplexNumber &c, const int &pos) {
    if (pos < 0 || pos > numOfElements) {
        cout << "Index out of range." << endl;
        return;
    }
    
    ComplexNumber* newArray = new ComplexNumber[numOfElements + 1];
    ++numOfElements;
    
    for (int i = 0; i < pos; i++)
        newArray[i] = data[i];

    for (int i = pos + 1; i < numOfElements; i++)
        newArray[i] = data[i - 1];

    newArray[pos] = c;
    
    delete[] data;
    data = newArray;
}

void ArrayComplexNumber::remove(const int &pos) {
    if (pos < 0 || pos >= numOfElements) {
        cout << "Index out of range." << endl;
        return;
    }

    ComplexNumber* newArray = new ComplexNumber[numOfElements - 1];
    --numOfElements;

    for (int i = 0; i < pos; i++)
        newArray[i] = data[i];

    for (int i = pos; i < numOfElements; i++)
        newArray[i] = data[i + 1];
    
    delete[] data;
    data = newArray;
}

istream& operator>>(istream &inDev, ArrayComplexNumber &arr) {
    inDev >> arr.numOfElements;

    arr.data = new ComplexNumber[arr.numOfElements]; 
    
    for (int i = 0; i < arr.numOfElements; i++)
        inDev >> arr.data[i];

    return inDev;
}

ostream& operator<<(ostream &outDev, const ArrayComplexNumber &arr) {
    for (int i = 0; i < arr.numOfElements; i++)
        outDev << arr.data[i] << endl;

    return outDev;
}