// DayOfWeek.h
#ifndef DAY_OF_WEEK_H
#define DAY_OF_WEEK_H





void inputDate(int &day, int &month, int &year);
void printDayOfWeek(const int &result);
bool isLeapYear(const int &year);
int getCenturyValue(const int &year);
int getYearValue(const int &year);
int getMonthValue(const int &month, const int &year);

#endif