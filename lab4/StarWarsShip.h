//Author: Chris Watkins
//Assignment: EECS268 lab4
//Description: Declaration of all my StarWarsShip class.
//Date: 2/18/17

#ifndef STAR_WARS_SHIP
#define STAR_WARS_SHIP

#include "SpaceShip.h"
#include<iostream>
#include<string>
using namespace std;

class StarWarsShip : public SpaceShip
{
public:
  StarWarsShip(string u, string p, int ap, int mh, bool ss, string words);
  StarWarsShip();
  ~StarWarsShip();
  int attackPower() const;
  // @pre none.
  // @post none.
  // @return returns attack power of ship.
  int currentHull() const;
  // @pre none.
  // @post Once a hull value reaches 0, the ship is destroyed.
  // @return Returns the amount of damage the hull can still sustain.
  int maxHull() const;
  // @pre none.
  // @post none.
  // @return Return the value the hull started the fight with
  bool takeDamage(int amount);
  // @pre none.
  // @post Reduces the Hull amount givern. If shields are on, the damage is halved.
  // @return If the ship dies, return true, otherwise return false.
  bool shields() const;
  // @pre none.
  // @post none.
  // @return returns the status of the shields.
  // True indicates shields are on, false indicates shields are off or disabled.
  // When shields are on, the ship takes 50% damage (rounded down).
  string universe() const;
  // @pre none.
  // @post none.
  // @return returns the Universe the ship is from, StarTrek or StarWars
  string status() const;
  // @pre none.
  // @post none.
  // @return returns a message indicating the current status of the ship.

protected:
  string pilot;
  string uni;
  int attackP;
  int maxH;
  bool shieldStatus;
  string lastWords;
  int currentH;

};
#endif
