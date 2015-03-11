#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

template<class T>
class Stack
{
public:
	// Constructors, Destructors, Operators
	Stack(int size);
	Stack(const Stack &stack);
	const Stack& operator=(const Stack &stack);
	~Stack();

	// Methods.
	T peek();
	T pop();
	void push(T element);

	// Trivial functions
	void clearError() {mErrorFlag = false;}
	bool isEmpty() {return mOpenSlot == 0;}
	bool isFull(){return mOpenSlot == mMaxSize;}
	bool isError() {return mErrorFlag;}

private:
	T* mData;
	int mMaxSize;
	int mOpenSlot;
	bool mErrorFlag;

};

#include "stackIMP.hpp"

#endif // STACK_HPP
