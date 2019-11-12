#ifndef __FAMILY_H
#define __FAMILY_H
#include <vector>
#include <string>

enum class Family {dog, cat, rabbit};

constexpr Family families[] = 
{
    Family::dog,
    Family::cat,
    Family::rabbit,
};

const std::vector<std::string> family_to_string = {"Dog", "Cat", "Rabbit"}; // change it up

#endif