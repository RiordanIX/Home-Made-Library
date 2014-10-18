#ifndef INSERTION_HPP
#define INSERTION_HPP


template<class T>
void insertion_sort(T *A, int size)
{
	// Return if empty array, or size is less than 1.
	if ((A == nullptr) || (size < 1))
		return;

	// Temporary object for moving stuff around.
	T temp;
	// looping variables initiated here because it's easier copying to the temp object.
	int i, j;

	// Start at second element.
	for (i = 1; i < size; i++)
	{
		temp = A[i];

		// Loop through elements starting with one less than i, and as long as
		// A[j] is greater than A[i], shift array to the right until the original
		// A[i] is INSERTED in the right place.
		for (j = i; j > 0 && temp < A[j-1]; j--)
		{
			A[j] = A[j-1];
		}
		A[j] = temp;
	}
}


#endif // INSERTION_HPP
