//Author: Chris Watkins
//Assignment: EECS268 lab2
//Description: Definitions of the LinkedListTester methods
//Date: 2/5/17
using namespace std;
#include<iostream>

LinkedListTester::LinkedListTester()
{
}
LinkedListTester::~LinkedListTester()
{
}

void LinkedListTester::runTests()
{
  test01();
  test02();
  test03();
  test04();
  test05();
  test06();
  test07();
  test08();
  test09();
  test10();
  test11();
  test12();
  test13();
  test14();
  test15();
  test16();
}

void LinkedListTester::test01()
{
    cout<<"Test #1: size of empty list is zero ";
    LinkedList<int> list;
    if(list.getLength()==0)
    {
      cout<<"PASSED\n";
    }
    else
    {
      cout<<"FAILED\n";
    }
    list.~LinkedList();
}

void LinkedListTester::test02()
{
  cout<<"Test #2: size returns correct value after 1 addFront ";
  LinkedList<int> list;
  list.addFront(1);
  list.getLength();
  if(list.getLength()==1)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test03()
{
  cout<<"Test #3: size returns correct value after 1 addBack ";
  LinkedList<int> list;
  list.addBack(1);
  list.getLength();
  if(list.getLength()==1)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test04()
{
  cout<<"Test #4: size returns correct value after multiple addFront  ";
  LinkedList<int> list;
  list.addFront(1);
  list.addFront(2);
  list.getLength();
  if(list.getLength()==2)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test05()
{
  cout<<"Test #5: size returns correct value after multiple addBack  ";
  LinkedList<int> list;
  list.addBack(1);
  list.addBack(2);
  list.getLength();
  if(list.getLength()==2)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test06()
{
  cout<<"Test #6: size returns correct value after adds and removeFront   ";
  LinkedList<int> list;
  list.addFront(1);
  list.removeFront();
  list.getLength();
  if(list.getLength()==0)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test07()
{
  LinkedList<int> list;
  list.addBack(1);
  list.removeBack();
  list.getLength();
  cout<<"Test #7: size returns correct value after adds and removeBack   ";
  if(list.getLength()==0)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test08()
{
  int preSize, postSize;
  LinkedList<int> list;
  list.addFront(1);
  list.addBack(2);
  list.addBack(3);
  preSize = list.getLength();
  list.removeFront();
  postSize = list.getLength();
  cout<<"Test #8: size reduced by 1 removeFront on populated list ";
  if(preSize-1 == postSize)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}


void LinkedListTester::test09()
{
  int preSize, postSize;
  LinkedList<int> list;
  list.addFront(1);
  list.addBack(2);
  list.addBack(3);
  preSize = list.getLength();
  list.removeBack();
  postSize = list.getLength();
  cout<<"Test #9: size reduced by 1 removeBack on populated list ";
  if(preSize-1 == postSize)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test10()
{
  LinkedList<int> list;
  cout<<"Test #10: positionOf returns 0 on empty list ";
  if(list.positionOf(1) == 0)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test11()
{
  LinkedList<int> list;
  list.addFront(1);
  list.addBack(2);
  cout<<"Test #11: positionOf returns 0 when value not in list ";
  if(list.positionOf(3) == 0)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test12()
{
  LinkedList<int> list;
  list.addFront(1);
  list.addBack(2);
  list.addBack(9);
  cout<<"Test #12: positionOf returns correct index if value is in populated list ";
  if(list.positionOf(9) == 3)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test13()
{
  bool flag;
  LinkedList<int> list;
  flag = list.removeFront();
  cout<<"Test #13: removeFront on empty list returns false ";
  if(flag ==false)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test14()
{
  bool flag;
  LinkedList<int> list;
  flag = list.removeBack();
  cout<<"Test #14: removeBack on empty list returns false ";
  if(flag ==false)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test15()
{
  bool flag;
  LinkedList<int> list;
  flag = list.insert(5, 10);
  cout<<"Test #15: insert returns false given an invalid position ";
  if(flag ==false)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}

void LinkedListTester::test16()
{
  bool flag=true;
  LinkedList<int> list;
  list.addFront(1);
  list.addBack(2);
  list.addBack(3);
  list.insert(2, 0);
  //we know what our list order and size are, let's store in an array
  int key[4] = {1, 0, 2, 3};
  //the key array represents our list values assuming insert preserved the order
  //now lets store our list values in an array
  int listArr[4];
  for(int i=1;i<=list.getLength();i++)
  {
      listArr[i-1]=list.getEntry(i);
  }
  //now we can simply compare the list array with our key to see if insert was prefomed correctly
  for(int i=0;i<list.getLength();i++)
  {
    if( listArr[i]!=key[i] )
    {
      flag=false;
    }
  }
  cout<<"Test #16: order preserved by insert on populated list  ";
  if(flag==true)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
  list.~LinkedList();
}
