#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include "Geometry.h"
using namespace std;

class Square:public Geometry
{
protected:
    double Side;
public:
    Square(void);
    Square(double);
    Square(char*, double);
    double ComputeVolume();
    double ComputeSurface();
    ~Square(void);
};
#endif
