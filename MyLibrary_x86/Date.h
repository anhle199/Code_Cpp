#ifndef DATE_H_
#define DATE_H_

#include <string>

using namespace std;

class Date {
	unsigned int _day, _month, _year;

public:
	// Initialize with current date.
	Date();

	// Initialize with day, month, year.
	Date(int, int, int);

	// Output in this format "dd/mm/yyyy".
	string toString();

	// Convert a string like "dd/mm/yyyy" into date.
	static Date parse(string);

	static bool tryParse(string, Date&);

	static bool isValid(string);

	static bool isLeapYear(int);

	static bool checkDay(int, int, int);

	static bool checkMonth(int);

	static bool checkYear(int);

	static int getNumberOfDaysInMonth(int, int);

	static int getCurrentYear();

	static int getCurrentMonth();

	static int getCurrentDay();
};

#endif