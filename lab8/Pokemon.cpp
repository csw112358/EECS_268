//Author: Chris Watkins
//Assignment: EECS268 lab1
//Description: Poxedex program
//Date: 1/25/17
#include"Pokemon.h"
using namespace std;


Pokemon::Pokemon()
{

}

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

const string Pokemon::getUSname()
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
//
// bool Pokemon::operator <(const Pokemon& lhs, const Pokemon& rhs)
// {
//   if(lhs.getUSname() < rhs.getUSname() )
//   {
//     return true;
//   }
//   else
//   {
//     return false;
//   }
// }
//
// bool Pokemon::operator >(const Pokemon& lhs, const Pokemon& rhs)
// {
//   return  operator< (rhs,lhs);
// }

bool Pokemon::operator <(const Pokemon& p) const
{
  return (this->USname < p.USname );

}

bool Pokemon::operator >(const Pokemon& p) const
{
  return(this->USname > p.USname);
}
