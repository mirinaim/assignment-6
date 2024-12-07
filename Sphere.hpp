/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#ifndef SPHERE
#define SPHERE

#include "Vec.hpp"
#include "rt.hpp"
#include "Color.hpp"
#include "Object.hpp"

class Sphere : public Object{
    private:
    double radius;
    Vec ctr;

    public:
    Sphere(double a_radius, Vec a_ctr, Color a_color, bool a_checker,
        Color a_color2);
    bool intersect(RAY_T ray, double &t, Vec &int_pt, Vec &normal);
};

#endif