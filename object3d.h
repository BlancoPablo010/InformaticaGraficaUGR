/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"

namespace axis {
typedef enum {X, Y, Z} _coordenate;
}

/*****************************************************************************
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
  public:
  vector<_vertex3ui> Triangles;
  vector<_vertex3f> ScaleVertices;

  void draw_line();
  void draw_fill();
  void draw_chess();

  void scale(float x, float y, float z);
  void move(float x, float y, float z);
  void rotate(axis::_coordenate _axis, float angle);

  // HAY QUE COMBINARLAS PARA QUE SEA MÁS EFICIENTE
  // MOTOR DE CÁLCULO SIMBOLICO, DEMASIADO COMPLEJOs
};
/*
class _PLY_object3D: _object3D {
  _PLY_object3D() {};
  bool create_object(std::string File_name);
};

class _sweep_object3D: public _object3D {

};
*/
#endif // OBJECT3D_H
