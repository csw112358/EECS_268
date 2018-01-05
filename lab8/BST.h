//Author: Chris Watkins
//Assignment: EECS268 lab8
//Description: BST.h
//Date: 3/29/17

#ifndef BST_H
#define BST_H
#include"BSTI.h"
#include "Node.h"
#include <iostream>
#include "ValueNotFoundException.h"
#include "Pokemon.h"

template <typename ItemType, typename KeyType>
class BST : public BSTI<ItemType, KeyType>
{
private:
    Node<ItemType>* m_root;
    /**
    * @post Adds the correct value to the appropriate position in the properly ordered binary search tree.
    */
    bool add (ItemType value, Node<ItemType>* subTree);
    /**
    * @post Deletes the left subtree and right subtree of the node the pointer passed in is pointing to.
    */
    void deleteTree(Node<ItemType>* subTree);
    /**
    * @return The T value if it exists in the tree. Throws exception if not found.
    */
    ItemType search(ItemType value, Node<ItemType>* subTree) const throw(ValueNotFoundException);
    /**
    * @post prints the tree in the specified order
    */
    void printTree(Node<ItemType>* subTree, Order order) const;
    //ItemType addAll(Node<ItemType>* subTree);
public:
    /**
    * @post sets m_root to nullptr
    */
    BST();
    /**
    * @post creates a deep copy of the other BST
    */
    BST(const BST<ItemType, KeyType>& other);
    /**
    * @post BST destructor
    */
    ~BST();
    /**
    * @post Creates a deep copy of this
    * @return A pointer to the deep copy of this
    */
    //BSTI<ItemType, KeyType>* clone();
    /**
    * @pre this is in a valid state
    * @post Creates a deep[ copy of this
    * @return true if no nodes in the tree, false otherwise
    */
    bool isEmpty() const;
    /**
    * @post adds a node containing the value in the tree
    * @return true if addition operation was successful (DUPLICATE COPIES WILL NEVER BE ADDED TO TE TREE)
    */
    bool add(ItemType value);
    //ItemType addAll();
    /**
    * @post If the tree is empty display "Tree Empty" Otherwise print the tree in the specified order
    */
    void printTree(Order order) const;
    /**
    * @post The contents of the tree are posted IN_ORDER
    */
    void sortedPrint() const;
    /**
    * @return The result from search(T value, Node<T>* saubtree). Throws excepion of not found.
    */
    //ItemType search(ItemType value) const throw (ValueNotFoundException);
    bool operator <(const Pokemon& p) const;
    bool operator >(const Pokemon& p) const;
};

#include "BST.hpp"
#endif
