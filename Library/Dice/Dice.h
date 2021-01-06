#ifndef DICE_H_
#define DICE_H_

#include "Random.h"

class Dice {
	Random _rng; // random number generator.
	int _counts[7] = { 0 };

public:
	// Generate a random integer number on [1, 6].
	int roll();
	
	// Print out all the counts for all the values of one dice.
	void printCountsAllTheValueOfOneDice();
};

#endif