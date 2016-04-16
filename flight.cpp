#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flight.h"

void readFlight(Flight *in, FILE *fp)
{
  fscanf(fp, "%d", &(in->flightNum));
  fgets(in->origin, AIRPORT_MAX, fp);
  fgets(in->origin, AIRPORT_MAX, fp);
  strtok(in->origin, "\n\r");
  fgets(in->destination, AIRPORT_MAX, fp);
  strtok(in->destination, "\n\r");
  in->plane = (Plane *) malloc(sizeof(Plane));
  in->plane = new Plane(fp);
}//readFlight

void addPassenger(Flight *in, int num)
{
  printf("Flt# Origin               Destination\n");

  for(int i = 0; i < num; i++)
    printFlightInfo(in + i);

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
        if(read == (in + k)->flightNum)
        {
          addPassenger(in + k);
          return;
        }//if
      }//for

      printf("We do not have a flight number %d.\nPlease try again.\n", read);
    }//else
  }//while
}//addPassenger

void addPassenger(Flight *in)
{
  if(in->plane->addPassenger() != 0)
    printf("We are sorry but Flight #%d is full.\n", in->flightNum);
}//addPassenger

void printFlightInfo(Flight *in)
{
  printf("%-4d %-20s %s\n", in->flightNum, in->origin, in->destination);
}//printFlightInfo

void writeFlights(Flight *in, int num)
{
  FILE *fp = fopen("reservations2.txt", "w");
  fprintf(fp, "%d\n", num);

  for(int i = 0; i < num; i++)
    writeFlight(in + i, fp);

  fclose(fp);
}//writeFlights

void writeFlight(Flight *in, FILE *fp)
{
  fprintf(fp, "%d\n%s\n%s\n", in->flightNum, in->origin, in->destination);
  in->plane->writePlane(fp);
}//writeFlight

void freeFlight(Flight *in)
{
  free(in->plane);
}
