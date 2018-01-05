//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: Declaration of all my Theater class
//Date: 2/18/17

#ifndef THEATER_H
#define THEATER_H
#include "StackInterface.h"
#include "Stack.h"
#include "QueueInterface.h"
#include "Queue.h"
#include "Node.h"
#include "PreconditionViolationException.h"
#include "LinkedList.h"
#include<iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Theater
{
private:
  Stack<string> theaterStack;
  Queue<string> ticketLineQueue;
  string fileName;
  LinkedList<string> inputList;


public:
  Theater(string file);
  // @pre none.
  // @post constructs Theater object
  // @return none
  ~Theater();
  // @pre none.
  // @post deconstructs Theater objec
  // @return none
  void run();
  // @pre Theater object created.
  // @post runs methods to take people to movies!
  // @return none.

};
#endif
