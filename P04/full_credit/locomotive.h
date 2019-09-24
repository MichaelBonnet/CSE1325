#ifndef __LOCOMOTIVE_H
#define __LOCOMOTIVE_H

#include <vector>
#include <string>
#include <iostream>
#include "stock.h"

class Locomotive : public Stock
{
	private:
		// the rating for the engine in kilowatts. More power can pull more weight faster.
		double _power;

	public:
		// sets _power and (via delegation to the base constructor) _weight to the parameter values.
		Locomotive(double weight, double power);

		// returns _power (i.e., a "getter").
		double power();
};

#endif