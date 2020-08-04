#include "FakeName.h"

Fullname FakeName::next() {
	string firstName, middleName, lastName;

	firstName = _listFirstNames[_rng.next(_listFirstNames.size())];
	middleName = _listMiddleNames[_rng.next(_listFirstNames.size())];
	lastName = _listLastNames[_rng.next(_listFirstNames.size())];

	Fullname result(firstName, middleName, lastName);

	return result;
}