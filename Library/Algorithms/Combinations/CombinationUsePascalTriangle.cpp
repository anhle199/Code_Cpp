// Use Pascal's Triangle.



unsigned long long c[10001][10001] = {0};

// Iterative version.
unsigned long long combination(int n, int k) {
    c[n][0] = c[n][k] = 1;
    c[n][1] = n;

    for (int i = 1; i < n; i++) {
        c[i][0] = 1;
        c[i][1] = i;

        for (int j = 2; j <= k; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }

    return c[n - 1][k - 1] + c[n - 1][k];
}

// Recursive version.
unsigned long long combinationRecursive(int n, int k) {
	if (k == 0 || n == k) {
		c[n][k] = 1;
		return 1;
	}
	if (k == 1) {
		c[n][k] = n;
		return n;
	}

	if (c[n - 1][k - 1] == 0)
		c[n - 1][k - 1] = combinationRecursive(n - 1, k - 1);
	if (c[n - 1][k] == 0)
		c[n - 1][k] = combinationRecursive(n - 1, k);

	return c[n - 1][k - 1] + c[n - 1][k];
}
