#ifndef DLLISTIMP_HPP
#define DLLISTIMP_HPP
/*****************************************************************************
 *
 *****************************************************************************/

#include "DLList.hpp"

/// DLList constructor. initializes head, tail, and size parameters to empty
/// values.  
template<class T>
DLList<T>::DLList(): _size(0), _head(nullptr), _tail(nullptr){}


/// Insert at the beginning of the list. Has to increase size variable, and 
/// sets head to the new element
template<class T>
DLList<T>::insertBegin(T begin){
	if (_tail == nullptr){
		initList(begin);
	} else {
		DLL_Node<T> *node = new DLL_Node<T>();
		node->data  = begin; 
		_head->last = node;
		node->next  = _head;
		node->last  = nullptr;// because at beginning, last is nullptr
		_head = node;// reset head node to this one now, since at front
		_size++; // Keep track of length of DLList.
	}
}

/// Initializer. Can only be called on empty lists, has a special rule for
/// initiating the list.
template<class T>
void DLList<T>::initList(T start)
{
	// Because it's the only element in the list,
	// the head and the tail are the same: nullptr
	_tail = new DLL_Node<T>();
	_tail->data = start;	// Set data
	_tail->last = nullptr;	// No last(previous) node.
	_tail->next = nullptr;	// No next node.
	_head = _tail;
	_size = 1;
}

#endif // DLLISTIMP_HPP
