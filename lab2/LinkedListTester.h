//Author: Chris Watkins
//Assignment: EECS268 lab2
//Description: Declaration of LinkedListTester Class
//Date: 2/5/17

#ifndef LINKED_LIST_TESTER_H
#define LINKED_LIST_TESTER_H
#include"LinkedList.h"
#include"Node.h"

class LinkedListTester
{

  public:
    LinkedListTester();
    ~LinkedListTester();
    //This will call all your test methods
    void runTests();

  private:
    /**
    * @brief Creates an empty list and verifies isEmpty() returns true
    **/
    void test01();
    /**
    * @brief Creates an empty list adds 1 value, verifies isEmpty() returns false
    **/
    void test02();
    /**
    * @brief Creates an empty list and verifies getLength() returns 0
    **/
    void test03();
    /**
    * @brief Creates a list, adds one node to back, and verifies getLength() returns 1.
    **/
    void test04();
    /**
    * @brief Creates a list, adds two nodes to front,
    *        and verifies getLength() returns 2.
    **/
    void test05();
    /**
    * @brief Creates a list, adds two nodes to back,
    *        and verifies getLength() returns 2.
    **/
    void test06();
    /**
    * @brief Creates a list, adds one nodes to front,
    *        then removes one node from front and verifies getLength() returns 0.
    **/
    void test07();
    /**
    * @brief Creates a list, adds one nodes to back,
    *        then removes one node from back and verifies getLength() returns 0.
    **/
    void test08();
    /**
    * @brief Creates a populated list, and stores size. Then removeFront() called and
    *        getLength() is used to verify that the size has decreased by 1.
    **/
    void test09();
    /**
    * @brief Creates a populated list, and stores size. Then removeBack() called and
    *        getLength() is used to verify that the size has decreased by 1.
    **/
    void test10();
    /**
    * @brief Creates empty list. Then it is verified that positionOf() returns 0 for this list.
    **/
    void test11();
    /**
    * @brief Creates a populated list, then the list is searched for a value not present in the list,
    * and it is verified that positionOf() returns 0 in this case.
    **/
    void test12();
    /**
    * @brief Creates a populated list, then the list is searched for a value present in the list,
    * and it is verified that positionOf() returns the correct index for this value.
    **/
    void test13();
    /**
    * @brief Creates an empty list, then it is verified that removeFront() returns false on this list.
    **/
    void test14();
    /**
    * @brief Creates an empty list, then it is verified that removeBack() returns false on this list.
    **/
    void test15();
    /**
    * @brief Creates a list, then calls insert(position, value) with an invalid position, and verifies
    *        positionOf() returns false.
    **/
    void test16();
    /**
    * @brief Creates a populated list. Then calls insert(pos, value). An array (key) is created matching what the
    *        list should read out as. Then the list elements are stored in an array and compared to the key to see
    *        whether or not the order was maintained.
    **/
};

#include"LinkedListTester.hpp"
#endif
