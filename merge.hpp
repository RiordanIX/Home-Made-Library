#ifndef MERGE_HPP
#define MERGE_HPP

// forward statements of functions.

template<class T>
void merge_sort(T A[], T temp[], int begin, int end);

template<class T>
void _merge(T A[], T temp[], int begin, int mid, int end);

template<class T>
void _copy(T A[], T temp[], int begin, int end);



// Implementation of functions.


template<class T> // temp is the empty array.
void merge_sort(T A[], T temp[], int begin, int end)
{
	if(end - begin < 2) // if size of array is == 1 
		return;
	// recursively split into halves until size is 1,
	// then merge and go back up.
	int mid = (end + begin) / 2;
	merge_sort(A, temp, begin, mid);	// mid will be excluded.
	merge_sort(A, temp, mid, end);		// mid will be included.
	_merge(A, temp, begin, mid, end);
	_copy (A, temp, begin, end);
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
