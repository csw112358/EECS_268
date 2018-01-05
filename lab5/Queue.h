//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: Declaration of Queue class
//Date: 2/22/17
#include <stdexcept>
using namespace std;
#include"QueueInterface.h"
#ifndef QUEUE_H
#define QUEUE_H
// #include "LinkedList.h"
// #include "Node.h"

template<typename T>
class Queue :  public QueueInterface<T>
{
public:
  Queue();
  ~Queue();
  // @pre StackInterface object present.
  // @post StackInterface object deleted.
  // @return none.
  bool isEmpty() const;
  // @pre none.
  // @post Entry added to back of queue. Throws exception should enqueue fail.
  // @return returns true if the stack is empty, false otherwise.
  void enqueue(const T value) throw(PreconditionViolationException);
  // @pre none.
  // @post Entry added to back of queue. Throws exception should enqueue fail.
  // Note: The interface allows for an exception to be thrown, but doesn't obligate an implementation
  // @return none.
  void dequeue() throw(PreconditionViolationException);
  // @pre assumes the queue is not empty
  // @post front of the front is removed
  // Note: throws PreconditionViolationException if attempted on an empty queue.
  // @return none.
  T& peek() const throw(PreconditionViolationException);
  // @pre assumes the stack is not empty.
  // @post returns the value at the top of the queue.
  // @return throws a PreconditionViolationException is attempted on an empty stack. Does not return a value in this case..
private:
  Node<T>* m_front;
  Node<T>* m_back;
  int m_size;
  int maxSize;
};
#endif
#include "Queue.hpp"
