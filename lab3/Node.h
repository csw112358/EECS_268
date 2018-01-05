//Author: Chris Watkins
//Assignment: EECS268 lab2
//Description: Declaration of Node class and variables/methods
//Date: 2/5/17
//HELLO
#ifndef NODE_H
#define NODE_H
using namespace std;
#include"City.h"


template <typename T>
class Node
{
   public:
   Node(T value);
   //@pre None
   //@post a new node is created
   void setValue(T value);
   //@pre None
   //@post m_value is set to value for a node
   void setNext(Node<T>* next);
   //@pre None
   //@post sets the m_next pointer of chosen node to the node passed in.
   Node<T>* getNext();
   //@pre None
   //@return returns the node pointed to by m_next
   T& getValue();
   //@pre None
   //@return returns the m_value of the chosen node

   private:
   T m_value; //still just a T
   Node<T>* m_next; //still a templated Node pointer
};

#include"Node.hpp"
#endif
