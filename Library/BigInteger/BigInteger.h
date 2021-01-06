// File: BigInteger.h

#ifndef BIG_INTEGER_H_
#define BIG_INTEGER_H_

#include <iostream>
#include <string>

#define POSITIVE 1
#define NEGATIVE 0
#define GREATER_THAN 1
#define LESS_THAN -1
#define EQUAL 0

#pragma pack(1)

using namespace std;

struct BigInteger {
    string data;
    int sign; // 1 nếu là số dương, 0 nếu là số âm.

    BigInteger(); 
};

BigInteger inputBigInteger();
void printBigInteger(const BigInteger &val);

// Gán giá trị truyền vào dưới dạng chuỗi.
bool assign(BigInteger &big_integer, const string &str);

// Gán giá trị truyền vào dưới dạng kiểu long long.
bool assign(BigInteger &big_integer, const long long &val);

/*
 * So sáng giá trị val1 và val2.
 * Trả về 1 nếu val1 > val2.
 * Trả về -1 nếu val1 < val2.
 * Trả về 0 nếu val1 = val2;
 */
int compareTo(const BigInteger &val1, const BigInteger &val2);

// Trả về 1 chuỗi biểu diễn giá trị của biến val.
// Nếu biến val có giá trị không hợp lệ thì trả về chuỗi rỗng.
string toString(const BigInteger &val);

// Tăng giá trị biến val lên thêm n.
// 1 <= n <= 9.
// Nếu n không hợp lệ thì n = 0.
BigInteger increase(BigInteger &val, const int &n);

// Giảm giá trị biến val xuống .
// 1 <= n <= 9.
// Nếu n không hợp lệ thì n = 0.
BigInteger decrease(BigInteger &val, const int &n);

// Trả về 1 giá trị không âm của biến val.
BigInteger absBigInteger(BigInteger val);

// Trả về 1 giá trị là kết quả của phép toán: val1 + val2.
BigInteger add(BigInteger val1, BigInteger val2);

// Trả về 1 giá trị là kết quả của phép toán: val1 - val2.
BigInteger subtract(BigInteger val1, BigInteger val2);

// Trả về 1 giá trị là kết quả của phép toán: val1 * val2.
BigInteger multiply(BigInteger val1, BigInteger val2);

// Trả về 1 giá trị là kết quả của phép toán: val1 / val2.
BigInteger divide(BigInteger val1, BigInteger val2);

// val1, val2 >= 0.
// Trả về 1 giá trị là kết quả của phép toán: val1 % val2.
BigInteger mod(BigInteger val1, BigInteger val2);

// Trả về giá trị của (val)^n.
// Điều kiện n: n >= 0.
BigInteger power(BigInteger val, int n);

// Trả về 1 giá trị là kết quả của val! (giai thừa).
BigInteger factorial(const BigInteger &val);

// Trả về ước chung lớn nhất của 2 số val1 và val2.
BigInteger GCD(BigInteger val1, BigInteger val2);

// Trả về bội chung nhỏ nhất của 2 số val1 và val2.
BigInteger LCM(BigInteger val1, BigInteger val2);

// Trả về 1 giá trị lớn nhất giữa val1 và val2.
BigInteger maxBigInteger(const BigInteger &val1, const BigInteger &val2);

// Trả về 1 giá trị nhỏ nhất giữa val1 và val2.
BigInteger minBigInteger(const BigInteger &val1, const BigInteger &val2);

#endif // End of file BigInteger.h