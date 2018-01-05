//Author: Chris Watkins
//Assignment: EECS268 lab2
//Description: Definitions of my LinkedList methods
//Date: 2/5/17
#include<iostream>
#include<typeinfo>


template<typename T>
LinkedList<T>::LinkedList()
{
  m_front = nullptr;
  m_length = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
  Node<T>* temp = m_front;
  while(m_front != nullptr)
  {
  	temp = m_front->getNext();
  	m_front -> setNext(nullptr);
  	delete m_front;
  	m_front = temp;
  }
  m_length=0;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
  bool isEmpty;
  if (m_length == 0)
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
int LinkedList<T>::getLength() const
{
  return(m_length);
}

template<typename T>
int LinkedList<T>::positionOf(T value) const
{
    bool flag= false;
    Node<T>* curPtr = m_front;
  	if(curPtr == nullptr)
    {
    return(0);
  	}
  	else
    {
      for(int i=1;i<=m_length;i++)
      {
        if(curPtr->getValue() == value)
        {
          return(i);
          flag = true;
        }
        curPtr = curPtr -> getNext();
      }
      if(flag==false)
      {
        return(0);
      }
    }
}

template<typename T>
void LinkedList<T>::addBack(T value)
{
  Node<T>* curPtr = m_front;
  if(curPtr == nullptr)
  {
    Node<T>* n = new Node<T>(value);
    n -> setValue(value);
    m_front = n;
    m_length++;
  }
  else
  {
    while( curPtr->getNext() != nullptr)
    {
       curPtr = curPtr->getNext();
    }
    Node<T>* n = new Node<T>(value);
    curPtr->setNext(n);
    n->setNext(nullptr);
    m_length++;
  }
}

template<typename T>
void LinkedList<T>::addFront(T value)
{
  Node<T>* n = new Node<T>(value);

  n -> setNext(m_front);
  m_front = n;
  m_length++;
}

template<typename T>
bool LinkedList<T>::removeBack()
{
  Node<T>* prev;
  Node<T>* current = m_front;
  	if(current == nullptr)
    {
    return(false);
  	}
  	else if(m_length==1)
    {
      delete current;
      m_length--;
      m_front=nullptr;
      return(true);
  	}
    else
    {
  		while(current->getNext() != nullptr)
      {
    		prev = current;
    		current = current->getNext();
  	  }
      delete current;
      prev -> setNext(nullptr);
      m_length--;
      return(true);
    }
}

template<typename T>
bool LinkedList<T>::removeFront()
{
  Node<T>* curPtr = m_front;
    if(curPtr == nullptr)
    {
      return(false);
    }
    else if(m_length==1)
    {
      delete curPtr;
      m_length--;
      m_front=nullptr;
      return(true);
    }
    else
    {
      curPtr = m_front->getNext();
      m_front -> setNext(nullptr);
      delete m_front;
      m_front = curPtr;
      m_length--;
      return(true);
    }
}

template<typename T>
bool LinkedList<T>::removeAt(int position)
{
  Node<T>* curPtr = m_front;
  Node<T>* back2spots = m_front;
  if( curPtr == nullptr)
  {
    return(false);
  }
  else if(position==1)
  {
    removeFront();
    return(true);
  }
  else if(position==m_length)
  {
      removeBack();
      return(true);
  }
  else if(position>1 && position<m_length)
  {
    for(int i=1;i<=position;i++)
    {
      curPtr = curPtr -> getNext();
    }

    for(int j=1;j<position-1;j++)
    {
      back2spots= back2spots->getNext();
    }
    (back2spots->getNext())->setNext(nullptr);
    delete back2spots->getNext();
    back2spots->setNext(curPtr);

    m_length--;
    return(true);
  }
}




template<typename T>
bool LinkedList<T>::insert(int position, T value)
{
  if(position==1)
  {
    addFront(value);
    return(true);
  }
  else if(position==m_length)
  {
      addBack(value);
      return(true);
  }
  else if(position>1 && position<m_length)
  {
    Node<T>* n = new Node<T>(value);
    Node<T>* curPtr = m_front;
      for(int i=1;i<position-1;i++)
      {
        curPtr = curPtr -> getNext();
      }
      n->setNext(curPtr->getNext());
      curPtr->setNext(n);
      m_length++;
    return(true);
  }
  else
  {
    return(false);
  }
}

template<typename T>
void LinkedList<T>::setEntry(int position, T value)
{
  Node<T>* curPtr = m_front;
  for(int i=1;i<position;i++)
  {
    curPtr = curPtr -> getNext();
  }
  curPtr->setValue(value);
}

template<typename T>
void LinkedList<T>::printList()
{
  if(m_length == 0)
  {
    std::cout<<"List empty.\n";
  }
  else
  {
    Node<T>* curPtr = m_front;
    T value;
    for(int i=1;i<=m_length;i++)
    {
      value = curPtr->getValue();
      cout<< value << " ";
      curPtr = curPtr -> getNext();
    }
    cout<< endl;
  }
}

template<typename T>
T& LinkedList<T>::getEntry( int position )
{
  Node<T>* curPtr = m_front;
  for(int i=1;i<position;i++)
  {
    curPtr = curPtr -> getNext();
  }

  // T value = curPtr->getValue();

  return(curPtr->getValue());
}
