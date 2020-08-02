#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>

#define DIV_BY_ZERO     "Cannot be divided by 0."
#define DENOM_IS_ZERO   "Denominator cannot be zero."

using namespace std;

class Fraction {
private:
    int num, denom;

    void format();

    // Reduce a fraction.
    void reduce();

public:
    // Default initialize a fraction = 0.
    Fraction();

    // Initialize a fraction = integer value.
    Fraction(const int& num);

    // Initialize a fraction with numerator and denominator.
    Fraction(const int& num, const int& denom);

    // Initialize a fraction from another fraction.
    Fraction(const Fraction& frac);

    // Operator to assign a fraction.
    Fraction& operator=(const Fraction& frac);

    operator int() const;
    operator double() const;

    // Inverse a fraction.
    void inverse();

    Fraction operator+(const Fraction& frac);
    Fraction operator-(const Fraction& frac);
    Fraction operator*(const Fraction& frac);
    Fraction operator/(const Fraction& frac);
    Fraction& operator+=(const Fraction& frac);
    Fraction& operator-=(const Fraction& frac);
    Fraction& operator*=(const Fraction& frac);
    Fraction& operator/=(const Fraction& frac);

    /*
     * Increase the value of this fraction by one and then use that value.
     * Prefix ++.
     */
    Fraction& operator++();

    /*
     * Use the value of this fraction before increasing it by one.
     * Postfix ++.
     */
    Fraction operator++(int); // postfix ++,  fraction++

    /*
     * Decrease the value of this fraction by one and then use that value.
     * Prefix --.
     */
    Fraction& operator--();

    /*
     * Use the value of this fraction before decreasing it by one.
     * Postfix ++.
     */
    Fraction operator--(int);

    /*
     * Returns true if the value to the left is greater than the value to the right;
     * otherwise returns false.
     */
    bool operator>(const Fraction& frac) const;

    /*
     * Returns true if the value to the left is less than the value to the right;
     * otherwise returns false.
     */
    bool operator<(const Fraction& frac) const;

    /*
     * Returns true if the value to the left is equal to the value to the right;
     * otherwise returns false.
     */
    bool operator==(const Fraction& frac) const;

    /*
     * Returns true if the value to the left is greater than or equal to
     * the value to the right; otherwise returns false.
     */
    bool operator>=(const Fraction& frac) const;

    /*
     * Returns true if the value to the left is less than or equal to
     * the value to the right; otherwise returns false.
     */
    bool operator<=(const Fraction& frac) const;

    /*
     * Returns true if the value to the left is not equal to the value to the right;
     * otherwise returns false.
     */
    bool operator!=(const Fraction& frac) const;

    /*
     * Print a fraction to output device.
     * Fraction are printed in the form:
     * Form 1 (denominator != 1): numerator / denominator.
     * Form 2 (denominator == 1): numerator.
     */
    friend ostream& operator<<(ostream& outDev, const Fraction& frac);

    /*
     * Enter a fraction from the input device.
     * The Numerator and denominator are separated by spaces.
     * After entering, this fraction will be reduced.
     */
    friend istream& operator>>(istream& inDev, Fraction& frac);
};

#endif // FRACTION_H_