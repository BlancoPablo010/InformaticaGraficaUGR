#include "../include/rana.h"
_rana::_rana() {

    ConeBase = new _cone;
    CylinderAntebrazo = new _cylinder;
    Rana = new _ply("../InformaticaGraficaUGR/ply_models/rana.ply");

    //ConeAsiento init
    for (unsigned int i=0; i<8; i++) {
        _cylinder* new_cylinder = new _cylinder;
        CylinderBrazo.push_back(new_cylinder);
    }

    //CubeCabina init
    for (unsigned int i=0; i<8; i++) {
        _cube* new_cube = new _cube;
        CubeCabina.push_back(new_cube);
    }

    //ConeAsiento init
    for (unsigned int i=0; i<16; i++) {
        _cone* new_cone = new _cone;
        ConeAsiento.push_back(new_cone);
    }

}

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
        ConeBase->draw_chess();
        break;
    case _mode::MODE_DRAW_FILL:
        ConeBase->draw_fill();
        break;
    case _mode::MODE_DRAW_LINE:
        ConeBase->draw_line();
        break;
    case _mode::MODE_DRAW_POINT:
        ConeBase->draw_chess();
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
        CylinderAntebrazo->draw_chess();
        break;
    case _mode::MODE_DRAW_FILL:
        CylinderAntebrazo->draw_fill();
        break;
    case _mode::MODE_DRAW_LINE:
        CylinderAntebrazo->draw_line();
        break;
    case _mode::MODE_DRAW_POINT:
        CylinderAntebrazo->draw_chess();
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
    brazo(draw, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef((rotationBrazosImpares),0.5,0,0.5);
    glRotatef(45,0.5,0,0.5);
    glRotatef(135,0,1,0);
    brazo(draw, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosPares,0,0,1);
    glRotatef(45,0,0,1);
    glRotatef(90,0,1,0);
    brazo(draw, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosImpares,-0.5,0,0.5);
    glRotatef(45,-0.5,0,0.5);
    glRotatef(45,0,1,0);
    brazo(draw, 3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosPares,-1,0,0);
    glRotatef(45,-1,0,0);
    brazo(draw, 4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosImpares,-0.5,0,-0.5);
    glRotatef(45,-0.5,0,-0.5);
    glRotatef(315,0,1,0);
    brazo(draw, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosPares,0,0,-1);
    glRotatef(45,0,0,-1);
    glRotatef(270,0,1,0);
    brazo(draw, 6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(rotationBrazosImpares,0.5,0,-0.5);
    glRotatef(45,0.5,0,-0.5);
    glRotatef(225,0,1,0);
    brazo(draw, 7);
    glPopMatrix();

}

void _rana::brazo(const _draw& draw, const unsigned int & index) {
    glColor3fv((GLfloat *) &_colors_ne::CYAN);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //glRotatef(rotationBase, 0, 1, 0);
    glTranslatef(0,0.5,0);
    glScalef(0.08,1,0.08);
    switch (draw){
    case _mode::MODE_DRAW_CHESS:
        CylinderBrazo[index]->draw_chess();
        break;
    case _mode::MODE_DRAW_FILL:
        CylinderBrazo[index]->draw_fill();
        break;
    case _mode::MODE_DRAW_LINE:
        CylinderBrazo[index]->draw_line();
        break;
    case _mode::MODE_DRAW_POINT:
        CylinderBrazo[index]->draw_chess();
        break;
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.2,0);
    glRotatef(rotationCabina,0,1,0);
    glRotatef(-40,0,1,0);
    cabina(draw, index);
    glPopMatrix();
}

void _rana::cabina(const _draw& draw, const unsigned int & index) {
    glMatrixMode(GL_MODELVIEW);

    glColor3fv((GLfloat *) &_colors_ne::BLACK);
    glPushMatrix();
    glScalef(0.2,0.4,0.2);
    switch (draw){
    case _mode::MODE_DRAW_CHESS:
        CubeCabina[index]->draw_chess();
        break;
    case _mode::MODE_DRAW_FILL:
        CubeCabina[index]->draw_fill();
        break;
    case _mode::MODE_DRAW_LINE:
        CubeCabina[index]->draw_line();
        break;
    case _mode::MODE_DRAW_POINT:
        CubeCabina[index]->draw_chess();
        break;
    }
    glPopMatrix();

    glColor3fv((GLfloat *) &_colors_ne::RED);
    glPushMatrix();
    glTranslatef(0,0.1,0.175);
    asiento(draw, index*2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.1,0.175);
    asiento(draw, index*2 +1);
    glPopMatrix();
}

void _rana::asiento(const _draw& draw, const unsigned int& index) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.15,0.15,0.15);
    switch (draw){
    case _mode::MODE_DRAW_CHESS:
        ConeAsiento[index]->draw_chess();
        break;
    case _mode::MODE_DRAW_FILL:
        ConeAsiento[index]->draw_fill();
        break;
    case _mode::MODE_DRAW_LINE:
        ConeAsiento[index]->draw_line();
        break;
    case _mode::MODE_DRAW_POINT:
        ConeAsiento[index]->draw_chess();
        break;
    }
    glPopMatrix();
}



