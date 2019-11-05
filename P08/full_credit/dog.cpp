#include "dog.h"

Dog::Dog(Dog_breed breed, std::string name, Gender gender, int age) : _breed{breed}, Animal(name, gender, age) { }

Dog::~Dog() {};

// error: passing ‘const Animal’ as ‘this’ argument discards qualifiers [-fpermissive]
std::string Dog::family()
{
	return "dog";
}

// error: passing ‘const Animal’ as ‘this’ argument discards qualifiers [-fpermissive]
std::string Dog::breed()
{
	// idk how to really implement this
}

