#include "Llist.hpp"

Llist::Llist() : mHead(nullptr), mTail(nullptr) {}

void Llist::initList(int _data)
{
	// Because it's the only element in the list,
	// the head and the tail are the same.
	mTail = new Node();
	mTail->data = _data;	// Set data
	mTail->next = nullptr;	// No next node.
	mHead = mTail;
}

void Llist::insertBegin(int _data)
{
	// if empty, need to make new stuff.
	if (mTail == nullptr)
	{
		initList(_data);
	}

	else
	{
		Node *node = new Node;
		node->data = _data;
		node->next = mHead;		// Setting next of the new node to this one
		mHead = node;
	}
}

void Llist::insertEnd(int _data)
{
	if (mHead == nullptr)
	{
		initList(_data);
	}

	else
	{
		Node *node = new Node;
		node->data = _data;
		node->next = nullptr;
		mTail->next = node; // This is now the second to last node, so pointing it to the end,
		mTail = node;		// before setting the Tail to the end.
	}
}

void Llist::printList()
{
	Node *step = mHead;		// Used to step through the list.

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

void Llist::clear()
{
	Node *step = mHead;
	while (step != nullptr)
	{
		Node *temp = step;	// Temporary node.
		step = step->next;	// Set the step to the next node.
		delete temp;		// Free the memory.
	}

	mHead = mTail = nullptr;
}

Llist::~Llist()
{
	clear();
}
