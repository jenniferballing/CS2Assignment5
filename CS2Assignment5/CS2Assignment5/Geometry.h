#ifndef GEOMETRY_H
#define GEOMETRY_H
class Geometry
{
protected:
    char * Name;
    char * Type;

    void setType(char* t)
    {
        Type=t;
    }

public:
    Geometry(void);
    Geometry(char*);
    Geometry(char*, char*);
    Geometry(const Geometry &obj);
    Geometry operator=(const Geometry &obj);
    char* getName();
    char* getType();
    virtual double ComputeVolume();
    virtual double ComputeSurface();
    ~Geometry(void);
};
#endif
