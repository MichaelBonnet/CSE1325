#include "rabbit.h"

Rabbit::Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age) : _breed{breed}, Animal(name, gender, age) { }

Rabbit::~Rabbit() {};

std::string Rabbit::family() const
{
	return "Rabbit";
}

std::string Rabbit::breed() const
{
	switch (_breed)
	{
		case Rabbit_breed::CaliforniaWhite:
			return "California White";
			break;
		case Rabbit_breed::ViennaWhite:
			return "Vienna White";
			break;
		case Rabbit_breed::Chinchilla:
			return "Chinchilla";
			break;
		case Rabbit_breed::FlemishGiant:
			return "Flemish Giant";
			break;
		case Rabbit_breed::Rex:
			return "Rex";
			break;
		case Rabbit_breed::Lionhead:
			return "Lionhead";
			break;
		case Rabbit_breed::SilverFox:
			return "Silver Fox";
			break;
		case Rabbit_breed::Jackalope:
			return "Jackalope";
			break;
	}
}