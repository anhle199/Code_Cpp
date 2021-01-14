// Using Sieve of Eratosthenes algorithm.
vector<Factor> factor(int n) {
	vector<int> smallestPrimeFactor(n + 1, -1);
	smallestPrimeFactor[0] = 0;
	smallestPrimeFactor[1] = 1;

	for (int i = 2; i * i <= n; i++) {
		if (smallestPrimeFactor[i] == -1)
			for (int j = i * i; j <= n; j += i)
				smallestPrimeFactor[j] = i;
	}

	vector<int> primes;

	while (n) { // n != 0
		primes.push_back(smallestPrimeFactor[n]);
		n /= smallestPrimeFactor[n];
	}

	return primes;
}