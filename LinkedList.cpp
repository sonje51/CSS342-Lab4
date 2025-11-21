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
// template<class ItemType>
// bool LinkedList<ItemType>::BuildList(const std::string& fileName)
// {

// }
// {
//     std::ifstream myFile(fileName);
//     if (myFile.is_open()) 
//     {
//         ItemType token;
//         while (myFile >> token)
//         {
//             Node* newNode = new Node;
//             newNode->data = token;
//             newNode->next = head;
//             head = newNode;
//         }
//         myFile.close();
//         return true;
//     }
//     else
//     {
//         std::cout << "Unable to open file";
//         return false;
//     }
// }

    /*
    Given a string which represents a file, open the file, read the objects from file, and build 
    an ordered list. Note that BuildList puts the responsibility on the Object class to know how 
    to read from a file. That is, do not have object specific logic in the implementation. You can 
    insert each item into the list as you read it from the file. If a list already has items, add 
    the new items to the list. Assume that the list passed in is well-formed for the object being 
    read into.
    */


template<class ItemType>
bool LinkedList<ItemType>::Insert(ItemType *obj)
{
    Node *temp = this->head;
    Node* newNode = new Node;
    newNode->data = obj;

    if(this->head == nullptr)
    {
        this->head = newNode;
        return true;
    }

    while(temp->next != nullptr)
    {
        if(temp->data == obj.data())
        {
            return false; // value being added already exists
        }
        temp = temp->next;
    } // Now temp is at the last value

    temp->next = newNode;
    return true;
    // TODO: Write method so it checks for duplicates and places it in the correct order
    // TODO: return false if it is a duplicate
    // obj is a new node that we need to place into the List
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