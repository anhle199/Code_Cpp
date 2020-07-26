#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <fstream>

using namespace std;

struct Date {
    int day, month, year;
};

void inputDate(ifstream &in, Date &date);
void inputDateArray(ifstream &in, Date dates[], int &n);
void outputDate(ofstream &out, const Date &date);
void outputDateArray(ofstream &out, Date dates[], const int &n);

/*
 * Returns 1 if date1 > date2.
 * Returns -1 if date1 < date2.
 * Returns 0 if date1 = date2.
 */
int compare(const Date &date1, const Date & date2);

// Sort the array in ascending order.
void sortArrayAscending(Date dates[], const int &n);

#endif