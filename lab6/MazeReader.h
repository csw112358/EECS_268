//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: Declaration of mazeReader class
//Date: 2/18/17

#ifndef MAZE_READER_H
#define MAZE_READER_H

#include "Exception.h"
#include <iostream>
#include "Exception.h"
using namespace std;

class MazeReader
{
public:
  MazeReader(string fileName) throw(Exception);
  // @pre none.
  // @post constructs MazeReader object
  // @return none
  ~MazeReader();
  // @pre none.
  // @post deconstructs MazeReader objec
  // @return none
  void run();
  // @pre MazeReader object created.
  // @post runs methods to take people to movies!
  // @return none.

private:
  int numRows, numCols, startRow, startCol;
  char** maze;

friend class MazeWalker;

};
#endif
