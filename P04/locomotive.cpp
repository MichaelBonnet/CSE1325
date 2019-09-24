#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "locomotive.h"
#include "stock.h"

// need to figure out delegation to the base constructor.
Locomotive::Locomotive(double weight, double power) : Stock(80000), _power(13500)
{
	_art = 
	{
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