#include "dog.h"

Dog::Dog(Dog_breed breed, std::string name, Gender gender, int age) : _breed{breed}, Animal(name, gender, age) { }

Dog::~Dog() {};

// error: passing ‘const Animal’ as ‘this’ argument discards qualifiers [-fpermissive]
std::string Dog::family() const
{
	return "Dog";
}

// error: passing ‘const Animal’ as ‘this’ argument discards qualifiers [-fpermissive]
std::string Dog::breed() const
{
	return ::to_string(_breed);
}

std::string to_string(const Dog_breed& breed) 
{
	std::map<Dog_breed, std::string> breed_to_string
	{
		{Dog_breed::Greyhound, "Greyhound"},
		{Dog_breed::Akita, "Akita"},
		{Dog_breed::CardiganCorgi, "Cardigan Corgi"},
		{Dog_breed::BlueHeeler, "Blue Heeler"},
		{Dog_breed::Chihuahua, "Chihuahua"},
		{Dog_breed::SaintBernard, "Saint Bernard"},
		{Dog_breed::BassetHound, "Basset Hound"},
		{Dog_breed::BlueTick, "Blue Tick"}
	};
	return breed_to_string[breed];
}

std::ostream& operator<<(std::ostream& ost, const Dog_breed& breed)
{
    ost << ::to_string(breed);
    return ost;
}

void Dog::save(std::ostream& ost) const
{
	int sex;
	if (_gender == Gender::MALE) sex = 0; // men #0
	else if (_gender == Gender::FEMALE) sex = 1; // wamen #1
	ost << 0 << std::endl << _name << sex << std::endl << _age << std::endl;
}

void Dog::load(std::ostream& ost) const
{
	std::string name;
	int sex;
	int age;
	ist >> name;
	ist >> sex;
	ist >> age;
	
}