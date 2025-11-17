#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
//#include <iostream>
#include "LinkedList.h"

//defualt constructor
template<class ItemType>
LinkedList<ItemType>::LinkedList()
{
    this->head = nullptr;
}

// copy constructor
template<class ItemType>
LinkedList<ItemType>::LinkedList(LinkedList<ItemType> &source)
{
    this->head = nullptr;
    *this = source;
}

/*
LinkedList::~LinkedList() {}

bool LinkedList::BuildList(string fileName)
{
    // TODO: Write method
    return false;
}

bool LinkedList::Insert(ItemType *obj)
{
    // TODO: Write method
    return false;

    // obj is a new node that we need to place into the List
}
*/

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    if(this->head==nullptr) return true;
    return false;
}

/*
bool LinkedList::Remove(ItemType target, ItemType &result)
{
    // TODO: Write method
    return false;
}

bool LinkedList::Peek(ItemType target, ItemType &result) const
{
    // TODO: Write method
    return false;
}
    */


/*
void LinkedList::DeleteList()
{
    // TODO: Write method
}

bool LinkedList::Merge(LinkedList &list1)
{
    // TODO: Write method
    return false;
}

LinkedList::LinkedList& operator+=(const LinkedList &ll)
{
    // TODO: Write method
}

LinkedList::LinkedList operator+(const LinkedList &ll) const
{
    // TODO: Write method
}

bool LinkedList::operator==(const LinkedList &ll) const
{
    // TODO: Write method
}

bool LinkedList::operator!=(const LinkedList &ll) const
{
    // TODO: Write method
}
*/
// TODO: Overload = operator

#endif