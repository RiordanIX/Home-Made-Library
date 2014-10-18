#ifndef INSERTION_HPP
#define INSERTION_HPP


template<class T>
void insertion_sort(T *A, int size)
{
	// Return if empty array, or size is less than 1.
	if (A == 0 || size < 1)
		return;

	T temp;
	int i, j;
	for (i = 1; i < size; i++)
	{
		temp = A[i];
		for (j = i; j > 0 && temp < A[j-1]; j--)
		{
			A[j] = A[j-1];
		}
		A[j] = temp;
	}
}


#endif // INSERTION_HPP
