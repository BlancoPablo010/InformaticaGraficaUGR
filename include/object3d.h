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

  void normalize_vector_vertex3f(vector<_vertex3f>&);

  public:
  vector<_vertex3ui> Triangles;
  vector<_vertex3f> Normal_Triangles;
  vector<_vertex3f> Normal_Vertices;

  void get_normal_triangles();
  void get_normal_vertices();

  void draw_line();
  void draw_fill();
  void draw_chess();

  void draw_flat_shadding();
  void draw_smooth_shadding();

};

#endif // OBJECT3D_H
