#ifndef __RABBIT_H
#define __RABBIT_H
#include <map>
#include <iostream>
#include "animal.h"
#include "rabbit_breeds.h"

class Rabbit : public Animal 
{
	public:
		Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age);
    	virtual ~Rabbit();
    	virtual std::string family() const override;
    	virtual std::string breed() const override;
    	Rabbit(std::istream& ist);
        virtual void save(std::ostream& ost);

	private:
    	Rabbit_breed _breed;
};

#endif