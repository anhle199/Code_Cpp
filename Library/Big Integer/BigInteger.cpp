// File: BigInteger.cpp
// Cài đặt những hàm được khai báo bên trong file BigInteger.h

#include "BigInteger.h"
#include <algorithm>

// -------------------------------------
// Những hàm trong struct

BigInteger::BigInteger() {
    data = "";
    sign = POSITIVE;
}

// -------------------------------------
// Những hàm viết thêm, không khai báo trong BigInteger.h

BigInteger formatBigInteger(BigInteger val, const bool &is_input = false) {
    int count_minus = 0;

    if (val.data.length() < 1)
        return val;
    
    if (is_input) {
        bool is_zero = true;

        for (string::iterator it = val.data.begin(); it != val.data.end(); it++) {
            if (*it == '+') { // Xóa những dấu cộng.
                val.data.erase(it);
                it--;
            } else if (*it == '-') { // Đếm số dấu - để xác định là số âm hay dương và xóa tất cả dấu trừ đó.
                count_minus++;
                val.data.erase(it);
                it--;
            } else if (*it != '0') {
                is_zero = false;
                break;
            }
        }

        // Truờng hợp nó là 00000... hoặc -0000.....
        if (is_zero)
            val.data = "0";
    }

    if (val.data != "0") {
        // Xoá những số 0 bị thừa. Ex: -06035 ==> -6035
        for (string::iterator it = val.data.begin(); it != val.data.end(); it++) {
            if ('1' <= (*it) && (*it) <= '9') // Đã hết số 0 thừa thì dùng ngay.
                break;
            else { // result.data[i] == '0' , và những số 0 này là số 0 thừa.
                val.data.erase(it);
                it--;
            }
        }
    }

    // Xác định có là số âm hay không.
    if (val.data != "0" && count_minus % 2 == 1)
        val.sign = NEGATIVE;

    return val;
}

void formatLengthOfNumber(BigInteger &val1, BigInteger &val2) {
    int len1 = val1.data.length(), len2 = val2.data.length();
    
    // Nếu độ dài 2 số không bằng nhau thì thêm 1 dãy số 0 vào phía trước số nhỏ hơn.
    if (len1 < len2) {
        for (int i = 0; i < (len2 - len1); i++)
            val1.data.insert(val1.data.begin(), '0');
    } else if (len2 < len1) {
        for (int i = 0; i < (len1 - len2); i++)
            val2.data.insert(val2.data.begin(), '0');
    }
}

bool isDigit(const char &c) {
    if ('0' <= c && c <= '9')
        return true;
    return false;
}

bool checkInputBigInteger(const BigInteger &val) {
    int len = val.data.length(), i;
    bool invalid_value = false;
    
    if (len < 1)
        return false;

    for (i = 0; i < len; i++) {
        if (val.data[i] == '+' || val.data[i] == '-') {
            if (i == len - 1)
                invalid_value = true;
        } else { // Trường hợp khác toán tử + và -
            if (!isDigit(val.data[i])) // Trường hợp không phải là toán hạng.
                invalid_value = true;
            
            break;
        }
    }

    if (invalid_value) 
        return false;
    
    for (int j = i; i < len; i++)
        if (!isDigit(val.data[i]))
            return false;

    return true;
}

string subString(const string &str, const int &begin, const int &end) {
    string result;

    for (int i = begin; i < end; i++)
        result += str[i];

    return result;
}

int sumOrMinusTwoDigits(const int &val1, const int &val2, int &temp, const char &__operator) {
    int result;

    if (__operator == '+') {
        result = val1 + val2 + temp; // Cộng thêm phần dư của phép cộng lần trước.
        temp = result / 10; // phần dư của phép cộng 2 số.
        result %= 10;
    } else if (__operator == '-') {
        if (val1 >= (val2 + temp)) {
            result = val1 - (val2 + temp);    
            temp = 0;
        } else {
            result = (val1 + 10) - (val2 + temp);
            temp = 1;
        }
    }

    return result;
}

BigInteger productOfBigIntegerAndDigit(const BigInteger &val, const int &digit) {
    int temp = 0, product, len = val.data.length();
    BigInteger result;

    if (val.data.length() < 1)
        result.data = "";
    else {
            if (digit == 0) {
            result.data = "0";
        } else if (digit == 1) {
            result = val;
        } else {
            for (int i = len - 1; i > -1; i--) {
                product = digit * (val.data[i] - '0') + temp;
                temp = product / 10;
                product %= 10;
                result.data.insert(result.data.begin(), (char)(product + '0'));
            }

            if (temp > 0)
                result.data.insert(result.data.begin(), (char)(temp + '0'));
        }
    }
    
    return result;
}

// -------------------------------------

// -------------------------------------
// Những hàm được khai báo trong BigInteger.h

BigInteger inputBigInteger() {
    BigInteger result;
    bool invalid_value;

    do {
        cout << "Enter big integer: " ;
        cin >> result.data;

        invalid_value = false;
        if (!checkInputBigInteger(result)) {
            invalid_value = true;
            cout << "Invalid value!" << endl;
        }

    } while (invalid_value);
    
    result = formatBigInteger(result, true);

    return result;
}

void printBigInteger(const BigInteger &val) {
    // Đối với hàm này không cần dùng hàm formatBigInteger trước khi in.
    // Vì khi nhập vào hay thực hiện xong 1 phép toán đã có format sẵn.
    
    if (val.sign == NEGATIVE)
        cout << "(-" << val.data << ")";
    else
        cout << val.data;
}

int compareTo(const BigInteger &val1, const BigInteger &val2) {
    int len1 = val1.data.length(), len2 = val2.data.length();

    if (val1.data == val2.data && val1.sign == val2.sign)
        return EQUAL;
    else if (val1.sign == NEGATIVE && val2.sign == NEGATIVE) {
        if (len1 < len2)
            return GREATER_THAN;
        else if (len2 < len1)
            return LESS_THAN;

        for (int i = 0; i < len1; i++) {
            if (val1.data[i] < val2.data[i])
                return GREATER_THAN;
            else if (val1.data[i] > val2.data[i])
                return LESS_THAN;
        }    
    } else if (val1.sign == NEGATIVE) {
        return LESS_THAN;
    } else if (val2.sign == NEGATIVE) {
        return GREATER_THAN;
    } else {
        if (len1 > len2)
            return GREATER_THAN;
        else if (len1 < len2) 
            return LESS_THAN;
        
        for (int i = 0; i < len1; i++) {
            if (val1.data[i] > val2.data[i])
                return GREATER_THAN;
            else if (val1.data[i] < val2.data[i])
                return LESS_THAN;
        }    
    }
}

bool assign(BigInteger &big_integer, const string &str) {
    BigInteger temp;
    temp.data = str;

    if (!checkInputBigInteger(temp))
        return false;

    big_integer = formatBigInteger(temp);
    return true;
}

bool assign(BigInteger &big_integer, const long long &val) {
    big_integer.data = to_string(val);
    return true;
}

string toString(const BigInteger &val) {
    if (val.sign == NEGATIVE)
        return ("-" + val.data);
    return val.data;
}

BigInteger increase(BigInteger &val, const int &n) {
    if (val.data.length() < 1) {
        BigInteger dummy;
        return dummy;
    } else if (n < 1 || n > 9)
        return val;
    else if (val.sign == POSITIVE) {
        int sum, temp = 0, len = val.data.length(), i = len - 1;

        sum = sumOrMinusTwoDigits(val.data[i] - '0', n, temp, '+');
        val.data[i] = (char)(sum + '0');
        i--;

        while (i > -1 && temp > 0) {
            sum = sumOrMinusTwoDigits(val.data[i] - '0', 0, temp, '+');
            val.data[i] = (char)(sum + '0');
            i--;
        }

        if (temp > 0)
            val.data.insert(val.data.begin(), (char)(temp + '0'));
    } else { // sign = NEGATIVE
        BigInteger n_big_integer;

        n_big_integer.data += (char)(n + '0'); // Mặc định thì sign = POSITIVE.
        val = subtract(val, n_big_integer);
    }

    return val;
}

BigInteger decrease(BigInteger &val, const int &n) {
    if (val.data.length() < 1) {
        BigInteger dummy;
        return dummy;
    } else if (n < 1 || n > 9)
        return val;
    else if (val.sign == POSITIVE) {
        BigInteger n_big_integer;

        n_big_integer.data += (char)(n + '0');
        val = subtract(val, n_big_integer);
    } else { // sign = NEGATIVE
        val.sign = POSITIVE;
        val = increase(val, n);
        val.sign = NEGATIVE;
    }

    return val;
}

BigInteger absBigInteger(BigInteger val) {
    BigInteger dummy;

    if (val.data.length() < 1)
        return dummy;
    else if (val.sign == NEGATIVE)
        val.sign = POSITIVE;

    return val;
}

BigInteger add(BigInteger val1, BigInteger val2) {
    BigInteger result;
    int temp = 0, sum, len;

    if (val1.data.length() < 1 || val2.data.length() < 1)
        result.data = "";
    else {
        if (val1.data == "0")
            return val2;
        else if (val2.data == "0")
            return val1;
        else {
            if (val1.sign == NEGATIVE && val2.sign == NEGATIVE)
                result.sign = NEGATIVE;
            else if (val1.sign == NEGATIVE)
                return subtract(val2, val1);
            else if (val2.sign == NEGATIVE)
                return subtract(val1, val2);

            formatLengthOfNumber(val1, val2);
            len = val1.data.length();

            for (int i = len - 1; i > -1; i--) {
                // Tính tổng 2 giá trị thẳng hàng (cùng vị trí) và số dư của tổng trước đó.
                sum = sumOrMinusTwoDigits(val1.data[i] - '0', val2.data[i] - '0', temp, '+');
                // Chèn phần đơn vị của giá trị vừa tính được vào đầu biến result.
                result.data.insert(result.data.begin(), (char)(sum + '0')); 
            }

            if (temp > 0)
                result.data.insert(result.data.begin(), (char)(temp + '0'));
        }
    }

    return result;
}

BigInteger subtract(BigInteger val1, BigInteger val2) {
    BigInteger result;

    if (val1.data.length() < 1 || val2.data.length() < 1)
        result.data = "";
    else {
        if (compareTo(val1, val2) == EQUAL) {
            result.data = "0";
            return result;
        }
        else if (val1.data == "0") {
            if (val2.sign == POSITIVE)
                val2.sign = NEGATIVE;
            else 
                val2.sign = POSITIVE;
            
            return val2;
        } else if (val2.data == "0") {
            return val1;
        } else {
            int temp = 0, minus, len;

            if (val1.sign == NEGATIVE && val2.sign == NEGATIVE) {
                val2.sign = POSITIVE;
                swap(val1, val2);
            } else if (val1.sign == NEGATIVE ||val1.sign == NEGATIVE) {
                if (val1.sign == NEGATIVE)
                    result.sign = NEGATIVE;

                result = add(val1, val2);
                return result;
            }

            if (compareTo(val1, val2) == LESS_THAN) {
                swap(val1.data, val2.data);
                result.sign = NEGATIVE;        
            }

            formatLengthOfNumber(val1, val2);
            len = val1.data.length();

            for (int i = len - 1; i > -1; i--) {
                minus = sumOrMinusTwoDigits(val1.data[i] - '0', val2.data[i] - '0', temp, '-');
                result.data.insert(result.data.begin(), (char)(minus + '0'));
            }

            // Xóa những số 0 bị thừa và dấu "-" thừa.
            result = formatBigInteger(result);
        }
    }
    
    return result;
}

BigInteger multiply(BigInteger val1, BigInteger val2) {
    BigInteger result, temp, sum;
    int len;
    
    if (val1.data.length() < 1 || val2.data.length() < 1)
        result.data = "";
    else {
        if (val1.data == "0" || val2.data == "0")
            result.data = "0";
        else {
            if (val1.sign == NEGATIVE && val2.sign == NEGATIVE)
                result.sign == POSITIVE;
            else if (val1.sign == NEGATIVE || val2.sign == NEGATIVE)
                result.sign = NEGATIVE;

            if (val1.data.length() < val2.data.length())
                swap(val1.data, val2.data);
            
            sum.data = "0";
            len = val2.data.length();

            for (int i = len - 1; i > -1; i--) {
                temp = productOfBigIntegerAndDigit(val1, val2.data[i] - '0');
                    
                for (int j = len - 1; j > i; j--)
                    temp.data += '0';

                sum = add(sum, temp);
            }

            result.data = sum.data;
        }
    }

    return result;
}

BigInteger divide(BigInteger val1, BigInteger val2) {
    BigInteger result;
    int count = 0;
    
    if (val1.data.length() < 1 || val2.data.length() < 1)
        result.data = "";
    else {
        if (val1.sign == NEGATIVE && val2.sign == NEGATIVE)
            result.sign = POSITIVE;
        else if (val1.sign == NEGATIVE || val2.sign == NEGATIVE)
            result.sign = NEGATIVE;

        if (val2.data == "0"); // Không thực hiện gì cả.
        else if (val1.data == "0" || compareTo(val1, val2) == LESS_THAN) { // val1 = 0 hoặc abs(val1) < abs(val2)
            result.data = "0";
            result.sign = POSITIVE;
        } else if (compareTo(val1, val2) == EQUAL) // abs(val1) = abs(val2)
            result.data = "1";
        else if (val2.data == "1") // abs(val2) = 1
            result.data = val1.data;
        else { // abs(val1) > abs(val2)
            do {
                val1 = subtract(val1, val2);
                count++;
            } while (compareTo(val1, val2) >= EQUAL); // ">= EQUAL" is greater than or equal

            result.data = to_string(count);
        }
    }

    return result;
}

BigInteger mod(BigInteger val1, BigInteger val2) {
    BigInteger temp;
    
    if (val1.data.length() < 1 || val2.data.length() < 1)
        return temp;
    else if (val1.sign == NEGATIVE || val2.sign == NEGATIVE)
        return temp;
    
    //-------------------------------------

    if (val2.data == "1"); // Không thực hiện gì cả.
    else if (val2.data == "0")
        val1.data = "";
    else if (val1.data == "0" || compareTo(val1, val2) == EQUAL) // val1 = 0 hoặc val1 = val2
        val1.data = "0";
    else if (compareTo(val1, val2) == GREATER_THAN) { // val1 > val2
        do {
            val1 = subtract(val1, val2);
        } while (compareTo(val1, val2) >= EQUAL);
    }

    return val1;
}

BigInteger power(BigInteger val, int n) {
    BigInteger result, temp;

    result.data = "1";
    temp.data = "1";

    if (val.data.length() < 1 && n < 0)
        return result;
    else if (val.data == "0")
        return val;
    else if ((val.data == "1") || (n == 0)) {
        if ((val.sign == NEGATIVE) && (n % 2 == 1))
            temp.sign = NEGATIVE;
        
        return temp;
    } else {
        if (val.sign == NEGATIVE) {
            if (n % 2 == 1)
                result.sign = NEGATIVE;
            
            val.sign = POSITIVE;
        }

        while (n) {
            if (n % 2 == 1)
                temp = multiply(temp, val);

            val = multiply(val, val);
            n /= 2;
        }

        result.data = temp.data;
    }

    return result;
}

BigInteger factorial(const BigInteger &val) {
    BigInteger result, i;

    if (val.data.length() < 1)
        return result;
    else if (val.sign == POSITIVE && assign(i, 2) == true && assign(result, 1) == true) {
        for ( ; compareTo(i, val) <= EQUAL; increase(i, 1))
            result = multiply(result, i);
    }

    return result;
}

BigInteger GCD(BigInteger val1, BigInteger val2) {
    BigInteger remainder;

    if (val1.data.length() < 1 || val2.data.length() < 1)
        return remainder;
    else if (val1.data == "0") {
        val2.sign = POSITIVE;
        return val2;
    } else if (val2.data == "0") {
        val1.sign = POSITIVE;
        return val1;
    } else {
        if (val1.sign == NEGATIVE) val1.sign = POSITIVE;
        if (val2.sign == NEGATIVE) val2.sign = POSITIVE;

        while (val2.data != "0") {
            remainder = mod(val1, val2);
            val1.data = val2.data;
            val2.data = remainder.data;
        }

        return val1;
    }
}

BigInteger LCM(BigInteger val1, BigInteger val2) {
    BigInteger dummy, gcd;

    if (val1.data.length() < 1 || val2.data.length() < 1)
        return dummy;
    else if (val1.sign == NEGATIVE || val2.sign == NEGATIVE)
        return dummy;
    else if (val1.data == "0" || val2.data == "0") {
        dummy.data = "0";
        return dummy;
    } else {
        gcd = GCD(val1, val2);
        return (divide(multiply(val1, val2), gcd));
    }
}

BigInteger maxBigInteger(const BigInteger &val1, const BigInteger &val2) {
    if (compareTo(val1, val2) >= EQUAL)
        return val1;
    return val2;
}

BigInteger minBigInteger(const BigInteger &val1, const BigInteger &val2) {
    if (compareTo(val1, val2) <= EQUAL)
        return val1;
    return val2;
}

// -------------------------------------
// End of file BigInteger.cpp