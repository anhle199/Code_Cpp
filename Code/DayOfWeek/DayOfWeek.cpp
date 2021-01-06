// DayOfWeek.cpp
#include "DayOfWeek.h"
#include <iostream>

using namespace std;

void inputDate(int &day, int &month, int &year)
{
    cout << "Enter a date (day, month, year): ";
    cin >> day >> month >> year;
}

void printDayOfWeek(const int &result)
{
    switch (result)
    {
        case 0:
            cout << "Sunday." << endl;
            break;
        case 1:
            cout << "Monday." << endl;
            break;
        case 2:
            cout << "Tuesday." << endl;
            break;
        case 3:
            cout << "Wednesday." << endl;
            break;
        case 4:
            cout << "Thursday." << endl;
            break;
        case 5:
            cout << "Friday." << endl;
            break;
        case 6:
            cout << "Saturday." << endl;
            break;
    }
}

bool isLeapYear(const int &year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

int getCenturyValue(const int &year)
{
    int r = (year / 100) % 4; // r is remainder
    return (2 * (3 - r));
}

int getYearValue(const int &year)
{
    int q = (year % 100) / 4; // q is quotient
    return (q + (year % 100));
}

int getMonthValue(const int &month, const int &year)
{
    bool is_leap_year = isLeapYear(year);

    switch (month)
    {
        case 1:
        case 10:
            if (is_leap_year == true && month == 1)
                return 6;
            return 0;
        case 5:
            return 1;
        case 8:
            return 2;
        case 2:
        case 3:
        case 11:
            if (is_leap_year == true && month == 2)
                return 2;
            return 3;
        case 6:
            return 4;
        case 9:
        case 12:
            return 5;
        case 4: case 7:
            return 6;
    }
}