#include "ply.h"

_ply::_ply(string File)
{
    open(File);
    vector<float> Coordinates;
    vector<unsigned int> Positions;
    read(Coordinates,Positions);
    close();

    Vertices.resize(Coordinates.size()/3);
    int verticeCounter = 0;
    for(int i=0; i<Coordinates.size(); i+=3) {
        Vertices[verticeCounter] =
            _vertex3f(Coordinates[i],
                      Coordinates[i+1],
                      Coordinates[i+2]);
        verticeCounter++;
    }

    Triangles.resize(Positions.size()/3);
    int triangleCounter = 0;
    for(int i=0; i<Positions.size(); i+=3) {
        Triangles[triangleCounter]  = _vertex3ui(Positions[i],
                                                Positions[i+1],
                                                Positions[i+2]);

        triangleCounter++;
    }

    ScaleVertices = Vertices;
}
