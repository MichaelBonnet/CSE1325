#include <iostream>
#include "locomotive.h"

class Locomotive : public Stock
{
	private:
		double _power;

	public:
		Locomotive(double weight, double power);
		double power()
		{
			return _power;
		}
}