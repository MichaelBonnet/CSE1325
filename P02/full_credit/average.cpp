#include "average.h"

Average::Average(double sum, int values) : _sum(0), _values(0) {};

std::ostream& operator<<(std::ostream& ost, Average& average)
{
	if (average._values == 0)
	{
		{ost << "UNDEFINED";}
	}
	else
	{
		// double average = (average._sum / average._values); not working?
		ost << (average._sum / average._values);
	}
	return ost;
}
		
std::istream& operator>>(std::istream& ist, Average& average)
{
	// int inc = 1;
	double val;
	ist >> val;
	average._sum += val;
	// average._values += inc;
	average._values += 1;
}

Average& operator+=(double value)
{
	int inc = 1;
	_sum += value;
	_values += inc;
}

// do I need a destructor?