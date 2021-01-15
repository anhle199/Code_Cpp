// Time complexity: O(nlog(log(n)))
// Space complexity: O(n)
vector<int> sieveEratosthenes(int n) {
	vector<bool> isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i])
			if ((long long)i * (long long)i <= n) // check overflow.
				for (int j = i * i; j <= n; j += i)
					isPrime[j] = false;
	}

	vector<int> primes;
	for (int i = 2; i <= n; i++)
		if (isPrime[i])
			primes.push_back(i);

	return primes;
}
