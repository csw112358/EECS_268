//Author: Chris Watkins
//Assignment: EECS268 lab4
//Description: Definition of all my FightManager methods
//Date: 2/18/17
#include<iostream>
#include<fstream>
using namespace std;
#include"FightManager.h"

FightManager::FightManager(string fileName)
{
  ifstream inFile;
  inFile.open(fileName);
  if(inFile.is_open())
  {


      while(!inFile.eof())
      {
        string tempPilot, tempCaptain, tempUni, tempWords, tempAP, tempMH, tempNC, tempShields;
        int AP, MH, NC;
        bool shields;
        getline(inFile, tempUni,',');
        if(tempUni=="StarWars")
        {
          getline(inFile, tempPilot, ',');
          getline(inFile, tempAP, ',');
          getline(inFile, tempMH, ',');
          getline(inFile, tempShields, ',');
          getline(inFile, tempWords, '\n');
          AP = stoi(tempAP);
          MH = stoi(tempMH);
          if(tempShields == "1")
          {
            shields = true;
          }
          else
          {shields = false;}
          StarWarsShip* temp = new StarWarsShip(tempUni, tempPilot, AP, MH, shields, tempWords);
          SpaceShipList.addFront(temp);
        }
        else if(tempUni=="StarTrek")
        {
          getline(inFile, tempCaptain, ',');
          getline(inFile, tempAP, ',');
          getline(inFile, tempNC, ',');
          getline(inFile, tempMH, ',');
          getline(inFile, tempShields, '\n');
          AP = stoi(tempAP);
          MH = stoi(tempMH);
          NC = stoi(tempNC);
          if(tempShields == "1")
          {
            shields = true;
          }
          else
          {shields = false;}
          StarTrekShip* temp = new StarTrekShip(tempUni, tempCaptain, AP, NC, MH, shields);
          SpaceShipList.addFront(temp);
        }

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

FightManager::~FightManager()
{
  SpaceShipList.~LinkedList();
}

void FightManager::run()
{
  if(SpaceShipList.getEntry(1) == nullptr)
  {
    cout<<"List empty\n";
  }
  else
  {
    int warsCount;
    int trekCount;
    do
    {
      warsCount =0;
      trekCount=0;
      for(int i=1; i<=SpaceShipList.getLength();i++)
      {
        int attack = SpaceShipList.getEntry(i)->attackPower();
        string u = SpaceShipList.getEntry(i)->universe();
        for(int j=1; j<=SpaceShipList.getLength();j++)
        {
          if(SpaceShipList.getEntry(j)->universe() != u)
          {
            SpaceShipList.getEntry(j)->takeDamage(attack);
            if(SpaceShipList.getEntry(j)->currentHull()<=0)
            {
              SpaceShipList.removeAt(j);
              if(j<i) { i--;}
            }
            //break;
          }
        }
      }

      for(int j=1; j<=SpaceShipList.getLength();j++)
      {
        cout<< SpaceShipList.getEntry(j)->status() <<endl;
        if(SpaceShipList.getEntry(j)->universe() == "StarTrek")
        {trekCount++;}
        else if(SpaceShipList.getEntry(j)->universe() == "StarWars")
        {warsCount++;}
      }
      cout<<endl;
    }while(warsCount>0 && trekCount >0);

    while(SpaceShipList.getLength() > 1)
    {
      for(int i=1; i<=SpaceShipList.getLength();i++)
      {
        int attack = SpaceShipList.getEntry(i)->attackPower();
        for(int j=1; j<=SpaceShipList.getLength();j++)
        {
            SpaceShipList.getEntry(j)->takeDamage(attack);
            if(SpaceShipList.getEntry(j)->currentHull()<=0)
            {
              SpaceShipList.removeAt(j);
              if(j<i) { i--;}
            }
            break;
        }
      }
    }
    cout<<endl;
    for(int j=1; j<=SpaceShipList.getLength();j++)
    {
      cout<< SpaceShipList.getEntry(j)->status() <<endl;
      if(SpaceShipList.getEntry(j)->universe() == "StarTrek")
      {cout<<"StarTrek is the victor.\n";}
      else if(SpaceShipList.getEntry(j)->universe() == "StarWars")
      {cout<<"StarWars is the victor.\n";}
    }
  }
}
