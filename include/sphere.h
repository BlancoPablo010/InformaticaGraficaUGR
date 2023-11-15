#ifndef _SPHERE_H
#define _SPHERE_H

#include "revolutionobject3d.h"
#include "math.h"

class _sphere:public _revolutionObject3D
{
public:
    _sphere(float Radius=0.5f, int NumDivisions=30);
};

#endif // _SPHERE_H
