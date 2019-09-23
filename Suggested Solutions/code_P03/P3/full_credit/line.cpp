#include <cmath>
#include "line.h"

Line::Line(double x1, double y1, double x2, double y2)
    : _x1{x1}, _y1{y1}, _x2{x2}, _y2{y2} { }

std::string Line::to_string() {
    return "(" + std::to_string(_x1) + ","
               + std::to_string(_y1) + ")-("
               + std::to_string(_x2) + ","
               + std::to_string(_y2) + ")";
}

double Line::length() {
    double x = _x2 - _x1;
    double y = _y2 - _y1;
    return sqrt(x*x + y*y);
}

