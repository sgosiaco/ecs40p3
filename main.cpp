#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

#include "flight.h"
#include "plane.h"
#include "utilities.h"

Flight** readFlights(int *in);
void addPassenger(Flight **in, int num);
void writeFlights(Flight **in, int num);
void freeFlights(Flight **in, int num);

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
  //FILE *fp = fopen("reservations.txt", "r");
  ifstream inf("reservations.txt");
  //fscanf(fp, "%d", in);
  inf >> *in;
  //f = (Flight *)malloc(*in * sizeof(Flight));
  f = new Flight*[*in];

  for(int i = 0; i < *in; i++)
    f[i] = new Flight(inf);

  inf.close();
  return f;
} //readFlights

void addPassenger(Flight **in, int num)
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
        cout << "That is an invalid flight nunber.\nPlease try again.\n";
      else //Exit case when user enters 0
        return;
    }//if
    else //Input greater than 0
    {
      for(int k = 0; k < num; k++)
      {
        if(read == in[k]->getFlightNum())
        {
          in[k]->addPassenger();
          return;
        }//if
      }//for

      cout << "We do not have a flight number "
           << read <<".\nPlease try again.\n";
    }//else
  }//while
}//addPassenger


void writeFlights(Flight **in, int num)
{
  //FILE *fp = fopen("reservations2.txt", "w");
  ofstream outf("reservations2.txt");
  outf << num << endl;

  for(int i = 0; i < num; i++)
    in[i]->writeFlight(outf);

  outf.close();
}//writeFlights

void freeFlights(Flight **in, int num)
{
  for(int i = 0; i < num; i++)
    delete in[i];

  delete [] in;
}//freeFlights
