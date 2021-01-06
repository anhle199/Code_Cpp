// Ngày thứ 256 trong năm
// 1700 <= year <= 2700
// 1700 --> 1917 (Julian calendar), từ 1919 trở đi (Gregorian calendar), 1918 (sau ngày 31/1 là ngày 14/2)
// Leap Year: julian calendar (chia hết 4), gregorian calendar ((chia hết 4 và không chia hết 100) hoặc (chia hết 400))
#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(const int &year) {
    if (year < 1918 && year % 4 == 0)
        return true;
    else if (year > 1918)
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) 
            return true;

    return false;
}

string dayOfProgrammer(int year) {
    if (year == 1918) return "26.09.1918";
    else if (isLeapYear(year)) {
            return "12.09." + to_string(year);
    } else return "13.09." + to_string(year);
}

int main() 
{
    int year;
    cout << "Enter a year: ";
    cin >> year;
    
    cout << "Day of programmer is: " << dayOfProgrammer(year) << endl;

    return 0;
}