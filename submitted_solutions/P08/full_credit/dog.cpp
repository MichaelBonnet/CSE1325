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
}

