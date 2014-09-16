#ifndef LLIST_HPP
#define LLIST_HPP

#include <iostream>

/** This is a templated Linked list class. 
**/

template<class T>
struct Node
{
	T data;		// Actual data.
	Node *next;	// Pointer to next node.
};

template<class T>
class Llist
{
public:
	Llist();
	void insertBegin(T data);
	void insertEnd(T data);
	void printList();
	void clear();

	~Llist();
private:
	Node<T> *mHead;
	Node<T> *mTail;
	void initList(T data);
};
#include "LlistIMP.hpp"

#endif // LLIST_HPP

