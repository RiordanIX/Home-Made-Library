#ifndef MERGE_HPP
#define MERGE_HPP

#include "insertion.hpp"
// forward statements of functions.

template<class T>
void merge_sort(T A[], const int size);

template<class T>
void _split(T A[], T temp[], int begin, int end);

template<class T>
void _merge(T A[], T temp[], int begin, int mid, int end);

template<class T>
void _copy(T A[], T temp[], int begin, int end);



// Implementation of functions.

/// Takes an array and its size.  Creates a temporary array in order to do the
/// sort and copy correctly.  
template<class T>
void merge_sort(T A[], const int size)
{
	// No point in sorting if array doesn't point to anything or has but 1 element.
	if ((A == nullptr) || (size <= 1))
		return;
	T temp[size];
	_split(A, temp, 0, size);
	// Will automatically delete temp when loses scope.
}

template<class T> // temp is the empty array.
void _split(T A[], T temp[], int begin, int end)
{
	// I chose 16 because it's a power of 2 and 
	// if ((end - begin) <= 16)
	//	insertion_sort(A, end - begin);
	// TODO: implement insertion sort for sizes < 16.
	if ((end - begin) < 2)
		return;
	// recursively split into halves until size is 1,
	// then merge and go back up.
	int mid = (end + begin) / 2;
	_split(A, temp, begin, mid);	// mid will be excluded.
	_split(A, temp, mid, end);		// mid will be included.
	_merge(A, temp, begin, mid, end);	// merge them back again.
	_copy (A, temp, begin, end);		// Copy sorted array to original array.
}

template<class T> // temp is the empty array to have the sorted part applied.
void _merge(T A[], T temp[], int begin, int mid, int end)
{
	int i = begin;
	int j = mid;

	for (int k = begin; k < end; ++k)
	{
		// If first half is still going and is < right run part.
		if (i < mid && (j >= end || A[i] <= A[j]))
		{
			temp[k] = A[i];
			++i;
		}
		else
		{
			temp[k] = A[j];
			++j;
		}
	}
}

template<class T> // To make the original array be sorted.
void _copy(T A[], T temp[], int begin, int end)
{
	for (int i = begin; i < end; ++i)
		A[i] = temp[i];
}


#endif // MERGE_HPP
