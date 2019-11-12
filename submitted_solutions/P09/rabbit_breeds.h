#ifndef __RABBIT_BREEDS_H
#define __RABBIT_BREEDS_H

#include "animal.h"

enum class Rabbit_breed
{
	CaliforniaWhite, 
	ViennaWhite, 
	Chinchilla, 
	FlemishGiant, 
	Rex, 
	Lionhead, 
	SilverFox, 
	Jackalope
};

constexpr Rabbit_breed rabbit_breeds[] = 
{
    Rabbit_breed::CaliforniaWhite,
    Rabbit_breed::ViennaWhite,
    Rabbit_breed::Chinchilla,
    Rabbit_breed::FlemishGiant,
    Rabbit_breed::Rex,
    Rabbit_breed::Lionhead,
    Rabbit_breed::SilverFox, 
    Rabbit_breed::Jackalope,
};

std::string to_string(const Rabbit_breed& breed);

std::ostream& operator<<(std::ostream& ost, const Rabbit_breed& breed);

#endif