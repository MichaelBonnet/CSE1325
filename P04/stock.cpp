#include <iostream>
#include <cmath>
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
	switch(row)
	{
		case 1:
			// stuff
			break;
		case 2:
			// stuff
			break;
		case 3:
			// stuff
			break;
		case 4:
			// stuff
			break;
		case 5:
			// stuff
			break;
		case 6:
			// stuff
			break;
	}

}
