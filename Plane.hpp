/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#ifndef PLANE
#define PLANE

#include "Object.hpp"
#include "Vec.hpp"

class Plane : public Object{
    private:
    Vec normal;
    double D;

    public:
    Plane(double D, Vec normal, Color a_color, bool a_checker,
        Color a_color2);
    bool intersect(RAY_T ray, double &t, Vec &int_pt, Vec &normal);
};

#endif