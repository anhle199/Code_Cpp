// Using Sieve of Eratosthenes algorithm.
vector<int> factor(int n) {
    vector<int> smallestPrimeFactor(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (smallestPrimeFactor[i] == 0) {
            smallestPrimeFactor[i] = i;

            for (int j = 2 * i; j <= n; j += i)
                if (smallestPrimeFactor[j] == 0)
                    smallestPrimeFactor[j] = i;
        }
    }

    vector<int> primes;

    while (n != 1) {
        primes.push_back(smallestPrimeFactor[n]);
        cout << smallestPrimeFactor[n] << endl;
        n /= smallestPrimeFactor[n];
    }

    return primes;
}
