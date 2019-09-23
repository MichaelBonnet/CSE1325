#include <iostream>
#include "average.h"

int main() {
    Average average;
    int command;
    while(true) {
        std::cout << R"(

    =========================
    Merely Average Calculator
    =========================
The current average is )"
            << average << R"(

1 - Enter a new value
2 - Auto enter a random value
9 - Clear the calculator
0 - Exit

Command? )";
        std::string s;
        std::getline(std::cin, s);
      try {
        command = std::stoi(s);
        if(command == 0) {break;
        } else if (command == 1) {
            std::cout << "Value? ";
            std::cin >> average;
        } else if (command == 2) {
            double d = static_cast<double> (rand()) 
                    / (static_cast<double> (RAND_MAX/100));
            std::cout << "Value is " << d << '\n';
            average += d;
        } else if (command == 9) {
            average = Average{};
        } else {
            std::cerr << "### Invalid command ###\n";
        }
      } catch(std::invalid_argument e) {
            std::cerr << "### Invalid command ###\n";
      }
    }      
}
