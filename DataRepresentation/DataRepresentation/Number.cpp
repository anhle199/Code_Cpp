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


    const Int lengthLhs = lhs.length();
    const Int lengthRhs = rhs.length();

    if (lengthLhs < lengthRhs)
        return true;
    if (lengthLhs > lengthRhs)
        return false;

    for (Int i = 0; i < lengthLhs - 1; i++) {
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

string Number::addTwoStrings(const string &left, const string &right, int radix) {
    const string lhs = removePrefix(left, '0');
    const string rhs = removePrefix(right, '0');

    if (lhs.length() < rhs.length())
        return addTwoStrings(rhs, lhs, radix);

    string sum(lhs.length(), '0');
    UInt surplus = 0;
    Int indexRhs = rhs.length() - 1;
    Int indexLhs = lhs.length() - 1;

    for (; indexRhs > -1; indexRhs--, indexLhs--) {
        UInt sumTwoDigits = Number::digitToInt(lhs[indexLhs]) + Number::digitToInt(rhs[indexRhs]) + surplus;
        surplus = sumTwoDigits / radix;
        sum[indexLhs] = Number::intToDigit(sumTwoDigits % radix);
    }

    for (; indexLhs > -1; indexLhs--) {
        UInt sumTwoDigits = Number::digitToInt(lhs[indexLhs]) + surplus;
        surplus = sumTwoDigits / radix;
        sum[indexLhs] = Number::intToDigit(sumTwoDigits % radix);
    }

    if (surplus != 0)
        sum = Number::intToDigit(surplus) + sum;

    return sum;
}

string Number::subtractTwoStrings(const string &left, const string &right) {
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

string Number::multiplyByDigit(const string &str, UInt digit) {
    if (Number::isValid(str))
        return "";

    string product;
    int remainder = 0;

    for (Int i = str.length() - 1; i > -1; i--) {
        int productByDigit = (Number::digitToInt(str[i]) * digit) + remainder;
        remainder = productByDigit / 10;
        product = Number::intToDigit(productByDigit % 10) + product;
    }

    if (remainder != 0)
        product = Number::intToDigit(remainder) + product;

    return product;
}

void Number::incrementByOne(string &number) {
    if (Number::isValid(number))
        return;

    if (Number::isLessThan(number, MAX_UINT64))
        number = to_string(stoull(number) + 1);

    int surplus = 0;
    Int i = number.length() - 1;

    do {
        int sumTwoDigits = Number::digitToInt(number[i]) + surplus;
        surplus = sumTwoDigits / 10;
        number[i] = Number::intToDigit(sumTwoDigits % 10);
    } while (surplus != 0);

    if (surplus != 0)
        number = Number::intToDigit(surplus) + number;
}

string Number::multiplyTwoStrings(const string &left, const string &right) {
    if (Number::isZero(left) || Number::isZero(right))
        return zero;

    string product = zero;
    string temp;

    for (Int i = right.length() - 1; i >= 0; i--) {
        product = addTwoStrings(product, multiplyByDigit(left, Number::digitToInt(right[i])) + temp);
        temp += '0';
    }

    return product;
}

string Number::divideTwoStrings(const string &left, const string &right) {
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

string Number::moduloTwoStrings(const string &left, const string &right) {
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

string removePrefix(const string &str, char repeatingValue) {
    Int startIndex = str.find_first_not_of(repeatingValue);

    if (startIndex == 0 || startIndex == string::npos)
        return str;

    return str.substr(startIndex, str.length() - startIndex);
}

string removeSuffix(const string &str, char repeatingValue) {
    Int lastIndex = str.length() - 1;

    for (; lastIndex >= 0; lastIndex--)
        if (str[lastIndex] != repeatingValue)
            break;

    if (lastIndex == -1)
        return str;

    return str.substr(0, lastIndex + 1);
}
