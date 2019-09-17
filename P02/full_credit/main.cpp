#include average.h
#include <string>
#include <iostream>
using namespace std

int main(int argc, char const *argv[])
{
	int choice;

	Average average(0, 0);

	while (choice != 0)
	{
		cout << "    =========================";
		cout << "    Merely Average Calculator";
		cout << "    =========================";
		cout << "The current average is " << average.operator<<();
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
			average.operator>>
		}
	}
	return 0;
}