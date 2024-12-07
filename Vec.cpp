/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#include <iostream> 
#include <math.h>
using namespace std;

#include "Vec.hpp"

// Returns sum of x, y, and z of a Vec
inline double Vec::sum_components(){
    return x + y + z + 0.0;
}
// Returns sum of the floors of x, y, and z of a Vec
double Vec::sum_floor_componenets(){
    return floor(x) + floor(y) + floor(z);
}

// Returns a normalized vector
Vec Vec::normalize(){
    return *this / this->length();
}

// Returns the dot product of two vectors
inline double Vec::dot(Vec vec){
    return (*this * vec).sum_components();
}

// Returns the length of a vector
inline double Vec::length(){
    return sqrt(this->dot(*this));
}