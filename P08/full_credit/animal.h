#ifndef __ANIMAL_H
#define __ANIMAL_H

#include "gender.h"
#include <ostream>


class Animal 
{
	public:
		Animal(std::string name, Gender gender, int age);
		~Animal();
		virtual std::string family() const = 0; // = 0
		virtual std::string breed() const = 0; // = 0
		std::string name() const;
		Gender gender() const;
		int age() const;
		virtual std::string to_string() const; // virtual?
		
	protected:
		std::string _name;
		Gender _gender;
		int _age;
};

std::ostream& operator<<(std::ostream& ost, const Animal& animal);

#endif
