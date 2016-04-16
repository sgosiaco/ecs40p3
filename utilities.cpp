#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

#include "utilities.h"

int getNumber()
{
  long long num = 0, flag = 1;
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
      flag = 0;
  }  // if first non-space is a digit
  else // first non-space is not a digit
    return ERR; // false

  while(c != '\n')
    c = cin.get();
  if (flag != 0)
    return num;
  else
    return ERR;
}//getNumber

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
      }//if
    }//else
  } while ((in == ERR) || (in > 1));

  if (in == 0)
    cout << "Goodbye.\n";

  return in;
} //getChoice
