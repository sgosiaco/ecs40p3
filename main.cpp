#include <stdio.h>
#include <stdlib.h>

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
  exit(EXIT_SUCCESS);
}//main

Flight** readFlights(int *in)
{
  Flight **f;
  FILE *fp = fopen("reservations.txt", "r");
  fscanf(fp, "%d", in);
  //f = (Flight *)malloc(*in * sizeof(Flight));
  f = new Flight*[*in];

  for(int i = 0; i < *in; i++)
    f[i] = new Flight(fp);

  fclose(fp);
  return f;
} //readFlights

void addPassenger(Flight **in, int num)
{
  printf("Flt# Origin               Destination\n");

  for(int i = 0; i < num; i++)
    in[i]->printFlightInfo();

  while(true)
  {
    printf("\nFlight number (0 = exit): ");
    int read = getNumber();

    if(read <= 0)
    {
      if(read == ERR)
        printf("That is an invalid flight nunber.\nPlease try again.\n");
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

      printf("We do not have a flight number %d.\nPlease try again.\n", read);
    }//else
  }//while
}//addPassenger


void writeFlights(Flight **in, int num)
{
  FILE *fp = fopen("reservations2.txt", "w");
  fprintf(fp, "%d\n", num);

  for(int i = 0; i < num; i++)
    in[i]->writeFlight(fp);

  fclose(fp);
}//writeFlights

void freeFlights(Flight **in, int num)
{
  for(int i = 0; i < num; i++)
    delete in[i];

  free(in);
}//freeFlights
