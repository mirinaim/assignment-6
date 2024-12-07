/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#ifndef LIGHT
#define LIGHT

#include "Vec.hpp"
#include "scene.hpp"
#include "Object.hpp"
#include "rt.hpp"

class Light{
    private:
    Vec loc;
    bool shadow_test(SCENE_T scene, Object *obj, Vec int_pt);

    public:
    
    Light(Vec a_loc){
        loc = a_loc;
    }

    Color illuminate(SCENE_T scene, Object *obj, Vec closest_int_pt, Vec closest_normal, RAY_T ray);
};

#endif