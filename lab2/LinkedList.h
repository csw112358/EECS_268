//Author: Chris Watkins
//Assignment: EECS268 lab2
//Description: Declaration of all my LinkedList interactive methods/variables
//Date: 2/5/17

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include<iostream>
#include<cstdlib>

template <typename T>
class LinkedList
{
	public:
		LinkedList();
			/** @pre None.
			*   @post An empty list is created.
			*/
		~LinkedList();
			/** @pre None.
			*   @post Deletes all nodes in the list.
			*/
		bool isEmpty() const;
			/** @pre None.
			*   @post None.
			*   @return true if the list is empty, false otherwise.
			*/
		int getLength() const;
			/** @pre None.
			*   @post None.
			*   @return the number of elements in the list.
			*/
		int positionOf(T value) const;
			/** @pre The type T is overloaded with the == operator
			*   @post None.
			*   @return returns the index of the first node in the list that contains the value. Returns 0 otherwise.
			* 		NOTE: The range of indices is from 1 to n, where n is the number of elements in the list
			*/
		void addBack(T value);
			/** @pre the value is a valid T.
			*   @post One new element added to the end of the list.
			*   @return none.
			*/
		void addFront(T value);
			/** @pre the value is a valid T.
			*   @post One new element added to the front of the list.
			*   @return none.
			*/
		bool insert(int position, T value);
			/** @pre None
			*   @post One new element is inserted at the given position.
			*   @return true if the element was inserted false otherwise.
			* 		NOTE: The range of indices is from 1 to n, where n is the number of elements in the list
			*/
		bool removeBack();
			/** @pre None
			*   @post One element is removed from the back of the list.
			*   @return true if the back element was removed, false if the list is empty.
			*/
		bool removeFront();
			/** @pre None
			*   @post One element is removed from the front of the list.
			*   @return true if the front element was removed, false if the list is empty.
			*/
		bool removeAt(int position);
			/** @pre None
			*   @post One element at the provided index is removed
			*   @return true if an element was removed, false otherwise.
			* 		NOTE: The range of indices is from 1 to n, where n is the number of elements in the list
			*/
		void setEntry(int position, T value);
			/** @pre None
			*   @post The value at the given position is overridden with the provided value.
			* 		NOTE: The range of indices is from 1 to n, where n is the number of elements in the list
			*/
		T getEntry( int position ) const;
			/** @pre None
			*   @post None
			*   @return The entry at the given position.
			* 		NOTE: The range of indices is from 1 to n, where n is the number of elements in the list
			*/
		void printList();
			//prints values in list
	private:
		Node<T>* m_front;
		int m_length;
};

#include "LinkedList.hpp"
#endif
