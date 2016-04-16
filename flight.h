#ifndef FLIGHT_H
#define FLIGHT_H

#include <stdio.h>
#include "plane.h"
#include "utilities.h"

#define AIRPORT_MAX 20
#define ERR -1

typedef struct
{
  int flightNum;
  char origin[AIRPORT_MAX];
  char destination[AIRPORT_MAX];
  Plane *plane;
} Flight;

void readFlight(Flight *in, FILE *fp);
void addPassenger(Flight *in, int num);
void printFlightInfo(Flight *in);
void addPassenger(Flight *in);
void writeFlights(Flight *in, int num);
void writeFlight(Flight *in, FILE *fp);
void freeFlight(Flight *in);

#endif
