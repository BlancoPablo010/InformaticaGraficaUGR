#include "../include/rana.h"

void _rana::setRotationBase(const int& rotationAngle) {
    this->rotationBase = rotationAngle;
}

void _rana::setRotationBrazos(const int& pares, const int& impares, const float& alturaBrazos) {
    this->rotationBrazosPares = pares;
    this->rotationBrazosImpares = impares;
    this->alturaBrazos = alturaBrazos;
}

void _rana::setRotationCabina(const int& rotationAngle) {
    this->rotationCabina = rotationAngle;
}

void _rana::draw(const _draw& draw)
{
    glColor3fv((GLfloat *) &_colors_ne::BLACK);
    base(draw);

    glColor3fv((GLfloat *) &_colors_ne::MAGENTA);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(rotationBase,0,1,0);
    antebrazo(draw);
    glPopMatrix();

}

void _rana::base(const _draw& draw) {
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

void _rana::antebrazo(const _draw& draw) {


    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.75,0);
    glScalef(0.25,1.5,0.25);
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
    glTranslatef(0,1.5,0);
    glScalef(0.07,0.07,0.07);
    glRotatef(180,0,0,1);

    glColor3fv((GLfloat *) &_colors_ne::GREEN);

    switch (draw){
    case _mode::MODE_DRAW_CHESS:
        Rana->draw_chess();
        break;
    case _mode::MODE_DRAW_FILL:
        Rana->draw_fill();
        break;
    case _mode::MODE_DRAW_LINE:
        Rana->draw_line();
        break;
    case _mode::MODE_DRAW_POINT:
        Rana->draw_chess();
        break;
    }
    glPopMatrix();

    brazos(draw);

}

void _rana::brazos(const _draw& draw) {

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosPares,1,0,0);
    glRotatef(45,1,0,0);
    glRotatef(180,0,1,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef((rotationBrazosImpares),0.5,0,0.5);
    glRotatef(45,0.5,0,0.5);
    glRotatef(135,0,1,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosPares,0,0,1);
    glRotatef(45,0,0,1);
    glRotatef(90,0,1,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosImpares,-0.5,0,0.5);
    glRotatef(45,-0.5,0,0.5);
    glRotatef(45,0,1,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosPares,-1,0,0);
    glRotatef(45,-1,0,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosImpares,-0.5,0,-0.5);
    glRotatef(45,-0.5,0,-0.5);
    glRotatef(315,0,1,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosPares,0,0,-1);
    glRotatef(45,0,0,-1);
    glRotatef(270,0,1,0);
    brazo(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosImpares,0.5,0,-0.5);
    glRotatef(45,0.5,0,-0.5);
    glRotatef(225,0,1,0);
    brazo(draw);
    glPopMatrix();

}

void _rana::brazo(const _draw& draw) {
    glColor3fv((GLfloat *) &_colors_ne::CYAN);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //glRotatef(rotationBase, 0, 1, 0);
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
    glRotatef(rotationCabina,0,1,0);
    glRotatef(-40,0,1,0);
    cabina(draw);
    glPopMatrix();
}

void _rana::cabina(const _draw& draw) {
    glMatrixMode(GL_MODELVIEW);

    glColor3fv((GLfloat *) &_colors_ne::BLACK);
    glPushMatrix();
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

    glColor3fv((GLfloat *) &_colors_ne::RED);
    glPushMatrix();
    glTranslatef(0,0.1,0.175);
    asiento(draw);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.1,0.175);
    asiento(draw);
    glPopMatrix();
}

void _rana::asiento(const _draw& draw) {
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



