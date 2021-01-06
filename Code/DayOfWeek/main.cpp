// main.cpp
#include "DayOfWeek.h"

int main()
{
    int day, month, year, result;

    inputDate(day, month, year);

    result = (day + getCenturyValue(year) + getYearValue(year) + getMonthValue(month, year)) % 7;
    
    printDayOfWeek(result);

    return 0;
}