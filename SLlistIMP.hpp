#ifndef SLLISTIMP_HPP
#define SLLISTIMP_HPP

#include "SLlist.hpp"    // Singly Linked List

template<class T>
SLlist<T>::SLlist() : mHead(nullptr), mTail(nullptr) {}

template<class T>
void SLlist<T>::initList(T _data)
{
	// Because it's the only element in the list,
	// the head and the tail are the same: nullptr
	mTail = new SLL_Node<T>();
	mTail->data = _data;	// Set data
	mTail->next = nullptr;	// No next node.
	mHead = mTail;
}

template<class T>
void SLlist<T>::insertBegin(T _data)
{
	// if empty, need to make new stuff.
	if (mTail == nullptr)
	{
		initList(_data);
	}

	else
	{
		SLL_Node<T> *node = new SLL_Node<T>();
		node->data = _data;
		node->next = mHead;		// Setting next of the new node to this one
		mHead = node;
	}
}

template<class T>
void SLlist<T>::insertEnd(T _data)
{
	if (mHead == nullptr)
	{
		initList(_data);
	}

	else
	{
		SLL_Node<T> *node = new SLL_Node<T>();
		node->data = _data;
		node->next = nullptr;
		mTail->next = node;	// This is now the second to last node, so pointing it to the end,
		mTail = node;		// before setting the Tail to the end.
	}
}

template<class T>
void SLlist<T>::printList()
{
	SLL_Node<T> *step = mHead;		// Used to step through the list.

	while (step != nullptr)		// while not at end of list.
	{
		std::cout << step->data << " ";
		step = step->next;      // Pointing to next in list.
	}

	std::cout << std::endl << std::endl;
	// Reiterate beginning and end of list.
	if (mHead)
		std::cout << "Head is " << mHead->data << std::endl;
	if (mTail)
		std::cout << "Tail is " << mTail->data << std::endl;
}

// Since this is a dynamic class, we need to free up the memory we allocated.
// No memory leaks here!
template<class T>
void SLlist<T>::clear()
{
	SLL_Node<T> *step = mHead;
	while (step != nullptr)
	{
		SLL_Node<T> *temp = step;	// Temporary node.
		step = step->next;	// Set the step to the next node.
		delete temp;		// Free the memory.
	}

	mHead = mTail = nullptr;
}

template<class T>
SLlist<T>::~SLlist()
{
	clear();
}

#endif // LLISTIMP_HPP
