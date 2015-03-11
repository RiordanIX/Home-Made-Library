#ifndef SLLISTIMP_HPP
#define SLLISTIMP_HPP

#include "SLList.hpp"    // Singly Linked List

template<class T>
SLList<T>::SLList() : _head(nullptr), _tail(nullptr) {}

template<class T>
void SLList<T>::initList(T _data)
{
	// Because it's the only element in the list,
	// the head and the tail are the same: nullptr
	_tail = new SLL_Node<T>();
	_tail->data = _data;	// Set data
	_tail->next = nullptr;	// No next node.
	_head = _tail;
}

template<class T>
void SLList<T>::insertBegin(T _data)
{
	// if empty, need to make new stuff.
	if (_tail == nullptr)
	{
		initList(_data);
	}

	else
	{
		SLL_Node<T> *node = new SLL_Node<T>();
		node->data = _data;
		node->next = _head;		// Setting next of the new node to this one
		_head = node;
	}
}

template<class T>
void SLList<T>::insertEnd(T _data)
{
	if (_head == nullptr)
	{
		initList(_data);
	}

	else
	{
		SLL_Node<T> *node = new SLL_Node<T>();
		node->data = _data;
		node->next = nullptr;
		_tail->next = node;	// This is now the second to last node, so pointing it to the end,
		_tail = node;		// before setting the Tail to the end.
	}
}

template<class T>
void SLList<T>::printList()
{
	SLL_Node<T> *step = _head;		// Used to step through the list.

	while (step != nullptr)		// while not at end of list.
	{
		std::cout << step->data << " ";
		step = step->next;      // Pointing to next in list.
	}

	std::cout << std::endl << std::endl;
	// Reiterate beginning and end of list.
	if (_head)
		std::cout << "Head is " << _head->data << std::endl;
	if (_tail)
		std::cout << "Tail is " << _tail->data << std::endl;
}

// Since this is a dynamic class, we need to free up the memory we allocated.
// No memory leaks here!
template<class T>
void SLList<T>::clear()
{
	SLL_Node<T> *step = _head;
	while (step != nullptr)
	{
		SLL_Node<T> *temp = step;	// Temporary node.
		step = step->next;	// Set the step to the next node.
		delete temp;		// Free the memory.
	}

	_head = _tail = nullptr;
}

template<class T>
SLList<T>::~SLList()
{
	clear();
}

#endif // LLISTIMP_HPP
