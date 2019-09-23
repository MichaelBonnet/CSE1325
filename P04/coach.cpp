#include <iostream>
#include "coach.h"

Coach::Coach(double weight)
{
	// code
}

void add_passengers(int passengers)
{
	_passengers += passengers;
}

double weight()
{
	return _weight + (_passengers * 60);
}