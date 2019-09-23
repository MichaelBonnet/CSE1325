#include <iostream>
#include "locomotive.h"
#include "stock.h"

// sets _power and (via delegation to the base constructor) _weight to the parameter values.
// need to figure out delegation to the base constructor.
Locomotive::Locomotive(double weight, double power) : _weight{weight}, _power{power} { }

// returns _power (i.e., a "getter").
double Locomotive::power()
{
	return _power;
}