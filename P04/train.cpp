#include <iostream>
#include <cmath>
#include <string>
#include <vector>
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
	double weight, power;

	for (int i = 0; i < _locomotives.size(); i++)
	{
		weight += _locomotives[i]->weight();
		power += _locomotives[i]->power();
	}

	for (int j = 0; j < _coaches.size(); j++)
	{
		weight += _coaches[j]->weight();
	}

	return std::sqrt( 2 * power * ( minutes * 60 ) / weight );

}

std::string Train::to_art()
{
	for (int r = 0; r < 6; r++)
	{
		for (int i = 0; i < Mic_locomotives.size(); i++)
		{
			std::cout << _locomotives[i]->ascii_art(r);
		}
		for (int j = 0; j < _coaches.size(); j++)
		{
			std::cout << _coaches[j]->ascii_art(r);
		}
		std::cout << std::endl;
	}
}