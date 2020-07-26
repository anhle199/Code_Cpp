#include "Date.h"

void inputDate(ifstream &in, Date &date) {
    in >> date.year >> date.month >> date.day;
}

void inputDateArray(ifstream &in, Date dates[], int &n) {
    in >> n;

    for (int i = 0; i < n; i++)
        inputDate(in, dates[i]);
}

void outputDate(ofstream &out, const Date &date) {
    out << date.year << " ";

    if (date.month % 10 == date.month) // If month < 10, add 0 to the front.
        out << 0;
    out << date.month << " ";

    if (date.day % 10 == date.day) // If day < 10, add 0 to the front.
        out << 0;
    out << date.day << " " << endl;
}

void outputDateArray(ofstream &out, Date dates[], const int &n) {
    for (int i = 0; i < n; i++)
        outputDate(out, dates[i]);
}

int compare(const Date &date1, const Date & date2) {
    if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
        return 0;
    else {
        if (date1.year > date2.year)
            return 1;
        else if (date1.year == date2.year && date1.month > date2.month)
            return 1;
        else if (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day)
            return 1;
    }

    return -1;
}

void sortArrayAscending(Date dates[], const int &n) {
    int pos;

    for (int i = 0; i < n - 1; i++) {
        pos = i;

        for (int j = i + 1; j < n; j++)
            if (compare(dates[pos], dates[j]) == 1)
                pos = j;

        swap(dates[i], dates[pos]);
    }
}