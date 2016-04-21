#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

#include "flight.h"
#include "plane.h"
#include "utilities.h"

Flight* readFlights(int *in);
int getChoice();
void addPassenger(const Flight *in, const int num);
void writeFlights(const Flight *in, const int num);
void freeFlights(const Flight *in);

int main(void)
{
  int numFlights;
  Flight *flights = readFlights(&numFlights);

  while(getChoice() != 0)
    addPassenger(flights, numFlights);

  writeFlights(flights, numFlights);
  freeFlights(flights);
  return 0;
}//main

Flight* readFlights(int *in)
{
  Flight *f;
  ifstream inf("reservations.txt");
  inf >> *in;
  f = new Flight[*in];

  for(int i = 0; i < *in; i++)
    f[i].readFlight(inf);

  inf.close();
  return f;
} //readFlights

int getChoice()
{
  int in = 0;
  cout << "\nECS Flight Reservation Menu\n";
  cout << "0. Exit.\n";
  cout << "1. Add Passenger.\n";

  do
  {
    cout << "\nPlease enter your choice: ";
    in = getNumber();

    if (in == ERR)
      cout << "Your choice is invalid.\nPlease try again.\n";
    else//not invalid
    {
      if (in > 1)
      {
        cout << in << " is not an available choice.\n";
        cout << "Please try again.\n";
      }//if in > 1
    }//else
  } while ((in == ERR) || (in > 1));

  if (in == 0)
    cout << "Goodbye.\n";

  return in;
} //getChoice

void addPassenger(const Flight *in, const int num)
{
  cout << "Flt# Origin               Destination\n";

  for(int i = 0; i < num; i++)
    in[i].printFlightInfo();

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
        if(read == in[k].getFlightNum())
        {
          in[k].addPassenger();
          return;
        }//if input matches flightNum
      }//for num

      cout << "We do not have a flight number "
           << read << ".\nPlease try again.\n";
    }//else
  }//while true
}//addPassenger


void writeFlights(const Flight *in, const int num)
{
  ofstream outf("reservations2.txt");
  outf << num << endl;

  for(int i = 0; i < num; i++)
    in[i].writeFlight(outf);

  outf.close();
}//writeFlights

void freeFlights(const Flight *in)
{
  delete [] in;
}//freeFlights
