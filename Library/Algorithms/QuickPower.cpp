// Calculate the value of a^n.
// Two cases:
// - Case 1: If n is even number, then a^n = (a^2)^(n/2).
// - Case 2: If n is odd number, then a^n = a * (a^2)^((n - 1) / 2).

double quickPower(double a, int n) {
	if (n < 0)
		return 1.0 / quickPower(a, -n);

	double res = 1;
	while (n) {
		if (n % 2 == 1)
			res *= a;

		a *= a;
		n /= 2;
	}

	return res;
}

double quickPowerRecursive(double a, int n) {
	if (n < 0)
		return 1.0 / quickPower(a, -n);

	if (n == 0)
		return 1;
	if (n == 1)
		return a;

	if (n % 2 == 0) // n is even number.
		return quickPowerRecursive(a * a, n / 2);
	return a * quickPowerRecursive(a * a, n / 2); // n is odd number.
}