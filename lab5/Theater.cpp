//Author: Chris Watkins
//Assignment: EECS268 lab5
//Description: Definiiton of Theater methods
//Date: 2/22/17
#include "Theater.h"
#include<iostream>
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;

Theater::Theater(string file)
{
  fileName = file;
  ifstream inFile;
  inFile.open(fileName);
  if(inFile.is_open())
  {
      int i=1;
      while(!inFile.eof())
      {
        string temp;
        inFile>>temp;
        inputList.addBack(temp);

        i++;
      if(inFile.eof())
        {
          break;
        }
      }
      inFile.close();
  }
  else
  {
    cout<<"Error, file not opened.";
  }
}

Theater::~Theater()
{
  // theaterStack.~Stack();
  // ticketLineQueue.~Queue();
  // inputList.~LinkedList();

}

void Theater::run()
{
  do
  {
    int i=1;
    string condition = inputList.getEntry(i);
          if(condition== "TICKET")
          {
            string name;
            name = inputList.getEntry(i+1);
            try
            {
              ticketLineQueue.enqueue(name);
              inputList.removeFront();
              inputList.removeFront();
  			    }
  			    catch (const PreconditionViolationException& e)
            {
  				    cout << e.what() << endl;
            }
          }
          else if(condition== "SEATING")
          {
            inputList.removeFront();
            while(theaterStack.getSize() < theaterStack.getMaxSize())
            {
              if(ticketLineQueue.isEmpty() == true)
              {
                break;
              }

              string person;
              try
              {
                person = ticketLineQueue.peek();
    			    }
    			    catch (const PreconditionViolationException& e)
              {
    				    cout << e.what() << endl;
              }

              try
              {
                theaterStack.push(person);
              }
              catch (const PreconditionViolationException& e)
              {
                cout << e.what() << endl;
              }

              try
              {
                ticketLineQueue.dequeue();
              }
              catch (const PreconditionViolationException& e)
              {
                cout << e.what() << endl;
              }
            }
          }
          else if(condition== "EJECTION")
          {
            string numString = inputList.getEntry(i+1);
            int num = stoi(numString);
            inputList.removeFront();
            inputList.removeFront();
            for(int i=1;i<=num;i++)
            {
              try
              {
                theaterStack.pop();
              }
              catch (const PreconditionViolationException& e)
              {
                cout << e.what() << endl;
              }
            }
          }
          else if(condition== "CREDITS")
          {
            inputList.removeFront();
            while(theaterStack.isEmpty()==false)
            {
              try
              {
                theaterStack.pop();
              }
              catch (const PreconditionViolationException& e)
              {
                cout << e.what() << endl;
              }
            }
          }
          else if(condition== "STATUS")
          {
            inputList.removeFront();
            cout<<"Welcome to the Jayhawk Cineplex:\n";
            if(theaterStack.isEmpty()==true)
            {
              cout<<"The theater is empty\n";
              try
              {
                //string ticketPerson = ticketLineQueue.peek();
                cout<<ticketLineQueue.peek()<<" is next in the ticket line.\n";
              }
              catch (const PreconditionViolationException& e)
              {
                cout << e.what() << endl;
              }
            }
            else
            {
              cout<<"The theater is not empty\n";

              if(ticketLineQueue.isEmpty()==false)
              {
                try
                {
                  //string ticketPerson = ticketLineQueue.peek();
                  cout<<ticketLineQueue.peek()<<" is next in the ticket line.\n";
                }
                catch (const PreconditionViolationException& e)
                {
                  cout << e.what() << endl;
                }
              }

              try
              {
                //string theaterPerson = theaterStack.peek();
                cout<<theaterStack.peek()<<" will be the first to leave the theater.\n";
              }
              catch (const PreconditionViolationException& e)
              {
                cout << e.what() << endl;
              }
              cout<<endl;
            }
          }
  }while(inputList.getLength() > 1);
  //this while loop assumes the inputlist ends with a new line i.e. whitespace
}
  // ifstream inFile;
  // inFile.open(fileName);
  // if(inFile.is_open())
  // {
  //     while(!inFile.eof())
  //     {
  //       string condition;
  //       inFile >> condition;
  //       if(condition== "TICKET")
  //       {
  //         string name;
  //         inFile>> name;
  //         try
  //         {
  //           ticketLineQueue.enqueue(name);
	// 		    }
	// 		    catch (const PreconditionViolationException& e)
  //         {
	// 			    cout << e.what() << endl;
  //         }
  //       }
  //       else if(condition== "SEATING")
  //       {
  //
  //       }
  //       else if(condition== "EJECTION")
  //       {
  //         int num;
  //         inFile>>num;
  //
  //       }
  //       else if(condition== "CREDITS")
  //       {
  //
  //       }
  //       else if(condition== "STATUS")
  //       {
  //
  //       }
  //
  //
  //       if(inFile.eof())
  //       {
  //         break;
  //       }
  //     }
  //   inFile.close();
  // }
  // else
  // {
  //   cout<<"Error, file not opened.";
  // }
