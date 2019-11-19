#ifndef __CAT_BREEDS_H
#define __CAT_BREEDS_H
#include <map>
#include <ostream>

#include "animal.h"

enum class Cat_breed {DomesticShorthair, DomesticLonghair, Persian, MaineCoon, Siamese, RussianBlue, Abyssinian, NorweiganForest};

constexpr Cat_breed cat_breeds[] = 
{
    Cat_breed::DomesticShorthair,
    Cat_breed::DomesticLonghair,
    Cat_breed::Persian,
    Cat_breed::MaineCoon,
    Cat_breed::Siamese,
    Cat_breed::RussianBlue,
    Cat_breed::Abyssinian, 
    Cat_breed::NorweiganForest,
};

std::string to_string(const Cat_breed& breed);

std::ostream& operator<<(std::ostream& ost, const Cat_breed& breed);

#endif