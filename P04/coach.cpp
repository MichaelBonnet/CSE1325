#include <iostream>
#include "coach.h"

class Coach : public Stock
{
	private:
		int _passengers;

	public:
		Coach(double weight);
		void add_passengers(int passengers);
		double weight();
}