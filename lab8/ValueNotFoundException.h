
#include<stdexcept>
#ifndef VALUENOTFOUNDEXCEPTION_H
#define VALUENOTFOUNDEXCEPTION_H

class ValueNotFoundException: public std::runtime_error
{
public:
    ValueNotFoundException(const char* msg);
};
#endif // VALUENOTFOUNDEXCEPTION_H
