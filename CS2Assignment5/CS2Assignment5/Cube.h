#ifndef CUBE_H
#define CUBE_H
#include "Square.h"
#include <iostream>
using namespace std;

class Cube:public Square
{
public:
    Cube(void);
    Cube(double, char*);
    double getSide();
    double ComputeVolume();
    double ComputeSurface();
    ~Cube(void);
};
#endif
