#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "plane.h"

Plane::Plane(ifstream &inf)
{
  int row = 0;
  char name[NAME], col = 0;
  inf >> rows >> width >> reserved;
  inf.ignore(THOUSAND, '\n');
  passengers = new char**[rows];

  for(int i = 0; i < rows; i++)
  {
    passengers[i] = new char*[width];

    for(int k = 0; k < width; k++)
      passengers[i][k] = 0;
  }//for rows

  for(int k = 0; k < reserved; k++)
  {
    inf >> row >> col;
    inf.get();
    inf.getline(name, NAME);
    passengers[row - 1][col-'A'] = new char[strlen(name) + 1];
    strcpy(passengers[row - 1][col-'A'], name);
  }//for reserved
}//Cons

Plane::~Plane()
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (passengers[i][j] != 0)
        delete [] passengers[i][j];
    }//for

    delete [] passengers[i];

  }//for

  delete [] passengers;
}//decon

int Plane::addPassenger()
{
  char name[NAME];
  int row = 0, col = 0;

  if (reserved == (rows) * (width))
    return 1;
  else//if there's room
  {
    cout << "Please enter the name of the passenger: ";
    cin.getline(name, NAME);
    showGrid();

    while(true)
    {
      row = getRow();
      cout << "Please enter the seat letter you wish to reserve: ";
      col = cin.get() - 'A';
      cin.get();

      if (passengers[row - 1][col] == 0)
        break;
      cout << "That seat is already occupied.\nPlease try again.\n";
    }//while

    passengers[row - 1][col] = new char[strlen(name) + 1];
    strcpy(passengers[row - 1][col], name);
    reserved++;
    return 0;
  }//else
}//addPassenger

int Plane::getRow() const
{
  int row = 0;

  do
  {
    do
    {
      cout << "\nPlease enter the row of the seat you wish to reserve: ";

      if((row  = getNumber()) < 0)
        cout << "That is an invalid row number.\nPlease try again.\n";

      if(row == 0 || (rows < row)) //Row is too large or too small
        cout << "There is no row #" << row
             << " on this flight.\nPlease try again.\n";

    } while (row <= 0);

  } while (rows < row);

  return row;
}//getRow

void Plane::writePlane(ofstream &outf) const
{
  outf << rows << " " << width << " " << reserved << endl;

  for(int row = 0; row < rows; row++)
  {
    for (int i = 0; i < width; i++)
    {
      if (passengers[row][i] != 0)
      {
        char aisle = i + 'A';
        outf << row + 1 << aisle << " " << passengers[row][i] << endl;
      }//if passenger exists
    }//for width
  }//for row
}//writePlane

void Plane::showGrid() const
{
  cout << "ROW# ";

  for(int i = 0; i < width; i++)
    cout.put(i + 'A');
  cout.put('\n');

  for(int k = 0; k < rows; k++)
  {
    cout << right << setw(2) << k + 1 << "   ";

    for(int j = 0; j < width; j++)
    {
      if(passengers[k][j] != 0)
        cout.put('X');
      else//seat isn't taken
        cout.put('-');
    }//for width

    cout.put('\n');
  }//for row

  cout << "\nX = reserved.\n";
}//showGrid
