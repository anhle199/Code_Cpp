//
//  NumberConverter.cpp
//  DataRepresentation
//
//  Created by Le Hoang Anh on 10/24/20.
//

#include "NumberConverter.h"
#include <iostream>

void ValueInBase::setValue(char c) {
    sign = c;
    value = ValueInBase::valueOfSign(sign);
}

UInt ValueInBase::valueOfSign(char sign) {
    if (isdigit(sign))
        return Number::digitToInt(sign);

    sign = toupper(sign);
    return sign - 'A' + 10;
}


const vector<ValueInBase> NumberConverter::_valueInBase = initTableValueInBase();

vector<ValueInBase> NumberConverter::initTableValueInBase() {
    vector<char> signInBase = {
       '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
       'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
       'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
       'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    const Int size = signInBase.size(); // auto is size_type.
    vector<ValueInBase> result(size);

    for (Int i = 0; i < size; i++)
        result[i].setValue(signInBase[i]);

    return result;
}

string NumberConverter::decimalToBaseN(string decimal, UInt radix) {
    if (radix == 10)
        return decimal;

    string result;

    while (!Number::isZero(decimal)) {
        int i = stoi(Number::moduloTwoStrings(decimal, to_string(radix)));
        result = NumberConverter::_valueInBase[i].sign + result;
        decimal = Number::divideTwoStrings(decimal, to_string(radix));
    }

    return result;
}

string NumberConverter::baseNToDecimal(const string &value, UInt radix) {
    string decimal      = zero;
    string powerOfRadix = one;

    Int len = value.length();
    for (Int i = len - 1; i >= 0; i--) {
        UInt valueOfSign = ValueInBase::valueOfSign(value[i]);
        decimal = Number::addTwoStrings(decimal, Number::multiplyByDigit(powerOfRadix, valueOfSign));
        powerOfRadix = Number::multiplyTwoStrings(powerOfRadix, to_string(radix));
    }

    return decimal;
}

string NumberConverter::toOneComplement(const string &binary) {
    if (binary[0] == '0') // non-negative number.
        return binary;

    string oneComplement = binary;

    for (int i = 1; i < binary.length(); i++)
    Number::notOperation(oneComplement[i]);

    return oneComplement;
}

string NumberConverter::toTwoComplement(const string &binary) {
    if (binary[0] == '0')
        return binary;

    string oneComplement = NumberConverter::toOneComplement(binary);
    oneComplement.erase(oneComplement.begin());
    return '1' + Number::addTwoStrings(oneComplement, "1", 2);
}

string NumberConverter::complementToDecimal(const string &complement) {
    string sign;
    string binary = complement;

    if (complement[0] == '1') {
        sign = "-";
        binary.erase(binary.begin());
    }

    return sign + NumberConverter::baseNToDecimal(binary, 2);
}

string NumberConverter::signMagnitudeToDecimal(string binary) {
    string sign; // positive;

    if (binary[0] == '1')
        sign = "-";

    binary.erase(binary.begin());
    return sign + NumberConverter::baseNToDecimal(binary, 2);
}

string NumberConverter::excessKToDecimal(const string &binary, UInt k) {
    return Number::subtractTwoStrings(baseNToDecimal(binary, 2), to_string(k));
}

NumberConverter::NumberConverter() : _decimalValue(zero) {}

NumberConverter::NumberConverter(const string &value, UInt radix) {
    setValueBaseN(value, radix);
}

NumberConverter::NumberConverter(const string &binary, TypeRepresentBinary type, UInt kForOffsetBinary) {
    setValueBinary(binary, type, kForOffsetBinary);
}

void NumberConverter::setValueBaseN(const string &value, UInt radix) {
    if (NumberConverter::isValid(value, radix))
        _decimalValue = (radix == 10) ? value : NumberConverter::baseNToDecimal(value, radix);
    else
        _decimalValue = UNKNOWN_VALUE;
}

void NumberConverter::setValueBinary(const string &binary, TypeRepresentBinary type, UInt kForOffsetBinary) {
    switch (type) {
        case NORMAL:
            _decimalValue = NumberConverter::baseNToDecimal(binary, 2);
            break;
        case OFFSET_BINARY:
            _decimalValue = NumberConverter::excessKToDecimal(binary, kForOffsetBinary);
            break;
        case SIGN_MAGNITUDE:
            _decimalValue = NumberConverter::signMagnitudeToDecimal(binary);
            break;
        case ONE_COMPLEMENT:
            _decimalValue = NumberConverter::complementToDecimal(toOneComplement(binary));
            break;
        case TWO_COMPLEMENT:
            _decimalValue = NumberConverter::complementToDecimal(toTwoComplement(binary));
            break;
        default:
            _decimalValue = UNKNOWN_VALUE;
            break;
    }
}

bool NumberConverter::isValid(const string &valueBaseN, UInt radix) {
    if (radix < 2 || radix > NumberConverter::_valueInBase.size())
        return false;

    for (const char &sign : valueBaseN)
        if (ValueInBase::valueOfSign(sign) >= radix)
            return false;

    return true;
}

string NumberConverter::decimal() const {
    return _decimalValue;
}

string NumberConverter::decimalRepresentByBinary(TypeRepresentBinary type, UInt kForOffsetBinary) const {
    string binary = valueBaseN(2);

    switch (type) {
        case NORMAL:
            return decimal();
        case OFFSET_BINARY:
            return NumberConverter::excessKToDecimal(binary, kForOffsetBinary);
        case SIGN_MAGNITUDE:
            return NumberConverter::signMagnitudeToDecimal(binary);
        case ONE_COMPLEMENT:
            return NumberConverter::complementToDecimal(toOneComplement(binary));
        case TWO_COMPLEMENT:
            return NumberConverter::complementToDecimal(toTwoComplement(binary));
        default:
            return UNKNOWN_VALUE;
    }
}

vector<string> NumberConverter::decimalRepresentByBinaryAllTypes(UInt kForOffsetBinary) const {
    vector<string> listOfBinaryValues(NUMBER_OF_TYPES);

    listOfBinaryValues[0] = decimal();
    listOfBinaryValues[1] = decimalRepresentByBinary(OFFSET_BINARY, kForOffsetBinary);
    listOfBinaryValues[2] = decimalRepresentByBinary(SIGN_MAGNITUDE);
    listOfBinaryValues[3] = decimalRepresentByBinary(ONE_COMPLEMENT);
    listOfBinaryValues[4] = decimalRepresentByBinary(TWO_COMPLEMENT);

    return listOfBinaryValues;
}

string NumberConverter::valueBaseN(UInt radix) const {
    return NumberConverter::decimalToBaseN(_decimalValue, radix);
}

string NumberConverter::convertBaseNToBaseM(const string &valueBaseN, UInt baseN, UInt baseM) {
    string decimal = NumberConverter::baseNToDecimal(valueBaseN, baseN);
    return NumberConverter::decimalToBaseN(decimal, baseM);
}
