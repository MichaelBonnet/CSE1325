#include <iostream>
#include <cmath>
#include <string>
#include "locomotive.h"
#include "stock.h"

// need to figure out delegation to the base constructor.
Locomotive::Locomotive(double weight, double power) : Stock{weight}, _power{power}
{
	_art = 
	{ // Locomotive
 		"       * # @ ",
 		"     . ______",
		"   _()_||__||",
		"  ( cse1325 |",
		" /-OO----OO''",
		"#############",
	};
}

double Locomotive::power()
{
	return _power;
}