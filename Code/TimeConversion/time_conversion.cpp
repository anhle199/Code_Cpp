#include <iostream>
#include <string>

using namespace std;

string timeConversion(string s) {
    /*
     * Write your code here.
     */
    int len = s.length();

    if (s[len - 2] == 'A')
    {
        if (s[0] == '1' && s[1] == '2')
        {
            s[0] = '0';
            s[1] = '0';
        }
    }
    else
    {
        string temp;
        int hour;

        temp += s[0];
        temp += s[1];
        hour = stoi(temp);
        
        if (hour != 12)
        {
            hour += 12;
            temp = to_string(hour);

            s[0] = temp[0];
            s[1] = temp[1];
        }
    }
    
    string s_new = s;
    s_new.pop_back();
    s_new.pop_back();

    return s_new;
}

int main()
{
    string s;
    
    cout << "Enter a time (12 hour format): ";
    getline(cin, s);

    cout << "Time (24 hour format): " << timeConversion(s) << endl;

    return 0;
}