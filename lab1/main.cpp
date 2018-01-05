//Author: Chris Watkins
//Assignment: EECS268 lab1
//Description: Poxedex program
//Date: 1/25/17

#include<iostream>
#include"Pokemon.h"
#include"Executive.h"
using namespace std;

int main(int argc, char** argv)
{
  if(argc<2)
  {
    cout<<"Incorrect number of parameters.\n";
  }
  else
  {
    string fileName = argv[1];
    Executive exec1(fileName);
    exec1.run();
  }
  return(0);
}
