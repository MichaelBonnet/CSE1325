#ifndef __STOCK_H
#define __STOCK_H

class Stock
{
	private:
		double _weight;

	protected:
		vector<string> _art;

	public:
		Stock();
		Stock(double weight);
		virtual double weight();
		std::string ascii_art(int row);
}

#endif