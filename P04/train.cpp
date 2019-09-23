#include <iostream>
#include "train.h"

void Train::add_locomotive(Locomotive& locomotive)
{
	_locomotives.push_back(&locomotive);
}

void Train::add_coach(Coach& coach)
{
	 _coaches.push_back(&coach);
}

double Train::speed(double minutes)
{
	return std::sqrt(2*power*(minutes*60)/weight);
}

string Train::to_art()
{
	// code
}