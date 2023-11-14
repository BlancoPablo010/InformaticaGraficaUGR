#ifndef _PLY_H
#define _PLY_H

#include "ply_object3d.h"

class _ply:public _PLY_object3D
{
public:
    _ply(){}
    _ply(string File);
};

#endif // _PLY_H
