#ifndef __LOCOMOTIVE_H
#define __LOCOMOTIVE_H

class Locomotive : public Stock
{
	private:
		double _power;

	public:
		Locomotive(double weight, double power);
		double power();
}

#endif