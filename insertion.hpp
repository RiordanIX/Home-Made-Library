#ifndef INSERTION_HPP
#define INSERTION_HPP

// We have a 'begin' variable in case you only want a certain part sorted.
// This is mostly added for the low-end phases of merge_sort and others.
template<class T>
void insertion_sort(T *A, int end, int begin = 0)
{
	// Return if empty array, or end (the size in some cases) is less than 1.
	if ((A == nullptr) || (end < 1))
		return;

	// Temporary object for moving stuff around.
	T temp;
	// looping variables initiated here because it's easier copying to the temp object.
	int i, j;

	// Start at second element.
	for (i = begin + 1; i < end; i++)
	{
		temp = A[i];

		// Loop through elements starting with one less than i, and as long as
		// A[j] is greater than A[i], shift array to the right until the original
		// A[i] is INSERTED in the right place.
		for (j = i; j > begin && temp < A[j-1]; j--)
		{
			A[j] = A[j-1];
		}
		A[j] = temp;
	}
}


#endif // INSERTION_HPP
