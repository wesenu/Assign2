#include <iostream>
#include <string>
#include <fstream>

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

  bool playGrid = false;

  cout << "=================================" << endl;
  cout << "\tGAME OF LIFE " << endl;
  cout << "===============================" << endl;

// ============ grid type ==============================
  cout << " Grid Type: " << endl;
  cout << " \tPress 1 for Random Grid or \n";
  cout << " \tPress 2 for Map File \n";
  cout << " My Board Type is ";
  cin >> gridType;
//=============== end of grid type =============================

//=========== game type ==========================
cout << " Game Type " << endl;
cout << " \t Press 1 for Classic Mode " << endl;
cout << " \t Press 2 for Mirror Mode " << endl;
cout << " \t Press 3 for Doughnut Mode " << endl;
cout << " My Game Type is: ";
cin >> gameType;
//============ end of game type =================

cout << " Output Type " << endl;
cout << " \t Press 1 for 3 seconds in between pause " << endl;
cout << " \t Press 2 for continue to output with 'Enter' key " << endl;
cout << " \t Press 3 for output in a textfile" << endl;
cout << " My Output Type is " << endl;
cin >> outputType;

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


do
{
  //========= GRIDTYPE====================
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

  if (gameType == 1 ) 
  {


  }

} while(playGrid == true);





  return 0;
}
