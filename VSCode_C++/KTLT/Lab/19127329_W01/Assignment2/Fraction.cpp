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

void outputFractionArray(ofstream &out, Fraction fractions[], const int &n) {
    for (int i = 0; i < n; i++)
        outputFraction(out, fractions[i]);
}

int compare(const Fraction &fraction1, const Fraction &fraction2) {
    int x = (fraction1.numerator * fraction2.denominator) - (fraction1.denominator * fraction2.numerator);
    
    if (x > 0) 
        return 1;
    else if (x < 0)
        return -1;
    return 0; // value1 == value2
}

void sortArrayAscending(Fraction fractions[], const int &n) {
    int pos;

    for (int i = 0; i < n - 1; i++) {
        pos = i;

        for (int j = i + 1; j < n; j++)
            if (compare(fractions[pos], fractions[j]) == 1)
                pos = j;

        swap(fractions[i], fractions[pos]);
    }
}