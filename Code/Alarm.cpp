#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    short dem_giay(0), b, phut, giay;
    //bien b dung de kiem tra dieu kien tai sau khi het 1 phut
    cout << "Nhap vao so phut: ";
    cin >> phut;
    cout << "Nhap vao so giay: ";
    cin >> giay;
    b = giay;

    system("cls");

    while (1)
    {
        Sleep(1000);

        if (phut == 0 && giay == 0)
        {
            cout << "00:00 Reng reng reng\a";
            break;
        }

        else if (phut == 0)
        {
            if (0 < giay && giay <= 5)
            {
                cout << "00:0" << giay << " Tich tac\a" << endl;
                giay--;
            }

            else if (giay < 10)
            {
                cout << "00:0" << giay << endl;
                giay--;
            }

            else
            {
                cout << "00:" << giay << endl;
                giay--;
            }
        }

        else if (phut < 10)
        {
            if (giay < 10)
            {
                cout << "0" << phut << ":0" << giay << endl;
                giay--;
            }

            else
            {
                cout << "0" << phut << ":" << giay << endl;
                giay--;
            }
        }

        else
        {
            if (giay < 10)
            {
                cout << phut << ":0" << giay << endl;
                giay--;
            }

            else
            {
                cout << phut << ":" << giay << endl;
                giay--;
            }
        }

        dem_giay++;
        if ((dem_giay == b + 1) && (phut > 0))
        {
            dem_giay = 0;
            phut--;
            b = 59;
            giay = 59;
        }
    }

    return 0;
}
