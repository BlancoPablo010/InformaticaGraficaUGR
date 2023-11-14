#ifndef _PLY_OBJECT3D_H
#define _PLY_OBJECT3D_H


#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "vertex.h"
#include "object3d.h"

class _PLY_object3D: public _object3D
{
public:
    _PLY_object3D(){}
    int open(const string &File_name);
    void read(vector<float> &Coordinates, vector<unsigned int> &Positions);
    void close();

private:
    void get_token(std::istringstream &Line_stream1,std::string &Token1);
    bool get_new_line(std::ifstream &File,std::istringstream &Line_stream);

    std::ifstream File;
};

#endif // _PLY_OBJECT3D_H
