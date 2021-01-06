#ifndef COMPLEX_NUMBER_H_
#define COMPLEX_NUMBER_H_

#include <iostream>
#include <iomanip>

using namespace std;

class ComplexNumber {
private:
	double realPart, imaginaryPart;
public:
	// constructor.

	ComplexNumber(double rPart = 0, double iPart = 0);
	ComplexNumber(const ComplexNumber&);


	// ----------------------------------------------------------
	// overload operator to calculate and compare complex number.

	ComplexNumber operator+ (const ComplexNumber&);
	ComplexNumber operator- (const ComplexNumber&);
	ComplexNumber operator* (const ComplexNumber&);
	ComplexNumber operator/ (const ComplexNumber&);
	ComplexNumber& operator+= (const ComplexNumber&);
	ComplexNumber& operator-= (const ComplexNumber&);
	ComplexNumber& operator*= (const ComplexNumber&);
	ComplexNumber& operator/= (const ComplexNumber&);
	bool operator== (const ComplexNumber&) const;
	bool operator!= (const ComplexNumber&) const;
	bool operator> (const ComplexNumber&) const;
	bool operator< (const ComplexNumber&) const;

	// ----------------------------------------------------------
	// another calculation with complex number.

	ComplexNumber power(int exp);
	double abs() const;


	// ----------------------------------------------------------
	// overload operator to input, ouput complex number.

	friend ostream& operator<< (ostream&, const ComplexNumber&);
	friend istream& operator>> (istream&, ComplexNumber&);
};

#endif