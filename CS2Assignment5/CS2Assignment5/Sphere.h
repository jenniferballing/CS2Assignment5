#ifndef SPHERE_H
#define SPHERE_H
#include "Circle.h"
#include <iostream>
using namespace std;

class Sphere: public Circle
{
public:
    Sphere(void);
    Sphere(double, char*);
    double ComputeVolume();
    double ComputeSurface();
    ~Sphere(void);
};
#endif
