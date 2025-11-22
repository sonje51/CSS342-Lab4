#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include <iostream>
#include <fstream>
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

template<class ItemType>
LinkedList<ItemType>::~LinkedList() 
{
    this->DeleteList();
    // std::cout << "LinkedList deconstructor called" << std::endl;
}

// /**
//  * @brief Builds the linked list from the contents of a file.
//  * 
//  * Reads objects of type ItemType from the specified file and inserts them into the list.
//  * 
//  * @param fileName The name of the file to read from.
//  * @return true if the file was successfully opened and the list was built, false otherwise.
//  */
template<class ItemType>
bool LinkedList<ItemType>::BuildList(std::string fileName)
{
    std::ifstream myFile(fileName);

    if(myFile.is_open())
    {
        ItemType obj;
        while(myFile >> obj)
        {
            this->Insert(new ItemType(obj));
        }
        return true;
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
        return false;
    }
}

template<class ItemType>
bool LinkedList<ItemType>::Insert(ItemType *obj)
{
    Node* temp = this->head;
    Node* newNode = new Node;
    newNode->data = obj;

    // If list is empty, add node and return true
    if(this->head == nullptr)
    {
        this->head = newNode;
        return true;
    }

    // iterate through list to find where node gets placed
    Node* prevNode = nullptr;
    while(temp != nullptr)
    {
        // Check if same node already exists
        if(*(newNode->data) == *(temp->data))
        {
            delete newNode;
            return false; // value being added already exists
        }

        // If newNode is less than temp, add it in before temp
        if(*(newNode->data) < *(temp->data))
        {
            newNode->next = temp;
            if(temp == this->head) // If at the beginning
            {
                this->head = newNode;
            }
            else
            {
                prevNode->next = newNode;
            }
            return true; // Node has been placed
        }

        // Keep moving through the list
        prevNode = temp;
        temp = temp->next;
    } // Now temp is nullptr at end of list

    // Insert newNode at the end since it must be greater than all other nodes
    prevNode->next = newNode; 
    return true;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    if(this->head==nullptr) return true;
    return false;
}

template<class ItemType>
bool LinkedList<ItemType>::Remove(ItemType target, ItemType &result)
{
    // TODO: Write method
    /*
    Assume ordered list
    1. Search for target
        This can be done by binary search since the list is ordered
    2. If found, remove it from the list
    3. Return true if found and removed, false otherwise
    */
    return false;
}

/*
bool LinkedList::Peek(ItemType target, ItemType &result) const
{
    // TODO: Write method
    return false;
}
    */

// Deletes all nodes in the linked list and frees memory.
// After calling this method, the list will be empty.
template<class ItemType>
void LinkedList<ItemType>::DeleteList()
{
    Node* temp = this->head;
    while(temp != nullptr)
    {
        Node* current = temp;
        temp = temp->next;
        delete current;  
    }
    this->head = nullptr;
    // std::cout << "LinkedList deleted" << std::endl;
}

/*
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
*/

// Compares two linked lists for equality.
// Returns true if both lists contain the same elements in the same order, false otherwise.
template<class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList &ll) const
{
    Node *curr1 = this->head;
    Node *curr2 = ll.head;
    while((curr1 != nullptr) && (curr2 != nullptr))
    {
        // When comparing the data, look at thier value, not address
        if(*(curr1->data) != *(curr2->data))
        {
            return false;
        }
        else
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    // If one is a nullptr, and the other is not, they are not equal
    if((curr1 != nullptr) ^ (curr2 != nullptr))
    {
        return false;
    }

    return true;
}

template<class ItemType>
bool LinkedList<ItemType>::operator!=(const LinkedList &ll) const
{
    return !(*this == ll);
}

// TODO: Overload = operator

#endif