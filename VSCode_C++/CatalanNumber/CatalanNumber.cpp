#include <iostream>

using namespace std;

int c[25][25] = {0};
int combination(const int &n, const int &k) {
    if (k == 0 || n == k) {
        c[n][k] = 1;
        return 1;
    }

    if (c[n - 1][k - 1] == 0)
        c[n - 1][k - 1] = combination(n - 1, k - 1);
    if (c[n - 1][k] == 0)
        c[n - 1][k] = combination(n - 1, k);

    return c[n - 1][k - 1] + c[n - 1][k];
}

int calculateCatalanNumber(int n)
{
    if (n == 0 || n % 2 == 1)
        return 0;
    
    n /= 2;
    return (combination(2 * n, n) / (n + 1));
}

int main() {
    clock_t start = clock();
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << calculateCatalanNumber(n) << endl;
    cout << (double) (clock() - start) / CLOCKS_PER_SEC << endl;
    return 0;
}

// Số thứ n: (1 / (n + 1)) * (c[2 * n][n])
