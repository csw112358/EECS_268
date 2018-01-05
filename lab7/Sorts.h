//Author: Chris Watkins
//Assignment: EECS268 lab7
//Description: Declaration of Sorts class that has static methods for each type of sorting algorithm.
//Date: 3/15/17
#ifndef SORTS_H
#define SORTS_H
#include <cstdlib>
#include <ctime>
#include <random>
#include <functional>
using namespace std;

template <typename T>
class Sorts
{
public:
  static void bubbleSort(T arr[], int size);
  // @pre
  // @post array is sorted by bubble sort algorithm.
  // @return none
  static void selectionSort(T arr[], int size);
  // @pre
  // @post array is sorted by selection sort algorithm.
  // @return none
  static void insertionSort(T arr[], int size);
  // @pre
  // @post array is sorted by insertion sort algorithm.
  // @return none
  static void mergeSort(T arr[], int first, int last);
  // @pre
  // @post array is sorted by merge sort algorithm.
  // @return none
  static void quickSort(T arr[], int size);
  // @pre
  // @post Calls quickSortRec with median flag set to false
  // @return none
  static void quickSortWithMedian(T arr[], int size);
  // @pre
  // @post Calls quickSortRec with median flag set to true
  // @return none
  static double timer(function<void(T[], int)> sort, T arr[], int size);
  //used to time the sort algorithms
  static double mergeTimer(function<void(T[],int,int)> sort, T arr[], int first, int last);

private:
  static int findIndexofLargest(const T arr[], int size);
  // @pre
  // @post Used to find index of largest value in given array.
  // @return none
  static void merge(int arr[], int first, int mid, int last);
  // @pre
  // @post Used by merge sort to combine two sorted arrays into a single sorted array.
  // @return none
  static void quickSortRec(T arr[], int first, int last, bool median);
  // @pre
  // @post Sorts the array by partitioning the array, quick sorting every left of the pivot,
  //       and quick sorting everything right of the pivot.
  //       Passes median to partition to inform that method how to pick a pivot value.
  // @return none
  static void setMedianPivot(T arr[], int first, int last);
  // @pre
  // @post Used by quickSort.
  //       Puts the median value of the array in the last position
  //       Does not lose any values in the process.
  // @return none
  static int partition(T arr[], int first, int last, bool median);
  // @pre
  // @post used by quickSort. Partitions the array; chooses a pivot based on the median flag,
  //       if median is true, use setMedianPivot, otherwise selects the last element in the array.
  // @return returns the index of the pivot
};

#include "Sorts.hpp"
#endif
