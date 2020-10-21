#include <iostream>
#include <set>

using namespace std;

int demSoChuoiCon(const string &s)
{
    set<string> result;
    string temp;
    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        temp += s[i];
        result.insert(temp);

        for (int j = i + 1; j < len; j++)
        {
            temp += s[j];
            result.insert(temp);
        }

        temp = "";
    }

    return result.size();
}

int main()
{
    string str;

    cout << "Nhap vao 1 chuoi: ";
    getline(cin, str);

    cout << "So luong chuoi con cua chuoi la: " << demSoChuoiCon(str) << endl;

    return 0;
}