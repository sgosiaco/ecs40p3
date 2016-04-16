#include <iostream>
#include <fstream>
#include <iomanip>
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
    cout << "We are sorry but Flight #" << flightNum << " is full.\n";
}//addPassenger

void Flight::printFlightInfo()
{
  //printf("%-4d %-20s %s\n", flightNum, origin, destination);
  cout << setw(4) << flightNum << setw(20) << origin << " " << destination
       << endl;
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
