// Michael Bonnet and Benjamin Lemke

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Line
{
	private:

		double _x1, _y1, _x2, _y2;

	public:
	
		Line(double x1, double y1, double x2, double y2): _x1{x1}, _y1{y1}, _x2{x2}, _y2{y2}
			{

			}
		~Line(double x1, double y1, double x2, double y2); _x1{x1}, _y1{y1}, _x2{x2}, _y2{y2}
			{

			}

		string to_string()
			{
				string string_x1 = std::to_string(_x1);
				string string_y1 = std::to_string(_y1);
				string string_x2 = std::to_string(_x2);
				string string_y2 = std::to_string(_y2);
				string string_format = "(" + string_x1 + "," + string_y1 + ")-(" + string_x2 + "," + string_y2 + ")";
				return string_format;
			};

		double length(double x1, double y1, double x2, double y2)
			{
				double output_length = sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );
				return output_length;
			};
}