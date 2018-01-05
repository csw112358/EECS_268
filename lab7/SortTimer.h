// Assignment: EECS268 lab7
// Description: Declaration of SortTimer class to time algorithms.
// Date: 3/15/17
#ifndef SORT_TIMER_H
#define SORT_TIMER_H
#include <functional>
using namespace std;

template <typename T>
class SortTimer
{
public:
  static double timer(function<void(T[], int)> sort, T arr[], int size);
private:

};

#endif
