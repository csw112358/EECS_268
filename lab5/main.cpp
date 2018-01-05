//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: main.cpp where I take in the input file and turn contorl to Theaters's run function.
//Date: 2/15/17

#include "Theater.h"
#include <iostream>
#include <string>
#include <stdexcept>
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

  Theater t = Theater(fileName);
  t.run();
  //t.~Theater();



  return(0);
}
