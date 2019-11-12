#ifndef __GENDER_H
#define __GENDER_H
#include <vector>
#include <string>

enum class Gender {MALE, FEMALE};

constexpr Gender genders[] = 
{
    Gender::MALE,
    Gender::FEMALE,
};

const std::vector<std::string> gender_to_string = {"Male", "Female"}; // change it up

#endif
