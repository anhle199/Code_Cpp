#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <fstream>

using namespace std;

struct Fraction {
    int numerator, denominator;
};

void inputFraction(ifstream &in, Fraction &fraction);
void inputFractionArray(ifstream &in, Fraction fractions[], int &n);
void outputFraction(ofstream &out, Fraction &fraction);
void outputFractionArray(ofstream &out, Fraction fractions[], const int &n);

/*
 * Returns 1 if fraction1 > fraction2.
 * Returns -1 if fraction1 < fraction2.
 * Returns 0 if fraction1 = fraction2.
 */
int compare(const Fraction &fraction1, const Fraction &fraction2);

// Sort the array of fractions in ascending order.
void sortArrayAscending(Fraction fractions[], const int &n);

#endif