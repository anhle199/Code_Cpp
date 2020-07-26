#include <iostream>
#include <iomanip>

using namespace std;

// Hình vuông cạnh a (a là số lẻ) bị rỗng bên trong được ghép lại từ 4 tam giác vuông cân
void hinh_1(const int &a);

int main()
{
    int a;

    cout << "Nhap vao do dai canh hinh vuong (so le): ";
    cin >> a;

    hinh_1(a);
    
    return 0;
}

void hinh_1(const int &a)
{
    int half_of_the_stars(a / 2), number_of_spaces(1);

    // In dòng đầu tiên
    for (int i = 0; i < a; i++)
        cout << "* ";
    cout << endl;
    
    // In dòng thứ 2 đến dòng ((a / 2) - 1)
    for (int i = 0; i < (a / 2) - 1; i++) // i là số dòng
    {
        for (int j = 0; j < half_of_the_stars; j++)
            cout << "* ";

        for (int j = 0; j < number_of_spaces; j++)
            cout << "  ";

        for (int j = 0; j < half_of_the_stars; j++)
            cout << "* ";
        
        cout << endl;
        
        number_of_spaces += 2;
        half_of_the_stars--;
    }

    // In dòng (a / 2)
    cout << "*" << setw(2 * (a - 1)) << right << "*" << endl;

    // In dòng thứ ((a / 2) - 1) đến dòng (a - 1)
    for (int i = 0; i < (a / 2) - 1; i++) // i là số dòng
    {
        half_of_the_stars++;
        number_of_spaces -= 2;

        for (int j = 0; j < half_of_the_stars; j++)
            cout << "* ";

        for (int j = 0; j < number_of_spaces; j++)
            cout << "  ";

        for (int j = 0; j < half_of_the_stars; j++)
            cout << "* ";
        
        cout << endl;
    }

    // In dòng cuối
    for (int i = 0; i < a; i++)
        cout << "* ";
    cout << endl;
}