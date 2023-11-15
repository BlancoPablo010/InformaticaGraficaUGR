/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "object3d.h"
#include "math.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _tetrahedron:public _object3D
{
public:
  _tetrahedron(float Size=1.0);
};


class _disk:public _object3D
{
  public:
  _disk(float Radius=0.5f, int Num_divisions=3);
};

#endif
