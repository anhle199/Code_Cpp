#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double rPart, double iPart) : realPart(rPart), imaginaryPart(iPart) {}

ComplexNumber::ComplexNumber(const ComplexNumber& c) {
	this->realPart = c.realPart;
	this->imaginaryPart = c.imaginaryPart;
}

ComplexNumber ComplexNumber::operator+ (const ComplexNumber& c) {
	ComplexNumber sum;

	sum.realPart = realPart + c.realPart;
	sum.imaginaryPart = imaginaryPart + c.imaginaryPart;

	return sum;
}

ComplexNumber ComplexNumber::operator- (const ComplexNumber& c) {
	ComplexNumber minus;

	minus.realPart = realPart - c.realPart;
	minus.imaginaryPart = imaginaryPart - c.imaginaryPart;

	return minus;
}

ComplexNumber ComplexNumber::operator* (const ComplexNumber& c) {
	ComplexNumber product;

	product.realPart = (realPart * c.realPart) - (imaginaryPart * c.imaginaryPart);
	product.imaginaryPart = (realPart * c.imaginaryPart) + (imaginaryPart * c.realPart);

	return product;
}

ComplexNumber ComplexNumber::operator/ (const ComplexNumber& c) {
	ComplexNumber res, temp(c.realPart, -c.imaginaryPart);
	double divisor = (c.realPart * c.realPart) + (c.imaginaryPart * c.imaginaryPart);

	res = this->operator*(temp);
	res.realPart /= divisor;
	res.imaginaryPart /= divisor;

	return res;
}

ComplexNumber& ComplexNumber::operator+= (const ComplexNumber& c) {
	*this = this->operator+(c);
	return *this;
}

ComplexNumber& ComplexNumber::operator-= (const ComplexNumber& c) {
	*this = this->operator-(c);
	return *this;
}

ComplexNumber& ComplexNumber::operator*= (const ComplexNumber& c) {
	*this = this->operator*(c);
	return *this;
}

ComplexNumber& ComplexNumber::operator/= (const ComplexNumber& c) {
	*this = this->operator/(c);
	return *this;
}

bool ComplexNumber::operator== (const ComplexNumber& c) const {
	return ((realPart == c.realPart) && (imaginaryPart == c.imaginaryPart));
}

bool ComplexNumber::operator!= (const ComplexNumber& c) const {
	return !this->operator==(c);
}

bool ComplexNumber::operator> (const ComplexNumber& c) const {
	return (this->abs() > c.abs());
}

bool ComplexNumber::operator< (const ComplexNumber& c) const {
	return (this->abs() < c.abs());
}

ComplexNumber ComplexNumber::power(int exp) {
	ComplexNumber res(1), temp(*this);

	while (exp) {
		if (exp % 2 == 1)
			res *= temp;

		temp *= temp;
		exp /= 2;
	}

	return res;
}

double ComplexNumber::abs() const {
	return sqrt((realPart * realPart) + (imaginaryPart * imaginaryPart));
}

ostream& operator<< (ostream& outDev, const ComplexNumber& c) {
	outDev << c.realPart;

	if (c.imaginaryPart != 0)
		outDev << ((c.imaginaryPart > 0) ? (" + ") : (" - ")) << fabs(c.imaginaryPart) << "i";

	return outDev;
}

istream& operator>> (istream& inDev, ComplexNumber& c) {
	cin >> c.realPart >> c.imaginaryPart;
	return inDev;
}