


#include "ValueNotFoundException.h"
ValueNotFoundException::ValueNotFoundException(const char* msg): std::runtime_error(msg)
{

}
