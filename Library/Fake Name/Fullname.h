#ifndef FULL_NAME_H_
#define FULL_NAME_H_

#include <iostream>
#include <string>

using namespace std;

class Fullname {
	string _firstName, _middleName, _lastName;

public:
	Fullname();
	Fullname(const string& firstName, const string& middleName, const string& lastName);
	Fullname(const Fullname& fullname);

	string toString();
	void show();
};

#endif