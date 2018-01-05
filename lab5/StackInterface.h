//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: Declaration of StackInterface
//Date: 2/22/17

#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H
#include <stdexcept>
#include "PreconditionViolationException.h"
// #include "LinkedList.h"
// #include "Node.h"
using namespace std;

template<typename T>
class StackInterface
{
public:
  virtual ~StackInterface() {};
  // @pre StackInterface object present.
  // @post StackInterface object deleted.
  // @return none.
  virtual bool isEmpty() const = 0;
  // @pre none.
  // @post none.
  // @return returns true if the stack is empty, false otherwise
  virtual void push(const T value) throw(PreconditionViolationException) = 0;
  // @pre assumes the stack is not empty.
  // @post top of the stack is removed
  // @return throws PreconditionViolationException if push cannot occur (e.g. stack full)
  virtual void pop() throw(PreconditionViolationException) = 0;
  // @pre assumes the stack is not empty
  // @post top of the stack is removed
  // @return throws PreconditionViolationException when a pop is attempted on an empty stack. Does not return a value in this case.
  virtual T& peek() const throw(PreconditionViolationException) = 0;
  // @pre assumes the stack is not empty.
  // @post returns the value at the top of the stack.
  // @return throws a PreconditionViolationException is attempted on an empty stack. Does not return a value in this case..
};
#endif
