#include "BigInteger.h"

int main() {
    BigInteger big_integer_1, big_integer_2;
    int n, m;
    big_integer_1 = inputBigInteger();
    // big_integer_2 = inputBigInteger();

    // printBigInteger(big_integer_1);
    // cout << " + ";
    // printBigInteger(big_integer_2);
    // cout << " = ";
    // printBigInteger(add(big_integer_1, big_integer_2));
    // cout << endl;

    // printBigInteger(big_integer_1);
    // cout << " - ";
    // printBigInteger(big_integer_2);
    // cout << " = ";
    // printBigInteger(subtract(big_integer_1, big_integer_2));
    // cout << endl;

    // printBigInteger(big_integer_1);
    // cout << " * ";
    // printBigInteger(big_integer_2);
    // cout << " = ";
    // printBigInteger(multiply(big_integer_1, big_integer_2));
    // cout << endl;
    
    // printBigInteger(big_integer_1);
    // cout << " / ";
    // printBigInteger(big_integer_2);
    // cout << " = ";
    // printBigInteger(divide(big_integer_1, big_integer_2));
    // cout << endl;

    // printBigInteger(big_integer_1);
    // cout << " % ";
    // printBigInteger(big_integer_2);
    // cout << " = ";
    // printBigInteger(mod(big_integer_1, big_integer_2));
    
    cout << "Enter the exponent of ";
    printBigInteger(big_integer_1);
    cout << ": ";
    cin >> n;

    // cout << "Enter the exponent of ";
    // printBigInteger(big_integer_2);
    // cout << ": ";
    // cin >> m;

    cout << endl;
    printBigInteger(big_integer_1);
    cout << "^" << n << " = ";
    printBigInteger(power(big_integer_1, n));

    // cout << endl;
    // printBigInteger(big_integer_2);
    // cout << "^" << m << " = ";
    // printBigInteger(power(big_integer_2, m));

    cout << endl;
    printBigInteger(big_integer_1);
    cout << "! = ";
    printBigInteger(factorial(big_integer_1));
    
    // cout << endl;
    // printBigInteger(big_integer_2);
    // cout << "! = ";
    // printBigInteger(factorial(big_integer_2));

    // cout << "\nGreatest common divisor of ";
    // printBigInteger(big_integer_1);
    // cout << " and ";
    // printBigInteger(big_integer_2);
    // cout << " are: ";
    // printBigInteger(GCD(big_integer_1, big_integer_2));
    
    // cout << "\nLeast common multiple of ";
    // printBigInteger(big_integer_1);
    // cout << " and ";
    // printBigInteger(big_integer_2);
    // cout << " are: ";
    // printBigInteger(LCM(big_integer_1, big_integer_2));

    // cout << "\nLargest values of ";
    // printBigInteger(big_integer_1);
    // cout << " and ";
    // printBigInteger(big_integer_2);
    // cout << " are: ";
    // printBigInteger(maxBigInteger(big_integer_1, big_integer_2));
    
    // cout << "\nSmallest values of ";
    // printBigInteger(big_integer_1);
    // cout << " and ";
    // printBigInteger(big_integer_2);
    // cout << " are: ";
    // printBigInteger(minBigInteger(big_integer_1, big_integer_2));
    
    // cout << "\nAbsolute of ";
    // printBigInteger(big_integer_1);
    // cout << " is: ";
    // printBigInteger(absBigInteger(big_integer_1));
    
    // cout << "\nAbsolute of ";
    // printBigInteger(big_integer_2);
    // cout << " is: ";
    // printBigInteger(absBigInteger(big_integer_2));

    return 0;
}