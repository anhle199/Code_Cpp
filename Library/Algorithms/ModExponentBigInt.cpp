// a^b % (10^9 + 7)
// 1 <= a, b <= 10^100000
// a % (10^9 + 7) != 0

// Fermat's Little Theorem: a^(p - 1) === 1 (mod p), p is prime number.
// M = 10^9 + 7
// a^b % M = ((a % M)^b) % M
// Let A = a % m
// A^(m - 1) === 1 (mod m)
// guess: b = (k * (m - 1)) + c, where k = some quotient, c = b % (m - 1).
// For every (m - 1) then A^(m - 1) === 1
// ==> A^b % M = A^c % M

#define ull unsigned long long

ull mod(const string &number, ull max) {
    ull remainder = 0;
    size_t i = 0;

    while (i < 10 && i < number.length())
        remainder = (remainder * 10) + (number[i++] - '0');

    remainder %= max;
    while (i < number.length()) {
        remainder = (remainder * 10) + (number[i++] - '0');
        remainder %= max;
    }

    return remainder;
}

// Complete the solve function below.
int solve(string a, string b) {
    ull res = 1;
    ull x = mod(a, 1000000007);
    ull y = mod(b, 1000000006);
    
    while (b != "0") {
        if ((b.back() - '0') % 2 == 1)
            res = (res * x) % 1000000007;

        x = (x * x) % 1000000007;
        y /= 2;
    }

    return (int)res;
}