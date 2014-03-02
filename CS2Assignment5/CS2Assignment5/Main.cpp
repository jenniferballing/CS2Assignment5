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

void image(Geometry *obj);
void Sort (double [], int[], int size);
void Report(Geometry* [], double [], double [], int size);
double findAverage(double Arr[], int size);
double findMedian(double Arr[], int size);
int main()
{
    //CHECKING THE MATH AND REPORT FUNCTION
    Box a(5, 5, 5, "Boxy");
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

    Report(Arr, SArr, VArr, 6);
          
    return 0;
}
void image(Geometry *obj)
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
    int i, j;
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
}
void Report(Geometry *GArr[], double SArr[], double VArr[], int size)
{
    double surArr[6];
    double volArr[6];
    int indArr[6];
    int i=0, j=0, k=0;
    double AveS, AveV, MedS, MedV;

    cout<<"OBJECTS STORED IN GEOMETRY ARRAY: "<<endl;
    for(i=0; i<size; i++)
    {
        Geometry *levi=GArr[i];
        image(levi);
    }
    cout<<endl<<endl;
    
    for(i=0; i<size;i++)
    {
        surArr[i]=SArr[i];
        indArr[i]=i;
    }

    Sort(surArr, indArr, size);
    cout<<"SORT BY SURFACE: "<<endl;
    cout<<"Descending order"<<endl<<endl;
    for(j=5; j>=0; j--)
    {
        int x=indArr[j];
        Geometry *temp=GArr[x];
        image(temp);
    } 
    cout<<endl<<endl;
    AveS=findAverage(surArr, size);
    MedS=findMedian(surArr, size);

    for(i=0; i<size;i++)
    {
        volArr[i]=VArr[i];
        indArr[i]=i;
    }

    Sort(volArr, indArr, size);
    cout<<"SORT BY VOLUME: "<<endl;
    cout<<"Ascending"<<endl<<endl;
    for(k=0; k<size; k++)
    {
        int y=indArr[k];
        Geometry *temp=GArr[y];
        image(temp);
    }
    cout<<endl<<endl;
    AveV=findAverage(volArr, size);
    MedV=findMedian(volArr, size);


    cout<<"STATISTICS: "<<endl;
    cout<<fixed<<setprecision(1)<<"Average Surface Area: "<<AveS<<endl;
    cout<<fixed<<setprecision(1)<<"Average Volume: "<<AveV<<endl;
    cout<<fixed<<setprecision(1)<<"Median Surface Area: "<<MedS<<endl;
    cout<<fixed<<setprecision(1)<<"Median Volume: "<<MedV<<endl;
}
double findAverage(double Arr[], int size)
{
    double sum=0;
    int i;
    for(i=0; i<size; i++)
    {
        sum+=Arr[i];
    }
    double ave= sum/size;
    return ave;
}
double findMedian(double Arr[], int size)
{
    double med=0;
    int ind[6]; 
    int i;
    for(i=0; i<size; i++)
    {
        ind[i]=i;
    }
    Sort(Arr,ind, size);
    if(size%2==0)
    {
        double first = Arr[size/2];
        double second= Arr[size/2+1];
        first+=second;
        med= first/2;
    }
    else 
    {
        med=Arr[size/2];
    }
    return med;
}






