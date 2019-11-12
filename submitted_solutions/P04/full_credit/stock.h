#ifndef __STOCK_H
#define __STOCK_H

#include <vector>
#include <string>
#include <iostream>

class Stock
{
	private:
		// the empty weight of the carriage, in kilograms. For carriages that carry cargo,
		// e.g., a coach, the weight of the cargo is tracked separately.
		double _weight; 

	protected:
		// vector of strings forming ASCII art[#]_ that visually represents a derived carriage
		std::vector<std::string> _art;

	public:
		// initializes _weight to NAN ("not a number") from <cmath>.
		Stock(); 

		// initializes _weight to the parameter.
		Stock(double weight);

		// returns the total weight of the carriage, which is the empty weight plus the weight of any cargo, e.g., human passengers.
		virtual double weight();

		// returns the indicated row of text in the ASCII art representation of the carriage.
		std::string ascii_art(int row);
};

#endif