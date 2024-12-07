/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#ifndef VEC
#define VEC

#include <math.h>

class Vec{
    private:
    double x, y, z;

    public:
    Vec(){
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }
    Vec(double a_x, double a_y, double a_z){
        x = a_x;
        y = a_y;
        z = a_z;
    }

    void set_xyz(double a_x,double a_y,double a_z){
        x = a_x;
        y = a_y;
        z = a_z;
    }

    Vec operator+(Vec const& vec){
        return Vec(x + vec.x, y + vec.y, z + vec.z);
    }
    Vec operator-(Vec const& vec){
        return Vec(x - vec.x, y - vec.y, z - vec.z);
    }
    Vec operator*(Vec const& vec){
        return Vec(x * vec.x, y * vec.y, z * vec.z);
    }
    Vec operator*(double val){
        return Vec(x * val, y * val, z * val);
    }
    Vec operator/(double val){
        return Vec(x / val, y / val, z / val);
    }

    double sum_components();
    double sum_floor_componenets();

    Vec normalize();

    // Returns the dot product of two vectors
    double dot(Vec vec);

    // Returns the length of a vector
    double length();
};

#endif