//Author: Chris Watkins
//Assignment: EECS268 lab7
//Description: Implementation of Sorts class methods.
//Date: 3/15/17
using namespace std;
#include <cstdlib>
#include <ctime>
#include <random>
#include <functional>

template <typename T>
double Sorts<T>::timer(function<void(T[],int)> sort, T arr[], int size)
{
  clock_t start;
  double duration;
  start = clock();
  //call passed in sort algo
  sort(arr, size);

  duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
  return duration;
}

template <typename T>
double Sorts<T>::mergeTimer(function<void(T[],int,int)> sort, T arr[], int first, int last)
{
  clock_t start;
  double duration;
  start = clock();
  //call passed in sort algo
  sort(arr, first, last);

  duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
  return duration;
}

template <typename T>
int Sorts<T>::findIndexofLargest(const T arr[], int size)
{
  int indexSoFar = 0;
  for(int currentIndex = 1; currentIndex < size; currentIndex++)
  {
    if(arr[currentIndex] > arr[indexSoFar])
    {
      indexSoFar = currentIndex;
    }
  }
  return indexSoFar;
} // end findIndexofLargest

template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
  bool sorted = false;
  int pass = 1;
  while (!sorted && (pass<size))
  {
    sorted = true;
    for(int i = 0 ; i<size-pass ; i++)
    {
      int nextIndex = i+1;
      if( arr[i] > arr[nextIndex])
      {
        swap(arr[i], arr[nextIndex]);
        sorted = false;
      }
    }
    pass++;
  }
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
  for(int last = size-1; last>= 1; last--)
  {
    int largest = findIndexofLargest(arr, last+1);
    swap(arr[largest], arr[last]);
  }
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
  int j, temp;
	for (int i = 0; i < size; i++)
  {
		j = i;
		while (j > 0 && (arr[j] < arr[j-1]))
    {
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
		}
	}
}


template <typename T>
void Sorts<T>::merge(int arr[], int first, int mid, int last)
{
    T tempArr[last+1];
    int first1 = first;
    int last1 = mid;
    int first2 = mid+1;
    int last2 = last;

  int index = first1;
  while((first1 <= last1) && (first2 <= last2))
  {
    if(arr[first1] <= arr[first2])
    {
      tempArr[index] = arr[first1];
      first1++;
    }
    else
    {
      tempArr[index] = arr[first2];
      first2++;
    }
      index++;
  }

  while(first1 <= last1)
  {
      tempArr[index] = arr[first1];
      first1++;
      index++;
  }
  while(first2<= last2)
  {
    tempArr[index] = arr[first2];
    first2++;
    index++;
  }
  for(index=first; index <= last; index++)
  {
    arr[index] = tempArr[index];
  }
}

template <typename T>
void Sorts<T>::mergeSort(T arr[], int first, int last)
{
  if (first < last)
  {
    int mid = first + (last - first) / 2;
     mergeSort(arr, first, mid);
     mergeSort(arr, mid + 1, last);
     merge(arr, first, mid, last);
   }
}

template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
  quickSortRec(arr, 0, (size-1), false);
}

template <typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{
  quickSortRec(arr, 0, (size-1), true);
}

template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
  int pivot;
  int size = (last+1) - first;
  if(size <=1)
  {
    return;
  }
  else
  {
    pivot = partition(arr, first, last, median);
    quickSortRec(arr, first, pivot-1, median);
    quickSortRec(arr, pivot+1, last, median);
  }
}

template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
  int pivot = (last+first)/2;
	T temp;
	temp = arr[pivot];
	arr[pivot] = arr[last];
	arr[last] = temp;
}

template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
	int left = first;
	int right = last-1;
	int pivot = last;
	T temp;

	if (median)
  {
		setMedianPivot(arr, first, last);
	}
	while (left != right)
  {
	  if (arr[left] <= arr[pivot])
    {
	    ++left;
	  }
	  else if (arr[right] > arr[pivot])
    {
	    --right;
	  }
	  else
    {
	    temp = arr[left];
	    arr[left] = arr[right];
	    arr[right] = temp;
	  }
	}
	if (arr[left] > arr[pivot])
  {
	  temp = arr[pivot];
	  arr[pivot] = arr[left];
	  arr[left] = temp;
	  pivot = left;
	}
	return(pivot);
}
