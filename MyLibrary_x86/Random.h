#ifndef RANDOM_H_
#define RANDOM_H_

#define MAX_RANDOM_NUMBER	65536

#include <iostream>
#include <ctime>

using namespace std;

class Random {
public:
	Random();

	// Generate a random integer number on [0, max - 1].
	int next(unsigned int max = MAX_RANDOM_NUMBER);

	// Generate a random integer number on [min, max].
	int next(unsigned int min, unsigned max);
};

#endif