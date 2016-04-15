#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

#include "utilities.h"

int getNumber()
{
  char buf[BUF_SIZE];
  char *line;
  long num = 0;
  fgets(buf, BUF_SIZE, stdin);
  
  if(buf[strlen(buf) - 1] == '\n' && strlen(buf) == 1)
    return ERR;
  
  if(buf[strlen(buf) - 1] == '\n')
    buf[strlen(buf) - 1] = '\0';
  num = strtol(buf, &line, BASE);

  for(int i = 0; i < (int)strlen(line); i++)
  {
    if(isalpha(line[i]) || ispunct(line[i]) || iscntrl(line[i]))
      num = ERR;
  }//for

  if(num > INT_MAX || num < INT_MIN || num < 0)
    return ERR;
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
