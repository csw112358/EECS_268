//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: Definitoin of Stack Class methods.
//Date: 2/22/17
#include <stdexcept>
#include <iostream>
#include <string>
#include "Node.h"
#include "PreconditionViolationException.h"
using namespace std;

template<typename T>
Stack<T>::Stack()
{
  maxSize = 10;
  m_size = 0;
  m_top = nullptr;

}

template<typename T>
int Stack<T>::getSize()
{
  return(m_size);
}

template<typename T>
int Stack<T>::getMaxSize()
{
  return(maxSize);
}


template<typename T>
Stack<T>::~Stack()
{
Node<T>* temp = m_top;
while(m_top != nullptr)
{
  temp = m_top->getNext();
  m_top -> setNext(nullptr);
  delete m_top;
  m_top = temp;
}
m_size=0;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
  bool isEmpty;
  if (m_size == 0)
  {
    isEmpty = true;
  }
  else
  {
    isEmpty = false;
  }
  return(isEmpty);

}

template<typename T>
void Stack<T>::push(const T value) throw(PreconditionViolationException)
{
  if(m_size==maxSize)
  {
    throw(PreconditionViolationException("Push attempted on a full stack."));
  }
  else
  {
  Node<T>* temp = new Node<T>(value);
  temp -> setNext(m_top);
  		m_top = temp;
  m_size++;
  }
}

template<typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
	if(isEmpty()==true)
  {
		throw(PreconditionViolationException("Pop attempted on an empty stack."));
	}
	else
  {
      Node<T>* curPtr = m_top;
      if(m_size==1)
      {
        string tempName = curPtr->getValue();
        delete curPtr;
        m_size--;
        m_top=nullptr;
        cout<<tempName<<" has left the theater.\n";
      }
      else
      {
        string tempName = curPtr->getValue();
        curPtr = m_top->getNext();
        m_top -> setNext(nullptr);
        delete m_top;
        m_top = curPtr;
        m_size--;
        cout<<tempName<<" has left the theater.\n";
      }
	}
}

template<typename T>
T& Stack<T>::peek() const throw(PreconditionViolationException)
{
	if(isEmpty()==true)
  {
		throw(PreconditionViolationException("Peek attempted on an empty stack."));
	}
	else
  {
		return(m_top->getValue());
	}
}
