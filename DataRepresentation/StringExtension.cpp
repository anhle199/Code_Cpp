//
//  StringExtension.cpp
//  DataRepresentation
//
//  Created by Le Hoang Anh on 26/11/2020.
//

#include "StringExtension.h"

string removePrefix(const string &str, char repeatingValue) {
    size_t startIndex = str.find_first_not_of(repeatingValue);

    if (startIndex == 0)
        return str;
    if (startIndex == string::npos)
        return "";

    return str.substr(startIndex, str.length() - startIndex);
}

string removeSuffix(const string &str, char repeatingValue) {
    size_t lastIndex = str.length() - 1;

    for (; lastIndex >= 0; lastIndex--)
        if (str[lastIndex] != repeatingValue)
            break;

    if (lastIndex == -1)
        return str;

    return str.substr(0, lastIndex + 1);
}
