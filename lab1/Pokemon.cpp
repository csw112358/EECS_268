//Author: Chris Watkins
//Assignment: EECS268 lab1
//Description: Poxedex program
//Date: 1/25/17
#include"Pokemon.h"
using namespace std;

Pokemon::Pokemon(string US, int ID, string JAP)
{
  USname = US;
  IDnum = ID;
  JAPname = JAP;
}

Pokemon::~Pokemon()
{
  //
}

string Pokemon::getUSname()
{
  return(USname);
}

int Pokemon::getIDnum()
{
  return(IDnum);
}

string Pokemon::getJAPname()
{
  return(JAPname);
}
