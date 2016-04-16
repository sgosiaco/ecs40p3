#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

#include "flight.h"

Flight::Flight(ifstream &inf)
{
  inf >> flightNum;
  inf.ignore(1000, '\n');
  inf.getline(origin, AIRPORT_MAX);
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

void Flight::writeFlight(ofstream &outf)
{
  outf << flightNum << endl << origin << endl << destination << endl;
  plane->writePlane(outf);
}//writeFlight

int Flight::getFlightNum()
{
  return flightNum;
}

Flight::~Flight()
{
  delete plane;
}//deconstructor
