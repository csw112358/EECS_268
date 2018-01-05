//Author: Chris Watkins
//Assignment: EECS268 lab4
//Description: Declaration of all my SpaceShip Interface
//Date: 2/18/17

#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H
// #include "LinkedList.h"
// #include "Node.h"
#include<iostream>

class SpaceShip
{
public:
  virtual ~SpaceShip() {};
  // @pre SpaceShip object present.
  // @post SpaceShip object deleted.
  // @return none.
  virtual int attackPower() const = 0;
  // @pre none.
  // @post none.
  // @return returns attack power of ship.
  virtual int currentHull() const = 0;
  // @pre none.
  // @post Once a hull value reaches 0, the ship is destroyed.
  // @return Returns the amount of damage the hull can still sustain.
  virtual int maxHull() const = 0;
  // @pre none.
  // @post none.
  // @return Return the value the hull started the fight with
  virtual bool takeDamage(int amount) = 0;
  // @pre none.
  // @post Reduces the Hull amount givern. If shields are on, the damage is halved.
  // @return If the ship dies, return true, otherwise return false.
  virtual bool shields() const = 0;
  // @pre none.
  // @post none.
  // @return returns the status of the shields.
  // True indicates shields are on, false indicates shields are off or disabled.
  // When shields are on, the ship takes 50% damage (rounded down).
  virtual std::string universe() const = 0;
  // @pre none.
  // @post none.
  // @return returns the Universe the ship is from, StarTrek or StarWars
  virtual std::string status() const = 0;
  // @pre none.
  // @post none.
  // @return returns a message indicating the current status of the ship.

};
#endif
