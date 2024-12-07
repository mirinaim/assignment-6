/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#include <iostream>
#include <fstream>
using namespace std;

#include "scene.hpp"
#include "Color.hpp"
#include "Vec.hpp"
#include "Light.hpp"
#include "Object.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"

static void init(SCENE_T &scene){
    scene.objs = NULL;
    Object* objs = NULL;
    Object* node;
    char type;
    char c;
    double x,y,z,d,r,g,b,r2,g2,b2;

    ifstream file("scene.txt");
    string line;
    while(file >> c){
        if(c == 's'){
            file >> x >> y >> z;
            file >> d;
            file >> r >> g >> b;

            node = new Sphere(d, Vec(x, y, z), Color(r, g, b), false, Color());
            node->type = 's';
            node->next = objs;
            objs = node;
            
        }
        else if(c == 'p'){
            file >> x >> y >> z;
            file >> d;
            file >> r >> g >> b;
            file >> r2 >> g2 >> b2;

            node = new Plane(d,Vec(x,y,z),Color(r,g,b),true,Color(r2,g2,b2));
            node->type = 'p';
            node->next = objs;
            objs = node;
        }
    }
    scene.objs = objs;
    file.close();
}

static Color trace(RAY_T ray, Light light, SCENE_T scene){
    Color color(0.3, 0.3, 0.5);
    Object *cur;

    double t;
    Vec int_pt;
    Vec normal;

    double closest_t = 1000.0;
    Object *closest_object;
    Vec closest_int_pt;
    Vec closest_normal;

    // Find the closest object
    for(cur = scene.objs; cur != NULL; cur = cur->next){
        if(cur->intersect(ray,t,int_pt,normal)){
            if(t < closest_t){
                closest_t = t;
                closest_int_pt = int_pt;
                closest_normal = normal;
                closest_object = cur;
            }
        }
    }

    // Get the color of the closest object
    if(closest_t < 1000.0){
        color = light.illuminate(scene, closest_object, closest_int_pt, closest_normal, ray);
    }

    return color;
}

int main(){
    SCENE_T scene;
    Light light = Light(Vec(5.0, 10.0, -2.0));
    RAY_T ray;
    ray.origin = Vec(0.0, 0.0, 0.0);
    Vec direction;
    Color color;

    int dim_x = 640;
    int dim_y = 480;

    init(scene);
    
    ofstream file("scene.ppm");
    file << "P6 " << dim_x << " " << dim_y << " 255 " ;

    //Aspect Ratio
    scene.start_x = -((double)dim_x/dim_y) / 2.0;
    scene.start_y = 0.5;
    scene.pixel_size = 1.0/dim_y;

    for (int y = 0; y < dim_y; y++){
        for (int x = 0; x < dim_x; x++){
            double dir_x = scene.start_x + (x * scene.pixel_size);
            double dir_y = scene.start_y - (y * scene.pixel_size);
            double dir_z = 1;

            direction.set_xyz(dir_x, dir_y, dir_z);

            color = trace(ray, light, scene);
            ray.direction = direction.normalize();

            file << (unsigned char) (color.get_R() * 255) <<
                    (unsigned char) (color.get_G() * 255) <<
                    (unsigned char) (color.get_B() * 255);
        }
    }

    file.close();
    return 0;
}