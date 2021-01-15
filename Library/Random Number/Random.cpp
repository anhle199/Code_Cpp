#include "Random.h"

Random::Random() {
	// Initialize a random number generator.
	srand(time(NULL));
}

int Random::next(unsigned int max) {
	return (rand() % max);
}

int Random::next(unsigned int min, unsigned max) {
	return next(max - min + 1) + min;
}