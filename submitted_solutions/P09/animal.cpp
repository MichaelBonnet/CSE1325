#include "animal.h"

Animal::Animal(std::string name, Gender gender, int age) : _name{name}, _gender{gender}, _age{age} { }

Animal::~Animal() { }

std::string Animal::name() const 
{
	return _name;
}

Gender Animal::gender() const 
{
	return _gender;
}

int Animal::age() const 
{
	return _age;
}

std::string Animal::to_string() const 
{
	int sex;
	if (_gender == Gender::MALE)
	{
		sex = 0; // men #0
	}
	else if (_gender == Gender::FEMALE)
	{
		sex = 1; // wamen #1
	}
	return _name + ", " + this->family() + ", " + gender_to_string[sex] + ", Age " + std::to_string(this->age()) + ", of breed " + this->breed(); // add breed() and family() eventually
}


std::ostream& operator<<(std::ostream& ost, const Animal& animal) 
{
    ost << animal.to_string();
    return ost;
}

