#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "flight.h"

void Flight::readFlight(ifstream &inf)
{
  inf >> flightNum;
  inf.ignore(THOUSAND, '\n');
  inf.getline(origin, AIRPORT_MAX);
  inf.getline(destination, AIRPORT_MAX);
  plane = new Plane(inf);
}//readFlight

void Flight::addPassenger() const
{
  if(plane->addPassenger() != 0)
    cout << "We are sorry but Flight #" << flightNum << " is full.\n";
}//addPassenger

void Flight::printFlightInfo() const
{
  cout << left << setw(4) << flightNum << " " << setw(20) << origin << " "
       << destination << endl;
}//printFlightInfo

void Flight::writeFlight(ofstream &outf) const
{
  outf << flightNum << endl << origin << endl << destination << endl;
  plane->writePlane(outf);
}//writeFlight

int Flight::getFlightNum() const
{
  return flightNum;
}//getFlightNum

Flight::~Flight()
{
  delete plane;
}//decon
