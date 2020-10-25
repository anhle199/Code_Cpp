//
//  RepresentInteger.h
//  DataRepresentation
//
//  Created by Le Hoang Anh on 10/24/20.
//

#ifndef REPRESENT_NUMBER_H_
#define REPRESENT_NUMBER_H_

//#pragma pack(1)

#include <vector>
#include <sstream>
#include <iomanip>
#include "Number.h"


#define NUMBER_OF_TYPES     5
enum TypeRepresentBinary    { NORMAL, OFFSET_BINARY, SIGN_MAGNITUDE, ONE_COMPLEMENT, TWO_COMPLEMENT };


struct ValueInBase {
    char sign; // sign in base n.
    UInt value; // decimal value of sign.

    void setValue(char c);
    static UInt valueOfSign(char sign);
};


class RepresentInteger {
    string _decimalValue;

    static const vector<ValueInBase> _valueInBase;

    static vector<ValueInBase> initTableValueInBase();

    static string decimalToBaseN(string decimal, UInt radix);

    static string toOneComplement(const string &binary);
    static string toTwoComplement(const string &binary);

    static string baseNToDecimal(const string &value, UInt radix);
    static string complementToDecimal(const string &binary);
    static string signMagnitudeToDecimal(string binary);
    static string excessKToDecimal(const string &binary, UInt k);
    
public:
    RepresentInteger();
    RepresentInteger(const string &value, UInt radix);
    RepresentInteger(const string &binary, TypeRepresentBinary type = NORMAL, UInt kForOffsetBinary = 0);

    void setValueBaseN(const string &value, UInt radix);
    void setValueBinary(const string &binary, TypeRepresentBinary type = NORMAL, UInt kForOffsetBinary = 0);

    static bool isValid(const string &valueBaseN, UInt radix);

    string decimal() const;

    string decimalRepresentByBinary(TypeRepresentBinary type = NORMAL, UInt kForOffsetBinary = 0) const;

    // index of type is value of type of TypeRepresentBinary.
    vector<string> decimalRepresentByBinaryAllTypes(UInt kForOffsetBinary = 0) const;

    // if radix is 2, binary is normal type.
    string valueBaseN(UInt radix) const;

    static string convertBaseNToBaseM(const string &valueBaseN, UInt baseN, UInt baseM);
};

#endif
