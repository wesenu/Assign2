#ifndef DOUGHNUTMODE_CPP
#define DOUGHNUTMODE_CPP

#include <iostream>
#include "gameofLife.cpp"
#include "doughnutMode.h"

doughnutMode::doughnutMode()
{

}
doughnutMode::~doughnutMode()
{

}

int doughnutMode::calculateDoughnut(int x, int y, int rows, int columns, int ***grid)
{

  int coordinate[9][2];
  int sum = 0;
  int alive = 0;



  coordinate[0][0] = (x+rows+(rows-1)) %rows;
  coordinate[0][1] = (y+columns+(columns-1)) %columns;

  coordinate[1][0] = (x+rows+(rows-1)) %rows;
  coordinate[1][1] = (y+columns+(columns)) %columns;

  coordinate[2][0] = (x+rows+(rows-1)) %rows;
  coordinate[2][1] = (y+columns+(columns+1)) %columns;

  coordinate[3][0] = (x+rows+(rows)) %rows;
  coordinate[3][1] = (y+columns+(columns-1)) %columns;

  coordinate[4][0] = (x+rows+(rows)) %rows;
  coordinate[4][1] = (y+columns+(columns)) %columns;

  coordinate[5][0] = (x+rows+(rows)) %rows;
  coordinate[5][1] = (y+columns+(columns+1)) %columns;

  coordinate[6][0] = (x+rows+(rows+1)) %rows;
  coordinate[6][1] = (y+columns+(columns-1)) %columns;

  coordinate[7][0] = (x+rows+(rows+1)) %rows;
  coordinate[7][1] = (y+columns+(columns)) %columns;

  coordinate[8][0] = (x+rows+(rows+1)) %rows;
  coordinate[8][1] = (y+columns+(columns+1)) %columns;

  for(int k=0; k < 9; k++)
  {

    sum += grid[coordinate[k][0]][coordinate[k][1]][0];

  }

  if(sum == 3)
  {
    alive = 1;
  }
  else if(sum == 4)
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
