#ifndef CIRCLE_H
#define CIRCLE_H
#include "Geometry.h"
#include <iostream>
using namespace std;

class Circle: public Geometry
{
protected:
    double Radius;
public:
    Circle(void);
    Circle(double);
    Circle(double, char*);
    double ComputeVolume();
    double ComputeSurface();
    ~Circle(void);
};
#endif
