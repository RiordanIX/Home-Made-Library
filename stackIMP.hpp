#ifndef STACKIMP_HPP
#define STACKIMP_HPP


#include "stack.hpp"

// Constructor
template<class T>
Stack<T>::Stack(int size)
{
	if (size > 0) // why we're not atomizing initiation of vars.
	{
		mMaxSize  = size;
		mOpenSlot = 0;

		mData = new T[size];
		if (mData == nullptr) // couldn't allocate memory.
			mErrorFlag = true;
		else
			mErrorFlag = false;
	}

	else
	{
		mErrorFlag = true; // Someone put a negative or 0 value.
	}
}

// Copy Constructor
template<class T>
Stack<T>::Stack(const Stack<T> &stack)
{
	mMaxSize = stack.mMaxSize;
	mOpenSlot = stack.mOpenSlot;

	mData = new T[mMaxSize];

	if (mData) //Could allocate memory.
	{
		mErrorFlag = false;

		for (int iii = 0; iii < mMaxSize; ++iii)
		{
			mData[iii] = stack.mData[iii];
		}
	}

	else
	{
		mErrorFlag = true;
	}
}

// Assignment
template<class T>
const Stack<T>& Stack<T>::operator=(const Stack &stack)
{
	delete[] mData; // Delete so can reallocate new array.
	mOpenSlot = stack.mOpenSlot;
	mMaxSize  = stack.mMaxSize;
	mData = new T[mMaxSize];

	if (mData)
	{
		mErrorFlag = false;
		for (int iii = 0; iii < mMaxSize; ++iii)
		{
			mData[iii] = stack.mData[iii];
		}
	}
	else
		mErrorFlag = true;
	return *this;
}


template<class T>
T Stack<T>::peek()
{
	if (isEmpty()) // Can't return anything if it's empty.
	{
		mErrorFlag = true;
		return 0;
	}

	return mData[mOpenSlot - 1];// Last available value
}


template<class T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		mErrorFlag = true;
		return 0;
	}
	mOpenSlot--;
	return mData[mOpenSlot];
}

template<class T>
void Stack<T>::push(T element)
{
	if (isFull())
	{
		mErrorFlag = true;
		return;
	}
	mData[mOpenSlot] = element;
	mOpenSlot++;
}

template<class T>
Stack<T>::~Stack()
{
	if(mData)
	{
		delete[] mData;
		mData = nullptr;
	}
}

#endif // STACKIMP_HPP
