#include <iostream>
#include <cmath>
#include <string>
#include <vector>
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
		std::cout << "=========================" << std::endl;
		std::cout << "   The CSE1325 Express   " << std::endl;
		std::cout << "=========================" << std::endl;

		std::cout << train.to_art();

		std::cout << std::setw(11) << "| Minutes  " << std::setw(11) << "|    1     " << std::setw(11) << "|    5     " << std::setw(11) << "|    10   |" << std::endl;
    	std::cout << std::setw(11) << "|----------" << std::setw(11) << "|----------" << std::setw(11) << "|----------" << std::setw(11) << "|---------|" << std::endl;
    	std::cout << std::setw(11) << "|   km/h   " << std::setw(15) << train.speed(1) << std::setw(15) << train.speed(5) << train.speed(10) << std::endl;

		std::cout << "1 - Add a locomotive" << std::endl;
		std::cout << "2 - Add a coach" << std::endl;
		std::cout << "9 - Clear the train" << std::endl;
		std::cout << "0 - Exit" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "Command?" << std::endl;

		std::string s;
        std::getline(std::cin, s);

        try
        {
        	int command = std::stoi(s);
        	if (command == 0)
        	{
        		break;
        	}
        		else if (command == 1)
        		{
            		train.add_locomotive( *(new Locomotive(80000, 13500)) ); // ?
        		}
        			else if (command == 2)
        			{
            			train.add_coach( *(new Coach(18000)) ); // ?
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