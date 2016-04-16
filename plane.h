#ifndef PLANE_H
#define PLANE_H

#include <stdio.h>
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
    ~Plane();
    int addPassenger();
    Plane(FILE *fp);
    void writePlane(FILE *fp);
};

#endif
