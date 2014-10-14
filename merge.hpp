#ifndef MERGE_HPP
#define MERGE_HPP

#include <iostream>

template<class T>
T* mergeSort(T* unsorted, int size)
{
	if (size <= 1)
		return unsorted;

	// Bit-shifting and subtracting so that odd size arrays will be split consistently.
	int sizeOfA = size >> 1;
	int sizeOfB = size - sizeOfA;

	T A[sizeOfA];// Front half
	T B[sizeOfB] = *(unsorted[sizeOfA]);// Second half.
	T C[size];

	if (size > 2)
	{
		A = mergeSort(unsorted, sizeOfA);
		// Pointer pointing to the dereferenced value of unsorted at sizeOfA
		// (Start of the second half of the array)
		B = mergeSort(*(unsorted[sizeOfA]), sizeOfB);
	}
	
	if (size == 2)
	{
		if (unsorted[0] < unsorted[1])
		{
			C[0] = unsorted[0];
			C[1] = unsorted[1];
			return C;
		}
	}

	int i = 0;
	int j = 0;
	// Actual merge part.
	for (int k = 0; k < size; ++k)
	{
		if (A[i] < B[j])
		{
			C[k] = A[i];
			++i;
		}
		else
		{
			C[k] = B[j];
			++j;
		}
	}

	return C;
}


#endif // MERGE_HPP
