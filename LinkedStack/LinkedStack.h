#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "Node.h"
#include "ErrorCode.h"

template<class StackEntry>
class LinkedStack
{
public:
	LinkedStack ();
	~LinkedStack ();
	bool empty () const;
	size_t size ()const;
	ErrorCode top (StackEntry &item) const;
	ErrorCode push (const StackEntry &item);
	ErrorCode pop ();
	void clear ();
protected:
	Node<StackEntry> *topNode = nullptr;
	size_t count = 0;
};

template<class StackEntry>
LinkedStack<StackEntry>::LinkedStack ()
{
	topNode = nullptr;
	count = 0;
}

template<class StackEntry>
LinkedStack<StackEntry>::~LinkedStack ()
{
	clear ();
}

template<class StackEntry>
bool LinkedStack<StackEntry>::empty () const
{
	return topNode == nullptr; // TODO: what if count != 0 ???
}

template<class StackEntry>
size_t LinkedStack<StackEntry>::size () const
{
	return count;
}

template<class StackEntry>
ErrorCode LinkedStack<StackEntry>::top (StackEntry &item) const
{
	if (empty ())
		return UNDERFLOW;
	else {
		item = topNode->entry;
		return SUCCESS;
	}
}

template<class StackEntry>
ErrorCode LinkedStack<StackEntry>::push (const StackEntry &item)
{
	Node<StackEntry> *tmp = new Node<StackEntry> (item, topNode);
	if (tmp == nullptr)
		return OVERFLOW; // TODO: is it possible???
	else {
		topNode = tmp;
		++count;
		return SUCCESS;
	}
}

template<class StackEntry>
ErrorCode LinkedStack<StackEntry>::pop ()
{
	if (empty ())
		return UNDERFLOW;
	else {
		Node<StackEntry> *oldTopNode = topNode;
		topNode = topNode->next;
		delete oldTopNode;
		--count;
		return SUCCESS;
	}
}

template<class StackEntry>
void LinkedStack<StackEntry>::clear ()
{
	while (!empty ())
		pop ();
}

#endif