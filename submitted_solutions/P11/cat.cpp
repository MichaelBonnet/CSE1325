#include "cat.h"

Cat::Cat(Cat_breed breed, std::string name, Gender gender, int age) : Animal(name, gender, age), _breed{breed} { }

Cat::~Cat() { };

std::string Cat::family() const
{
	return "Cat";
}

std::string Cat::breed() const
{
	return ::to_string(_breed);
}

std::string to_string(const Cat_breed& breed) 
{
	std::map<Cat_breed, std::string> breed_to_string
	{
		{Cat_breed::DomesticShorthair, "Domestic Shorthair"},
		{Cat_breed::DomesticLonghair, "Domestic Longhair"},
		{Cat_breed::Persian, "Persian"},
		{Cat_breed::MaineCoon, "Maine Coon"},
		{Cat_breed::Siamese, "Siamese"},
		{Cat_breed::RussianBlue, "Russian Blue"},
		{Cat_breed::Abyssinian, "Abyssinian"},
		{Cat_breed::NorweiganForest, "Norweigan Forest"}
	};
	return breed_to_string[breed];
}

std::ostream& operator<<(std::ostream& ost, const Cat_breed& breed)
{
    ost << ::to_string(breed);
    return ost;
}

void Cat::save(std::ostream& ost) 
{
	int sex;
	if (_gender == Gender::MALE) sex = 0; // men #0
	else if (_gender == Gender::FEMALE) sex = 1; // wamen #1
	ost << 1 << std::endl << _name << sex << std::endl << _age << std::endl;
}

void Cat::load(std::ostream& ost)
{
	
}