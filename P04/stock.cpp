#include <iostream>
#include <cmath>
#include <string>
#include "stock.h"

// initialization list to set _weight to NaN. 2 is outside range of arcsin so it returns nan.
Stock::Stock() : _weight{asin(2);} { }

// initialization list to set _weight to parameter
Stock::Stock(double weight) : _weight{weight} { } 

//  returns the total weight of the carriage, which is the empty weight plus the weight of any cargo, e.g., human passengers.
virtual double Stock::weight() 
{                              
	return _weight;
}

std::string Stock::ascii_art(int row) // returns the indicated row of text in the ASCII art representation of the carriage.
{
	return _art[row];
}
