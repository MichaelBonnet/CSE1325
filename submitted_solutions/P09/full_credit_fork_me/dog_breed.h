#ifndef __DOG_BREED_H
#define __DOG_BREED_H
#include <vector>
#include <string>

enum class Dog_breed {Greyhound, Akita, CardiganCorgi, BlueHeeler, Chihuahua, SaintBernard, BassetHound, BlueTick};

constexpr Dog_breed dog_breeds[] = 
{
    Dog_breed::Greyhound,
    Dog_breed::Akita,
    Dog_breed::CardiganCorgi,
    Dog_breed::BlueHeeler,
    Dog_breed::Chihuahua,
    Dog_breed::SaintBernard,
    Dog_breed::BassetHound, 
    Dog_breed::BlueTick,
};

const std::vector<std::string> breed_to_string = 
{"Greyhound", "Akita", "Cardigan Corgi", "Blue Heeler", "Chihuahua", "Saint Bernard", "Basset Hound", "Blue Tick"};

#endif
