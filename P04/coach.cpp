#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "coach.h"
#include "stock.h"

// need to figure out delegation to the base constructor.
Coach::Coach(double weight) : Stock(18000) 
{
	_art = 
	{ // Coach
		"               ",
		" ______________",
		" | [] [] [] []|",
		" |            |",
		"='OO--------OO'",
		"###############"
	};
}

void Coach::add_passengers(int passengers)
{
	_passengers += passengers;
	if ( _passengers > 120 ) { std::cout << "Exception: Too many passengers (more than 120). " << std::endl; }
}

double Coach::weight()
{
	return weight() + (_passengers * 60);
}