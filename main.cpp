#include <iostream>
#include <string>
#include <fstream>
#include "classicMode.cpp"
#include "doughnutMode.cpp"
#include "mirrorMode.cpp"
#include "unistd.h"


using namespace std;

int main()
{

  int gridType = 0;
  int row = 0;
  int col = 0;
  float density = 0.0;

  string textFile = "";
  ifstream inFile;

  int gameType = 0;
  int outputType = 0;

  bool playGrid = true;
  ofstream myGen;
  string outputFile = "";

  int rcCounter = 0;
  int counter0 = 0;
  int numofRounds = 0;

  float myRand = 0.0;
  int num_myRand = 0;

  string lines = "";
  classicMode classicGame;
  doughnutMode doughnutGame;
  MirrorMode mirrorGame;



  srand(time(0));






  cout << "=================================" << endl;
  cout << "\tGAME OF LIFE " << endl;
  cout << "===============================" << endl;


// ============ grid type ==============================
  cout << " Grid Type: " << endl;
  cout << " \tPress 1 for Random Grid or \n";
  cout << " \tPress 2 for Map File \n";
  cout << " My Board Type is ";
  cin >> gridType;
  if (gridType == 1)
  {
    cout << " Enter ROW dimension " << endl;
    cin >> row;
    cout << " Enter column dimension " << endl;
    cin >> col;
    cout << " Enter the dimension population between 0 and 1 " << endl;
    cin >> density;


  }

else if(gridType == 2)
  {
    cout << " Enter map file (map1.txt) : " << endl;
    cin >> textFile;
    inFile.open(textFile);
    inFile >> row;
    inFile >> col;

}

//=========== game type ==========================
cout << " Game Type " << endl;
cout << " \t Press 1 for Classic Mode " << endl;
cout << " \t Press 2 for Doughnut Mode " << endl;
cout << " \t Press 3 for Mirror Mode " << endl;
cout << " My Game Type is: ";
cin >> gameType;
//============ end of game type =================


// ================ output type ==================
cout << " Output Type " << endl;
cout << " \t Press 1 for 3 seconds in between pause " << endl;
cout << " \t Press 2 for continue to output with 'Enter' key " << endl;
cout << " \t Press 3 for output in a textfile" << endl;
cout << " My Output Type is ";
cin >> outputType;

if (outputType == 3)
{
  cout << " Enter the output file name (ex: output1.txt)";
   cin >> outputFile;
   myGen.open(outputFile.c_str(), ofstream::out | ofstream::app);
}

int ***grid = new int**[row];
for (int i = 0; i < row; i++)
{
   grid[i] = new int*[col];
   for (int j = 0; j < col; j++)
   {
       grid[i][j] = new int[1];
   }

}

int ***newGrid = new int**[row];
for (int i = 0; i < row; i++)
{
   newGrid[i] = new int*[col];
   for (int j = 0; j < col; j++)
   {
     newGrid[i][j] = new int[1];
   }
}

//generate a random grid
if(gridType == 1)
{
for (int x = 0; x < row; ++x)
{
  for (int y = 0; y < col; ++y)
  {
    myRand = ((float)rand() / (RAND_MAX));
    if (myRand < density)
     {
       num_myRand = 1;
     }
     else if (myRand > density)
     {
       num_myRand = 0;
    }
    grid[x][y][0]= num_myRand;
  }
}


cout << endl;
}

// reads the file example: map1.txt

if(gridType == 2)
      {       for (int x = 0; x < row; x++)
                 {
                   inFile >> lines;
                   for (int y = 0; y < col; y++)
                   {

                     if (lines[y] == '-')
                     {
                     grid[x][y][0] = 0;

                    }
                    else if (lines[y] == 'X')
                    {
                      grid[x][y][0] = 1;

                    }

                   }
}
       }


//=============== end of grid type =============================


 int gridSize = row*col;


// output original grid
 if (outputType == 1 )
 {cout << " Original Grid" << endl;
   for (int x = 0; x < row; ++x)
   {
     for (int y = 0; y < col; ++y)
     {

       if (grid[x][y][0] == 0)
       {
         cout << " - ";
       }
       else if (grid[x][y][0] == 1)
       {
         cout << " X ";
       }

     }
     cout << endl;

   }
   cout << endl;
 }

 else if (outputType == 2)
 {cout << " Original Grid" << endl;
   for (int x = 0; x < row; ++x)
   {
     for (int y = 0; y < col; ++y)
     {


       if (grid[x][y][0] == 0)
       {
         cout << " - ";
       }
       else if (grid[x][y][0] == 1)
       {
         cout << " X ";
       }
       //cout << endl;
       //cout << " Press 'enter' key " << endl;
       //cout << endl;
     }

     cout << endl;
   }
      //<< " Press 'enter' key " << endl;

      cout << endl;

 }


 else if (outputType == 3)
 myGen << " Original Grid " << endl;
 {
   for (int x = 0; x < row; ++x)
   {
     for (int y = 0; y < col; ++y)
     {


       if (grid[x][y][0] == 0)
       {
         myGen << " - ";
       }
       else if (grid[x][y][0] == 1)
       {
         myGen << " X ";
       }
       //cout << endl;
       //cout << " Press 'enter' key " << endl;
       //cout << endl;
     }

     myGen << endl;
   }
      //<< " Press 'enter' key " << endl;

      myGen << endl;

 }


// starts to generate the cells 
do
{
  //========= GRIDTYPE=====================================================

  if (gameType == 1 ) // classic mode
  {
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        newGrid[i][j][0] = classicGame.calculateClassic(i,j,row,col, grid);
      }
    }
  }

  else if (gameType == 2)   // doughnut mode
  {
    for(int i = 0; i < row; ++i)
				{
					for(int j = 0; j < col; ++j)
					{
						newGrid[i][j][0] = doughnutGame.calculateDoughnut(i,j,row,col,grid);
					}
				}

  }

  else if (gameType == 3)
  {
    for(int i = 0; i < row; ++i)
    {
      for(int j = 0; j < col; ++j)
      {
        newGrid[i][j][0] = mirrorGame.calculateMirror(i,j,row,col,grid);
      }
    }
  }

  //========output mode ===================================

  if (outputType == 1 )
  {
    for (int x = 0; x < row; ++x)
    {
      for (int y = 0; y < col; ++y)
      {

        if (newGrid[x][y][0] == 0)
        {
          cout << " - ";
        }
        else if (newGrid[x][y][0] == 1)
        {
          cout << " X ";
        }

      }
      cout << endl;

    }
    cout << endl;
    sleep(3);


  }
  else if (outputType == 2)
  {
    cin.ignore();
    cout << " Press enter key" << endl;
    cin.ignore();
    //cout << " Press 'enter' key ";


    for (int x = 0; x < row; ++x)
    {
      //cout << " Press 'enter' key " << endl;;
      //cin.ignore();
      for (int y = 0; y < col; ++y)
      {
        //cout << " Press 'enter' key " << endl;;
      //  cin.ignore();

        if (newGrid[x][y][0] == 0)
        {
          cout << " - ";
        }
        else if (newGrid[x][y][0] == 1)
        {
          cout << " X ";
        }

      }

          cout << endl;
          //cin.ignore();
    }
    cout << endl;
  }

else if (outputType == 3)
{
  for (int x = 0; x < row; ++x)
  {
    for (int y = 0; y < col; ++y)
    {

      if (newGrid[x][y][0] == 0)
      {
        myGen << " - ";
      }
      else if (newGrid[x][y][0] == 1)
      {
        myGen << " X ";
      }
      //myGen << endl;
    }
    myGen << endl;
  }
  myGen << endl;
}


for (int x = 0; x < row; ++x)
     {
       for (int y = 0; y < col; ++y)
       {
           if (newGrid[x][y][0] == grid[x][y][0])
           {
             rcCounter++;
           }
           if (newGrid[x][y][0] == 0)
           {
             counter0++;
           }
       }
     }

for (int x = 0; x < row; ++x)
    {
      for (int y = 0; y < col; ++y)
      {
        grid[x][y][0] = newGrid[x][y][0];
      }
    }
    if (rcCounter == (row*col) || numofRounds == 1000 || counter0 == gridSize)
    {
      playGrid = false;
    }
    else
    {
      rcCounter = 0;
      counter0 = 0;
      numofRounds++;
    }

} while(playGrid == true);

  return 0;
}
