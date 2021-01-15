#define GREATER             1
#define EQUAL               0
#define LESS                -1

#define ULL_MAX_STRING      "18446744073709551615"

string removePrefix(const string &str, char repeatingValue) {
    size_t startIndex = str.find_first_not_of(repeatingValue);

    if (startIndex == 0)
        return str;
    if (startIndex == string::npos)
        return "";

    return str.substr(startIndex, str.length() - startIndex);
}

int compare(const string &lhs, const string &rhs) {
    if (lhs <= ULL_MAX_STRING && rhs <= ULL_MAX_STRING) {
        unsigned long long left = stoull(lhs);
        unsigned long long right = stoull(rhs);

        if (left < right)
            return LESS;
        if (left == right)
            return EQUAL;
        return GREATER;
    }

    if (lhs.length() < rhs.length())
        return LESS;
    if (lhs.length() > rhs.length())
        return GREATER;

    for (int i = 0; i < lhs.length(); i++) {
        if (lhs[i] < rhs[i])
            return LESS;
        if (lhs[i] > rhs[i])
            return GREATER;
    }

    return EQUAL;
}

void incrementByOne(string &number) {
    int carry = 1;
    for (int i = number.length() - 1; i > -1; i--) {
        int sum = (number[i] - '0') + carry;
        carry = sum / 10;
        sum %= 10;

        number[i] = sum + '0';
    }

    if (carry != 0)
        number = (char)(carry + '0') + number;
}

string add(const string &lhs, const string &rhs) {
    if (lhs.length() < rhs.length())
        return add(rhs, lhs);

    int maxLength = lhs.length();
    string sum(maxLength, '0');

    int j = maxLength - 1; // index of lhs
    int carry = 0;
    for (int i = rhs.length() - 1; i > -1; i--, j--) { // i is index of rhs.
        int sumTwoDigits = (lhs[j] - '0') + (rhs[i] - '0') + carry;
        carry = sumTwoDigits / 10;
        sumTwoDigits %= 10;

        sum[j] = sumTwoDigits + '0';
    }

    while (j > -1) {
        int sumTwoDigits = (lhs[j] - '0') + carry;
        carry = sumTwoDigits / 10;
        sumTwoDigits %= 10;

        sum[j] = sumTwoDigits + '0';
        --j;
    }

    if (carry != 0)
        sum = (char)(carry + '0') + sum;

    return sum;
}

string subtract(const string &lhs, const string &rhs) {
    if (lhs.length() < rhs.length())
        return '-' + subtract(rhs, lhs);


    int maxLength = lhs.length();
    string diff(maxLength, '0'); // difference between two numbers.

    int j = maxLength - 1; // index of lhs
    int borrow = 0;
    for (int i = rhs.length() - 1; i > -1; i--, j--) { // i is index of rhs.
        int diffTwoDigits = (lhs[j] - '0') - (rhs[i] - '0') - borrow;

        if (diffTwoDigits < 0) {
            diffTwoDigits += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        diff[j] = diffTwoDigits + '0';
    }

    while (j > -1) {
        int diffTwoDigits = (lhs[j] - '0') - borrow;

        if (diffTwoDigits < 0) {
            diffTwoDigits += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        diff[j] = diffTwoDigits + '0';
        --j;
    }

    diff = removePrefix(diff, '0');

    if (diff.empty())
        return "0";
    return diff;
}

string multiply(const string &lhs, const string &rhs) {
    if (lhs == "0" || rhs == "0")
        return "0";
    if (lhs == "1")
        return rhs;
    if (rhs == "1")
        return lhs;

    string product = "0";
    string tail = "";

    for (int i = lhs.length() - 1; i > -1; i--) {
        if (lhs[i] != '0') {
            string a(rhs.length(), '0');
            int b = 0;

            for (int j = rhs.length() - 1; j > -1; j--) {
                int productTwoDigits = (lhs[i] - '0') * (rhs[j] - '0') + b;

                b = productTwoDigits / 10;
                productTwoDigits %= 10;

                a[j] = productTwoDigits + '0';
            }

            if (b != 0)
                a = (char)(b + '0') + a;

            product = add(product, a + tail);
        }

        tail += "0";
    }

    return product;
}

void divideAndModular(const string &lhs, const string &rhs, string &quotient, string &remainder) {
    if (rhs == "0")
        runtime_error("Error: Division by zero.");

    if (lhs == "0") {
        quotient = "0";
        remainder = "0";
    } else if (rhs == "1") {
        quotient = lhs;
        remainder = "0";
    } else {
        quotient = "0";
        remainder = "0";

        string dividend = lhs;
        while (compare(dividend, rhs) != LESS) {
            dividend = subtract(dividend, rhs);
            incrementByOne(quotient);
        }

        remainder = dividend;
    }
}
