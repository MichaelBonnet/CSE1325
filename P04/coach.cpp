#include <iostream>
#include "coach.h"
#include "stock.h"

// constructor, which sets _weight (via delegation to the base constructor) to the parameter.
// need to figure out delegation to the base constructor.
Coach::Coach(double weight)
{
	// code
}

// adds its parameters to _passengers. If the resulting number of passengers exceeds 120, throw an exception.
void Coach::add_passengers(int passengers)
{
	_passengers += passengers;
	if ( _passengers > 120 ) { cout << "Exception: Too many passengers (more than 120). " << endl; }
}

// overrides Stock::weight(), returning the empty weight of the carriage plus the weight of 
// the passengers. Each passenger weighs 60 kilograms.
virtual double Coach::weight()
{
	return _weight + (_passengers * 60);
}