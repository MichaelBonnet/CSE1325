#include "cat.h"

Cat::Cat(Cat_breed breed, std::string name, Gender gender, int age) : _breed{breed}, Animal(name, gender, age) { }

Cat::~Cat() {};

std::string Cat::family() const
{
	return "Cat";
}

std::string Cat::breed() const
{
	switch (_breed)
	{
		case Cat_breed::DomesticShorthair:
			return "Domestic Shorthair";
			break;
		case Cat_breed::DomesticLonghair:
			return "Domestic Longhair";
			break;
		case Cat_breed::Persian:
			return "Persian";
			break;
		case Cat_breed::MaineCoon:
			return "Maine Coon";
			break;
		case Cat_breed::Siamese:
			return "Siamese";
			break;
		case Cat_breed::RussianBlue:
			return "Russian Blue";
			break;
		case Cat_breed::Abyssinian:
			return "Abyssinian";
			break;
		case Cat_breed::NorweiganForest:
			return "Norweigan Forest";
			break;
	}
}