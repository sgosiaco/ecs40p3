#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flight.h"

Flight::Flight(FILE *fp)
{
  fscanf(fp, "%d", &(flightNum));
  fgets(origin, AIRPORT_MAX, fp);
  fgets(origin, AIRPORT_MAX, fp);
  strtok(origin, "\r\n");
  fgets(destination, AIRPORT_MAX, fp);
  strtok(destination, "\r\n");
  plane = new Plane(fp);
}//readFlight

void Flight::addPassenger()
{
  if(plane->addPassenger() != 0)
    printf("We are sorry but Flight #%d is full.\n", flightNum);
}//addPassenger

void Flight::printFlightInfo()
{
  printf("%-4d %-20s %s\n", flightNum, origin, destination);
}//printFlightInfo

void Flight::writeFlight(FILE *fp)
{
  fprintf(fp, "%d\n%s\n%s\n", flightNum, origin, destination);
  plane->writePlane(fp);
}//writeFlight

int Flight::getFlightNum()
{
  return flightNum;
}

Flight::~Flight()
{
  delete plane;
}//deconstructor
