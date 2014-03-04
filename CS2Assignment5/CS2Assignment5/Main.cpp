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
void Calculations(Geometry* [], double [], double [], int size);
double findAverage(double Arr[], int size);
double findMedian(double Arr[], int size);

int main()
{
    const int SIZE = 6;
    int i;
    double SArr[SIZE];
    double VArr[SIZE];
    //CHECKING THE MATH AND REPORT FUNCTION
    Geometry *array[SIZE]; 
 
    array[0] = new Box (3, 4, 5, "Boxy");
    array[1] = new rectangle (2, 6, "Rectangley");
    array[2] = new Sphere (5,"Spherey");    
    array[3] = new Circle (2,"Circley");    
    array[4] = new Cube (7,"Cubey");    
    array[5] = new Square (4,"Squarey");

    for(i=0; i<SIZE; i++)
    {
        report(array[i]);
        cout<<endl;
    }
    for(i=0; i<SIZE; i++)
    {
        
        SArr[i]=array[i]->ComputeSurface();
        VArr[i]=array[i]->ComputeVolume();
    }

    Calculations(array, SArr, VArr, SIZE);

    //COPY CONSTRUCTOR and ASSIGNMENT OPERATOR WORK IN DERIVED CLASSES
    Geometry* j(array[2]);
    double jsur= j->ComputeSurface();
    string jname= j->getName();
    string jtype= j->getType();
    cout<<"Copy of sphere: "<< jname<<" " <<jtype<<" "<<jsur<<endl;
        
    delete [] array;
    
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
void Calculations(Geometry *GArr[], double SArr[], double VArr[], int size)
{
    double surArr[50];
    double volArr[50];
    int indArr[50];
    int i=0, j=0, k=0;
    double AveS, AveV, MedS, MedV;
    
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
        report(temp);
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
        report(temp);
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
    int ind[50]; 
    int i;
    for(i=0; i<size; i++)
    {
        ind[i]=i;
    }
    Sort(Arr,ind, size);
    if(size%2==0)
    {
        double first = Arr[size/2];
        double second= Arr[size/2-1];
        first+=second;
        med= first/2;
    }
    else 
    {
        med=Arr[size/2];
    }
    return med;
}






