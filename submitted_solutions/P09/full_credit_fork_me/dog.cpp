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
	/*
	switch (_breed)
	{
		case Dog_breed::Greyhound:
			return "Greyhound";
			break;
		case Dog_breed::Akita:
			return "Akita";
			break;
		case Dog_breed::CardiganCorgi:
			return "Cardigan Corgi";
			break;
		case Dog_breed::BlueHeeler:
			return "Blue Heeler";
			break;
		case Dog_breed::Chihuahua:
			return "Chihuahua";
			break;
		case Dog_breed::SaintBernard:
			return "Saint Bernard";
			break;
		case Dog_breed::BassetHound:
			return "Basset Hound";
			break;
		case Dog_breed::BlueTick:
			return "Blue Tick";
			break;
	}
	// idk how to really implement this
	*/
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