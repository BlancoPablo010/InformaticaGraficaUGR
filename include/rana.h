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

class _saltamontes
{
    _cone *Cone = new _cone;
    _cylinder *Cylinder = new _cylinder;
    _ply *Rana = new _ply("../InformaticaGraficaUGR/ply_models/rana.ply");
    _cube *Cube = new _cube;
    int alphaBase;
    int alphaBrazosPares;
    int alphaBrazosImpares;
    int alturaBrazos;
    int alphaCabina;

public:
    _saltamontes() {}
    void draw(const _draw&);

    void base(const _draw&);
    void antebrazo(const _draw&);
    void brazo(const _draw&);
    void cabina(const _draw&);
    void asiento(const _draw&);
    void brazos(const _draw&);
    void setAlphaBase(const int&);
    void setAlphaBrazos(const int&, const int&, const float&);
    void setAlphaCabina(const int&);

};

#endif // RANA_H
