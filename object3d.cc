/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2023
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;
using namespace axis;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);
    for(int i=0;i<Triangles.size();i++){
        int Vertex_1=Triangles[i][0];
        int Vertex_2=Triangles[i][1];
        int Vertex_3=Triangles[i][2];
        glVertex3f(ScaleVertices[Vertex_1].x, ScaleVertices[Vertex_1].y, ScaleVertices[Vertex_1].z);
        glVertex3f(ScaleVertices[Vertex_2].x, ScaleVertices[Vertex_2].y, ScaleVertices[Vertex_2].z);
        glVertex3f(ScaleVertices[Vertex_3].x, ScaleVertices[Vertex_3].y, ScaleVertices[Vertex_3].z);
    }
    glEnd();

/*  Otra forma de hacerlo, no óptima
    glBegin(GL_LINE_LOOP);
    for (unsigned int i = 0; i<Triangles.size(); i++) {
        glVertex3fv((GLfloat *) &ScaleVertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &ScaleVertices[Triangles[i]._1]);

        glVertex3fv((GLfloat *) &ScaleVertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &ScaleVertices[Triangles[i]._2]);

        glVertex3fv((GLfloat *) &ScaleVertices[Triangles[i]._2]);
        glVertex3fv((GLfloat *) &ScaleVertices[Triangles[i]._0]);
    }
    glEnd();
*/
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);
    for(int i=0;i<Triangles.size();i++){
        int Vertex_1=Triangles[i][0];
        int Vertex_2=Triangles[i][1];
        int Vertex_3=Triangles[i][2];
        glVertex3f(ScaleVertices[Vertex_1].x, ScaleVertices[Vertex_1].y, ScaleVertices[Vertex_1].z);
        glVertex3f(ScaleVertices[Vertex_2].x, ScaleVertices[Vertex_2].y, ScaleVertices[Vertex_2].z);
        glVertex3f(ScaleVertices[Vertex_3].x, ScaleVertices[Vertex_3].y, ScaleVertices[Vertex_3].z);
    }
    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);
    for(int i=0;i<Triangles.size();i++){
        if(i%2==0) glColor3fv((GLfloat *) &RED);
        else  glColor3fv((GLfloat *) &BLUE);
        int Vertex_1=Triangles[i][0];
        int Vertex_2=Triangles[i][1];
        int Vertex_3=Triangles[i][2];
        glVertex3f(ScaleVertices[Vertex_1].x, ScaleVertices[Vertex_1].y, ScaleVertices[Vertex_1].z);
        glVertex3f(ScaleVertices[Vertex_2].x, ScaleVertices[Vertex_2].y, ScaleVertices[Vertex_2].z);
        glVertex3f(ScaleVertices[Vertex_3].x, ScaleVertices[Vertex_3].y, ScaleVertices[Vertex_3].z);
    }
    glEnd();
}

void _object3D::scale(float x, float y, float z) {
    for(int i=0; i<ScaleVertices.size(); i++) {
        ScaleVertices[i][0] *= x;
        ScaleVertices[i][1] *= y;
        ScaleVertices[i][2] *= z;
    }
}

void _object3D::move(float x, float y, float z) {
    for(int i=0; i<ScaleVertices.size(); i++) {
        ScaleVertices[i][0] += x;
        ScaleVertices[i][1] += y;
        ScaleVertices[i][2] += z;
    }
}

void _object3D::rotate(_coordenate _axis, float angle) {
    if(_axis == X) {
        for(int i=0; i<ScaleVertices.size(); i++) {
            ScaleVertices[i][1] *= cos(angle);
            ScaleVertices[i][2] *= sin(angle);
        }
    }
    else if(_axis == Y) {
        for(int i=0; i<ScaleVertices.size(); i++) {
            ScaleVertices[i][0] *= cos(angle);
            ScaleVertices[i][2] *= sin(angle);
        }
    }
    else if(_axis == Z) {
        for(int i=0; i<ScaleVertices.size(); i++) {
            ScaleVertices[i][0] *= cos(angle);
            ScaleVertices[i][1] *= sin(angle);
        }
    }
}
