//Author: Chris Watkins
//Assignment: EECS268 lab3
//Description: Interaction with user and calls MedicalExecutive function to take over
//Date: 2/5/17

#include<iostream>
#include"LinkedList.h"
#include"Node.h"
#include"City.h"
#include"MedicalExecutive.h"
#include<string>
using namespace std;

int main()
{
  // string fileName;
  // cout<<"Input file name: ";
  // cin>>fileName;

  MedicalExecutive exec("input.txt");
  exec.run();
  exec.~MedicalExecutive();

  return 0;
}
