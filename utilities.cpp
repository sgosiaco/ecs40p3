#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

#include "utilities.h"

int getNumber()
{
  long long num = 0;
  char c;

  for(c = cin.get(); isspace(c) && c != '\n'; c = cin.get());

  if(isdigit(c))
  {
    do
    {
      num = num * 10 + c - '0';
      c = cin.get();
    }  while(isdigit(c) && num <= INT_MAX);

    while(c != '\n' && isspace(c))
      c = cin.get();

    if(c != '\n' || num > INT_MAX)
      return ERR;
  }  // if first non-space is a digit
  else // first non-space is not a digit
    return ERR; // false

  while(c != '\n')
    c = cin.get();

  return num;
}//getNumber

int getChoice()
{
  int in = 0;
  printf("\nECS Flight Reservation Menu\n");
  printf("0. Exit.\n");
  printf("1. Add Passenger.\n");

  do
  {
    printf("\nPlease enter your choice: ");
    in = getNumber();

    if (in == ERR)
      printf("Your choice is invalid.\nPlease try again.\n");
    else//not invalid
    {
      if (in > 1)
      {
        printf("%d is not an available choice.\n", in);
        printf("Please try again.\n");
      }//if
    }//else
  } while ((in == ERR) || (in > 1));

  if (in == 0)
    printf("Goodbye.\n");

  return in;
} //getChoice
