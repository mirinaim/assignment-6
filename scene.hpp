/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#ifndef SCENE
#define SCENE

#include "Object.hpp"

class Light;

// Scene type
typedef struct {
    Object *objs;
    double start_x;
    double start_y;
    double pixel_size;
} SCENE_T;

#endif