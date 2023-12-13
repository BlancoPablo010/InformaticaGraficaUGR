/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2023
 * GPL 3
 */


#include "../include/object3d.h"

using namespace _colors_ne;
using namespace axis;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::get_normal_triangles() {
    Normal_Triangles.resize(Triangles.size());

    for (unsigned int i=0; i<Triangles.size(); i++) {
        _vertex3f A = Vertices[Triangles[i][1]] - Vertices[Triangles[i][0]];
        _vertex3f B = Vertices[Triangles[i][2]] - Vertices[Triangles[i][0]];
        _vertex3f product = {A[1]*B[2] - A[2]*B[1], A[2]*B[0] - A[0]*B[2], A[0]*B[1] - A[1]*B[0]};
        Normal_Triangles[i] = product;

    }

    //normalize_vector_vertex3f(Normal_Triangles);
}

void _object3D::get_normal_vertices() {
    Normal_Vertices.resize(Vertices.size(), {0.0f, 0.0f, 0.0f});

    for(unsigned int i = 0; i<Triangles.size(); i++) {

        Normal_Vertices[Triangles[i][0]][0] += Normal_Triangles[i][0];
        Normal_Vertices[Triangles[i][0]][1] += Normal_Triangles[i][1];
        Normal_Vertices[Triangles[i][0]][2] += Normal_Triangles[i][2];

        Normal_Vertices[Triangles[i][1]][0] += Normal_Triangles[i][0];
        Normal_Vertices[Triangles[i][1]][1] += Normal_Triangles[i][1];
        Normal_Vertices[Triangles[i][1]][2] += Normal_Triangles[i][2];

        Normal_Vertices[Triangles[i][2]][0] += Normal_Triangles[i][0];
        Normal_Vertices[Triangles[i][2]][1] += Normal_Triangles[i][1];
        Normal_Vertices[Triangles[i][2]][2] += Normal_Triangles[i][2];


    }

    normalize_vector_vertex3f(Normal_Vertices);
}

void _object3D::normalize_vector_vertex3f(vector<_vertex3f> &vector) {
    for (unsigned int i = 0; i<vector.size(); i++) {
        float x = vector[i][0];
        float y = vector[i][1];
        float z = vector[i][2];

        float length = sqrt(x*x + y*y + z*z);

        x /= length;
        y /= length;
        z /= length;

        vector[i][0] = x;
        vector[i][1] = y;
        vector[i][2] = z;
    }
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{

    glPolygonMode(GL_FRONT, GL_LINE);
    glBegin(GL_TRIANGLES);
    for(int i=0;i<Triangles.size();i++){
        int Vertex_1=Triangles[i][0];
        int Vertex_2=Triangles[i][1];
        int Vertex_3=Triangles[i][2];
        glVertex3f(Vertices[Vertex_1].x, Vertices[Vertex_1].y, Vertices[Vertex_1].z);
        glVertex3f(Vertices[Vertex_2].x, Vertices[Vertex_2].y, Vertices[Vertex_2].z);
        glVertex3f(Vertices[Vertex_3].x, Vertices[Vertex_3].y, Vertices[Vertex_3].z);
    }
    glEnd();

/*  Otra forma de hacerlo, no óptima
    glBegin(GL_LINE_LOOP);
    for (unsigned int i = 0; i<Triangles.size(); i++) {
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
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
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);
    for(int i=0;i<Triangles.size();i++){
        int Vertex_1=Triangles[i][0];
        int Vertex_2=Triangles[i][1];
        int Vertex_3=Triangles[i][2];
        glVertex3f(Vertices[Vertex_1].x, Vertices[Vertex_1].y, Vertices[Vertex_1].z);
        glVertex3f(Vertices[Vertex_2].x, Vertices[Vertex_2].y, Vertices[Vertex_2].z);
        glVertex3f(Vertices[Vertex_3].x, Vertices[Vertex_3].y, Vertices[Vertex_3].z);
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
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i<Triangles.size();i++){
        if(i%2==0) glColor3fv((GLfloat *) &RED);
        else  glColor3fv((GLfloat *) &BLUE);
        int Vertex_1=Triangles[i][0];
        int Vertex_2=Triangles[i][1];
        int Vertex_3=Triangles[i][2];
        glVertex3f(Vertices[Vertex_1].x, Vertices[Vertex_1].y, Vertices[Vertex_1].z);
        glVertex3f(Vertices[Vertex_2].x, Vertices[Vertex_2].y, Vertices[Vertex_2].z);
        glVertex3f(Vertices[Vertex_3].x, Vertices[Vertex_3].y, Vertices[Vertex_3].z);
    }
    glEnd();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_flat_shadding() {
    get_normal_triangles();
    get_normal_vertices();


    glPolygonMode(GL_FRONT, GL_FILL);

    glShadeModel(GL_FLAT);

    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i<Triangles.size();i++){
        int Vertex_1=Triangles[i][0];
        int Vertex_2=Triangles[i][1];
        int Vertex_3=Triangles[i][2];
        glVertex3f(Vertices[Vertex_1].x, Vertices[Vertex_1].y, Vertices[Vertex_1].z);
        glVertex3f(Vertices[Vertex_2].x, Vertices[Vertex_2].y, Vertices[Vertex_2].z);
        glVertex3f(Vertices[Vertex_3].x, Vertices[Vertex_3].y, Vertices[Vertex_3].z);
    }
    glEnd();

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_smooth_shadding() {
    get_normal_triangles();
    get_normal_vertices();


    glPolygonMode(GL_FRONT, GL_FILL);

    glShadeModel(GL_SMOOTH);

    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i<Triangles.size();i++){
        int Vertex_1=Triangles[i][0];
        int Vertex_2=Triangles[i][1];
        int Vertex_3=Triangles[i][2];
        glNormal3f(Normal_Vertices[Vertex_1].x, Normal_Vertices[Vertex_1].y, Normal_Vertices[Vertex_1].z);
        glVertex3f(Vertices[Vertex_1].x, Vertices[Vertex_1].y, Vertices[Vertex_1].z);

        glNormal3f(Normal_Vertices[Vertex_2].x, Normal_Vertices[Vertex_2].y, Normal_Vertices[Vertex_2].z);
        glVertex3f(Vertices[Vertex_2].x, Vertices[Vertex_2].y, Vertices[Vertex_2].z);

        glNormal3f(Normal_Vertices[Vertex_3].x, Normal_Vertices[Vertex_3].y, Normal_Vertices[Vertex_3].z);
        glVertex3f(Vertices[Vertex_3].x, Vertices[Vertex_3].y, Vertices[Vertex_3].z);
    }
    glEnd();

}
