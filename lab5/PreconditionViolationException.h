//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: Declaration of PreconditionViolationException class
//Date: 2/22/17

#ifndef PRECONDITION_VIOLATION_EXCEPTION_H
#define PRECONDITION_VIOLATION_EXCEPTION_H
#include <stdexcept>
#include<string>
// #include "LinkedList.h"
// #include "Node.h"

class PreconditionViolationException : public std::runtime_error
{
public:
  PreconditionViolationException(const std::string& msg);
  ~PreconditionViolationException();

};
#endif
 
