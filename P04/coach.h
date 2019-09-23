#ifndef __COACH_H
#define __COACH_H

class Coach : public Stock
{
	private:
		// the number of passengers currently in the Coach.
		int _passengers;

	public:
		// the constructor, which sets _weight (via delegation to the base constructor) to the parameter.
		Coach(double weight);

		//  adds its parameters to _passengers. If the resulting number of passengers exceeds 120, thrown an exception.
		void add_passengers(int passengers);

		// overrides Stock::weight(), returning the empty weight of the carriage plus the weight of the
		// passengers. Each passenger weighs 60 kilograms.
		double weight();
}

#endif