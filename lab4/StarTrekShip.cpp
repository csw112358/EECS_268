//Author: Chris Watkins
//Assignment: EECS268 lab4
//Description: Definition of all StarTrecShip functions
//Date: 2/18/17
using namespace std;
#include<iostream>
#include<string>
#include"StarTrekShip.h"

StarTrekShip::StarTrekShip(string u, string c, int ap, int nc, int mh, bool ss)
{
  uni = u;
  captain = c;
  attackP = ap;
  crewNum = nc;
  maxH = mh;
  shieldStatus = ss;
  currentH = mh;
}

StarTrekShip::~StarTrekShip()
{
  cout<<"The final message from " <<captain<< ": My greatest honor was being the captain for "<<crewNum<< " crew members.\n";
}

int StarTrekShip::attackPower() const
{
  return(attackP);
}

int StarTrekShip::currentHull() const
{
  if(currentH==0)
  {
    return(currentH);
    cout<<"Hull=0, ship being destroyed.\n";
    //~StarWarsShip();
  }
  else{
    return(currentH);
  }
}

int StarTrekShip::maxHull() const
{
  return(maxH);
}

bool StarTrekShip::takeDamage(int amount)
{
  if(shieldStatus==true)
  {
    currentH = currentH - (amount/2);
  }
  else
  {
    currentH = currentH - amount;
  }

  if(currentH==0)
  {
    cout<<"Hull=0, ship being destroyed.\n";
    //~StarWarsShip();
    return(true);
  }
  else{
    return(false);
  }
}

bool StarTrekShip::shields() const
{
  return(shieldStatus);
}

string StarTrekShip::universe() const
{
  return(uni);
}

string StarTrekShip::status() const
{
  string cur = to_string(currentH);
  string max = to_string(maxH);
  string crew = to_string(crewNum);
  string statusMessage = captain + "'s ship holding " + crew + " crew members has " + cur + " out of " + max + " remaining.";
  return(statusMessage);
}
