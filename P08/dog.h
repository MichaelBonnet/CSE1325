#ifndef __DOG_H
#define __DOG_H

#include "animal.h"
#include "dog_breed.h"


class Dog : public Animal 
{
	public:
		Dog(Dog_breed breed, std::string name, Gender gender, int age);
		~Dog();
		std::string family() override;
		std::string breed() override;
		
	private:
		Dog_breed _breed;
};
#endif
