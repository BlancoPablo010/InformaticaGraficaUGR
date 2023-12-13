#include "../include/cone.h"


_cone::_cone(float Radius, float Heigth, int NumDivisions)
{
    Vertices.resize(NumDivisions + 2);
    Triangles.resize(2*NumDivisions);

    vector<vector<float>> points {
                                 {Radius, -Heigth/2, Radius}
    };
    _initialize(axis::Y, points, Radius, Heigth, NumDivisions, 1, 2);





}
