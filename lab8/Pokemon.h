//Author: Chris Watkins
//Assignment: EECS268 lab1
//Description: Poxedex program
//Date: 1/25/17
#ifndef POKEMON_H
#define POKEMON_H
#include <string>

using namespace std;

class Pokemon
{
private:
  string USname;
  int IDnum;
  string JAPname;

public:
  Pokemon();
  Pokemon(string US, int ID, string JAP);
  ~Pokemon();
  const string getUSname();
  int getIDnum();
  string getJAPname();
  bool operator <(const Pokemon& p) const;
  bool operator >(const Pokemon& p) const;
  // bool operator< (const Pokemon& lhs, const Pokemon& rhs);
  // bool operator> (const Pokemon& lhs, const Pokemon& rhs);
};

#endif
