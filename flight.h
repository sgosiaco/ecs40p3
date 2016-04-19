#ifndef FLIGHT_H
#define FLIGHT_H

#include <fstream>
#include "plane.h"
#include "utilities.h"

#define AIRPORT_MAX 20
#define ERR -1
#define THOUSAND 1000

class Flight
{
  private:
    int flightNum;
    char origin[AIRPORT_MAX];
    char destination[AIRPORT_MAX];
    Plane *plane;
  public:
    ~Flight();
    void readFlight(ifstream &inf);
    void printFlightInfo() const;
    void addPassenger() const;
    void writeFlight(ofstream &outf) const;
    int getFlightNum() const;
}; //Flight

#endif
