#ifndef BOX_H
#define BOX_H
#include "rectangle.h"
#include <iostream>
using namespace std;

class Box:public rectangle
{
   double Height;
public:
    Box(void);
    Box(double, double, double, char*);
    double ComputeVolume();
    double ComputeSurface();
    ~Box(void);
};
#endif
