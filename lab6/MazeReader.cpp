//Author: Chris Watkins
//Assignment: EECS268 lab6
//Description: Definition of mazeReader class methods
//Date: 2/18/17
#include "MazeReader.h"
#include "Exception.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


MazeReader::MazeReader(string fileName) throw(Exception)
{
  ifstream inFile;
  inFile.open(fileName);

  if(inFile.is_open())
  {
    inFile >> numRows;
    inFile >> numCols;
    inFile >> startRow;
    inFile >> startCol;

    if(numRows<1)
    {
      throw(Exception("Number of rows less than 1."));

    }
    else if(numCols<1)
    {
      throw(Exception("Number of columns less than 1."));
    }
    else
    {
      maze = new char*[numRows];
      for(int i=0; i<numRows; i++)
      {
        maze[i] = new char[numCols];
      }

      string input;
      getline(inFile, input);
      for(int i=0;i<numRows;i++)
      {
        getline(inFile, input);

        for(int j=0;j<numCols;j++)
        {
          maze[i][j] = input.at(j);
        }
      }
    }
  }
  else
  {
    throw(Exception("File not found/ does not exist."));
  }

}
MazeReader::~MazeReader()
{
  for(int i=0; i<numRows;i++)
  {
    delete[] maze[i];
  }

  delete[] maze;
}

void MazeReader::run()
{
  for(int i=0;i<numRows;i++)
  {
    for(int j=0;j<numCols;j++)
    {
      cout<< maze[i][j];
    }
    cout<< endl;
  }
}
