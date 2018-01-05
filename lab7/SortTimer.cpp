// Author: Chris Watkins
// Assignment: EECS268 lab7
// Description: Definition of SortTimer methods.
// Date: 3/15/17
#include "SortTimer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Sorts.h"
#include <random>
#include <functional>
#include <cstdio>
using namespace std;

template <typename T>
double SortTimer<T>::timer(function<void(T[],int)> sort, T arr[], int size)
{
  clock_t start;
  double duration;
  start = clock();
  //call passed in sort algo
  sort(arr, size);

  duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
  return duration;
}
