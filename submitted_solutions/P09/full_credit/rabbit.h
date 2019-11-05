#ifndef __RABBIT_H
#define __RABBIT_H

#include "animal.h"
#include "rabbit_breed.h"


class Rabbit : public Animal 
{
	public:
		Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age);
		~Rabbit();
		std::string family() const override;
		std::string breed() const override;
		
	private:
		Rabbit_breed _breed;
};
#endif