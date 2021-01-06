#include "Fraction.h"

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
    if (this->denom == 0)
        this->denom = 1;
    else {
        if (this->denom < 0) {
            this->num = -this->num;
            this->denom = -this->denom;
        }

        this->reduce();
    }
}

void Fraction::reduce() {
    int gcdTwoNumbers = gcd(abs(num), denom);

    this->num /= gcdTwoNumbers;
    this->denom /= gcdTwoNumbers;
}

Fraction::Fraction() : num(0), denom(1) {}

Fraction::Fraction(const int& num) {
    this->num = num;
    this->denom = 1;
}

Fraction::Fraction(const int& num, const int& denom) {
    this->num = num;
    
    try {
        if (denom == 0)
            throw DENOM_IS_ZERO;
        else {
            this->denom = denom;
            this->reduce();
        }
    }
    catch (const char* mess) {
        cout << mess << endl;

        system("pause");
        exit(0);
    }
}

Fraction::Fraction(const Fraction& frac) {
    this->num = frac.num;
    this->denom = frac.denom;
}

Fraction& Fraction::operator=(const Fraction& frac) {
    this->num = frac.num;
    this->denom = frac.denom;

    return *this;
}

Fraction::operator int() const {
    return this->num / this->denom;
}

Fraction::operator double() const {
    return (double)this->num / this->denom;
}

void Fraction::inverse() {
    try {
        if (this->num == 0)
            throw "After inversing, denominator is zero.";
        else {
            swap(this->num, this->denom);
            this->reduce();
        }
    }
    catch (const char* mess) {
        cout << mess << endl;

        system("pause");
        exit(0);
    }
}

Fraction Fraction::operator+(const Fraction& frac) {
    Fraction sum;

    sum.num = (this->num + frac.denom) + (denom + frac.num);
    sum.denom = this->denom * frac.denom;
    
    sum.reduce();
    return sum;
}

Fraction Fraction::operator-(const Fraction& frac) {
    Fraction diff; // difference

    diff.num = (this->num + frac.denom) - (denom + frac.num);
    diff.denom = this->denom * frac.denom;

    diff.reduce();
    return diff;
}

Fraction Fraction::operator*(const Fraction& frac) {
    Fraction product;

    product.num = num * frac.num;
    product.denom = denom * frac.denom;
    
    product.reduce();
    return product;
}

Fraction Fraction::operator/(const Fraction& frac) {
    try {
        if (frac.num == 0)
            throw DIV_BY_ZERO;
        else {
            Fraction quotient;

            quotient.num = this->num * frac.denom;
            quotient.denom = this->denom * frac.num;

            quotient.reduce();
            return quotient;
        }
    }
    catch (const char* mess) {
        cout << mess << endl;

        system("pause");
        exit(0);
    }
}

Fraction& Fraction::operator+=(const Fraction& frac) {
    *this = *this + frac;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& frac) {
    *this = *this - frac;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& frac) {
    *this = *this * frac;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& frac) {
    *this = *this / frac;
    return *this;
}

Fraction& Fraction::operator++() {
    this->num += this->denom;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction result(*this);
    ++(*this);

    return result;
}

Fraction& Fraction::operator--() {
    this->num -= this->denom;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction result(*this);
    --(*this);

    return result;
}

bool Fraction::operator>(const Fraction& frac) const {
    int diff = (this->num * frac.denom) - (this->denom * frac.num); // difference two fractions.
    return (diff > 0);
}

bool Fraction::operator<(const Fraction& frac) const {
    int diff = (this->num * frac.denom) - (this->denom * frac.num); // difference two fractions.
    return (diff < 0);
}

bool Fraction::operator==(const Fraction& frac) const {
    return (this->num == frac.num && this->denom == frac.denom);
}

bool Fraction::operator>=(const Fraction& frac) const {
    return (*this > frac) || (*this == frac);
}

bool Fraction::operator<=(const Fraction& frac) const {
    return (*this < frac) || (*this == frac);
}

bool Fraction::operator!=(const Fraction& frac) const {
    return !(*this == frac);
}

ostream& operator<<(ostream& outDev, const Fraction& frac) {
    outDev << frac.num;

    if (frac.denom != 1)
        outDev << " / " << frac.denom;

    return outDev;
}

istream& operator>>(istream& inDev, Fraction& frac) {
    inDev >> frac.num >> frac.denom;

    try {
        if (frac.denom == 0)
            throw DENOM_IS_ZERO;
        else {
            frac.format();
            return inDev;
        }
    }
    catch (const char* mess) {
        cout << mess << endl;

        system("pause");
        exit(0);
    }
}