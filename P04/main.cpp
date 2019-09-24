#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include "train.h"
#include "stock.h"
#include "locomotive.h"
#include "coach.h"

int main(int argc, char const *argv[])
{
	Train train;

	while(true)
	{
		std::cout << "=========================" << endl;
		std::cout << "   The CSE1325 Express   " << endl;
		std::cout << "=========================" << endl;

		std::cout << train.to_art();

		std::cout << std::setw(11) << "| Minutes  " << std::setw(11) << "|    1     " << std::setw(11) << "|    5     " << std::setw(11) << "|    10   |" << endl;
    	std::cout << std::setw(11) << "|----------" << std::setw(11) << "|----------" << std::setw(11) << "|----------" << std::setw(11) << "|---------|" << endl;
    	std::cout << std::setw(11) << "|   km/h   " << std::setw(15) << train.speed(1) << std::setw(15) << train.speed(5) << train.speed(10) << endl;

		std::cout << "1 - Add a locomotive" << endl;
		std::cout << "2 - Add a coach" << endl;
		std::cout << "9 - Clear the train" << endl;
		std::cout << "0 - Exit" << endl;
		std::cout << " " << endl;
		std::cout << "Command?" << endl;

		std::string s;
        std::getline(std::cin, s);

        try
        {
        	command = std::stoi(s);
        	if (command == 0)
        	{
        		break;
        	}
        		else if (command == 1)
        		{
            		train.add_locomotive(locomotive); // ?
        		}
        			else if (command == 2)
        			{
            			train.add_coach(coach); // ?
        			}
        				else if (command == 9)
        				{
            				train = Train{};
        				}
        					else
        					{
            					std::cerr << "### Invalid command ###\n";
        					}
      	} 
	      	catch (std::invalid_argument e)
	      	{
	            std::cerr << "### Invalid command ###\n";
			}
	}
	return 0;
}