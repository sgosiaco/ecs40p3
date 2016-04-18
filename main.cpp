#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

#include "flight.h"
#include "plane.h"
#include "utilities.h"

Flight** readFlights(int *in);
void addPassenger(Flight **in, const int num);
void writeFlights(Flight **in, const int num);
void freeFlights(Flight **in, const int num);

int main(void)
{
  int numFlights;
  Flight **flights = readFlights(&numFlights);

  while(getChoice() != 0)
    addPassenger(flights, numFlights);

  writeFlights(flights, numFlights);
  freeFlights(flights, numFlights);
  return 0;
}//main

Flight** readFlights(int *in)
{
  Flight **f;
  ifstream inf("reservations.txt");
  inf >> *in;
  f = new Flight*[*in];

  for(int i = 0; i < *in; i++)
    f[i] = new Flight(inf);

  inf.close();
  return f;
} //readFlights

void addPassenger(Flight **in, const int num)
{
  cout << "Flt# Origin               Destination\n";

  for(int i = 0; i < num; i++)
    in[i]->printFlightInfo();

  while(true)
  {
    cout << "\nFlight number (0 = exit): ";
    int read = getNumber();

    if(read <= 0)
    {
      if(read == ERR)
        cout << "That is an invalid flight number.\nPlease try again.\n";
      else //Exit case when user enters 0
        return;
    }//if invalid input
    else //Input greater than 0
    {
      for(int k = 0; k < num; k++)
      {
        if(read == in[k]->getFlightNum())
        {
          in[k]->addPassenger();
          return;
        }//if input matches flightNum
      }//for num

      cout << "We do not have a flight number "
           << read << ".\nPlease try again.\n";
    }//else
  }//while true
}//addPassenger


void writeFlights(const Flight **in, const int num)
{
  ofstream outf("reservations2.txt");
  outf << num << endl;

  for(int i = 0; i < num; i++)
    in[i]->writeFlight(outf);

  outf.close();
}//writeFlights

void freeFlights(Flight **in, const int num)
{
  for(int i = 0; i < num; i++)
    delete in[i];

  delete [] in;
}//freeFlights
