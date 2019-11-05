#ifndef __CAT_BREED_H
#define __CAT_BREED_H
#include <vector>
#include <string>

enum class cat_breed {DomesticShorthair, DomesticLonghair, Persian, MaineCoon, Siamese, RussianBlue, Abyssinian, NorweiganForest};

const std::vector<std::string> breed_to_string = 
{"Domestic Shorthair", "Domestic Longhair", "Persian", "Maine Coon", "Siamese", "Russian Blue", "Abyssinian", "Norweigan Forest"};

#endif