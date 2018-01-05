//Author: Chris Watkins
//Assignment: EECS268 lab3
//Description: MedicalExecutive method definitions
//Date: 1/25/17
#include<iostream>
#include"LinkedList.h"
#include"Node.h"
#include"City.h"
#include<fstream>
#include<string>
#include<cstdlib>
#include<stdexcept>
#include<limits>
using namespace std;

MedicalExecutive::MedicalExecutive(string fileName)
{
  ifstream inFile;
  inFile.open(fileName);
  if(inFile.is_open())
  {
      LinkedList<City> cityList;
      LinkedList<City> quarantineList;

      while(!inFile.eof())
      {
          string tempName, tempPop, tempIFNlevel;
          char tempChar = ',';
          getline(inFile, tempName, tempChar);
          getline(inFile, tempPop, tempChar);
          getline(inFile, tempIFNlevel, '\n');
          if(inFile.eof())
          {
            break;
          }
          int pop;
          int IFNlevel;

          pop = stoi(tempPop);
          IFNlevel = stoi(tempIFNlevel);

          // cout<<tempName<<" "<<pop<<" "<<IFNlevel<<" \n";
          City temp = City(tempName, pop, IFNlevel);
          addCityToList(temp);
          // cout<< (cityList.getEntry(1).getPop()) << endl;
      }
        inFile.close();
  }
  else
  {
    std::cout<<"Error, file not opened.";
  }
}

MedicalExecutive::~MedicalExecutive()
{
  cityList.~LinkedList();
  quarantineList.~LinkedList();
}

void MedicalExecutive::requiredActions()
{
  LinkedList<City> tempList;

  int pop, IFNlevel;
  string name;
  int i = 1;
  while (cityList.getLength() >0)
  {
    int level = (cityList.getEntry(i)).getIFNlevel();

    if( level == 1)
    {
      name = (cityList.getEntry(i)).getName();
      pop = (cityList.getEntry(i)).getPop();
      IFNlevel = (cityList.getEntry(i)).getIFNlevel();
      City temp1 = City(name, pop, IFNlevel);
      removeCityFromList( cityList.getEntry(i) );
      temp1.decPop(10);
      // addCityToList(temp);
      tempList.addFront(temp1);
      cout<<"1\n";

    }
    else if(level == 2)
    {
      name = (cityList.getEntry(i)).getName();
      pop = (cityList.getEntry(i)).getPop();
      IFNlevel = (cityList.getEntry(i)).getIFNlevel();
      City temp2 = City(name, pop, IFNlevel);
      removeCityFromList( cityList.getEntry(i) );
      temp2.decPop(20);
      // addCityToList(temp);
      tempList.addFront(temp2);
      cout<<"2\n";

    }
    else if( level == 3)
    {
      name = (cityList.getEntry(i)).getName();
      pop = (cityList.getEntry(i)).getPop();
      IFNlevel = (cityList.getEntry(i)).getIFNlevel();
      City temp3 = City(name, pop, IFNlevel);
      removeCityFromList( cityList.getEntry(i) );

      int newPop;
      string newName;
      string nw = "New ";
      newPop = (temp3.getPop() / 4);
      newName = (nw + temp3.getName());
      City newCity = City(newName, newPop, 0);

      temp3.decPop(25);
      tempList.addFront(temp3);
      tempList.addFront(newCity);
      cout<<"3\n";
    }
    else if(level == 4)
    {
      name = (cityList.getEntry(i)).getName();
      pop = (cityList.getEntry(i)).getPop();
      IFNlevel = (cityList.getEntry(i)).getIFNlevel();
      City temp4 = City(name, pop, IFNlevel);
      removeCityFromList( cityList.getEntry(i) );
      addCityToQList(temp4);
      cout<< name <<" has been placed in quarantine.\n";
      cout<<"4\n";
    }
  }

  for(int i=1;i<=tempList.getLength();i++)
  {
    City temp = tempList.getEntry(i);
    addCityToList( temp );
  }
   tempList.~LinkedList();
}

void MedicalExecutive::upIFNlevel(string cityName)
{
  for(int i=1;i<=cityList.getLength();i++)
  {
    if( ((cityList.getEntry(i)).getName()) == cityName )
    {
      (cityList.getEntry(i)).incIFNlevel();
      cout<<"The IFN level of" << (cityList.getEntry(i)).getName() << "was increased by 1.\n";
    }
    else
    {
      cout<<"Sorry that city is not on the list";
    }
  }
}


void MedicalExecutive::upIFNlevelALL()
{
  for(int i=1;i<=cityList.getLength();i++)
  {
      (cityList.getEntry(i)).incIFNlevel();
  }
  cout<<"The IFN level for all cities has been increased by 1.\n";
}

void MedicalExecutive::removeCityFromList(City c)
{
  if(cityList.getLength()==0)
  {
    cout<<"List empty - cannot remove city.\n";
  }
  else
  {
    for(int i=1; i<=cityList.getLength(); i++)
    {
      if( ((cityList.getEntry(i)).getName()) == c.getName())
      {
        cityList.removeAt(i);
      }
    }
  }
}

void MedicalExecutive::addCityToList(City c)
{
  if(cityList.getLength()==0)
  {
    cityList.addFront(c);
  }
  else
  {
    int i =1;
    for(i; i<cityList.getLength(); i++)
    {
      City temp = cityList.getEntry(i);
      if(temp.getPop()< c.getPop())
      {
        break;
      }
    }
    cityList.insert(i, c);
  }
}

void MedicalExecutive::addCityToQList(City c)
{
  if(quarantineList.getLength() ==0 )
  {
    quarantineList.addFront(c);
  }
  else
  {
    int i =1;
    for(i; i<quarantineList.getLength(); i++)
    {
      City temp = quarantineList.getEntry(i);
      if(temp.getPop()< c.getPop())
      {
        break;
      }
    }
    quarantineList.insert(i, c);
  }
}

void MedicalExecutive::printCity(string cityName)
{
  for(int i=1;i<=cityList.getLength();i++)
  {
    if( ((cityList.getEntry(i)).getName()) == cityName)
    {
      cout<< "City name: " << (cityList.getEntry(i)).getName() << endl
          << "Population: " << (cityList.getEntry(i)).getPop() << endl
          << "Infection level: " << (cityList.getEntry(i)).getIFNlevel() << endl;
      cout<< endl;
    }
  }
}

void MedicalExecutive::run()
{
    int choice = 0;
    do
    {
      printMenu();
      cin>>choice;

    while ( std::cin.fail() )
    {
        int n=0;
        std::cin.clear(); // unset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
        std::cout << "Sorry, your input did not seem to be an int. Try again: ";
        std::cin >> n;
    }

      if(choice == 1)
      {
        upIFNlevelALL();
        requiredActions();
      }
      else if(choice == 2)
      {
        string cityName;
        cout<<"Enter name of City: ";
        cin>>ws;
        getline(cin, cityName);
        upIFNlevel(cityName);
        requiredActions();
      }
      else if(choice == 3)
      {
        string cityName;
        cout<<"Enter name of city: ";
        cin>>ws;
        getline(cin, cityName);
        printCity(cityName);
      }
      else if(choice == 4)
      {
        if(quarantineList.isEmpty()== true)
        {
          cout<<"Quarantine list currently empty.\n";
        }
        else
        {
          string fileName;
          cout<<"Enter file name to save list to: ";
          cin>>fileName;

          ofstream outFile;
          outFile.open(fileName);
          for(int i=1;i<=quarantineList.getLength();i++)
          {
            outFile << (quarantineList.getEntry(i)).getName()
                    << ", " << (quarantineList.getEntry(i)).getPop() << ", "
                    <<  (quarantineList.getEntry(i)).getIFNlevel() << endl;
          }
          outFile.close();
        }
      }
      else if (choice==5)
      {
        int level;
        cout<<"Enter infection level: ";
        cin>>level;

    while ( std::cin.fail() )
    {
        int n = 0;
        std::cin.clear(); // unset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
        std::cout << "Sorry, your input did not seem to be an int. Try again: ";
        std::cin >> n;
    }

        for(int i=1;i<=cityList.getLength();i++)
        {
          if( ((cityList.getEntry(i)).getIFNlevel()) >= level)
          {
            cout<< "City name: " << (cityList.getEntry(i)).getName() << endl
                << "Population: " << (cityList.getEntry(i)).getPop() << endl
                << "Infection level: " << (cityList.getEntry(i)).getIFNlevel() << endl;
            cout<< endl;
          }
        }
      }

    }while (choice!=6);
    cityList.~LinkedList();
    quarantineList.~LinkedList();
}


void MedicalExecutive::printMenu()
{
  cout<<"Make a selection\n"
      <<"1) Increase infection level of all cities\n"
      <<"2) Increase infection level of specific city\n"
      <<"3) Print status of a specific city\n"
      <<"4) Create quarantine log\n"
      <<"5) Print all cities above an infection level\n"
      <<"6) Exit\n"
      <<"Choice: ";
}
