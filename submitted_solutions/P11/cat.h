#ifndef __CAT_H
#define __CAT_H
#include <map>
#include <ostream>
#include <iostream>

#include "animal.h"
#include "cat_breeds.h"

/*
enum class Cat_breed {DomesticShorthair, DomesticLonghair, Persian, MaineCoon, Siamese, RussianBlue, Abyssinian, NorweiganForest};

constexpr Cat_breed cat_breeds[] = 
{
    Cat_breed::DomesticShorthair,
    Cat_breed::DomesticLonghair,
    Cat_breed::Persian,
    Cat_breed::MaineCoon,
    Cat_breed::Siamese,
    Cat_breed::RussianBlue,
    Cat_breed::Abyssinian, 
    Cat_breed::NorweiganForest,
};

std::string to_string(const Cat_breed& breed);

std::ostream& operator<<(std::ostream& ost, const Cat_breed& breed);
*/

class Cat : public Animal 
{
	public:
		Cat(Cat_breed breed, std::string name, Gender gender, int age);
		~Cat();
		std::string family() const override;
		std::string breed() const override;
		//Cat(std::istream& ist);
        virtual void save(std::ostream& ost);
		
	private:
		Cat_breed _breed;
};
#endif