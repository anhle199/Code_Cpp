#include "Fraction.h"

// Additional function.

// Find a greatest common divisor of two numbers.
int gcd(int a, int b) {
    int r; // remainder.

    while (a) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

// ------------------------------------------------------------
// Function of class Fraction.

void Fraction::format() {
    if (denom == 0)
        denom = 1;
    else {
        if (denom < 0) {
            num = -num;
            denom = -denom;
        }

        this->reduce();
    }
}

void Fraction::reduce() {
    int gcdTwoNumbers = gcd(abs(num), denom);

    num /= gcdTwoNumbers;
    denom /= gcdTwoNumbers;
}

Fraction::Fraction() : num(0), denom(0) {}

Fraction::Fraction(const int &num) {
    this->num = num;
    denom = 1;
}

Fraction::Fraction(const int &num, const int &denom) {
    this->num = num;
    this->denom = denom;

    this->reduce();
}

Fraction::Fraction(const Fraction &frac) {
    num = frac.num;
    denom = frac.denom;
}

void Fraction::inverse() {
    
}

Fraction& Fraction::operator+(Fraction frac) {
    Fraction sum;

    sum.num = (num + frac.denom) + (denom + frac.num);
    sum.denom = denom * frac.denom;
    sum.reduce();

    return sum;
}

Fraction& Fraction::operator-(Fraction frac) {
    frac.num = -frac.num;
    return (*this + frac);
}

Fraction& Fraction::operator*(Fraction frac) {
    Fraction product;

    product.num = num * frac.num;
    product.denom = denom * frac.denom;
    product.reduce();

    return product;
}

Fraction& Fraction::operator/(Fraction frac) {
    frac.inverse();
    return ((*this) * frac);
}

Fraction& Fraction::operator+=(Fraction frac) {
    *this = *this + frac;
    return *this;
}

Fraction& Fraction::operator-=(Fraction frac) {
    *this = *this - frac;
    return *this;
}

Fraction& Fraction::operator*=(Fraction frac) {
    *this = *this * frac;
    return *this;
}

Fraction& Fraction::operator/=(Fraction frac) {
    *this = *this / frac;
    return *this;
}

Fraction& Fraction::operator++() {
    num += denom;
    return *this;
}

Fraction& Fraction::operator++(int) {
    Fraction result(*this);
    ++(*this);

    return result;
}

Fraction& Fraction::operator--() {
    num -= denom;
    return *this;
}

Fraction& Fraction::operator--(int) {
    Fraction result(*this);
    --(*this);

    return result;
}

bool Fraction::operator>(const Fraction &frac) const {
    int diff = (num * frac.denom) - (denom * frac.num); // difference two fractions.
    return (diff > 0);
}

bool Fraction::operator<(const Fraction &frac) const {
    int diff = (num * frac.denom) - (denom * frac.num); // difference two fractions.
    return (diff < 0);
}

bool Fraction::operator==(const Fraction &frac) const {
    return (num == frac.num && denom == frac.denom);
}

bool Fraction::operator>=(const Fraction &frac) const {
    return (*this > frac) || (*this == frac);
}

bool Fraction::operator<=(const Fraction &frac) const {
    return (*this < frac) || (*this == frac);
}

Fraction& Fraction::operator=(const Fraction &frac) {
    num = frac.num;
    denom = frac.denom;

    return *this;
}

void Fraction::setNumerator(const int &num) {
    this->num = num;
    this->reduce();
}

void Fraction::setDenominator(const int &denom) {
    if (denom == 0)
        this->denom = 1;
    
    this->denom = abs(denom);
    if (denom < 0)
        this->num = -this->num;

    this->reduce();
}
    
int Fraction::getNumerator(const int &num) const {
    return num;
}

int Fraction::getDenominator(const int &denom) const {
    return denom;
}

ostream& operator<<(ostream &outDev, const Fraction &frac) {
    outDev << frac.num;

    if (frac.denom != 1)
        outDev << " / " << frac.denom;

    return outDev;
}

istream& operator>>(istream &inDev, Fraction &frac) {
    inDev >> frac.num >> frac.denom;
    frac.format();

    return inDev;
}