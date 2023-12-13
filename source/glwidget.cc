/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2023
 * GPL 3
 */


#include "../include/glwidget.h"
#include "../include/window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);

  connect(&baseTimer, SIGNAL(timeout()), this, SLOT(updateBase()));
  baseTimer.start(16);

  connect(&brazosTimer, SIGNAL(timeout()), this, SLOT(updateBrazos()));
  brazosTimer.start(16);

  connect(&brazosTimer, SIGNAL(timeout()), this, SLOT(updateCabina()));
  cabinaTimer.start(16);

  connect(&lightTimer, SIGNAL(timeout()), this, SLOT(updateLight()));
  lightTimer.start(16);
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
  case Qt::Key_2:Object=OBJECT_CUBE;break;
  case Qt::Key_3:Object=OBJECT_CONE;break;
  case Qt::Key_4:Object=OBJECT_CYLINDER;break;
  case Qt::Key_5:Object=OBJECT_SPHERE;break;
  case Qt::Key_6:Object=OBJECT_PLY;break;
  case Qt::Key_7:Object=OBJECT_MODEL;break;

  case Qt::Key_A:Animation_activated=!Animation_activated;break;
  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;
  case Qt::Key_C:Draw_chess=!Draw_chess;break;

  //Teclas para controlar los modos de desplegue

  case Qt::Key_F3:Draw_flat=!Draw_flat;break;
  case Qt::Key_F4:Draw_smooth=!Draw_smooth;break;

  //Teclas para controlar las luces y los materiales

  case Qt::Key_J:light0=!light0;break;
  case Qt::Key_K:light1=!light1;break;

  case Qt::Key_M:material = (material+1)%3;break;

  //Teclas para controlar los movimientos de los grados de libertad
  case Qt::Key_Q:betaBase-=10;break;
  case Qt::Key_W:betaBase+=10;break;

  case Qt::Key_S:betaBrazosPares-=5;betaBrazosImpares+=5;break;
  case Qt::Key_D:betaBrazosPares+=5;betaBrazosImpares-=5;break;

  case Qt::Key_Z:betaCabina-=5;break;
  case Qt::Key_X:betaCabina+=5;break;

  //Teclas para subir la velocidad de los movimientos con los grados de libertad
  case Qt::Key_E:velocidadBase-=0.1;break;
  case Qt::Key_R:velocidadBase+=0.1;break;

  case Qt::Key_T:velocidadBrazos-=0.1;break;
  case Qt::Key_Y:velocidadBrazos+=0.1;break;

  case Qt::Key_U:velocidadCabina-=0.1;break;
  case Qt::Key_I:velocidadCabina+=0.1;break;

  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:Observer_distance*=1.2;break;
  case Qt::Key_PageDown:Observer_distance/=1.2;break;
  }

  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}

/*****************************************************************************//**
 * Funciones para actualizar la animación con QTimer
 *
 *
 *
 *****************************************************************************/

void _gl_widget::updateBase() {
  if(Animation_activated) {
        if(velocidadBase <= 0) velocidadBase = 0;
        alphaBase += 2 * velocidadBase;
        if (alphaBase >= 360) {
            alphaBase = 0;
        }
        Rana->setRotationBase(alphaBase);
        update();
    } else {
        if(abs(betaBase) >= 360) {
            alphaBase = 0;
        }
        else if (alphaBase <= 0){
            alphaBase = 360;
        }
        Rana->setRotationBase(betaBase);
        update();
    }
}

void _gl_widget::updateBrazos() {

    if(Animation_activated) {
        primeraAnimacion = false;

        if(velocidadBrazos<=0) velocidadBrazos = 0;
        if (rotateDownBrazos) {

            alphaBrazosPares += 1 * velocidadBrazos;
            alphaBrazosImpares -= 1 * velocidadBrazos;

            if(alphaBrazosPares >= 80) {
                alphaBrazosPares = 80;
                alphaBrazosImpares = 0;

                rotateDownBrazos = false;
            }
        } else {
            if(velocidadBrazos<=0) velocidadBrazos = 0;
            alphaBrazosPares -= 1 * velocidadBrazos;
            alphaBrazosImpares += 1 * velocidadBrazos;

            if(alphaBrazosPares <= 0) {
                alphaBrazosPares = 0;
                alphaBrazosImpares = 80;
                rotateDownBrazos = true;
            }
        }
        Rana->setRotationBrazos(alphaBrazosPares, alphaBrazosImpares, alturaBrazos);
        update();
    } else if (primeraAnimacion){
        primeraAnimacion = false;
        alphaBrazosPares = 0;
        alphaBrazosImpares = 80;
        Rana->setRotationBrazos(alphaBrazosPares, alphaBrazosImpares, alturaBrazos);
        update();
    }
    else {
        if(abs(betaBrazosPares) >= 80) {
            betaBrazosPares = 80;
            betaBrazosImpares = 0;

        } else if(betaBrazosImpares >= 80) {
            betaBrazosPares = 0;
            betaBrazosImpares = 80;
        }
        Rana->setRotationBrazos(betaBrazosPares, betaBrazosImpares, alturaBrazos);
        update();
    }
}


void _gl_widget::updateCabina() {
    if(Animation_activated) {
        if(velocidadCabina <= 0) velocidadCabina = 0;
        if (rotateCabina) {
            alphaCabina += 1 * velocidadCabina;

            if(alphaCabina >= 80) {
                alphaCabina = 80;
                rotateCabina = false;
            }
        } else {
            alphaCabina -= 1 * velocidadCabina;

            if(alphaCabina <= 0) {
                alphaCabina = 0;
                rotateCabina = true;
            }
        }

        Rana->setRotationCabina(alphaCabina);
        update();
    } else {
        if(betaCabina >= 80) {
            betaCabina = 80;
        } else if (betaCabina <= 0) {
                betaCabina = 0;
        }


        Rana->setRotationCabina(betaCabina);
        update();
    }
}

void _gl_widget::updateLight() {
    if(Animation_activated) {
        if (light1) {
                angle_light1 = (angle_light1 < 360.0f ) ? angle_light1 += 5.0f : angle_light1 = 0.0f;
                update();
        }
    }
}

/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_CONE:Cone->draw_point();break;
    case OBJECT_CYLINDER:Cylinder->draw_point();break;
    case OBJECT_SPHERE:Sphere->draw_point();break;
    case OBJECT_PLY:Ply->draw_point();break;
    case OBJECT_MODEL:Rana->draw(_mode::MODE_DRAW_POINT);break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_CONE:Cone->draw_line();break;
    case OBJECT_CYLINDER:Cylinder->draw_line();break;
    case OBJECT_SPHERE:Sphere->draw_line();break;
    case OBJECT_PLY:Ply->draw_line();break;
    case OBJECT_MODEL:Rana->draw(_mode::MODE_DRAW_LINE);break;
    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
    case OBJECT_CUBE:Cube.draw_fill();break;
    case OBJECT_CONE:Cone->draw_fill();break;
    case OBJECT_CYLINDER:Cylinder->draw_fill();break;
    case OBJECT_SPHERE:Sphere->draw_fill();break;
    case OBJECT_PLY:Ply->draw_fill();break;
    case OBJECT_MODEL:Rana->draw(_mode::MODE_DRAW_FILL);break;
    default:break;
    }
  }

  if (Draw_chess){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_CONE:Cone->draw_chess();break;
    case OBJECT_CYLINDER:Cylinder->draw_chess();break;
    case OBJECT_SPHERE:Sphere->draw_chess();break;
    case OBJECT_PLY:Ply->draw_chess();break;
    case OBJECT_MODEL:Rana->draw(_mode::MODE_DRAW_CHESS);break;
    default:break;
    }
  }

  if (Draw_flat) {
    _vertex4f Ambient(0.1,0.1,0.1,1);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,(GLfloat *)&Ambient);

    init_lights();
    init_materials();

    glEnable(GL_LIGHTING);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_flat_shadding();break;
    case OBJECT_CUBE:Cube.draw_flat_shadding();break;
    case OBJECT_CONE:Cone->draw_flat_shadding();break;
    case OBJECT_CYLINDER:Cylinder->draw_flat_shadding();break;
    case OBJECT_SPHERE:Sphere->draw_flat_shadding();break;
    case OBJECT_PLY:Ply->draw_flat_shadding();break;
    case OBJECT_MODEL:Rana->draw(_mode::MODE_DRAW_CHESS);break;
    default:break;
    }
    glDisable(GL_LIGHTING);
  }

  if(Draw_smooth) {
    _vertex4f Ambient(0.1,0.1,0.1,1);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,(GLfloat *)&Ambient);

    init_lights();
    init_materials();

    glEnable(GL_LIGHTING);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_smooth_shadding();break;
    case OBJECT_CUBE:Cube.draw_smooth_shadding();break;
    case OBJECT_CONE:Cone->draw_smooth_shadding();break;
    case OBJECT_CYLINDER:Cylinder->draw_smooth_shadding();break;
    case OBJECT_SPHERE:Sphere->draw_smooth_shadding();break;
    case OBJECT_PLY:Ply->draw_smooth_shadding();break;
    case OBJECT_MODEL:Rana->draw(_mode::MODE_DRAW_CHESS);break;
    default:break;
    }
    glDisable(GL_LIGHTING);
  }
}

/*****************************************************************************//**
 * Inits de luces y materiales
 *
 *
 *
 *****************************************************************************/
/*
void _gl_widget::init_lights() {
  if (light0){
    _vertex4f position(1,1,1,0); //Posición de la luz, último parámetro hace que sea una luz direccional
    _vertex4f diffuse(1,1,1,1);  //Color de la luz, en este caso blancoç



    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glLightfv(GL_LIGHT0,GL_POSITION,(GLfloat *)&position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,(GLfloat *)&diffuse);
    glPopMatrix();

    glEnable(GL_LIGHT0);

  }
  else{
    glDisable(GL_LIGHT0);
  }

  if (light1){

    _vertex4f diffuse(1.0f, 0.0f, 1.0f, 1.0f);
    _vertex4f position(12.0, 10.0, 20.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glLightfv(GL_LIGHT1, GL_POSITION, (GLfloat *)&position);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  (GLfloat *)&diffuse);
    glRotatef(angle_light1,0,1,0);
    glPopMatrix();

    glEnable(GL_LIGHT1);


  }
  else{
    glDisable(GL_LIGHT1);
  }
}

*/

void _gl_widget::init_lights() {
  if (light0){
    _vertex4f Position(0,0,1,0);

    glEnable(GL_LIGHT0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glLightfv(GL_LIGHT0,GL_POSITION,(GLfloat *)&Position);
    glPopMatrix();
  }
  else{
    glDisable(GL_LIGHT0);
  }

  if (light1){

    GLfloat light_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_magenta[] = {1.0f, 0.0f, 1.0f, 1.0f};

    _vertex4f light1_position(12.0, 10.0, 20.0, 1.0);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_magenta);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_magenta);
    glEnable(GL_LIGHT1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(angle_light1,0,1,0);
    glLightfv(GL_LIGHT1,GL_POSITION, (GLfloat *)&light1_position);
    glPopMatrix();



  }
  else{
    glDisable(GL_LIGHT1);
  }
}

void _gl_widget::init_materials() {
    switch (material){
      case 0:{
        _vertex3f Material_diffuse(0.3,0.3,0.3);
        _vertex3f Material_specular(0.1,0.1,0.1);
        _vertex3f Material_ambient(0.05,0.05,0.05);
        float Material_shininess=1;

        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(GLfloat *)&Material_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(GLfloat *)&Material_specular);
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(GLfloat *)&Material_ambient);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,Material_shininess);
    }
    break;
    case 1: {// emerald
        float Material_shininess=0.6;
        _vertex3f Material_diffuse(0.07568,0.61424, 	0.07568);
        _vertex3f Material_specular( 	0.633,0.727811, 	0.633);
        _vertex3f Material_ambient(0.0215, 0.1745, 0.0215);

        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(GLfloat *)&Material_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(GLfloat *)&Material_specular);
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(GLfloat *)&Material_ambient);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,Material_shininess);
    }
    break;
    case 2: { // yellow plastic
        float Material_shininess=.25;
        _vertex3f Material_diffuse(0.5,0.5,0.0);
        _vertex3f Material_specular(0.6,0.6, 0.5);
        _vertex3f Material_ambient(0.0, 0.0, 0.0);

        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(GLfloat *)&Material_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(GLfloat *)&Material_specular);
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(GLfloat *)&Material_ambient);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,Material_shininess);
    }
    break;
    }
}

/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=false;
  Draw_fill=false;
  Draw_chess=true;
  Draw_model=false;
  Draw_flat=false;
  Draw_smooth=false;
  Animation_activated=false;

  light0 = true;

  light1 = false;

  angle_light1=0.0f;

  material = 0;

  Cylinder = new _cylinder(0.5f,2,60);
  Cone = new _cone(0.5f,2,60);
  Sphere = new _sphere(1.f,60);
  string path = "../InformaticaGraficaUGR/ply_models/rana.ply";
  Ply = new _ply(path);
  Rana = new _rana();

}
