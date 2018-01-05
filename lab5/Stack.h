//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: Declaration of Stack Class
//Date: 2/22/17

#ifndef STACK_H
#define STACK_H
#include "PreconditionViolationException.h"
#include "Node.h"
#include "StackInterface.h"
using namespace std;

template <typename T>
class Stack : public StackInterface<T>
{
public:
  Stack();
  ~Stack();
  // @pre StackInterface object present.
  // @post StackInterface object deleted.
  // @return none.
   bool isEmpty() const;
  // @pre none.
  // @post none.
  // @return returns true if the stack is empty, false otherwise
  void push(const T value) throw(PreconditionViolationException);
  // @pre assumes the stack is not empty.
  // @post top of the stack is removed
  // @return throws PreconditionViolationException if push cannot occur (e.g. stack full)
  void pop() throw(PreconditionViolationException);
  // @pre assumes the stack is not empty
  // @post top of the stack is removed
  // @return throws PreconditionViolationException when a pop is attempted on an empty stack. Does not return a value in this case.
  T& peek() const throw(PreconditionViolationException);
  // @pre assumes the stack is not empty.
  // @post returns the value at the top of the stack.
  // @return throws a PreconditionViolationException is attempted on an empty stack. Does not return a value in this case..
  int getSize();
  int getMaxSize();
private:
  Node<T>* m_top;
  int m_size;
  int maxSize;
};
#endif
#include "Stack.hpp"
