#ifndef __DOG_H
#define __DOG_H

#include "animal.h"
#include "dog_breed.h"
#include <map>
#include <ostream>

std::string to_string(const Dog_breed& breed);

std::ostream& operator<<(std::ostream& ost, const Dog_breed& breed);


class Dog : public Animal 
{
	public:
		Dog(Dog_breed breed, std::string name, Gender gender, int age);
		~Dog();
		std::string family() const override;
		std::string breed() const override;
		
	private:
		Dog_breed _breed;
};
#endif
