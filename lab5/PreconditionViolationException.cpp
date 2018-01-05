//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: Declaration of PreconditionViolationException methods
//Date: 2/22/17
#include<string>
#include <stdexcept>
#include "PreconditionViolationException.h"


PreconditionViolationException::PreconditionViolationException(const std::string& msg) : std::runtime_error(msg)
{

}

PreconditionViolationException::~PreconditionViolationException() {};
