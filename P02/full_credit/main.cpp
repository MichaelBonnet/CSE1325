// real talk, thought this was due the following thursday.

#include "average.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int choice;

	Average average(0, 0);

	while (choice != 0)
	{
		cout << "    =========================";
		cout << "    Merely Average Calculator";
		cout << "    =========================";
		cout << "The current average is " << average; // think I figured it out
		cout << " ";
		cout << "1 - Enter a new value";
		cout << "2 - Auto enter a random value";
		cout << "9 - Clear the calculator";
		cout << "0 - Exit";
		cout << " ";
		cout << "Command?";
		cin >> choice;
		if (choice == 1)
		{
			cin >> average; // think I figured this one out too
		}
			else if (choice == 2)
			{
				double rand_d = ( rand() % 100 + 1 ); // no idea how to generate a random double between 0.0 and 100.0 inclusive, but whatever lol
				average += rand_d; // think I figured it out
			}
				else if (choice == 9)
				{
					average._sum = 0;
					average._values = 0;
				} 
					else if (choice == 0)
					{
						break;
					}
	}
	cout << "Thank you for playing.";
	return 0;
}