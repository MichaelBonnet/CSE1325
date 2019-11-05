#ifndef __CAT_H
#define __CAT_H

#include "animal.h"
#include "cat_breed.h"


class Cat : public Animal 
{
	public:
		Cat(Cat_breed breed, std::string name, Gender gender, int age);
		~Cat();
		std::string family() const override;
		std::string breed() const override;
		
	private:
		Cat_breed _breed;
};
#endif