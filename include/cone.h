#ifndef _CONE_H
#define _CONE_H

#include "revolutionobject3d.h"


class _cone:public _revolutionObject3D
{
public:
    _cone(float Radius=0.5f, float Heigth=1, int NumDivisions=20);
};

#endif // _CONE_H
