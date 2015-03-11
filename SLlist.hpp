#ifndef SLLIST_HPP
#define SLLIST_HPP

#include <iostream>

/** This is a templated Linked list class. 
**/

template<class T>
struct SLL_Node // Singly Linked List node
{
	T data;		// Actual data.
	SLL_Node *next;	// Pointer to next node.
};

template<class T>
class SLList
{
public:
	SLList();
	~SLList();
	void insertBegin(T data);
	void insertEnd(T data);
	void printList();
	void clear();

private:
	SLL_Node<T> *_head;
	SLL_Node<T> *_tail;
	void initList(T data);
};
#include "SLListIMP.hpp"

#endif // SLLIST_HPP
