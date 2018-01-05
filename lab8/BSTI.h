//Author: Chris Watkins
//Assignment: EECS268 lab8
//Description: Interface for a Binary Search Tree
//Date: 4/6/17
#ifndef BSTI_H
#define BSTI_H
#include "ValueNotFoundException.h"


enum Order
{
    PRE_ORDER, IN_ORDER, POST_ORDER
};

template <typename ItemType, typename KeyType>
class BSTI
{
public:
    /**
    * @pre A BSTI exists
    * @post Deletes the entire tree
    */
    virtual ~BSTI(){};
    /**
    * @pre this is in a valid state
    * @post Creates a deep[ copy of this
    * @return a pointer to the deep copy of this
    */
    //virtual BSTI<ItemType, KeyType>* clone() = 0;
    /**
    * @return true if no nodes in the tree. false if otherwise.
    */
    virtual bool isEmpty() const = 0;

    //virtual ItemType addAll() = 0;
    /**
    * @pre Vlue is a valid T value
    * @post a new Node<T> is created and inserted in the tree
    * @return false if the value coudn't be added (DUPLICATE VALUES ARE NOT ALLOWED IN THE TREE)
    */
    virtual bool add(ItemType value) = 0;
    /**
    * @pre The type t is comparable with the == operator.
    * @return The T value if it exists in the tree, otherwise exception is thrown.
    */
    //virtual ItemType search(ItemType value) const throw (ValueNotFoundException) = 0;
    /**
    * @post The contents of the tree are printed to the console in the specified order.
    */
    virtual void printTree(Order order) const = 0;
    /**
    * @post The contents of the tree are printed in IN_ORDER
    */
    virtual void sortedPrint() const = 0;
};
#endif // BSTI_H
