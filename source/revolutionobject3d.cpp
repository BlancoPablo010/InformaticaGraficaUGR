#include "revolutionobject3d.h"
using namespace axis;

void _revolutionObject3D::_initialize(_coordenate axis, vector<vector<float>> sidePoints, float radius, float heigth, int numDivisions,
                                      int triangleStep, int matrixRows)
{
    float increment = 2*M_PI / numDivisions;
    float angle;
    int verticeCounter = 0;

    //Vertices initializer
    for(int i=0; i<numDivisions; i++) {
        angle = i * increment;
        for (int j=0; j<sidePoints.size(); j++) {
            switch (axis) {
            case X:

                Vertices[verticeCounter] = _vertex3f(sidePoints[j][0], sidePoints[j][1]*cos(angle), sidePoints[j][2]*sin(angle));
                if(i+1 == numDivisions) {
                    Vertices[verticeCounter+1] = _vertex3f(heigth/2, 0, 0);
                    Vertices[verticeCounter+2] = _vertex3f(-heigth/2, 0, 0);
                }
                break;
            case Y:
                Vertices[verticeCounter] = _vertex3f(sidePoints[j][0]*cos(angle), sidePoints[j][1], sidePoints[j][2]*sin(angle));
                if(i+1 == numDivisions) {
                    Vertices[verticeCounter+1] = _vertex3f(0, heigth/2, 0);
                    Vertices[verticeCounter+2] = _vertex3f(0, -heigth/2, 0);
                }
                break;
            case Z:
                Vertices[verticeCounter] = _vertex3f(sidePoints[j][0]*cos(angle), sidePoints[j][1]*sin(angle), sidePoints[j][2]);
                if(i+1 == numDivisions) {
                    Vertices[verticeCounter+1] = _vertex3f(0, 0, heigth/2);
                    Vertices[verticeCounter+2] = _vertex3f(0, 0, -heigth/2);
                }
                break;
            }
            verticeCounter++;
        }
    }

    //Triangle initializer
    int module = Vertices.size()-2;
    int triangleCounter = 0;
    for(int i=0; i<matrixRows; i++) {
        for(int j=0; j<module; j+=triangleStep) {
            if(i==0) {
                Triangles[triangleCounter]=_vertex3ui(module,(triangleStep+j)%module, j%module);
                triangleCounter++;
            }
            else if(i==matrixRows-1) {
                Triangles[triangleCounter]=_vertex3ui(module+1, (triangleStep-1+j)%module, (2*triangleStep-1+j)%module);
                triangleCounter++;
            }
            else {
                Triangles[triangleCounter]=_vertex3ui((i+j)%module, (i-1+j)%module, (i-1+triangleStep+j)%module);
                Triangles[triangleCounter+1]=_vertex3ui((i-1+triangleStep+j)%module, (i-1+triangleStep+1+j)%module, (i+j)%module);
                triangleCounter+=2;
            }
        }
    }
}
