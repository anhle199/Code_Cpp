#include <iostream>

#define cost_1km_dau 15
#define cost_tu_2km_den_5km 13.5
#define cost_tu_6km 11

using namespace std;

int main()
{
    int km, a, b, c;
    double total_money, discount(1);

    cout << "Nhap so km ban da di (so duong): ";
    cin >> km;

    a = km;
    b = km - 1;
    c = km - 5;

    if (km > 120) { discount = 0.9; a = 1; b = 4; }
    else if (km > 5) { a = 1; b = 4; }
    else if (km > 1) { a = 1; c = 0; }
    else { b = 0; c = 0; }

    total_money = discount * ((a * cost_1km_dau) + (b * cost_tu_2km_den_5km) + (c * cost_tu_6km));

    cout << "Tien taxi cua quy khach sau " << km << "km la: " << total_money << " dong." << endl;

    return 0;
}