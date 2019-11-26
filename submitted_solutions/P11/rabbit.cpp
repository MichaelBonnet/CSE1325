#include "rabbit.h"

Rabbit::Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age) : Animal(name, gender, age), _breed{breed} { }

Rabbit::~Rabbit() { };

std::string Rabbit::family() const
{
	return "Rabbit";
}

std::string Rabbit::breed() const
{
	return ::to_string(_breed);
}

std::string to_string(const Rabbit_breed& breed) 
{
	std::map<Rabbit_breed, std::string> breed_to_string
	{
		{Rabbit_breed::CaliforniaWhite, "California White"},
		{Rabbit_breed::ViennaWhite, "Vienna White"},
		{Rabbit_breed::Chinchilla, "Chinchilla"},
		{Rabbit_breed::FlemishGiant, "FlemishGiant"},
		{Rabbit_breed::Rex, "Rex"},
		{Rabbit_breed::Lionhead, "Lionhead"},
		{Rabbit_breed::SilverFox, "Silverfox"},
		{Rabbit_breed::Jackalope, "Jackalope"}
	};
	return breed_to_string[breed];
}

std::ostream& operator<<(std::ostream& ost, const Rabbit_breed& breed)
{
    ost << ::to_string(breed);
    return ost;
}

void Rabbit::save(std::ostream& ost) const
{
	int sex;
	if (_gender == Gender::MALE) sex = 0; // men #0
	else if (_gender == Gender::FEMALE) sex = 1; // wamen #1
	ost << 2 << std::endl << _name << sex << std::endl << _age << std::endl;
}

void Rabbit::load(std::ostream& ost) const
{
	
}