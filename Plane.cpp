/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#include <iostream>
using namespace std;

#include "Object.hpp"
#include "rt.hpp"
#include "Vec.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Color.hpp"

Plane::Plane(double D, Vec normal, Color a_color, bool a_checker, Color a_color2){
    // default any appropriate parameters to unused values and
    // create objects in line, such as Vec, when calling constructor

    this->D = D;
    this->normal = normal;

    this->color = a_color;
    this->checker = a_checker;
    this->color2 = a_color2;
};

bool Plane::intersect(RAY_T ray, double &t, Vec &int_pt, Vec &normal){
    double dp = this->normal.dot(ray.direction);
    
    if(dp == 0){
        return 0;
    }
    else{
        t = -(this->normal.dot(ray.origin) + this->D) / dp;
        if(t < 0){
            return 0;
        }
        else{
            int_pt = ray.origin + (ray.direction * t);

            normal = this->normal;
            return 1;
        }
    }
};
