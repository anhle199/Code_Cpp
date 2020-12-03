//
//  Operation.h
//  DataRepresentation
//
//  Created by Le Hoang Anh on 26/11/2020.
//

#ifndef OPERATION_H_
#define OPERATION_H_

#include "Number.h"
#include "StringExtension.h"

class Operation {
    Operation() {}
    
public:
    static string addTwoStrings(const string &left, const string &right, int radix = 10);

    static string subtractTwoStrings(const string &left, const string &right);

    static string multiplyByDigit(const string &str, UInt digit);

    static void incrementByOne(string &number);

    static string multiplyTwoStrings(const string &left, const string &right);

    static string divideTwoStrings(const string &left, const string &right);

    static string moduloTwoStrings(const string &left, const string &right);
};

#endif
