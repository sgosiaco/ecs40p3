#ifndef FLIGHT_H
#define FLIGHT_H

#include <fstream>
#include "plane.h"
#include "utilities.h"

#define AIRPORT_MAX 20
#define ERR -1

class Flight
{
  private:
    int flightNum;
    char origin[AIRPORT_MAX];
    char destination[AIRPORT_MAX];
    Plane *plane;
  public:
    Flight(ifstream &inf);
    ~Flight();
    void printFlightInfo();
    void addPassenger();
    void writeFlight(ofstream &outf);
    const int getFlightNum();
}; //Flight

#endif
