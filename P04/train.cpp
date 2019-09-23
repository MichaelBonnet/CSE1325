#include <iostream>
#include "train.h"

class Train
{
	private:
		vector<Locomotive*> _locomotives;
		vector<Coach*> _coaches;

	public:
		void add_locomotive(Locomotive& locomotive)
		{
			_locomotives.push_back(&locomotive);
		}
		void add_coach(Coach& coach)
		{
			 _coaches.push_back(&coach);
		}
		double speed(double minutes)
		{
			return std::sqrt(2*power*(minutes*60)/weight);
		}
		string to_art();
}