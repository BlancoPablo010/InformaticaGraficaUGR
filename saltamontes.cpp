#include "saltamontes.h"

void _saltamontes::setAlphaBase(const int& rotationAngle) {
    alphaBase = rotationAngle;
}

void _saltamontes::setAlphaBrazos(const int& pares, const int& impares, const float& alturaBrazos) {
    this->alphaBrazosPares = pares;
    this->alphaBrazosImpares = impares;
    this->alturaBrazos = alturaBrazos;
}

void _saltamontes::draw(const _draw& draw)
{


    glColor3fv((GLfloat *) &_colors_ne::BLACK);
    base(draw);
    glRotatef(alphaBase,0,1,0);
    glColor3fv((GLfloat *) &_colors_ne::MAGENTA);
    antebrazo(draw);

    //brazo(draw);


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
    glTranslatef(0,0.75,0);
    glScalef(0.25,1.5,0.25);
    switch (draw){
    case _mode::MODE_DRAW_CHESS:
        Cylinder->draw_chess();
        break;
    case _mode::MODE_DRAW_FILL:glScalef(0.2,0.4,0.2);
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
    glTranslatef(0,1.5,0);
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
    glTranslatef(0,1,0);
    glTranslatef(0,alturaBrazos,0);
    glRotatef(alphaBrazosPares,1,0,0);
    glRotatef(45,1,0,0);
    glTranslatef(0,-alturaBrazos,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glTranslatef(0,alturaBrazos,0);
    glRotatef((alphaBrazosImpares),0.5,0,0.5);
    glRotatef(45,0.5,0,0.5);
    glTranslatef(0,-alturaBrazos,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glTranslatef(0,alturaBrazos,0);
    glRotatef(alphaBrazosPares,0,0,1);
    glRotatef(45,0,0,1);
    glTranslatef(0,-alturaBrazos,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glTranslatef(0,alturaBrazos,0);
    glRotatef(alphaBrazosImpares,-0.5,0,0.5);
    glRotatef(45,-0.5,0,0.5);
    glTranslatef(0,-alturaBrazos,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glTranslatef(0,alturaBrazos,0);
    glRotatef(alphaBrazosPares,-1,0,0);
    glRotatef(45,-1,0,0);
    glTranslatef(0,-alturaBrazos,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glTranslatef(0,alturaBrazos,0);
    glRotatef(alphaBrazosImpares,-0.5,0,-0.5);
    glRotatef(45,-0.5,0,-0.5);
    glTranslatef(0,-alturaBrazos,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glTranslatef(0,alturaBrazos,0);
    glRotatef(alphaBrazosPares,0,0,-1);
    glRotatef(45,0,0,-1);
    glTranslatef(0,-alturaBrazos,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glTranslatef(0,alturaBrazos,0);
    glRotatef(alphaBrazosImpares,0.5,0,-0.5);
    glRotatef(45,0.5,0,-0.5);
    glTranslatef(0,-alturaBrazos,0);
    brazo(draw);
    glPopMatrix();

}

void _saltamontes::brazo(const _draw& draw) {
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(alphaBase, 0, 1, 0);
    glTranslatef(0,0.5,0);
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
    glTranslatef(0,1.2,0);
    cabina(draw);
    glPopMatrix();
}

void _saltamontes::cabina(const _draw& draw) {
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glRotatef(alphaBase,0,1,0);
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

    glPushMatrix();
    glTranslatef(0,0.1,0.175);
    asiento(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.1,0.175);
    asiento(draw);
    glPopMatrix();
}

void _saltamontes::asiento(const _draw& draw) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.15,0.15,0.15);
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



