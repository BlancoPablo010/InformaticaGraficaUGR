#include "saltamontes.h"

void _saltamontes::setAlphaBase(const int& rotationAngle) {
    alphaBase = rotationAngle;
}

void _saltamontes::setAlphaBrazos(const int& rotationAngle) {
    alphaBrazos = rotationAngle;
}

void _saltamontes::draw(const _draw& draw)
{


    glColor3fv((GLfloat *) &_colors_ne::BLACK);
    base(draw);
    glRotatef(alphaBase,0,1,0);
    glColor3fv((GLfloat *) &_colors_ne::MAGENTA);
    antebrazo(draw);


}

void _saltamontes::base(const _draw& draw) {
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0.05,0);
    glScalef(2,0.10,2);
    switch (draw){
    case _mode::MODE_DRAW_CHESS:
        Cone->draw_chess();
        break;
    case _mode::MODE_DRAW_FILL:
        Cone->draw_fill();
        break;
    case _mode::MODE_DRAW_LINE:
        Cone->draw_line();
        break;
    case _mode::MODE_DRAW_POINT:
        Cone->draw_chess();
        break;
    }
    glPopMatrix();
}

void _saltamontes::antebrazo(const _draw& draw) {


    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glScalef(0.25,1,0.25);
    switch (draw){
    case _mode::MODE_DRAW_CHESS:
        Cylinder->draw_chess();
        break;
    case _mode::MODE_DRAW_FILL:
        Cylinder->draw_fill();
        break;
    case _mode::MODE_DRAW_LINE:
        Cylinder->draw_line();
        break;
    case _mode::MODE_DRAW_POINT:
        Cylinder->draw_chess();
        break;
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(0.25,0.25,0.25);
    switch (draw){
    case _mode::MODE_DRAW_CHESS:
        Sphere->draw_chess();
        break;
    case _mode::MODE_DRAW_FILL:
        Sphere->draw_fill();
        break;
    case _mode::MODE_DRAW_LINE:
        Sphere->draw_line();
        break;
    case _mode::MODE_DRAW_POINT:
        Sphere->draw_chess();
        break;
    }
    glPopMatrix();

    glColor3fv((GLfloat *) &_colors_ne::CYAN);
    brazos(draw);

}

void _saltamontes::brazos(const _draw& draw) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(alphaBrazos%60,1,0,0);
    glRotatef(45,1,0,0);
    glTranslatef(0,0,-0.5);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glRotatef((alphaBrazos)%60+8,0.5,0,0.5);
    glRotatef(45,0.5,0,0.5);
    glTranslatef(0.35,0,-0.35);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glRotatef((alphaBrazos+16)%60,0,0,1);
    glRotatef(45,0,0,1);
    glTranslatef(0.5,0,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glRotatef((alphaBrazos+23)%60,-0.5,0,0.5);
    glRotatef(45,-0.5,0,0.5);
    glTranslatef(0.35,0,0.35);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glRotatef((alphaBrazos+30)%60,-1,0,0);
    glRotatef(45,-1,0,0);
    glTranslatef(0,0,0.5);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glRotatef((alphaBrazos+38)%60,-0.5,0,-0.5);
    glRotatef(45,-0.5,0,-0.5);
    glTranslatef(-0.35,0,0.35);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glRotatef((alphaBrazos+45)%60,0,0,-1);
    glRotatef(45,0,0,-1);
    glTranslatef(-0.5,0,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glRotatef((alphaBrazos+52)%60,0.5,0,-0.5);
    glRotatef(45,0.5,0,-0.5);
    glTranslatef(-0.35,0,-0.35);
    brazo(draw);
    glPopMatrix();

}

void _saltamontes::brazo(const _draw& draw) {
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(alpha, 0, 1, 0);
    glTranslatef(0,1,0);
    glScalef(0.08,1,0.08);
    switch (draw){
    case _mode::MODE_DRAW_CHESS:
        Cylinder->draw_chess();
        break;
    case _mode::MODE_DRAW_FILL:
        Cylinder->draw_fill();
        break;
    case _mode::MODE_DRAW_LINE:
        Cylinder->draw_line();
        break;
    case _mode::MODE_DRAW_POINT:
        Cylinder->draw_chess();
        break;
    }
    glPopMatrix();

    glPushMatrix();
    asiento(draw);
    glPopMatrix();
}

void _saltamontes::asiento(const _draw& draw) {
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotatef(alphaBase,0,1,0);
    glTranslatef(0,1.5,0);
    glScalef(0.2,0.4,0.2);
    switch (draw){
    case _mode::MODE_DRAW_CHESS:
        Cube->draw_chess();
        break;
    case _mode::MODE_DRAW_FILL:
        Cube->draw_fill();
        break;
    case _mode::MODE_DRAW_LINE:
        Cube->draw_line();
        break;
    case _mode::MODE_DRAW_POINT:
        Cube->draw_chess();
        break;
    }
    glPopMatrix();
}



