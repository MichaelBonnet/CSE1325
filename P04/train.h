#ifndef __TRAIN_H
#define __TRAIN_H

#include <vector>
#include <string>
#include <iostream>
#include "stock.h"
#include "coach.h"
#include "locomotive.h"

class Train
{
	private:
		// a vector of pointers to instances of Locomotive.
		std::vector<Locomotive*> _locomotives;

		// a vector of pointers to instances of Coach.
		std::vector<Coach*> _coaches;

	public:
		// pushes a pointer to the parameter onto _locomotives.
		void add_locomotive(Locomotive& locomotive);

		// pushes a pointer to the parameter onto _coaches.
		void add_coach(Coach& coach);

		// returns the maximum speed the train can reach from a standing start in
		// the number of minutes specified by the parameter.
		double speed(double minutes);

		//  returns a complete string representation of the train as ASCII art.
		std::string to_art();
};

#endif