/*
 * Greatest Common Division (GCD).
 */

/*
 * Euclidean algorithm.
 *
 * gcd(a, b) = gcd(b, a % b).
 * Iterative until (a % b == 0) then result is b.
 */

int GCD(int a, int b) {
    int r; // remainder.

    while (b) { // b != 0
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int GCD_Recursive(int a, int b) {
    if (b == 0)
        return a;
    return GCD_Recursive(b, a % b);
}


// **************************************************************


/*
 * Extended Euclidean algorithm.

 * ax + by = gcd(a, b). (1)
 *
 * bx1 + (a % b)y1 = gcd(b, a % b).  (gcd(a, b) == gcd(b, a % b))
 * Put: a % b = a - (floor(a / b) * b)
 * => bx1 + (a - (floor(a / b) * b))y1 = gcd.
 * <=> ay1 + b(x1 - (floor(a / b) * y1)) = gcd. (2)
 *
 * Compare coefficient of (1) and (2):
 * x = y1.
 * y = (x1 - (floor(a / b) * y1)).
 */

int process(int a, int b, stack<pair<int, int>> &coefficient) {
    int r; // remainder.

    while (b) { // b != 0
        coefficient.push(pair<int, int>(a, b));
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int GCD_Extended(int a, int b, int &x, int &y) {
    stack<pair<int, int>> coefficient;
    int gcd = process(a, b, coefficient);
    int x1 = 1, y1 = 0;


    while (!coefficient.empty()) {
        pair<int, int> item = coefficient.top();
        coefficient.pop();

        x = y1;
        y = x1 - (item.first / item.second) * y1;

        x1 = x;
        y1 = y;
    }

    return gcd;
}

int GCD_ExtendedRecursive(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1;
    int y1;
    int gcd = GCD_ExtendedRecursive(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}


// **************************************************************


/*
 * Least Common Multiple (LCM).
 * LCM(a, b) = (a * b) / GCD(a, b).
 */

int LCM(int a, int b) {
    return (a * b) / GCD(a, b);
}
