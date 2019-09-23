#include <iostream>
#include <map>
#include "average.h"

int main() {
    std::string student;
    std::map<std::string, Average> students;
    int command;
    char c;
    while(true) {
        std::cout << R"(

    =========================
    Merely Average Calculator
    =========================
)";
        if (students.count(student)) {
            std::cout << student << "'s average is " << students[student] << '\n';
        }
        std::cout << R"(

1 - Enter a new value
2 - Auto enter a random value
5 - Create a new student
6 - Select an existing student
0 - Exit

Command? )";
        std::cin >> command; std::cin.ignore(65535, '\n');
        if(command == 0) {break;
        } else if (command == 1) {
            std::cout << "Value? ";
            std::cin >> students[student]; std::cin.ignore(65535, '\n');
        } else if (command == 2) {
            double d = static_cast<double> (rand()) 
                    / (static_cast<double> (RAND_MAX/100));
            std::cout << "Value is " << d << '\n';
            students[student] += d;
        } else if (command == 5) {
            std::cout << "Enter new student name: ";
            std::getline(std::cin, student);
            if (!students.count(student)) students[student] = Average{};
        } else if (command == 6) {
            std::cout << "Current students:\n";
            for(auto s : students) std::cout << "  " << s.first << '\n';
            while(true) {
                std::cout << "Enter existing student name: ";
                std::getline(std::cin, student);
                if(students.count(student)) break;
                std::cerr << student << " is not currently a student - create (Y/N)? ";
                std::cin >> c; std::cin.ignore(65535, '\n');
                if(toupper(c) == 'Y') {students[student] = Average{}; break;}
            }
        } else {
            std::cerr << "### Invalid command ###\n";
        }
    }      
}
