#ifndef MERGE_HPP
#define MERGE_HPP

// forward statements of functions.
template<class T>
void mergeSort(T A[], T B[], int size);

template<class T>
void __MSSplit(T A[], T B[], int _begin, int _end);

template<class T>
void __MSMerge(T A[], T B[], int _begin, int _middle, int _end);

template<class T>
void __MSCopy(T A[], T B[], int _begin, int _end);



// Implementation of functions.
// B is the uninitialized array to be filled.
template<class T>
void mergeSort(T A[], T B[], int size)
{
	__MSSplit(A, B, 0, size);
}

template<class T> // B is the empty array.
void __MSSplit(T A[], T B[], int _begin, int _end)
{
	if(_end - _begin < 2) // if size of array is == 1 
		return;
	// recursively split into halves until size is 1,
	// then merge and go back up.
	int _middle = (_end + _begin) / 2;
	__MSSplit(A, B, _begin, _middle);	// middle will be excluded.
	__MSSplit(A, B, _middle, _end);		// middle will be included.
	__MSMerge(A, B, _begin, _middle, _end);
	__MSCopy (A, B, _begin, _end);
}

template<class T> // B is the empty array to have the sorted part applied.
void __MSMerge(T A[], T B[], int _begin, int _middle, int _end)
{
	int i = _begin;
	int j = _middle;

	for (int k = _begin; k < _end; ++k)
	{
		// If first half is still going and is < right run part.
		if (i < _middle && (j >= _end || A[i] <= A[j]))
		{
			B[k] = A[i];
			++i;
		}
		else
		{
			B[k] = A[j];
			++j;
		}
	}
}

template<class T> // To make the original array be sorted.
void MSCopy(T A[], T B[], int _begin, int _end)
{
	for (int i = _begin; i < _end; ++i)
		A[i] = B[i];
}


#endif // MERGE_HPP
