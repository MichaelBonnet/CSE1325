#include <iostream>
#include "locomotive.h"
#include "stock.h"

// need to figure out delegation to the base constructor.
Locomotive::Locomotive(double weight, double power) : Stock{weight}, _power{power} { }

double Locomotive::power()
{
	return _power;
}