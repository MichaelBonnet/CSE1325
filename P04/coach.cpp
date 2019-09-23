#include <iostream>
#include "coach.h"
#include "stock.h"

// need to figure out delegation to the base constructor.
Coach::Coach(double weight) : Stock{weight} { }

void Coach::add_passengers(int passengers)
{
	_passengers += passengers;
	if ( _passengers > 120 ) { cout << "Exception: Too many passengers (more than 120). " << endl; }
}

virtual double Coach::weight()
{
	return _weight + (_passengers * 60);
}