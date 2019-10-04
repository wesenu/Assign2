#ifndef MIRRORMODE_CPP
#define MIRRORMODE_CPP

#include <iostream>
#include "gameofLife.cpp"
#include "mirrorMode.h"

MirrorMode::MirrorMode()
{

}

MirrorMode::~MirrorMode()
{

}

int MirrorMode::calculateMirror(int x, int y, int rows, int columns, int ***grid)
{
  int coordinate[9][2];
  int sum =0;
  int alive =0;


  for(int i=0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      sum =0;
				if (i == 0 && j == 0) {
					if(grid[i+1][j][0] == 1) sum+=2;
					if(grid[i][j+1][0] == 1) sum+=2;
					if(grid[i+1][j+1][0] == 1) sum++;
					if(grid[i][j][0] == 1) sum+=3;
				}
				else if (i == 0 && j == (columns - 1)) {
					if(grid[i+1][j][0] == 1) sum+=2;
					if(grid[i][j-1][0] == 1) sum+=2;
					if(grid[i+1][j-1][0] == 1) sum++;
					if(grid[i][j][0] == 1) sum+=3;
				}
				else if (i == (rows - 1 ) && j == (columns - 1)) {
					if(grid[i-1][j][0] == 1) sum+=2;
					if(grid[i][j-1][0] == 1) sum+=2;
					if(grid[i-1][j-1][0] == 1) sum++;
					if(grid[i][j][0] == 1) sum+=3;
				}
				else if (i == (rows - 1) && j == 0) {
					if(grid[i-1][j][0] == 1) sum+=2;
					if(grid[i][j+1][0] == 1) sum+=2;
					if(grid[i-1][j+1][0] == 1) sum++;
					if(grid[i][j][0] == 1) sum+=3;
            	}
	            else if (i == 0) {
					if(grid[i+1][j][0] == 1) sum++;
					if(grid[i][j+1][0] == 1) sum+=2;
					if(grid[i+1][j+1][0] == 1) sum++;
					if(grid[i][j-1][0] ==1) sum+=2;
					if(grid[i+1][j-1][0] == 1) sum++;
					if(grid[i][j][0] == 1) sum++;
    	        }
				else if (j == 0) {
					if(grid[i-1][j][0] == 1) sum+=2;
					if(grid[i+1][j][0] == 1) sum+=2;
					if(grid[i][j+1][0] == 1) sum++;
					if(grid[i+1][j+1][0] == 1) sum++;
					if(grid[i-1][j+1][0] == 1) sum++;
					if(grid[i][j][0] == 1) sum++;
				}
	            else if (i == (rows - 1)) {
					if(grid[i-1][j][0] == 1) sum++;
					if(grid[i][j+1][0] == 1) sum+=2;
					if(grid[i-1][j+1][0] == 1) sum++;
					if(grid[i][j-1][0] ==1) sum+=2;
					if(grid[i-1][j-1][0] == 1) sum++;
					if(grid[i][j][0] == 1) sum++;
				}
				else if (j == (columns - 1)) {
					if(grid[i-1][j][0] == 1) sum+=2;
					if(grid[i+1][j][0] == 1) sum+=2;
					if(grid[i][j-1][0] == 1) sum++;
					if(grid[i+1][j-1][0] == 1) sum++;
					if(grid[i-1][j-1][0] == 1) sum++;
					if(grid[i][j][0] == 1) sum++;
				}
				else {
					if(grid[i+1][j][0] == 1) sum++;
					if(grid[i][j+1][0] == 1) sum++;
					if(grid[i+1][j+1][0] == 1) sum++;
					if(grid[i][j-1][0] ==1) sum++;
					if(grid[i-1][j][0] == 1) sum++;
					if(grid[i-1][j-1][0] == 1) sum++;
					if(grid[i+1][j-1][0] ==1) sum++;
					if(grid[i-1][j+1][0] == 1) sum++;
            	}


    }

      }










  if(sum == 3)
  {
    alive = 1;
  }
  else if(sum == 4)
  {
    alive = grid[x][y][0];
  }
  else{
    alive = 0;
  }

  return alive;


}


#endif
