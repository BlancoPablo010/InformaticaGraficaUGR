#ifndef _REVOLUTIONOBJECT3D_H
#define _REVOLUTIONOBJECT3D_H
#include "object3d.h"
#include "math.h"



class _revolutionObject3D:public _object3D
{
public:
    void _initialize(axis::_coordenate _axis, vector<vector<float>> sidePoints, float radius, float heigth, int numDivisions,
                     int triangleStep, int matrixRows);
private:
    axis::_coordenate Axis;
};

#endif // _REVOLUTIONOBJECT3D_H
