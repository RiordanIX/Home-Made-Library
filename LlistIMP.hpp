#ifndef LLISTIMP_HPP
#define LLISTIMP_HPP

#include "Llist.hpp"

template<class T>
Llist<T>::Llist() : mHead(nullptr), mTail(nullptr) {}

template<class T>
void Llist<T>::initList(T _data)
{
	// Because it's the only element in the list,
	// the head and the tail are the same.
	mTail = new Node<T>();
	mTail->data = _data;	// Set data
	mTail->next = nullptr;	// No next node.
	mHead = mTail;
}

template<class T>
void Llist<T>::insertBegin(T _data)
{
	// if empty, need to make new stuff.
	if (mTail == nullptr)
	{
		initList(_data);
	}

	else
	{
		Node<T> *node = new Node<T>();
		node->data = _data;
		node->next = mHead;		// Setting next of the new node to this one
		mHead = node;
	}
}

template<class T>
void Llist<T>::insertEnd(T _data)
{
	if (mHead == nullptr)
	{
		initList(_data);
	}

	else
	{
		Node<T> *node = new Node<T>();
		node->data = _data;
		node->next = nullptr;
		mTail->next = node; // This is now the second to last node, so pointing it to the end,
		mTail = node;		// before setting the Tail to the end.
	}
}

template<class T>
void Llist<T>::printList()
{
	Node<T> *step = mHead;		// Used to step through the list.

	while (step != nullptr) // while not at end of list.
	{
		std::cout << step->data << " ";
		step = step->next;	// Pointing to next in list.
	}

	std::cout << std::endl << std::endl;
	// Reiterate beginning and end of list.
	if (mHead)
		std::cout << "Head is " << mHead->data << std::endl;
	if (mTail)
		std::cout << "Tail is " << mTail->data << std::endl;
}

template<class T>
void Llist<T>::clear()
{
	Node<T> *step = mHead;
	while (step != nullptr)
	{
		Node<T> *temp = step;	// Temporary node.
		step = step->next;	// Set the step to the next node.
		delete temp;		// Free the memory.
	}

	mHead = mTail = nullptr;
}

template<class T>
Llist<T>::~Llist()
{
	clear();
}

#endif // LLISTIMP_HPP
