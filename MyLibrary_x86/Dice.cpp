#include "Dice.h"

int Dice::roll() {
	int number = _rng.next(1, 6);
	_counts[number]++;
	
	return number;
}

void Dice::printCountsAllTheValueOfOneDice() {
	for (int i = 1; i < 7; i++)
		cout << "Number " << i << ": " << _counts[i] << " times." << endl;
}