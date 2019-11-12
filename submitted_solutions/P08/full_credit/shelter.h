#ifndef __SHELTER_H
#define __SHELTER_H
#include "dog.h"
#include <vector>
#include "animal.h"

class Shelter 
{
	public:
		Shelter(std::string name);
		std::string name();
		void add_animal(Animal& animal);
		int num_animals();
		Animal& animal(int index);
		
	private:
		std::string _name;
		std::vector<Animal*> _available;
};
#endif
