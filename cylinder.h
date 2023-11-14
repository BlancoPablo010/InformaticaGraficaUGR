#ifndef CYLINDER_H
#define CYLINDER_H
#include "revolutionobject3d.h"
#include "math.h"


class _cylinder:public _revolutionObject3D
{
public:
    _cylinder(float Radius=0.5f, float Heigth=1, int NumDivisions=20);
};

#endif // CYLINDER_H
