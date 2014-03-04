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
    Geometry *array[SIZE]; 
 
    array[0] = new Box ("Boxy", 3, 4, 5);
    array[1] = new rectangle ("Rectangley", 2, 6);
    array[2] = new Sphere ("Spherey", 5);    
    array[3] = new Circle ("Circley", 2);    
    array[4] = new Cube ("Cubey", 7);    
    array[5] = new Square ("Squarey", 4);

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

    //COPY CONSTRUCTOR and ASSIGNMENT OPERATOR FROM DERIVED CLASSES
    cout<<endl;
    cout<<"DRIVER TO SHOW COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR:"<<endl;
    for(i=0; i<SIZE; i++)
    {
        Geometry* j(array[i]);
        Geometry* k= array[i];
        string jname= j->getName();
        string jtype= j->getType();
        double jsur= j->ComputeSurface();
        double jvol= j->ComputeVolume();
        string kname= k->getName();
        string ktype= k->getType();
        double ksur= k->ComputeSurface();
        double kvol= k->ComputeVolume();
        cout<< "Object created with copy constructor: "<<endl;
        cout<<"Name: "<<jname<<" Type: " <<jtype<<" Surface Area: "<<jsur<<" Volume: "<< jvol<<endl;
        cout<< "Object assigned with overloaded assignment operator: "<<endl;
        cout<<"Name: "<<kname<<" Type: " <<ktype<<" Surface Area: "<<ksur<<" Volume: "<< kvol<<endl<<endl;
    }
    
    for(i=0; i<SIZE; i++)
    {
        delete array[i];
    }
    
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






