#include <climits>
#include <cctype>
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
    flag = 0; // false

  while(c != '\n')
    c = cin.get();

  if (flag)
    return num;
  else //not a number
    return ERR;
}//getNumber
