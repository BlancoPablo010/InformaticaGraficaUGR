#ifndef RANA_H
#define RANA_H

#include "object3d.h"
#include "cone.h"
#include "cylinder.h"
#include "sphere.h"
#include "cube.h"
#include "ply.h"


namespace _mode {
    typedef enum { MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _draw;
}

using namespace _mode;

class _rana
{
    _cone *Cone = new _cone;
    _cylinder *Cylinder = new _cylinder;
    _ply *Rana = new _ply("../InformaticaGraficaUGR/ply_models/rana.ply");
    _cube *Cube = new _cube;
    int rotationBase;
    int rotationBrazosPares;
    int rotationBrazosImpares;
    int alturaBrazos;
    int rotationCabina;

public:
    _rana() {}
    void draw(const _draw&);

    void base(const _draw&);
    void antebrazo(const _draw&);
    void brazo(const _draw&);
    void cabina(const _draw&);
    void asiento(const _draw&);
    void brazos(const _draw&);
    void setRotationBase(const int&);
    void setRotationBrazos(const int&, const int&, const float&);
    void setRotationCabina(const int&);

};

#endif // RANA_H
