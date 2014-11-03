#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

template<class T>
void _quick_sort(T * array, int start, int stop, int &m)
{
	// If array is only 1 or 0 elements long, it's sorted, so return.
	if ((stop - start) < 2)
		return;

	// These are the comparisons to be performed, and it keeps a running tally.
	m += (stop - start) -1;

	// picking the pivot point.  Right now we choose the median of the first,
	//							 middle, and last elements.
	int pick;
	T first = array[start];
	T mid = array[(stop + start - 1) / 2];
	T last = array [stop - 1];

	// Only using '<' so you don't need to overload more operators than needed.
	if ((first < mid && mid < last) || (mid < first && last < mid))
		pick = (stop + start - 1) / 2;
	else if ((first < last && last < mid) || (last < first && mid < last))
		pick = stop - 1;
	else
		pick = start;

	// Put pivot at front of array.
	T pivot = array[pick];
	// Again, using '<' instead of '!=' so only need to overload '=' and '<'.
	if (pivot < array[start] || array[start] < pivot)
	{
		T temp = array[pick];
		array[pick] = array[start];
		array[start] = temp;
	}

	int i = start + 1;
	int j = start + 1;

	// Actual pivot part.  Moves items less than the pivot to the left,
	// items higher than the pivot to the right.
	for (;j < stop; j++)
	{
		if (array[j] < pivot)
		{
			T temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			i++;
		}
	}

	// Put the pivot in it's properly sorted location.
	T temp = array[start];
	array[start] = array[i - 1];
	array[i - 1] = temp;

	// Recursively sort first then second halves.
	_quick_sort(array, start, i - 1, m);
	_quick_sort(array, i, stop, m);
}

// quick_sort returns the number of comparisons performed.
template<class T>
int quick_sort(T * array, const unsigned int n)
{
	// Initialize number of comparisons.
	int _comparisons = 0;
	_quick_sort(array, 0, n, _comparisons);
	return _comparisons;
}

#endif // QUICKSORT_HPP
