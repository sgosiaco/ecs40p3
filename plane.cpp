#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "plane.h"

int addPassenger(Plane *in)
{
  char name[NAME_MAX];
  int row = 0, col = 0;

  if (in->reserved == (in->rows) * (in->width))
    return 1;
  else//if there's room
  {
    printf("Please enter the name of the passenger: ");
    fgets(name, NAME_MAX, stdin);
    strtok(name, "\n\r");
    showGrid(in);

    while(true)
    {
      row = getRow(in);
      printf("Please enter the seat letter you wish to reserve: ");
      col = getchar() - 'A';
      getchar();

      if ((in->passengers)[row - 1][col] == 0)
        break;
      printf("That seat is already occupied.\nPlease try again.\n");
    }//while

    (in->passengers)[row - 1][col] = (char *) malloc(strlen(name) + 1);
    strcpy((in->passengers)[row - 1][col], name);
    in->reserved++;
    return 0;
  }//else
}//addPassenger

int getRow(Plane *in)
{
  int row = 0;

  do
  {
    do
    {
      printf("\nPlease enter the row of the seat you wish to reserve: ");

      if((row  = getNumber()) < 0)
        printf("That is an invalid row number.\nPlease try again.\n");

      if(row == 0 || (in->rows < row)) //Row is too large or too small
        printf("There is no row #%d on this flight.\nPlease try again.\n", row);

    } while (row <= 0);

  } while (in->rows < row);

  return row;
}//getRow

void freePlane(Plane *in)
{
  for (int i = 0; i < in->rows; i++)
  {
    for (int j = 0; j < in->width; j++)
    {
      if ((in->passengers)[i][j] != 0)
        free((in->passengers)[i][j]);
    }//for

    free((in->passengers)[i]);

  }//for

  free(in->passengers);
}//freePlane

void readPlane(Plane *in, FILE *fp)
{
  int row = 0;
  char name[NAME_MAX], col = 0;
  fscanf(fp, "%d %d %d", &(in->rows), &(in->width), &(in->reserved));
  in->passengers = (char ***) malloc(in->rows * sizeof(char **));

  for(int i = 0; i < in->rows; i++)
  {
    (in->passengers)[i] = (char **) malloc(in->width * sizeof(char *));

    for(int k = 0; k < in->width; k++)
      (in->passengers)[i][k] = 0;
  }//for

  for(int k = 0; k < in->reserved; k++)
  {
    fscanf(fp, "%d%c ", &row, &col);
    fgets(name, NAME_MAX, fp);
    strtok(name, "\r\n");
    (in->passengers)[row - 1][col-'A'] = (char *) malloc(strlen(name) + 1);
    strcpy((in->passengers)[row - 1][col-'A'], name);
  }//for
}//readPlane

void writePlane(Plane *in, FILE *fp)
{
  fprintf(fp, "%d %d %d\n", in->rows, in->width, in->reserved);

  for(int row = 0; row < in->rows; row++)
  {
    for (int i = 0; i < in->width; i++)
    {
      if ((in->passengers)[row][i] != 0)
        fprintf(fp, "%d%c %s\n", row + 1, i + 'A', (in->passengers)[row][i]);
    }//for
  }//for
}//writePlane

void showGrid(Plane *in)
{
  printf("ROW# ");

  for(int i = 0; i < in->width; i++)
    putchar(i + 'A');
  putchar('\n');

  for(int k = 0; k < in->rows; k++)
  {
    printf("%2d   ", k + 1);

    for(int j = 0; j < in->width; j++)
    {
      if((in->passengers)[k][j] != 0)
        putchar('X');
      else//seat isn't taken
        putchar('-');
    }//for

    putchar('\n');
  }//for

  printf("\nX = reserved.\n");
}//showGrid
