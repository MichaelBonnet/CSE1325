#ifndef __DOG_H
#define __DOG_H

#include "animal.h"
#include <map>

// List of dog breeds, conversion to/from string and stream, and iteration
enum class Dog_breed 
{
    BEAGLE,
    BOXER,
    BULLDOG,
    DACHSHUND,
    LABRADOR,
    MIX,
    POINTER, 
    POODLE,
    RETRIEVER,
    ROTTWEILER,
    SHEPHERD,
    TERRIER,
};

constexpr Dog_breed dog_breeds[] = 
{
    Dog_breed::BEAGLE,
    Dog_breed::BOXER,
    Dog_breed::BULLDOG,
    Dog_breed::DACHSHUND,
    Dog_breed::LABRADOR,
    Dog_breed::MIX,
    Dog_breed::POINTER, 
    Dog_breed::POODLE,
    Dog_breed::RETRIEVER,
    Dog_breed::ROTTWEILER,
    Dog_breed::SHEPHERD,
    Dog_breed::TERRIER,
};

// Dog implements to_string using a switch statement (if/else if/else is equivalent)
std::string to_string(const Dog_breed& breed);

std::ostream& operator<<(std::ostream& ost, const Dog_breed& breed);

extern const std::map<Dog_breed, std::string> dogs_map;

// Class Dog with overrides for family and breed
class Dog : public Animal 
{
  public:
    Dog(Dog_breed breed, std::string name, Gender gender, int age);
    Dog(std::istream& ist);
    void save(std::ostream& ost) override;
    virtual ~Dog();
    virtual std::string family() const override;
    virtual std::string breed() const override;
  private:
    Dog_breed _breed;
};

#endif
