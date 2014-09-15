#ifndef LLIST_HPP
#define LLIST_HPP

#include <iostream>

template<class T>
struct Node
{
	T data;		// Actual data.  TODO:  Templatize this.
	Node *next;	// Pointer to next node.
};

template<class T>
class Llist
{
public:
	Llist();
	void insertBegin(int data);
	void insertEnd(int data);
	void printList();
	void clear();

	~Llist();
private:
	Node<T> *mHead;
	Node<T> *mTail;
	void initList(int data);
};

#endif // LLIST_HPP

