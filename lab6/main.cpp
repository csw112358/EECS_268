//Author: Chris Watkins
//Assignment: EECS268 lab6
//Description: main.cpp where I take in the input file and turn contorl to MazeReader and MazeRunner classes
//Date: 3/8/17

#include <iostream>
#include <string>
#include "MazeReader.h"
#include "MazeWalker.h"
#include "Exception.h"
using namespace std;

int main(int argc, char** argv)
{
  string fileName;
  if(argc<2)
  {
    cout<<"Incorrect number of parameters.\n";
  }
  else
  {
    fileName = argv[1];
  }

  MazeReader* reader;
  try
  {
    reader =  new MazeReader(fileName);
    //reader->run();
  }
  catch (const Exception& e)
  {
    cout << e.what() << endl;
  }

  try
  {
  MazeWalker walker = MazeWalker(reader);
  walker.run();
  }
  catch (const Exception& e)
  {
    cout << e.what() << endl;
  }

  delete reader;
return(0);
}
