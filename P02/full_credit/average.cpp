#include "average.h"

Average::Average(): _sum{0}, _values{0} {};
std::ostream& operator<<(ostream& ost, Average& average)
{
	if (average._values == 0)
	{
		{ost << "UNDEFINED";}
	}
	else
	{
		double average = (average._sum / average._values);
		ost << average;
	}
	return ost;
}
		
std::istream& operator>>(istream& ist, Average& average)
{
	int inc = 1;
	double val;
	ist >> val;
	average._sum += val;
	average._values += inc;
}

Average& operator+=(double value)
{
	int inc = 1;
	_sum += value;
	_values += inc;
}