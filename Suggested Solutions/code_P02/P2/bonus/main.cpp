#include <iostream>
#include <vector>
#include "average.h"

int main() {
    std::vector<Average> students {Average{}};
    int student{0};
    int command;
    while(true) {
        std::cout << R"(

    =========================
    Merely Average Calculator
    =========================
)";
        if (0 <= student && student < students.size()) {
            std::cout << "The current  student  is " << student << '\n'
                      << "The student's average is " << students[student] << '\n';
        }
        std::cout << R"(

1 - Enter a new value
2 - Auto enter a random value
5 - Create a new student
6 - Select an existing student
0 - Exit

Command? )";
        std::cin >> command;
        if(command == 0) {break;
        } else if (command == 1) {
            std::cout << "Value? ";
            std::cin >> students[student];
        } else if (command == 2) {
            double d = static_cast<double> (rand()) 
                    / (static_cast<double> (RAND_MAX/100));
            std::cout << "Value is " << d << '\n';
            students[student] += d;
        } else if (command == 5) {
            students.push_back(Average{});
            student = students.size() - 1;
        } else if (command == 6) {
            std::cout << "Enter student number (0 to " 
                      << students.size() - 1 << ")? ";
            std::cin >> student;
            if (student < 0) student = 0;
            if (student > students.size() - 1) student = students.size() - 1;
        } else {
            std::cerr << "### Invalid command ###\n";
        }
    }      
}
