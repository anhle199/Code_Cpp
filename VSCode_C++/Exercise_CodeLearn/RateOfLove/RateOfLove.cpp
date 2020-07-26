#include <iostream>
#include <vector>
#include <string>

using namespace std;

int rateOfLove(std::vector<std::string> name)
{
    vector<int> count_alphabet(26, 0);
    vector<bool> check_alphabet(26, false);
    string number, result;
    int index, len, sum;

    // Đếm số lần xuất hiện của kí trong tên.
    for (string &str : name)
        for (char &ch : str)
        {
            if (ch == ' ')
                continue;
            else if ('A' <= ch && ch <= 'Z')
                ch += 32;
            
            count_alphabet[ch - 'a']++;
        }

    // Tạo thành dãy số theo đề bài.
    for (string &str : name)
        for (char &ch : str)
            if (ch != ' ')
            {
                index = ch - 'a';

                if (check_alphabet[index] == true)
                    continue;
                
                number += to_string(count_alphabet[index]);
                check_alphabet[index] = true;
            }

    len = number.length();
    // Biến đổi dãy số theo yêu cầu để bài đến khi được số thỏa mãn.
    while (len > 3 || (stoi(number) > 100))
    {
        len--;

        for (int i = 0; i < len; i++)
        {
            sum = (number[i] + number[i + 1] - (2 * '0'));
            result += ((sum % 10) + '0');
        }

        number = result;
        result = "";
    }

    return stoi(number);
}

int main()
{
    vector<string> name(2);

    cout << "Nhap ten nguoi dau tien: ";
    getline(cin, name[0]);

    cout << "Nhap ten nguoi thu hai: ";
    getline(cin, name[1]);

    cout << "Ti le hai nguoi yeu nhau la: ";
    cout << rateOfLove(name) << "%" << endl;

    system("pause");
    return 0;
}