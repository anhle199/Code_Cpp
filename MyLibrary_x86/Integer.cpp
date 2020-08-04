#include "Integer.h"

bool Integer::isPrime(const int& n) {
	if (n < 2)
		return false;

	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;

	return true;
}