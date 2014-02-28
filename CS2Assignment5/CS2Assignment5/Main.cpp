#include <iostream>
#include <string>
#include "Box.h"
#include "rectangle.h"
#include "Cube.h"
#include "Square.h"
#include "Sphere.h"
#include "Circle.h"
//3D objects are inheriting 2D objects
//Members in Geometry should be protected
//Constructors that go with pointers in base class
//Getters in base class and others. 
//Create protected function to change the name in Geometry

using namespace std;

void report(Geometry *obj);
int main()
{
    //CHECKING THE MATH AND REPORT FUNCTION
    Box a(5, 5, 5, "Boxy");
    Geometry *aptr=&a;
    report (aptr);

    rectangle b(5, 5, "Rectangley");
    Geometry *bptr=&b;
    report (bptr);

    Sphere c(5,"Spherey");
    Geometry *cptr=&c;
    report (cptr);

    Circle d(5,"Circley");
    Geometry *dptr=&d;
    report (dptr);

    Cube e(5,"Cubey");
    Geometry *eptr=&e;
    report (eptr);

    Square f(5,"Squarey");
    Geometry *fptr=&f;
    report (fptr);
    
    return 0;
}
void report(Geometry *obj)
{
    cout<<"----- Geometry Report -----"<<endl;
    cout<< "Type: "<<obj->getType()<<endl;
    cout<< "Name: "<<obj->getName()<<endl;
    cout<< "Volume: "<<obj->ComputeVolume()<<endl;
    cout<< "Surface: "<<obj->ComputeSurface()<<endl;
}
