#include <iostream>
#include "train.h"

class Train
{
	private:
		vector<Locomotive*> _locomotives;
		vector<Coach*> _coaches;

	public:
		void add_locomotive(Locomotive& locomotive);
		void add_coach(Coach& coach);
		double speed(double minutes);
		string to_art();
}