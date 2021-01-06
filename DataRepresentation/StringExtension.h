//
//  StringExtension.h
//  DataRepresentation
//
//  Created by Le Hoang Anh on 26/11/2020.
//

#ifndef STRING_EXTENSION_H_
#define STRING_EXTENSION_H_

#include <string>

using namespace std;

// Remove all `repeatingValue` values at the beginning of `str` string.
string removePrefix(const string &str, char repeatingValue);

// Remove all `repeatingValue` values at the end of `str` string.
string removeSuffix(const string &str, char repeatingValue);

#endif
