//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: Definitoin of Queue Class methods.
//Date: 2/22/17
#include <stdexcept>
#include "Node.h"
#include "PreconditionViolationException.h"
using namespace std;

template<typename T>
Queue<T>::Queue()
{

  m_size = 0;
  m_front = nullptr;
  m_back = nullptr;
}

template<typename T>
Queue<T>::~Queue()
{
  Node<T>* temp = m_front;
  while(m_front != nullptr)
  {
    temp = m_front->getNext();
    m_front -> setNext(nullptr);
    delete m_front;
    m_front = temp;
  }
  m_size=0;
}

template <typename T>
bool Queue<T>::isEmpty() const
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
void Queue<T>::enqueue(const T value) throw(PreconditionViolationException)
{
  // if(m_size==maxSize)
  // {
  //   throw(PreconditionViolationException("Enqueue attempted on a full queue."));
  // }
  if(m_size==0)
  {
    Node<T>* n = new Node<T>(value);
    // n->setNext(m_front);
    		m_front = n;
        m_back= n;
        n->setNext(nullptr);
    m_size++;
  }
  else
  {
    Node<T>* n = new Node<T>(value);
    n->setNext(m_back);
    		m_back = n;
    m_size++;
  }
}

template<typename T>
void Queue<T>::dequeue() throw(PreconditionViolationException)
{
  if(isEmpty()==true)
  {
		throw(PreconditionViolationException("Dequeue attempted on an empty queue."));
	}
	else
  {
      Node<T>* curPtr = m_back;
      if(m_size==1)
      {
        delete m_front;
        m_front = nullptr;
        m_back = nullptr;
        m_size--;
      }
      else
      {
        while(curPtr->getNext() != m_front )
        {
          curPtr = curPtr->getNext();
        }

        delete m_front;
        m_size--;
        curPtr->setNext(nullptr);
        m_front=curPtr;
      }
	}

}

template<typename T>
T& Queue<T>::peek() const throw(PreconditionViolationException)
{
  if(isEmpty()==true)
  {
		throw(PreconditionViolationException("Peek attempted on an empty queue."));
	}
	else
  {
		return(m_front->getValue());
	}

}
