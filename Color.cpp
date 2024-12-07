/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#include <iostream>
using namespace std;

#include "Color.hpp"

void Color::cap(){
    if(this->r > 1.0){
        this->r = 1.0;
    }
    if(this->g > 1.0){
        this->g = 1.0;
    }
    if(this->b > 1.0){
        this->b = 1.0;
    }   
}