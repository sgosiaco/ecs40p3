#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

#include "flight.h"

Flight::Flight(ifstream &inf)
{
  //fscanf(fp, "%d", &(flightNum));
  inf >> flightNum;
  //fgets(origin, AIRPORT_MAX, fp);
  inf.ignore(1000, '\n');
  //fgets(origin, AIRPORT_MAX, fp);
  //strtok(origin, "\r\n");
  inf.getline(origin, AIRPORT_MAX);
  //fgets(destination, AIRPORT_MAX, fp);
  //strtok(destination, "\r\n");
  inf.getline(destination, AIRPORT_MAX);
  plane = new Plane(inf);
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
