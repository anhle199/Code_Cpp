// Thời gian thực hiện 2 cách không chênh lệch nhiều
#ifndef MY_QUICK_POWER
#define MY_QUICK_POWER

// --------------------------------------
// Phần khai báo

double quickPower(double a, long n);
double quickPowerRecursive(double a, long n); // Đệ qui (cách này dễ hiểu hơn, vẫn giống cách ở trên)

// --------------------------------------
// Phần cài đặt

double quickPower(double a, long n)
{
    if (n < 0)
        return 1 / quickPower(a, -n);

    double result = 1;

    while (n)
    {
        if (n % 2 == 1)
            result *= a;
        
        a *= a;
        n /= 2;
    }

    return result;
}

double quickPowerRecursive(double a, long n)
{
    if (n < 0)
        return 1 / quickPowerRecursive(a, -n);

    if (n == 0)
        return 1;
    
    if (n == 1)
        return a;

    if (n % 2 == 0)
        return quickPowerRecursive(a * a, n / 2);
    
    return a * quickPowerRecursive(a * a, n / 2);
}

#endif