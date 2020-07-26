#include <iostream>

#define COLSIZE 199

using namespace std;

void upper_half_1(int matrix[][COLSIZE], const int &n);
void lower_half_1(int matrix[][COLSIZE], const int &n);
void upper_half_2(int matrix[][COLSIZE], const int &n);
void lower_half_2(int matrix[][COLSIZE], const int &n);

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int matrix[n][COLSIZE];

    cout << "Nhap cac phan tu cua ma tran:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }

    // test
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         matrix[i][j] = n;

    cout << "\nNua tren cua ma tran(dua vao duong cheo chinh):" << endl;
    upper_half_1(matrix, n);

    cout << "\nNua duoi cua ma tran (dua vao duong cheo chinh):" << endl;
    lower_half_1(matrix, n);

    cout << "\nNua tren cua ma tran (dua vao duong cheo phu):" << endl;
    upper_half_2(matrix, n);

    cout << "\nNua duoi cua ma tran (dua vao duong cheo phu):" << endl;
    lower_half_2(matrix, n);

    return 0;
}

void upper_half_1(int matrix[][COLSIZE], const int &n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << "  ";

        for (int j = i; j < n; j++)
            cout << matrix[i][j] << " ";
        
        cout << endl;
    }
}

void lower_half_1(int matrix[][COLSIZE], const int &n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j =  0; j < i + 1; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void upper_half_2(int matrix[][COLSIZE], const int &n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void lower_half_2(int matrix[][COLSIZE], const int &n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
            cout << "  ";
        
        for (int j = n - i - 1; j < n; j++)
            cout << matrix[i][j] << " ";
        
        cout << endl;
    }
}