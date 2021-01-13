// Time complexity: O(nlog(log(n)))
// Space complexity: O(n)
vector<bool> sieveEratosthenes(int n) {
	vector<bool> primes(n + 1, true);
	primes[0] = primes[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (primes[i])
			if ((long long)i * (long long)i <= n) // check overflow.
				for (int j = i * i; j <= n; j += i)
					primes[j] = false;
	}

	return primes;
}