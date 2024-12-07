/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#ifndef OBJECT
#define OBJECT

#include "Color.hpp"
#include "rt.hpp"
#include "Vec.hpp"

class Object {
    public:
    char type;
    Color color;
    Color color2;
    bool checker;
    Object *next;

    virtual bool intersect(RAY_T ray, double &t, Vec &int_pt, Vec &normal){
        return false;
    }
};

#endif