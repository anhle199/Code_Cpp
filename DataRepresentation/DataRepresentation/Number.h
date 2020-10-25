//
//  Number.h
//  DataRepresentation
//
//  Created by Le Hoang Anh on 10/24/20.
//

#ifndef NUMBER_H_
#define NUMBER_H_

#include <vector>           // Use macro ULLONG_MAX
#include <string>
#include <cstdint>

using namespace std;


typedef uint64_t            UInt64;
typedef int64_t             Int64;
typedef char                Sign;
typedef unsigned int        UInt;
typedef int                 Int;


#define MAX_UINT64          to_string(ULLONG_MAX)
#define MAX_INT64           to_string(LONG_LONG_MAX)
#define UNKNOWN_VALUE       "[Unknown Value]"


const string zero           = "0";
const string one            = "1";


class Number {
    Number() {}

public:
    // Convert '0' to 0, '1' to 1,..., '9' to 9.
    static int digitToInt(char digit);

    // Convert 0 to '0', 1 to '1',..., 9 to '9'.
    static char intToDigit(int number);

    // Check if a number is valid or not.
    static bool isValid(const string &number);

    static bool isZero(const string &number);

    static bool isOddDigit(char digit);

    static bool isEvenDigit(char digit);

    static bool isOdd(const string &number);

    static bool isEven(const string &number);

    static bool isPositive(const string &number);

    static bool isNegative(const string &number);

    // Returns true if `sign` is plus or minus sign; otherwise return false.
    static bool isSign(Sign sign);

    static bool isPlusSign(Sign sign);

    static bool isMinusSign(Sign sign);

    static bool isLessThan(const string &left, const string &right);

    static bool isLessThanOrEqualTo(const string &left, const string &right);

    // Remove a plus sign in the front of `number`.
    // Remove zero numbers in the front of `number`.
    static string format(const string &number);

    // Returns -number.
    static string negate(const string &number);

    static void notOperation(char &digit);

    static string addTwoStrings(const string &left, const string &right, int radix = 10);

    static string subtractTwoStrings(const string &left, const string &right);

    static string multiplyByDigit(const string &str, UInt digit);

    static void incrementByOne(string &number);

    static string multiplyTwoStrings(const string &left, const string &right);

    static string divideTwoStrings(const string &left, const string &right);

    static string moduloTwoStrings(const string &left, const string &right);

};

// Remove all `repeatingValue` values at the beginning of `str` string.
string removePrefix(const string &str, char repeatingValue);

// Remove all `repeatingValue` values at the end of `str` string.
string removeSuffix(const string &str, char repeatingValue);

#endif
