//
//  RepresentInteger.cpp
//  DataRepresentation
//
//  Created by Le Hoang Anh on 10/24/20.
//

#include "RepresentInteger.h"
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


const vector<ValueInBase> RepresentInteger::_valueInBase = initTableValueInBase();

vector<ValueInBase> RepresentInteger::initTableValueInBase() {
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

string RepresentInteger::decimalToBaseN(string decimal, UInt radix) {
    if (radix == 10)
        return decimal;

    string result;

    while (!Number::isZero(decimal)) {
        int i = stoi(Number::moduloTwoStrings(decimal, to_string(radix)));
        result = RepresentInteger::_valueInBase[i].sign + result;
        decimal = Number::divideTwoStrings(decimal, to_string(radix));
    }

    return result;
}

string RepresentInteger::baseNToDecimal(const string &value, UInt radix) {
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

string RepresentInteger::toOneComplement(const string &binary) {
    if (binary[0] == '0') // non-negative number.
        return binary;

    string oneComplement = binary;

    for (int i = 1; i < binary.length(); i++)
    Number::notOperation(oneComplement[i]);

    return oneComplement;
}

string RepresentInteger::toTwoComplement(const string &binary) {
    if (binary[0] == '0')
        return binary;

    string oneComplement = RepresentInteger::toOneComplement(binary);
    oneComplement.erase(oneComplement.begin());
    return '1' + Number::addTwoStrings(oneComplement, "1", 2);
}

string RepresentInteger::complementToDecimal(const string &complement) {
    string sign;
    string binary = complement;

    if (complement[0] == '1') {
        sign = "-";
        binary.erase(binary.begin());
    }

    return sign + RepresentInteger::baseNToDecimal(binary, 2);
}

string RepresentInteger::signMagnitudeToDecimal(string binary) {
    string sign; // positive;

    if (binary[0] == '1')
        sign = "-";

    binary.erase(binary.begin());
    return sign + RepresentInteger::baseNToDecimal(binary, 2);
}

string RepresentInteger::excessKToDecimal(const string &binary, UInt k) {
    return Number::subtractTwoStrings(baseNToDecimal(binary, 2), to_string(k));
}

RepresentInteger::RepresentInteger() : _decimalValue(zero) {}

RepresentInteger::RepresentInteger(const string &value, UInt radix) {
    setValueBaseN(value, radix);
}

RepresentInteger::RepresentInteger(const string &binary, TypeRepresentBinary type, UInt kForOffsetBinary) {
    setValueBinary(binary, type, kForOffsetBinary);
}

void RepresentInteger::setValueBaseN(const string &value, UInt radix) {
    if (RepresentInteger::isValid(value, radix))
        _decimalValue = (radix == 10) ? value : RepresentInteger::baseNToDecimal(value, radix);
    else
        _decimalValue = UNKNOWN_VALUE;
}

void RepresentInteger::setValueBinary(const string &binary, TypeRepresentBinary type, UInt kForOffsetBinary) {
    switch (type) {
        case NORMAL:
            _decimalValue = RepresentInteger::baseNToDecimal(binary, 2);
            break;
        case OFFSET_BINARY:
            _decimalValue = RepresentInteger::excessKToDecimal(binary, kForOffsetBinary);
            break;
        case SIGN_MAGNITUDE:
            _decimalValue = RepresentInteger::signMagnitudeToDecimal(binary);
            break;
        case ONE_COMPLEMENT:
            _decimalValue = RepresentInteger::complementToDecimal(toOneComplement(binary));
            break;
        case TWO_COMPLEMENT:
            _decimalValue = RepresentInteger::complementToDecimal(toTwoComplement(binary));
            break;
        default:
            _decimalValue = UNKNOWN_VALUE;
            break;
    }
}

bool RepresentInteger::isValid(const string &valueBaseN, UInt radix) {
    if (radix < 2 || radix > RepresentInteger::_valueInBase.size())
        return false;

    for (const char &sign : valueBaseN)
        if (ValueInBase::valueOfSign(sign) >= radix)
            return false;

    return true;
}

string RepresentInteger::decimal() const {
    return _decimalValue;
}

string RepresentInteger::decimalRepresentByBinary(TypeRepresentBinary type, UInt kForOffsetBinary) const {
    string binary = valueBaseN(2);

    switch (type) {
        case NORMAL:
            return decimal();
        case OFFSET_BINARY:
            return RepresentInteger::excessKToDecimal(binary, kForOffsetBinary);
        case SIGN_MAGNITUDE:
            return RepresentInteger::signMagnitudeToDecimal(binary);
        case ONE_COMPLEMENT:
            return RepresentInteger::complementToDecimal(toOneComplement(binary));
        case TWO_COMPLEMENT:
            return RepresentInteger::complementToDecimal(toTwoComplement(binary));
        default:
            return UNKNOWN_VALUE;
    }
}

vector<string> RepresentInteger::decimalRepresentByBinaryAllTypes(UInt kForOffsetBinary) const {
    vector<string> listOfBinaryValues(NUMBER_OF_TYPES);

    listOfBinaryValues[0] = decimal();
    listOfBinaryValues[1] = decimalRepresentByBinary(OFFSET_BINARY, kForOffsetBinary);
    listOfBinaryValues[2] = decimalRepresentByBinary(SIGN_MAGNITUDE);
    listOfBinaryValues[3] = decimalRepresentByBinary(ONE_COMPLEMENT);
    listOfBinaryValues[4] = decimalRepresentByBinary(TWO_COMPLEMENT);

    return listOfBinaryValues;
}

string RepresentInteger::valueBaseN(UInt radix) const {
    return RepresentInteger::decimalToBaseN(_decimalValue, radix);
}

string RepresentInteger::convertBaseNToBaseM(const string &valueBaseN, UInt baseN, UInt baseM) {
    string decimal = RepresentInteger::baseNToDecimal(valueBaseN, baseN);
    return RepresentInteger::decimalToBaseN(decimal, baseM);
}
