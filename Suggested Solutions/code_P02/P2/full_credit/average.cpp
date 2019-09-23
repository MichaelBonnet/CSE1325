#include <iostream>
#include "average.h"

Average::Average() : _sum{0}, _values{0} { }

std::ostream& operator<<(std::ostream& ost, const Average& average) {
    if (average._values > 0) {
        ost << average._sum / average._values;
    } else {
        ost << "undefined";
    }
    return ost;
}
std::istream& operator>>(std::istream& ist, Average& average) {
    double d;
    if(ist >> d) {
        average._sum += d; 
        ++average._values;
    }
    return ist;
}
Average& Average::operator+=(double value) {
    _sum += value; 
    ++_values;
    return *this;
}

