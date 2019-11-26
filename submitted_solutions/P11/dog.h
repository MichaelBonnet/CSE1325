#ifndef __DOG_H
#define __DOG_H

#include "animal.h"
#include "dog_breed.h"
#include <map>
#include <ostream>
#include <iostream>

class Dog : public Animal 
{
	public:
		Dog(Dog_breed breed, std::string name, Gender gender, int age);
		~Dog();
		std::string family() const override;
		std::string breed() const override;
		Dog(std::istream& ist);
        void save(std::ostream& ost) const override;
        void load(std::istream& ist) const override;
		
	private:
		Dog_breed _breed;
};
#endif
