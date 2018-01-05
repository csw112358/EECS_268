//Author: Chris Watkins
//Assignment: EECS268 lab2
//Description: Node methods definitions
//Date: 2/5/17
using namespace std;


template<typename T>
Node<T>::Node(T value)
{
	m_next = nullptr;
	m_value = value;
}

template<typename T>
Node<T>::~Node()
{
	delete m_value;
}

template<typename T>
T& Node<T>::getValue( )
{
	return(m_value);
}

template<typename T>
void Node<T>::setValue(T val)
{
  m_value = val;
}

template<typename T>
void Node<T>::setNext(Node<T>* next)
{
   m_next = next;
}

template<typename T>
Node<T>* Node<T>::getNext()
{
  return(m_next);
}
