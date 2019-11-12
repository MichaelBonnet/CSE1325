#ifndef __AVERAGE_H
#define __AVERAGE_H

class Average
{
	public:
		Average ();
		friend std::ostream& operator<<(std::ostream& ost, const Average& average);
		friend std::istream& operator>>(std::istream& ist, Average& average);
		Average& operator+=(double value);

	private:
		double _sum;
		int _values;
};

#endif