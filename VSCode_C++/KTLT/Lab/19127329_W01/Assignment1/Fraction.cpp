#include "Fraction.h"

void inputFraction(ifstream &in, Fraction &fraction) {
    in >> fraction.numerator >> fraction.denominator;
}

void inputFractionArray(ifstream &in, Fraction fractions[], int &n) {
    in >> n;

    for (int i = 0; i < n; i++) {
        inputFraction(in, fractions[i]);
    }
}

void outputFraction(ofstream &out, Fraction &fraction) {
    out << fraction.numerator << " " << fraction.denominator << endl;
}

int compare(const Fraction &fraction1, const Fraction &fraction2) {
    int x = (fraction1.numerator * fraction2.denominator) - (fraction1.denominator * fraction2.numerator);
    
    if (x > 0) 
        return 1;
    else if (x < 0)
        return -1;
    return 0; // value1 == value2
}

Fraction findMaxFraction(Fraction fractions[], const int &n) {
    Fraction result;

    if (n > 0) {
        result = fractions[0];

        for (int i = 1; i < n; i++)
            if (compare(fractions[i], result) == 1)
                result = fractions[i];
    }

    return result;
}