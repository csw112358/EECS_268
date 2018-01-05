//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: Declaration of QueueInterface
//Date: 2/22/17

#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H
#include <stdexcept>
#include "PreconditionViolationException.h"
using namespace std;
// #include "LinkedList.h"
// #include "Node.h"

template<typename T>
class QueueInterface
{
public:
  virtual ~QueueInterface() {};
  // @pre StackInterface object present.
  // @post StackInterface object deleted.
  // @return none.
  virtual bool isEmpty() const = 0;
  // @pre none.
  // @post Entry added to back of queue. Throws exception should enqueue fail.
  // @return returns true if the stack is empty, false otherwise.
  virtual void enqueue(const T value) throw(PreconditionViolationException) = 0;
  // @pre none.
  // @post Entry added to back of queue. Throws exception should enqueue fail.
  // Note: The interface allows for an exception to be thrown, but doesn't obligate an implementation
  // @return none.
  virtual void dequeue() throw(PreconditionViolationException) = 0;
  // @pre assumes the queue is not empty
  // @post front of the front is removed
  // Note: throws PreconditionViolationException if attempted on an empty queue.
  // @return none.
  virtual T& peek() const throw(PreconditionViolationException) = 0;
  // @pre assumes the stack is not empty.
  // @post returns the value at the top of the queue.
  // @return throws a PreconditionViolationException is attempted on an empty stack. Does not return a value in this case..
};
#endif
