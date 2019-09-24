#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char const *argv[])
{
	std::cout << std::setw(11) << "| Minutes  " << std::setw(11) << "|    1     " << std::setw(11) << "|    5     " << std::setw(11) << "|    10   |" << std::endl;
    std::cout << std::setw(11) << "|----------" << std::setw(11) << "|----------" << std::setw(11) << "|----------" << std::setw(11) << "|---------|" << std::endl;
    std::cout << std::setw(11) << "|   km/h   " << std::setw(15) << 1 << std::setw(15) << 3 << 3 << std::endl;
	return 0;
}