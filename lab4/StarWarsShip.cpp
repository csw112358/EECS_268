//Author: Chris Watkins
//Assignment: EECS268 lab4
//Description: Definition of all StarWarsShip functions
//Date: 2/18/17
using namespace std;
#include<iostream>
#include<string>
#include"StarWarsShip.h"


StarWarsShip::StarWarsShip(string u, string p, int ap, int mh, bool ss, string words)
{
  uni = u;
  pilot = p;
  attackP = ap;
  maxH = mh;
  shieldStatus = ss;
  currentH = mh;
  lastWords = words;
}

StarWarsShip::~StarWarsShip()
{
  cout<<"The final message from " <<pilot<< ": "<<lastWords<< endl;
}

int StarWarsShip::attackPower() const
{
  return(attackP);
}

int StarWarsShip::currentHull() const
{
  if(currentH==0)
  {
    return(currentH);
    //cout<<"Hull=0, ship being destroyed.\n";
    //~StarWarsShip();
  }
  else{
    return(currentH);
  }
}

int StarWarsShip::maxHull() const
{
  return(maxH);
}

bool StarWarsShip::takeDamage(int amount)
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
    // cout<<"Hull=0, ship being destroyed.\n";
    //~StarWarsShip();
    return(true);
  }
  else{
    return(false);
  }
}

bool StarWarsShip::shields() const
{
  return(shieldStatus);
}

string StarWarsShip::universe() const
{
  return(uni);
}

string StarWarsShip::status() const
{
  string cur = to_string(currentH);
  string max = to_string(maxH);
  string statusMessage = pilot + "'s ship has " + cur + " out of " + max + " remaining.";
  return(statusMessage);
}
