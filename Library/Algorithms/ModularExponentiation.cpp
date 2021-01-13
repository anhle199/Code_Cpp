// Calculate the value of: x^y % n.
// Calculate above value by using "quick power" to calculate x^y.

// x, y and n is integer number.
// y greater than or equal to 0.

int modExponent(int x, int y, int n) {
	int res = 1;

	x %= n;
	while (y) {
		if (y % 2 == 1)
			res = (res * x) % n;

		x = (x * x) % n;
		y /= 2;
	}

	return res;
}

int modExponentRecursive(int x, int y, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return modExponentRecursive(x * x, y / 2, n) % n;
	return ((x % n) * (modExponentRecursive(x * x, y / 2, n) % n)) % n;
}