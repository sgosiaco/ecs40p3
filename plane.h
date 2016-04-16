#ifndef PLANE_H
#define PLANE_H

#include <fstream>
#include "utilities.h"

#define NAME_MAX 80

class Plane
{
  private:
    int rows;
    int width;
    int reserved;
    char ***passengers;
    int getRow();
    void showGrid();
  public:
    Plane(ifstream &inf);
    ~Plane();
    int addPassenger();
    void writePlane(ofstream &outf);
};

#endif
