#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Geometry.h"
#include <iostream>
using namespace std;

class rectangle: public Geometry
{
protected:
    double Length;
    double Width;
public:
    rectangle(void);
    rectangle (double, double);
    rectangle(char*, double, double);
    double ComputeVolume();
    double ComputeSurface();
    ~rectangle(void);
};
#endif
