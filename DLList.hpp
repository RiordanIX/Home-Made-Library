#ifndef DLLIST_HPP
#define DLLIST_HPP
/*****************************************************************************
 * Creates a templated Doubly linked list. This defines what the DLList is,
 * and acts as the forward declaration.
 *****************************************************************************/

// Will temporarily leave marks here showing what I've completed so I don't
// Have to go back and forth seeing what i've done and not done. Will clear
// that out when it's all done.
template<class T>
class DLList{
public:
	DLList(); // Done!
	~DLList();
	void insertBegin(T item); // Done
	void insertEnd(T item); // Done
	void insertAtIndex(T item, int index);
	void push(T item);

	void deleteAt(int index);
	void clear();
	T getAt(int index);

	T pop() {return getAt(_size - 1);}	// Done
	int size() {return _size;}			// Done

private:
	struct DLL_Node{
		T data;
		DLL_Node *next;
		DLL_Node *prev;
	};
	void __transverseTo(int index);
	void __initList(T start); // Done!
	int _size;
	DLL_Node<T> *_head;
	DLL_Node<T> *_tail;

	
};

#include "DLListIMP.hpp"

#endif // DLLIST_HPP
