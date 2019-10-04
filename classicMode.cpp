#ifndef CLASSICMODE_CPP
#define CLASSICMODE_CPP

#include <iostream>
#include "classicMode.h"
#include "gameofLife.cpp"
#include "gameofLife.h"


classicMode::classicMode()
{
}

classicMode::~classicMode()
{
}

int classicMode::calculateClassic(int x, int y, int rows, int columns, int ***grid)
{
  int coordinate[9][2];
  int sum = 0;
  int alive = 0;

  coordinate[0][0] = x-1;
  coordinate[0][1] = y -1;

  coordinate[1][0] = x-1;
  coordinate[1][1] = y;

  coordinate[2][0] = x-1;
  coordinate[2][1] = y + 1;

  coordinate[3][0] = x;
  coordinate[3][1] = y-1;

  coordinate[4][0] = x;
  coordinate[4][1] = y;

  coordinate[5][0] = x;
  coordinate[5][1] = y + 1;

  coordinate[6][0] = x + 1;
  coordinate[6][1] = y -1;

  coordinate[7][0] = x+1;
  coordinate[7][1] = y;

  coordinate[8][0] = x + 1;
  coordinate[8][1] = y + 1;

  for (int i = 0; i < rows; i++)
  {
    if (coordinate[i][0] < 0 || coordinate[i][1] < 0)
    {
      sum += 0;
    }

    else if (coordinate[i][0] >= rows || coordinate[i][1] >= columns)
    {
      sum += 0;
    }

    else
    {
      sum += grid[coordinate[i][0]] [coordinate[i][1]]  [0];
    }
  }

  if (sum == 3)
  {
    alive = 1;
  }
  else if (sum == 4)
  {
    alive = grid[x][y][0];
  }
  else
  {
    alive = 0;
  }



  return alive;
}
#endif
