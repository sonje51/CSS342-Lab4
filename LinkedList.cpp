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

/*
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