#ifndef LLIST_HPP
#define LLIST_HPP

#include <iostream>

struct Node
{
	int data;	// Actual data.  TODO:  Templatize this.
	Node *next;	// Pointer to next node.
};

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
	Node *mHead;
	Node *mTail;
	void initList(int data);
};

#endif // LLIST_HPP
