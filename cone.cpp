#include "cone.h"


_cone::_cone(float Radius, int Heigth, int NumDivisions)
{
    Vertices.resize(NumDivisions + 2);
    Triangles.resize(2*NumDivisions);

    vector<vector<float>> points {
        {Radius, Radius, -Heigth/2}
    };
    _initialize(axis::Z, points, Radius, Heigth, NumDivisions, 1, 2);
    ScaleVertices = Vertices;
}
