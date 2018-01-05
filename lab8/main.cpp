//Author: Chris Watkins
//Assignment: EECS268 lab8
//Description: main.cpp where I take in the input file
//Date: 4/6/17
#include <iostream>
#include <fstream>
#include "BST.h"
#include "BSTI.h"
#include "Node.h"
#include "ValueNotFoundException.h"
#include "Pokemon.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
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

  BSTI<Pokemon, string>* myBST = new BST<Pokemon, string>();

  string USname, tempID, JAPname, currentline;
  int ID;
  ifstream inFile;
  inFile.open(fileName);
  if(inFile.is_open())
  {
    while (getline(inFile, currentline))
    {
      istringstream iss(currentline);
      if (getline(iss, USname, ',') && getline(iss, tempID, ',') && getline(iss, JAPname, '\n'))
      {
        //cout<<USname<<tempID<<JAPname<< endl;
        ID = stoi(tempID);
        Pokemon temp = Pokemon(USname, ID, JAPname);
        myBST->add(temp);
        myBST->printTree(IN_ORDER);
        cout<<endl;
      }
      else
        break;
    }
    inFile.close();

    // while(getline(inFile, line))
    // {
    //     if(inFile.eof())
    //     {
    //       break;
    //     }
    //     string tempID, tempUSname, tempJAPname;
    //     char tempChar = ',';
    //     getline(inFile, tempUSname, tempChar);
    //     getline(inFile, tempID, tempChar);
    //     getline(inFile, tempJAPname, '\n');
        // cout<<tempID<< endl;
        // int IDnum = stoi(tempID);
        // Pokemon temp = Pokemon(tempUSname, IDnum, tempJAPname);
        // myBST->add(temp);
    //
    // }
    // inFile.close();
  }
  else
  {
    cout<<"Error, file not opened.";
  }

  // myBST->printTree(IN_ORDER);

return(0);
}
