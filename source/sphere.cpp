#include "sphere.h"

_sphere::_sphere(float Radius, int NumDivisions)
{
    Vertices.resize((NumDivisions/2 - 1)*NumDivisions + 2);
    Triangles.resize((NumDivisions/2 - 1)*NumDivisions * 2);

    vector<vector<float>> points;
    float increment = M_PI / float(NumDivisions/2);
    float angle;
    for(int i=1; i<NumDivisions/2; i++) {
        angle = M_PI/2 - i*increment;
        points.push_back({Radius*cos(angle), Radius*sin(angle), Radius*cos(angle)});
    }
    int step = NumDivisions/2 - 1;
    int matrixRows = NumDivisions/2;
    _initialize(axis::Y, points, Radius, 2*Radius, NumDivisions, step, matrixRows);

}
