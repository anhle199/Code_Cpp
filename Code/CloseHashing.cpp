// Assuming, the hash table is not full.

int linearProbing(Data* hashTable, int value, int tableSize) {
	int hashValue = hash(value);
	int pos = hashValue % tableSize;

	while (!hashTable[pos].isNonValue())
		pos = (pos + 1) % tableSize;

	return pos;
}

int quadraticProbing(Data* hashTable, int value, int tableSize) {
	int hashValue = hash(value);
	int pos;

	hashValue %= tableSize
	for (unsigned long long i = 0; i <= INT_MAX; i++)
		pos = (hashValue + (i * i) % tableSize) % tableSize;

	return pos;
}

int doubleHashing(Data* hashTable, int value, int tableSize) {
	int firstHashValue = hash(value);
	int secondHashValue = secondHash(value, tableSize);
	int pos;

	for (unsigned long long i = 0; i <= INT_MAX; i++)
		pos = (firstHashValue + i * secondHashValue) % tableSize;

	return pos;
}

bool isPrime(int n) {
	if (n < 2)
		return false;

	int sqrtN = sqrt(n);
	for (int i = 2; i < sqrtN; i++)
		if (n % i == 0)
			return false;

	return true;
}

int secondHash(int value, int tableSize) {
	int primeNumber = tableSize - 1;

	if (primeNumber % 2 == 0)
		--primeNumber;

	if (primeNumber > 1) {
		while (!isPrime(primeNumber) && primeNumber > 2)
			primeNumber -= 2;

		if (primeNumber == 1)
			primeNumber = 2;
	}

	return primeNumber - (value % primeNumber);
}
