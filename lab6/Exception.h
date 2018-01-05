//Author: Chris Watkins
//Assignment: EECS268 lab6
//Description: Declaration of Exception class
//Date: 2/22/17

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <stdexcept>
#include <string>

class Exception : public std::exception
{
public:
  Exception(const std::string& msg);
  // @pre string reference passed in.
  // @post constructs an exception instance
  // @return none
  ~Exception();
  // @pre none.
  // @post deconstructs exceptions  
  // @return none
};
#endif
