//Author: Chris Watkins
//Assignment: EECS268 lab8
//Description: NOTE:: This is a SPECIAL case for nodes to be used in Binary Search Trees
//Date: 4/7/17

#ifndef NODE_H
#define NODE_H
using namespace std;

template <typename T>
class Node
{
private:
   T m_value;
   Node<T>* m_left;
   Node<T>* m_right;
public:
   Node();
   //@pre None
   //@post a new node is created
   Node(const Node<T>& other);
   ~Node();
   T& getValue();
   //@pre None
   //@return returns the m_value of the chosen node
   Node<T>* getLeft();
    /**
    * @return A pointer to the right node.
    */
    Node<T>* getRight();
    /**
    * @post Sets the value of the node.
    */
    void setValue(T value);
    /**
    * @post Sets m_left
    */
    void setLeft(Node<T>* left);
    /**
    * @post Se3ts m_right
    */
    void setRight(Node<T>* right);

};

#include"Node.hpp"
#endif
