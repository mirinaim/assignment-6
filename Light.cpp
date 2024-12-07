/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#include <iostream>
#include "Light.hpp"
#include "Vec.hpp"
#include "rt.hpp"

bool Light::shadow_test (SCENE_T scene, Object *obj, Vec int_pt){
    RAY_T shadow_ray;
    shadow_ray.direction = this->loc - int_pt;
    shadow_ray.direction = shadow_ray.direction.normalize();
    shadow_ray.origin = int_pt;

    Object *cur;
    double t;
    Vec int_pt_dummy;
    Vec normal;

    for(cur = scene.objs; cur != NULL; cur = cur->next){
        if(cur == obj){
            continue;
        }
        else if(cur->intersect(shadow_ray,t,int_pt_dummy,normal)){
            return 1;
        }
    }
    return 0;
}

Color Light::illuminate(SCENE_T scene, Object *obj, Vec closest_int_pt, Vec closest_normal, RAY_T ray){
    
    Color color;
    Color obj_color;
    Vec light_loc = this->loc;

    // Checkerboard
    if(obj->checker && (((int)closest_int_pt.sum_floor_componenets())&1)){
        obj_color = obj->color2;
    }
    else{
        obj_color = obj->color;
    }

    // Ambient Lighting
    color = obj_color * 0.1;

    if(!(shadow_test(scene, obj, closest_int_pt))){
        // Light attenuation
        Vec distance_vector = this->loc - closest_int_pt;
        double light_distance = distance_vector.length();
        double atten = 1.0 / (0.002 * (light_distance * light_distance) + 0.02 * light_distance + 0.2);

        // Diffuse lighting
        Vec light_vec;
        light_vec = light_loc - closest_int_pt;

        light_vec = light_vec.normalize();
        double dp = light_vec.dot(closest_normal);
        if(dp > 0){
            color = color + (obj_color * dp * atten);

            // Specular lighting
            Vec reflect_vec;
            reflect_vec = light_vec - closest_normal * 2 * dp;

            reflect_vec = reflect_vec.normalize();
            double dp2 = reflect_vec.dot(ray.direction);
            if(dp2 > 0){
                color = color + (pow(dp2, 200) * atten);
            }
        }
    }
    
    // Cap color channels
    color.cap();
    
    return color;
}