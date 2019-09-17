#ifndef __AVERAGE_H
#define __AVERAGE_H

#include <string>
#include <iostream>

class Average
{
	private:
		double _sum;
		int _values;

	public:
		Average (double sum, int values);
		friend std::ostream& operator<<(ostream& ost, Average& average);
		friend std::istream& operator>>(istream& ist, Average& average);
		Average& operator+=(double value);
}

#endif