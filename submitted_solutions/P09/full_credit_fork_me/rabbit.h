#ifndef __RABBIT_H
#define __RABBIT_H
#include <map>
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

class Rabbit : public Animal 
{
	public:
		Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age);
    	virtual ~Rabbit();
    	virtual std::string family() const override;
    	virtual std::string breed() const override;
	private:
    	Rabbit_breed _breed;
};

#endif