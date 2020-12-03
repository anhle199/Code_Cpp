//
//  Number.cpp
//  DataRepresentation
//
//  Created by Le Hoang Anh on 10/24/20.
//

#include "Number.h"

void Number::notOperation(char &digit) {
    digit = (digit == '0') ? '1' : '0';
}

int Number::digitToInt(char digit) {
    if (isnumber(digit))
        return digit - '0';
    return -1;
}

char Number::intToDigit(int number) {
    if (0 <= number && number <= 9)
        return number + '0';

    return '\0';
}

bool Number::isSign(Sign sign) {
    return Number::isPlusSign(sign) || Number::isMinusSign(sign);
}

bool Number::isPlusSign(Sign sign) {
    return sign == '+';
}

bool Number::isMinusSign(Sign sign) {
    return sign == '-';
}

bool Number::isValid(const string &number) {
    const string numberFormatted = Number::format(number);
    int i = 0;

    if (Number::isSign(numberFormatted[0]))
        ++i;

    for (; i < numberFormatted.length(); i++)
        if (!isdigit(numberFormatted[i]))
            return false;

    return true;
}

bool Number::isZero(const string &number) {
    return Number::format(number) == zero;
}

bool Number::isPositive(const string &number) {
    const string numberFormatted = Number::format(number);

    if (numberFormatted.empty())
        return false;
    return numberFormatted[0] == '\0' || Number::isPlusSign(numberFormatted[0]);
}

bool Number::isNegative(const string &number) {
    const string numberFormatted = Number::format(number);

    if (numberFormatted.empty())
        return false;
    return Number::isMinusSign(numberFormatted[0]);
}

bool Number::isOddDigit(char digit) {
    const int n = Number::digitToInt(digit);
    return isdigit(n) && ((n & 1) == 1);
}

bool Number::isEvenDigit(char digit) {
    const int n = Number::digitToInt(digit);
    return isdigit(n) && ((n & 1) == 0);
}

bool Number::isOdd(const string &number) {
    if (!Number::isValid(number))
        return false;

    const string numberFormatted = Number::format(number);
    return Number::isOddDigit(numberFormatted.back());
}

bool Number::isEven(const string &number) {
    if (!Number::isValid(number))
        return false;

    const string numberFormatted = Number::format(number);
    return Number::isEvenDigit(numberFormatted.back());
}

bool Number::isLessThan(const string &left, const string &right) {
    if (Number::isValid(left) && Number::isValid(right))
        return false;
    if (left == right)
        return false;
    if (Number::isMinusSign(left[0]) && Number::isMinusSign(right[0]) == false)
        return true;
    if (Number::isMinusSign(left[0]) == false && Number::isMinusSign(right[0]))
        return false;

    string lhs = Number::format(left); // left hand side.
    string rhs = Number::format(right); // right hand side

    if (Number::isSign(lhs[0]))
        lhs.erase(lhs.begin());
    if (Number::isSign(rhs[0]))
        rhs.erase(rhs.begin());


    const int lengthLhs = lhs.length();
    const int lengthRhs = rhs.length();

    if (lengthLhs < lengthRhs)
        return true;
    if (lengthLhs > lengthRhs)
        return false;

    for (int i = 0; i < lengthLhs - 1; i++) {
        if (lhs[i] < rhs[i])
            return true;
        else if (lhs[i] > rhs[i])
            return false;
    }

    return lhs.back() < rhs.back();
}

bool Number::isLessThanOrEqualTo(const string &left, const string &right) {
    return left == right || Number::isLessThan(left, right);
}

string Number::format(const string &number) {
    Sign sign = '\0';
    int startIndex = 0;

    if (Number::isSign(number.front())) {
        ++startIndex;

        if (Number::isMinusSign(number.front()))
            sign = '-';
    }

    if (number[startIndex] == '0') {
        for (; startIndex < number.length(); startIndex++)
            if (number[startIndex] != '0')
                break;
    }

    if (startIndex > number.length())
        return "";
    if (startIndex == number.length())
        return "0";
    
    return sign + number.substr(startIndex, number.length() - startIndex);
}

string Number::negate(const string &number) {
    if (!Number::isValid(number))
        return "";

    const string numberFormatted = Number::format(number);
    return (Number::isMinusSign(numberFormatted.front()) ? '-' : '\0') + numberFormatted;
}
