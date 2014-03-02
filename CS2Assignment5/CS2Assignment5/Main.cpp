#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
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
void Sort (double [], int[], int size);
void getSur(Geometry* [], double [], int size);
int main()
{
    //CHECKING THE MATH AND REPORT FUNCTION
    Box a(5, 5, 5, "Boxy");
    Geometry *aptr=&a;
    report (aptr);
    

    rectangle b(5, 5, "Rectangley");
    Sphere c(5,"Spherey");    
    Circle d(5,"Circley");    
    Cube e(5,"Cubey");    
    Square f(5,"Squarey");

    Geometry *Arr[6];
    Arr[0]=&a;
    Arr[1]=&b;
    Arr[2]=&c;
    Arr[3]=&d;
    Arr[4]=&e;
    Arr[5]=&f;


    double SArr[6];
    SArr[0]=a.ComputeSurface();
    SArr[1]=b.ComputeSurface();
    SArr[2]=c.ComputeSurface();
    SArr[3]=d.ComputeSurface();
    SArr[4]=e.ComputeSurface();
    SArr[5]=f.ComputeSurface();

    double VArr[6];
    VArr[0]=a.ComputeVolume();
    VArr[1]=b.ComputeVolume();
    VArr[2]=c.ComputeVolume();
    VArr[3]=d.ComputeVolume();
    VArr[4]=e.ComputeVolume();
    VArr[5]=f.ComputeVolume();

    getSur(Arr, SArr, 6);

    
          
    return 0;
}
void report(Geometry *obj)
{
    cout<<"----- Geometry Report -----"<<endl;
    cout<< "Type: "<<obj->getType()<<endl;
    cout<< "Name: "<<obj->getName()<<endl;
    cout<< fixed<<setprecision (1)<<"Volume: "<<obj->ComputeVolume()<<endl;
    cout<< fixed<<setprecision(1)<<"Surface: "<<obj->ComputeSurface()<<endl<<endl;
}
void Sort (double Arr[], int index[], int size)
{
    //Ascending order
    int i, j, min;
    for(i=0; i<size; i++)
    {
        cout<< "Value: "<<Arr[i]<<" Index: "<<index[i]<<endl;
    }

    for(i=0; i<size-1; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(Arr[i]>Arr[j])
            {
                swap(Arr[i],Arr[j]);
                swap(index[i], index[j]);
            }
        }
    }
    for(min=0; min<size; min++)
    {
        cout<< Arr[min]<<index[min]<<endl;
    }
}

void getSur(Geometry *GArr[], double Arr[], int size)//add size as parameter
{
    //cout<<"Checking Garr surface: "<<*GArr[0].ComputeSurface()<<endl;
    double surArr[6];
    int indArr[6];
    int i=0, j=0;
    
    for(int i=0; i<size;i++)
    {
        surArr[i]=Arr[i];
        indArr[i]=i;
    }
    Sort(surArr, indArr, size);
    /*Geometry *a=GArr[0];
    Geometry *b=GArr[1];
    Geometry *c=GArr[2];
    Geometry *d=GArr[3];
    Geometry *e=GArr[4];
    Geometry *b=GArr[5];*/

    for(int i=0; i<6; i++)
    {
        int x=indArr[i];
        Geometry *temp=GArr[x];
        report(temp);
    }   
}







