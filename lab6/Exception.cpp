//Author: Chris Watkins
//Assignment: EECS268 lab6
//Description: Declaration of Exception methods
//Date: 2/22/17
#include <string>
#include <stdexcept>
#include "Exception.h"

Exception::Exception(const std::string& msg) : std::exception()
{

}

Exception::~Exception() {};
