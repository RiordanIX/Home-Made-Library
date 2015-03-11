#ifndef DLLIST_HPP
#define DLLIST_HPP
/*****************************************************************************
 * Creates a templated Doubly linked list. This defines what the DLList is,
 * and acts as the forward declaration.
 *****************************************************************************/

template<class T>
class DLList{
public:
	DLList();
	~DLList();
	void insertBegin(T item);
	void insertEnd(T item);
	void insertAtIndex(T item, int index);
	void push(T item);

	void deleteAt(int index);
	void clear();
	T getAt(int index);

	T pop() {return getAt(_size - 1);}
	int size() {return _size;}

private:
	struct DLL_Node<T>{
		T data;
		DLL_Node *next;
		DLL_Node *last;
	};
	int _size;
	DLL_Node<T> *_data;
	
};

#include "DLListIMP.hpp"

#endif // DLLIST_HPP
