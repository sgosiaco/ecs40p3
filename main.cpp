#include <stdio.h>
#include <stdlib.h>

#include "flight.h"
#include "plane.h"
#include "utilities.h"

void readFlights(Flight **f, int *in);

int main(void)
{
  int numFlights;
  Flight *flights;
  readFlights(&flights, &numFlights);

  while(getChoice() != 0)
    addPassenger(flights, numFlights);

  writeFlights(flights, numFlights);
  exit(EXIT_SUCCESS);
}//main

void readFlights(Flight **f, int *in)
{
  FILE *fp = fopen("reservations.txt", "r");
  fscanf(fp, "%d", in);
  *f = (Flight *)malloc(*in * sizeof(Flight));

  for(int i = 0; i < *in; i++)
    readFlight(*f + i, fp);

  fclose(fp);
} //readFlights
