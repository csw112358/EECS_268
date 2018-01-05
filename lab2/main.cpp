//Author: Chris Watkins
//Assignment: EECS268 lab2
//Description: Interaction with user and calls to interactive and test classes.
//Date: 2/5/17

#include<iostream>
#include"LinkedList.h"
#include"Node.h"
#include"LinkedListTester.h"
using namespace std;

//helper functions
void printMenu()
{
  cout<<"Make a selection\n"
      <<"1) Add front\n"
      <<"2) Add back\n"
      <<"3) Remove front\n"
      <<"4) Remove back\n"
      <<"5) Insert value at position\n"
      <<"6) Print length\n"
      <<"7) Print list\n"
      <<"8) Exit\n"
      <<"Choice: ";
}


int main(int argc, char** argv)
{
  if(argc<2)
  {
    cout<<"Incorrect number of parameters.\n";
  }
  else
  {
        string flag = argv[1];
        if(flag == "-i")
        {

          LinkedList<int> list;

            int choice = 0;
            do
            {
              printMenu();
              cin>>choice;
              if(choice == 1)
              {
                int value;
                cout<<"Enter value to add to front: ";
                cin>>value;
                list.addFront(value);
              }
              else if(choice == 2)
              {
                int value;
                cout<<"Enter value to add to back: ";
                cin>>value;
                list.addBack(value);
              }
              else if(choice == 3)
              {
                list.removeFront();
              }
              else if(choice == 4)
              {
                list.removeBack();
              }
              else if(choice==5)
              {
                int position;
                int value;
                cout<<"Enter position: \n";
                cin>>position;
                cout<<"Enter value: \n";
                cin>>value;
                list.insert(position, value);
              }
              else if(choice == 6)
              {
                int length = list.getLength();
                cout<< length<<endl;
              }
              else if(choice == 7)
              {
                list.printList();
              }
            }while (choice!=8);
        }
        else if(flag == "-t")
        {
          LinkedListTester tester;
          tester.runTests();
        }
        else
        {
          cout<<"Error: no flag parameter given.\n";
        }
  }
  return(0);
}
