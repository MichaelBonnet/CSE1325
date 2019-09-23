#ifndef __COACH_H
#define __COACH_H

class Coach : public Stock
{
	private:
		int _passengers;

	public:
		Coach(double weight);
		void add_passengers(int passengers);
		double weight();
}

#endif