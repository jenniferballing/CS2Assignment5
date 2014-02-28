#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    Person::Person()
    {
        name=" ";
        age=0;

    }
    Person::Person(string n, int a)
    {
        name= n;
        age=a;
    }
    int Person::GetAge()
    {
        return age;
    }
    void Person::SetAge(int n)
    {
        age=n;
    }
    
};

class Employee: public Person
{
private:
    float payRate;
public:
    Employee::Employee()
    {
        payRate=0;
    }
    Employee(float p);
    Employee(string n, int a)
    {
        name= n;
        age = a;
    }
    Employee(string n, int a, float p):Person (n, a)
    {
        payRate=p;
    }
};
bool IsOlder(Person obj, Person Oobj)
    {
        int first, second;
        first= obj.GetAge();
        second= Oobj.GetAge();
        cout<<"First: "<<first<<endl<<"Second: "<<second<<endl;
        if(first >second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

int main ()
{
    Person a;
    Employee b;

    a.SetAge(30);
    b.SetAge(5);
    int i= a.GetAge();
    cout<<"i: "<<i;
    int j=b.GetAge();
    cout<<"j: "<<j;
    
    if(IsOlder(a,b)) cout<< "a is older"<<endl;
    if(IsOlder(b,a)) cout<< "b is older"<<endl;
    
    return 0;
}
