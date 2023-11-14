#include "cylinder.h"

_cylinder::_cylinder(float Radius, float Heigth, int NumDivisions)
{
    Vertices.resize(2*NumDivisions + 2);
    Triangles.resize(4*NumDivisions);

    vector<vector<float>> points {
                                 {Heigth/2, Radius, Radius},
                                 {-Heigth/2, Radius, Radius}
    };
    _initialize(axis::X, points, Radius, Heigth, NumDivisions, 2, 3);
    ScaleVertices = Vertices;
}
