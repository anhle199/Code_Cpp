#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
using namespace std;

class Fraction {
private:
    int num, denom;
    
    void format();
    
    // Reduce a fraction.
    void reduce();

public:
    // Default value of numerator and denominator is 1.
    Fraction();

    // Default value of denominator is 1.
    Fraction(const int &num);

    Fraction(const int &num, const int &denom);
    Fraction(const Fraction &frac);

    // Inverse a fraction.
    void inverse();

    Fraction& operator+(Fraction frac);
    Fraction& operator-(Fraction frac);
    Fraction& operator*(Fraction frac);
    Fraction& operator/(Fraction frac);
    Fraction& operator+=(Fraction frac);
    Fraction& operator-=(Fraction frac);
    Fraction& operator*=(Fraction frac);
    Fraction& operator/=(Fraction frac);

    /* 
     * Increase the value of this fraction by one and then use that value.
     * Prefix ++;
     */
    Fraction& operator++();

    /* 
     * Use the value of this fraction before increasing it by one.
     * Postfix ++;
     */
    Fraction& operator++(int); // postfix ++,  fraction++

    /* 
     * Decrease the value of this fraction by one and then use that value.
     * Prefix --;
     */
    Fraction& operator--();

    /* 
     * Use the value of this fraction before decreasing it by one.
     * Postfix ++;
     */
    Fraction& operator--(int);
    
    /* 
     * Returns true if the value to the left is greater than the value to the right;
     * otherwise returns false.
     */
    bool operator>(const Fraction &frac) const;
    
    /* 
     * Returns true if the value to the left is less than the value to the right;
     * otherwise returns false.
     */
    bool operator<(const Fraction &frac) const;
    
    /* 
     * Returns true if the value to the left is equal to the value to the right;
     * otherwise returns false.
     */
    bool operator==(const Fraction &frac) const;
    
    /* 
     * Returns true if the value to the left is greater than or equal to 
     * the value to the right; otherwise returns false.
     */
    bool operator>=(const Fraction &frac) const;
    
    /* 
     * Returns true if the value to the left is less than or equal to 
     * the value to the right; otherwise returns false.
     */
    bool operator<=(const Fraction &frac) const;

    // Operator to assign a fraction.
    Fraction& operator=(const Fraction &frac);

    // Assign / Update the numerator value of a fraction.
    void setNumerator(const int &num);

    /* 
     * Assign / Update the denominator value of a fraction.
     * If the denominator parameter is 0, the default is 1.
     */
    void setDenominator(const int &denom);
    
    /* 
     * Return the numerator value of a fraction.
     * This value is only readable.
     */
    int getNumerator(const int &num) const;

    /* 
     * Return the denominator value of a fraction.
     * This value is only readable.
     */
    int getDenominator(const int &denom) const;

    /* 
     * Print a fraction to output device.
     * Fraction are printed in the form: 
     * Form 1 (denominator != 1): numerator / denominator.
     * Form 2 (denominator == 1): numerator.
     */
    friend ostream& operator<<(ostream &outDev, const Fraction &frac);
    
    /* 
     * Enter a fraction from the input device.
     * The Numerator and denominator are separated by spaces.
     * After entering, this fraction will be reduced. 
     */
    friend istream& operator>>(istream &inDev, Fraction &frac);
};

#endif