#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "plane.h"

Plane::Plane(FILE *fp)
{
  int row = 0;
  char name[NAME_MAX], col = 0;
  fscanf(fp, "%d %d %d", &(rows), &(width), &(reserved));
  passengers = (char ***) malloc(rows * sizeof(char **));

  for(int i = 0; i < rows; i++)
  {
    passengers[i] = (char **) malloc(width * sizeof(char *));

    for(int k = 0; k < width; k++)
      passengers[i][k] = 0;
  }//for

  for(int k = 0; k < reserved; k++)
  {
    fscanf(fp, "%d%c ", &row, &col);
    fgets(name, NAME_MAX, fp);
    strtok(name, "\r\n");
    passengers[row - 1][col-'A'] = (char *) malloc(strlen(name) + 1);
    strcpy(passengers[row - 1][col-'A'], name);
  }//for
}//Constructor

Plane::~Plane()
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (passengers[i][j] != 0)
        free(passengers[i][j]);
    }//for

    free(passengers[i]);

  }//for

  free(passengers);
}//destructor

int Plane::addPassenger()
{
  char name[NAME_MAX];
  int row = 0, col = 0;

  if (reserved == (rows) * (width))
    return 1;
  else//if there's room
  {
    printf("Please enter the name of the passenger: ");
    fgets(name, NAME_MAX, stdin);
    strtok(name, "\r\n");
    showGrid();

    while(true)
    {
      row = getRow();
      printf("Please enter the seat letter you wish to reserve: ");
      col = getchar() - 'A';
      getchar();

      if (passengers[row - 1][col] == 0)
        break;
      printf("That seat is already occupied.\nPlease try again.\n");
    }//while

    passengers[row - 1][col] = (char *) malloc(strlen(name) + 1);
    strcpy(passengers[row - 1][col], name);
    reserved++;
    return 0;
  }//else
}//addPassenger

int Plane::getRow()
{
  int row = 0;

  do
  {
    do
    {
      printf("\nPlease enter the row of the seat you wish to reserve: ");

      if((row  = getNumber()) < 0)
        printf("That is an invalid row number.\nPlease try again.\n");

      if(row == 0 || (rows < row)) //Row is too large or too small
        printf("There is no row #%d on this flight.\nPlease try again.\n", row);

    } while (row <= 0);

  } while (rows < row);

  return row;
}//getRow

void Plane::writePlane(FILE *fp)
{
  fprintf(fp, "%d %d %d\n", rows, width, reserved);

  for(int row = 0; row < rows; row++)
  {
    for (int i = 0; i < width; i++)
    {
      if (passengers[row][i] != 0)
        fprintf(fp, "%d%c %s\n", row + 1, i + 'A', passengers[row][i]);
    }//for
  }//for
}//writePlane

void Plane::showGrid()
{
  printf("ROW# ");

  for(int i = 0; i < width; i++)
    putchar(i + 'A');
  putchar('\n');

  for(int k = 0; k < rows; k++)
  {
    printf("%2d   ", k + 1);

    for(int j = 0; j < width; j++)
    {
      if(passengers[k][j] != 0)
        putchar('X');
      else//seat isn't taken
        putchar('-');
    }//for

    putchar('\n');
  }//for

  printf("\nX = reserved.\n");
}//showGrid
