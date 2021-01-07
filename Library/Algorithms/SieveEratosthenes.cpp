// In các số nguyên tố từ 2 đến n bằng phương pháp sàng Eratosthenes
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void sieveEratosthenes(vector<bool> &checkPrimes, int &n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (checkPrimes[i])
            for (int j = i * i; j < n + 1; j += i)
                checkPrimes[j] = false;
}

int main()
{
    int n;

    cout << "Nhap n = ";
    cin >> n;

    vector<bool> checkPrimes(n + 1, true);
    sieveEratosthenes(checkPrimes, n);
    
    cout << "Cac so nguyen to tu 2 den n la: ";
    for (int i = 2; i < n + 1; i++)
        if (checkPrimes[i])
            cout << i << " ";
    cout << endl;

    return 0;
}