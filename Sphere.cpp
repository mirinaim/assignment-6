/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#include <iostream>
#include <math.h>
using namespace std;

#include "Object.hpp"
#include "rt.hpp"
#include "Vec.hpp"
#include "Sphere.hpp"
#include "Color.hpp"

Sphere::Sphere(double a_radius, Vec a_ctr, Color a_color, bool a_checker, Color a_color2){
    radius = a_radius;
    ctr = a_ctr;

    color = a_color;
    checker = a_checker;
    color2 = a_color2;
}

bool Sphere::intersect(RAY_T ray, double &t, Vec &int_pt, Vec &normal){
    double A = 1;
    double B = (ray.direction * (ray.origin - this->ctr)).sum_components() * 2;
    double C = ((ray.origin - this->ctr) * (ray.origin - this->ctr)).sum_components()
                - this->radius * this->radius;

    double discriminant = B * B - 4 * A * C;

    if (discriminant < 0){
        return 0;
    }
    else{
        double t1 = (-B + sqrt(discriminant)) / 2;
        double t2 = (-B - sqrt(discriminant)) / 2;

        if((t1 < 0 && t2 < 0) || (t1 < 0 || t2 < 0)){
            return 0;
        }
        else if (t1 < t2){
            t = t1;
        }
        else{
            t = t2;
        }

        int_pt = ray.origin + ray.direction * t;
        
        normal = int_pt - this->ctr;
        
        normal = normal.normalize();
        
        return 1;
    }
}
