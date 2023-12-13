/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2023
 * GPL 3
 */


#include "../include/tetrahedron.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_tetrahedron::_tetrahedron(float Size)
{
  Vertices.resize(4);

  Vertices[0]=_vertex3f(-Size/2,-Size/2,-Size/2);
  Vertices[1]=_vertex3f(0,-Size/2,Size/2);
  Vertices[2]=_vertex3f(Size/2,-Size/2,-Size/2);
  Vertices[3]=_vertex3f(0,Size/2,0);

  Triangles.resize(4);

  Triangles[0]=_vertex3ui(0,1,3);
  Triangles[1]=_vertex3ui(1,2,3);
  Triangles[2]=_vertex3ui(2,0,3);
  Triangles[3]=_vertex3ui(0,2,1);


}

_disk::_disk(float Radius, int Num_divisions) {
  Vertices.resize(Num_divisions + 1);

  Triangles.resize(Num_divisions);
  float increment = 2*M_PI / float(Num_divisions);
  float angle = 0;
  for(int i=0; i<Num_divisions; i++) {
      angle = float(i)*increment;
      Vertices[i]=_vertex3f(Radius*cos(angle),Radius*sin(angle),0);
  }

  for(int i=0;i<Num_divisions;i++) {
      Triangles[i]=_vertex3ui(i,(i+1)%Num_divisions,Num_divisions);
  }

}



