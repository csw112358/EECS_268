//Author: Chris Watkins
//Assignment: EECS268 lab7
//Description: main.cpp - main program taking in command arguments and timing sorts.
//Date: 3/20/17
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "Sorts.h"
#include <random>
#include <functional>
#include <iomanip>
#include "SortTimer.h"
using namespace std;

int main(int argc, char* argv[])
{
  string sortType, fileName;
  int startVal, endVal, increment;
  char s;

  if(argc<6)
  {
    cout<<"Incorrect number of parameters.\n";
  }
  else
  {
    sortType = argv[1];
    startVal = stoi(argv[2]);
    endVal = stoi(argv[3]);
    increment = stoi(argv[4]);
    fileName = argv[5];

    if(sortType == "bubble")
    {s= 'B';}
    else if(sortType == "selection")
    {s = 'S';}
    else if(sortType == "insertion")
    {s = 'I';}
    else if(sortType == "merge")
    {s = 'M';}
    else if(sortType == "quick")
    {s = 'Q';}
    else if(sortType == "quickWithMedian")
    {s = 'W';}
  }

  random_device seed;
  mt19937 gen(seed());
  uniform_int_distribution<int> dist(1, 100);
  ofstream outFile;
  outFile.open(fileName);

  outFile << sortType <<endl;
  for(int i = startVal; i<= endVal; i= i+increment)
  {
    int array[i];
    for(int j = 0; j< i; j++)
    {
      array[j] = dist(gen);
    }

    double sortTime;
    switch (s)
    {
      case 'B' :
        sortTime = Sorts<int>::timer(Sorts<int>::bubbleSort, array, i);
        //Sorts<int>::bubbleSort(array, i);
        break;
      case 'S' :
        sortTime = Sorts<int>::timer(Sorts<int>::selectionSort, array, i);
        //Sorts<int>::selectionSort(array, i);
        break;
      case 'I' :
        sortTime = Sorts<int>::timer(Sorts<int>::insertionSort, array, i);
        //Sorts<int>::insertionSort(array, i);
        break;
      case 'M' :
        //sortTime = Sorts<int>::timer(Sorts<int>::mergeSort, array, i);
        sortTime = Sorts<int>::mergeTimer(Sorts<int>::mergeSort, array, 0, i-1);
        //Sorts<int>::mergeSort(array, 0, i-1);
        break;
      case 'Q' :
        sortTime = Sorts<int>::timer(Sorts<int>::quickSort, array, i);
        //Sorts<int>::quickSort(array, i);
        break;
      case 'W' :
        sortTime = Sorts<int>::timer(Sorts<int>::quickSortWithMedian, array, i);
        //Sorts<int>::quickSortWithMedian(array, i);
        break;
      default :
        cout<<"Invalid type of sort." <<endl;
    }

    outFile << std::setprecision(6) << std::fixed;
    outFile << i <<", "<< sortTime<<endl;

    // for(int k = 0; k< i; k++)
    // {
    //   outFile << array[k] << ' ';
    // }
    // outFile << endl;
  }
    outFile.close();



return(0);
}
