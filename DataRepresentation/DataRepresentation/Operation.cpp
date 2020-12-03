//
//  Operation.cpp
//  DataRepresentation
//
//  Created by Le Hoang Anh on 26/11/2020.
//

#include "Operation.h"

string Operation::addTwoStrings(const string &left, const string &right, int radix) {
    const string lhs = removePrefix(left, '0');
    const string rhs = removePrefix(right, '0');

    if (lhs.length() < rhs.length())
        return addTwoStrings(rhs, lhs, radix);

    string sum(lhs.length(), '0');
    UInt carry = 0;
    Int indexRhs = rhs.length() - 1;
    Int indexLhs = lhs.length() - 1;

    for (; indexRhs > -1; indexRhs--, indexLhs--) {
        UInt sumTwoDigits = Number::digitToInt(lhs[indexLhs]) + Number::digitToInt(rhs[indexRhs]) + carry;
        carry = sumTwoDigits / radix;
        sum[indexLhs] = Number::intToDigit(sumTwoDigits % radix);
    }

    for (; indexLhs > -1; indexLhs--) {
        UInt sumTwoDigits = Number::digitToInt(lhs[indexLhs]) + carry;
        carry = sumTwoDigits / radix;
        sum[indexLhs] = Number::intToDigit(sumTwoDigits % radix);
    }

    if (carry != 0)
        sum = Number::intToDigit(carry) + sum;

    return sum;
}

string Operation::subtractTwoStrings(const string &left, const string &right) {
    if (Number::isZero(left))
        return Number::negate(right);
    if (Number::isZero(right))
        return left;

    if (Number::isLessThan(left, right))
        return '-' + subtractTwoStrings(right, left);
    if (left == right)
        return zero;

    const string lhs = removePrefix(left, '0');
    const string rhs = removePrefix(right, '0');

    string difference;
    Int surplus = 0;
    Int indexRhs = rhs.length() - 1;
    Int indexLhs = lhs.length() - 1;

    for (; indexRhs > -1; indexRhs--, indexLhs--) {
        Int diffTwoDigits = Number::digitToInt(lhs[indexLhs]) - Number::digitToInt(rhs[indexRhs]) - surplus;

        surplus = 0;
        if (diffTwoDigits < 0) {
            diffTwoDigits += 10;
            surplus = 1;
        }

        difference = Number::intToDigit(diffTwoDigits % 10) + difference;
    }

    for (; indexLhs > 0; indexLhs--) {
        Int diffTwoDigits = Number::digitToInt(lhs[indexLhs]) - surplus;

        surplus = 0;
        if (diffTwoDigits < 0) {
            diffTwoDigits += 10;
            surplus = 1;
        }

        difference = Number::intToDigit(diffTwoDigits % 10) + difference;
    }

    if (Number::digitToInt(lhs[indexLhs]) != surplus) {
        Int diffTwoDigits = Number::digitToInt(lhs[indexLhs]) - surplus;
        difference = Number::intToDigit(diffTwoDigits % 10) + difference;
    }

    return difference;
}

string Operation::multiplyByDigit(const string &str, UInt digit) {
    if (Number::isValid(str))
        return "";

    string product;
    int remainder = 0;

    for (int i = str.length() - 1; i > -1; i--) {
        int productByDigit = (Number::digitToInt(str[i]) * digit) + remainder;
        remainder = productByDigit / 10;
        product = Number::intToDigit(productByDigit % 10) + product;
    }

    if (remainder != 0)
        product = Number::intToDigit(remainder) + product;

    return product;
}

void Operation::incrementByOne(string &number) {
    if (Number::isValid(number))
        return;

    if (Number::isLessThan(number, MAX_UINT64))
        number = to_string(stoull(number) + 1);

    int surplus = 0;
    int i = number.length() - 1;

    do {
        int sumTwoDigits = Number::digitToInt(number[i]) + surplus;
        surplus = sumTwoDigits / 10;
        number[i] = Number::intToDigit(sumTwoDigits % 10);
    } while (surplus != 0);

    if (surplus != 0)
        number = Number::intToDigit(surplus) + number;
}

string Operation::multiplyTwoStrings(const string &left, const string &right) {
    if (Number::isZero(left) || Number::isZero(right))
        return zero;

    string product = zero;
    string temp;

    for (int i = right.length() - 1; i >= 0; i--) {
        product = addTwoStrings(product, multiplyByDigit(left, Number::digitToInt(right[i])) + temp);
        temp += '0';
    }

    return product;
}

string Operation::divideTwoStrings(const string &left, const string &right) {
    if (Number::isLessThan(left, right))
        return zero;
    if (left == right)
        return one;
    if (Number::isLessThanOrEqualTo(left, MAX_UINT64) &&
        Number::isLessThanOrEqualTo(right, MAX_UINT64))
    {
        return to_string(stoull(left) / stoull(right));
    }

    string quotient = zero;
    string divisor = left;
    while (Number::isLessThanOrEqualTo(divisor, right)) {
        incrementByOne(quotient);
        divisor = subtractTwoStrings(divisor, right);
    }

    return quotient;
}

string Operation::moduloTwoStrings(const string &left, const string &right) {
    if (Number::isLessThan(left, right))
        return left;
    if (left == right)
        return zero;
    if (Number::isLessThanOrEqualTo(left, MAX_UINT64) &&
        Number::isLessThanOrEqualTo(right, MAX_UINT64))
    {
        return to_string(stoull(left) % stoull(right));
    }

    string divisor = left;
    while (Number::isLessThanOrEqualTo(divisor, right))
        divisor = subtractTwoStrings(divisor, right);

    return divisor;
}
