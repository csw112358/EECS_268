//Author: Chris Watkins
//Assignment: EECS268 lab1
//Description: Poxedex program
//Date: 1/25/17
#include"Executive.h"
#include"Pokemon.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

Executive::Executive(string fileName)
{
  ifstream inFile;
  inFile.open(fileName);
  if(inFile.is_open())
  {
    inFile >> count;
    pokemonArray = new Pokemon*[count];
    for(int i =0; i<count;i++)
    {
      string tempID, tempUSname, tempJAPname;
      char tempChar = ',';
      getline(inFile, tempUSname, tempChar);
      getline(inFile, tempID, tempChar);
      getline(inFile, tempJAPname, '\n');
      int IDnum = stoi(tempID);
      pokemonArray[i]= new Pokemon(tempUSname, IDnum, tempJAPname);
    }
    inFile.close();
  }
  else
  {
    cout<<"Error, file not opened.";
  }
}

Executive::~Executive()
{
  for(int i=0; i<count;i++)
  {
    delete pokemonArray[i];
    pokemonArray[i] = nullptr;
  }
    delete[] pokemonArray;
}

void Executive::printMenu()
{
  cout<<"Select an option:\n"
           <<"1) Print the data for a Pokemon based on ID\n"
           <<"2) Print all pokemon whose IDs are between a range\n"
           <<"3) Write all Japanese names to file\n"
           <<"4) Print all pokemon whose names begin with a certain letter\n"
           <<"5) Quit\n"
           <<"Enter your choice: ";
}

void Executive::printPokeData(int ID)
{
  for(int i=0; i<count;i++)
  {
    if((pokemonArray[i]->getIDnum()) == ID)
    {
      cout<<"Pokemon #";
      cout<< pokemonArray[i]->getIDnum();
      cout<<": ";
      cout<< pokemonArray[i]->getUSname();
      cout<<" (USA), ";
      cout<< pokemonArray[i]->getJAPname();
      //cout<<" (JPN)";
    }
  }
}


void Executive::writeJapToFile(string fileName)
{
  ofstream outFile;
  outFile.open(fileName);

  for(int i=0; i<count;i++)
  {
    outFile<< pokemonArray[i]->getJAPname()<< endl;
  }
  outFile.close();
}

void Executive::run()
{
  int choice = 0;
  do
  {
    printMenu();
    cin>>choice;
    if(choice == 1)
    {
      int ID;
      cout<<"Enter ID #: ";
      cin>> ID;
      printPokeData(ID);
      cout<<endl;
    }
    else if(choice == 2)
    {
      int low, high;
      cout<<"Enter a range of numbers between 1 and 151 (e.g. 22 78):\n";
      cin>> low;
      cin>> high;
      if((low<1)||(high>151)||(low>high))
      {
        cout<<"Invalid range, try again: ";
        cin>> low;
        cin>> high;
      }
      for(int i=0;i<count;i++)
      {
        if((pokemonArray[i]->getIDnum()>=low) && (pokemonArray[i]->getIDnum()<=high))
        {
          printPokeData((pokemonArray[i]->getIDnum()));
          cout<<endl;
        }
      }
    }
    else if(choice == 3)
    {
      string fileName;
      cout<<"Enter a file name to write Japanese names to:\n";
      cin>>fileName;
      writeJapToFile(fileName);
    }
    else if(choice == 4)
    {
      char letter;
      cout<<"Enter first letter (capitalize): ";
      cin>> letter;
      for(int i=0;i<count;i++)
      {
        string name = (pokemonArray[i]->getUSname());
        char temp = name[0];
        if(letter ==temp)
        {
          printPokeData((pokemonArray[i]->getIDnum()));
          cout<<endl;
        }
      }
    }
  }while (choice!=5);


}
