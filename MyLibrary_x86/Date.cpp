#include "Date.h"
#include <ctime>

const int dayInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date() {
	time_t info = time(nullptr);
	tm* now = new tm;

	localtime_s(now, &info);

	_day = now->tm_mday;
	_month = now->tm_mon + 1;
	_year = now->tm_year + 1900;

	delete now;
}

Date::Date(int day, int month, int year) {
	this->_year = (Date::checkYear(year)) ? year : 1900;
	this->_month = (Date::checkMonth(this->_month)) ? month : 1;
	this->_day = (Date::checkDay(day, this->_month, this->_year)) ? day : 1;
}

string Date::toString() {
	string date;

	date = ((_day < 10) ? "0" : "") + to_string(_day) + "/";
	date += ((_month < 10) ? "0" : "") + to_string(_month) + "/";
	date += to_string(_year);

	return date;
}

Date Date::parse(string str) {
	Date dt(1, 1, 1);

	if (Date::isValid(str)) {
		int day = stoi(str.substr(0, 2));
		int month = stoi(str.substr(3, 2));
		int year = stoi(str.substr(6)); // 6 to the end of string.

		dt = Date(day, month, year);
	}

	return dt;
}

bool Date::tryParse(string str, Date& dt) {
	return true;
}

bool Date::isValid(string str) {
	if (str.length() < 7)
		return false;


	// check day, month (before converting into numbers) and two slashes.
	for (int i = 0; i < 6; i += 3) {
		if (!isdigit(str[i]) && !isdigit(str[i + 1]))
			return false;
		if (str[i + 2] != '/')
			return false;
	}

	// check year (before converting into number).
	for (int i = 6; i < str.length(); i++)
		if (!isdigit(str[i]))
			return false;

	
	int day = stoi(str.substr(0, 2));
	int month = stoi(str.substr(3, 2));
	int year = stoi(str.substr(6)); // 6 to the end of string.

	// check day, month, year (after converting numbers).
	if (Date::checkYear(year) == false || Date::checkMonth(month) == false ||
		Date::checkDay(day, month, year) == false) {

		return false;
	}

	return true;
}

bool Date::isLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool Date::checkDay(int day, int month, int year) {
	int maxDay = Date::getNumberOfDaysInMonth(month, year);

	if (maxDay == -1)
		return false;

	return (1 <= day && day <= maxDay);
}

bool Date::checkMonth(int month) {
	return (1 <= month && month <= 12);
}

bool Date::checkYear(int year) {
	return (year > 0);
}

int Date::getNumberOfDaysInMonth(int month, int year) {
	if (Date::checkYear(year) == false && Date::checkMonth(month) == false)
		return -1;

	int maxDay = dayInMonth[month - 1];

	if (Date::isLeapYear(year) == true && month == 2)
		maxDay = 29;

	return maxDay;
}

int Date::getCurrentYear() {
	Date currentDate;
	return currentDate._year;
}

int Date::getCurrentMonth() {
	Date currentDate;
	return currentDate._month;
}

int Date::getCurrentDay() {
	Date currentDate;
	return currentDate._day;
}