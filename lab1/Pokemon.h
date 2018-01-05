//Author: Chris Watkins
//Assignment: EECS268 lab1
//Description: Poxedex program
//Date: 1/25/17
#ifndef POKEMON_H
#define POKEMON_H
#include<string>

using namespace std;

class Pokemon
{
private:
  string USname;
  int IDnum;
  string JAPname;

public:
  Pokemon(string US, int ID, string JAP);
  ~Pokemon();
  string getUSname();
  int getIDnum();
  string getJAPname();
};

#endif
