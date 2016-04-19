#ifndef PLANE_H
#define PLANE_H

#include <fstream>
using namespace std;
#include "utilities.h"

#define NAME 80
#define THOUSAND 1000

class Plane
{
  private:
    int rows;
    int width;
    int reserved;
    char ***passengers;
    int getRow() const;
    void showGrid() const;
  public:
    Plane(ifstream &inf);
    ~Plane();
    int addPassenger();
    void writePlane(ofstream &outf) const;
}; //Plane

#endif
