//Author: Chris Watkins
//Assignment: EECS268 lab6
//Description: Definition of MazeWalker class methods
//Date: 2/18/17
#include "MazeWalker.h"
#include "MazeReader.h"
#include "Exception.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <string>
using namespace std;


MazeWalker::MazeWalker(MazeReader* reader) throw(Exception)
{
  //check that there is an exit
  //check that starting position is not X
  mr = reader;
  rows = mr->numRows;
  cols = mr->numCols;
  stRow = mr->startRow;
  stCol = mr->startCol;

  if((mr->maze)[mr->startRow][mr->startCol] == 'X')
  {
    throw(Exception("Starting position not in a passage."));
  }
  bool exitPresent = false;
  for(int i=0;i<mr->numRows;i++)
  {
    for(int j=0;j<mr->numCols;j++)
    {
      if(mr->maze[i][j] == 'E')
      {
        exitPresent = true;
      }
    }
  }
  if(exitPresent == false)
  {
    throw(Exception("Exit does not exist."));
  }

  intMaze = new int*[rows];
  for(int i=0; i<rows; i++)
  {
    intMaze[i] = new int[cols];
  }
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      intMaze[i][j] = 0;
    }
  }
}

MazeWalker::~MazeWalker()
{
  for(int i=0; i<rows;i++)
  {
    delete[] intMaze[i];
  }

  delete[] intMaze;
}

void MazeWalker::printMaze()
{
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      cout<< left<< intMaze[i][j] << '\t';
    }
    cout<< endl;
  }
  // for(int i=0;i<mr->numRows;i++)
  // {
  //   for(int j=0;j<mr->numCols;j++)
  //   {
  //     cout<< mr->maze[i][j];
  //   }
  //   cout<< endl;
  // }
}

void MazeWalker::solve(int row, int col, int num)
{
  if(mr->maze[row][col]==' ')
  {
    mr->maze[row][col] = '0';
    intMaze[row][col] = num;
  }

  //base case: we are at the exit
  if(mr->maze[row][col]== 'E')
  {
    mr->maze[row][col] = '0';
    intMaze[row][col]= num;
    printMaze();
    cout<<"We escaped!\n";
    exitFound = true;
    return;
  }

  //check up
  if(mr->maze[row-1][col]==' '|| mr->maze[row-1][col]=='E')
  {
    solve(row-1, col, num+1);
    mr->maze[row][col]= '0';
    intMaze[row][col] = num;
  }

  //check right
  if(mr->maze[row][col+1]==' ' || mr->maze[row][col+1]=='E')
  {
    solve(row, col+1, num+1);
    mr->maze[row][col]= '0';
    intMaze[row][col] = num;
  }

  //check down
  if(mr->maze[row+1][col]==' '|| mr->maze[row+1][col]=='E')
  {
    solve(row+1, col, num+1);
    mr->maze[row][col]= '0';
    intMaze[row][col] = num;
  }

  //check left
  if(mr->maze[row][col-1]==' '|| mr->maze[row][col-1]=='E')
  {
    solve(row, col-1, num+1);
    mr->maze[row][col]= '0';
    intMaze[row][col] = num;
  }

  //unmark this space as all directions have been exhausted
  mr->maze[row][col]=' ';
  intMaze[row][col]= 0;
  if(exitFound==false && num ==1)
  {
    cout<<"Exit was unreachable from starting position.\n";
  }
  return;
}


void MazeWalker::run()
{
  cout<< "Size: " << mr->numRows << ", " << mr->numCols<< endl;
  cout<< "Starting position: "<<mr->startRow<< ", "<<mr->startCol<< endl;

  solve(stRow, stCol, 1);
}
