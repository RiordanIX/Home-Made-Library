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
class SLlist
{
public:
	SLlist();
	void insertBegin(T data);
	void insertEnd(T data);
	void printList();
	void clear();

	~SLlist();
private:
	SLL_Node<T> *mHead;
	SLL_Node<T> *mTail;
	void initList(T data);
};
#include "SLlistIMP.hpp"

#endif // SLLIST_HPP

