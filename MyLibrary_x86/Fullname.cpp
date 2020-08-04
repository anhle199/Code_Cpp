#include "Fullname.h"
#include <sstream>

Fullname::Fullname() {

}

Fullname::Fullname(const string& firstName, const string& middleName, const string& lastName) {
	this->_firstName = firstName;
	this->_middleName = middleName;
	this->_lastName = lastName;
}

Fullname::Fullname(const Fullname& fullname) {
	*this = fullname;
}

string Fullname::toString() {
	stringstream writer;

	writer << _firstName << " " << _middleName << " " << _lastName;
	return writer.str();
}

void Fullname::show() {
	cout << this->toString();
}