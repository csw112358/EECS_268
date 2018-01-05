//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: Declaration of MazeWalker class
//Date: 2/18/17

#ifndef MAZE_WALKER_H
#define MAZE_WALKER_H

#include "Exception.h"
#include <iostream>
#include "MazeReader.h"
using namespace std;

class MazeWalker
{
private:
  MazeReader* mr;
  int rows, cols, stRow, stCol;
  int** intMaze;
  bool exitFound = false;

public:
  MazeWalker(MazeReader* reader) throw(Exception);
  // @pre a pointer to an existing 2D array of chars is passed in.
  // @post constructs MazeWalker object
  // @return none
  ~MazeWalker();
  // @pre none.
  // @post deconstructs MazeWalker objec
  // @return none
  void run();
  // @pre MazeWalker object created.
  // @post handles finding solutoin and printing maze info/solution path.
  // @return none.
  void printMaze();
  // @pre Mazewalker has access to a populated maze from MazeReader class
  // @post prints values in the maze
  // @return none.
  void solve(int row, int col, int num);
  // @pre starting postion passed in
  // @post prints solution to maze
  // @return none.

};
#endif
