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
		Average (); // maybe removing parameters will help since there seems to be disagreement
		friend std::ostream& operator<<(std::ostream& ost, const Average& average); // tried removing const because "read-only"
		friend std::istream& operator>>(std::istream& ist, Average& average); // tried removing const because "read-only"
		Average& operator+=(double value); // --ahhh gotta relate it to average-- std onto average?
};

#endif