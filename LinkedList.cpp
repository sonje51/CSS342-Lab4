#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include <iostream>
#include <fstream>
#include "LinkedList.h"

/**
 * @brief Default constructor. Initializes an empty linked list.
 */
template<class ItemType>
LinkedList<ItemType>::LinkedList()
{
    this->head = nullptr;
}

/**
 * @brief Copy constructor. Creates a new linked list as a copy of an existing one.
 * 
 * @param source The linked list to copy from.
 */
template<class ItemType>
LinkedList<ItemType>::LinkedList(LinkedList<ItemType> &source)
{
    this->head = nullptr;
    *this = source;
}

/**
 * @brief Deconstructor. Deletes individual nodes.
 * 
 * Frees memory allocated for the linked list by calling DeleteList().
 */
template<class ItemType>
LinkedList<ItemType>::~LinkedList() 
{
    this->DeleteList();
    // std::cout << "LinkedList deconstructor called" << std::endl;
}

/**
 * @brief Builds the linked list from the contents of a file.
 * 
 * Reads objects of type ItemType from the specified file and inserts them into the list.
 * 
 * @param fileName The name of the file to read from.
 * @return true if the file was successfully opened and the list was built, false otherwise.
 */
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
    Node* temp = this->head;
    Node* prevNode = nullptr;
    while(temp != nullptr)
    {
        if(*(temp->data) == target) // check if target matches node
        {
            result = *(temp->data);
            if(prevNode == nullptr) // If target is the first node
            {
                this->head = temp->next;
            }
            else
            {
                prevNode->next = temp->next;
            }
            delete temp;
            return true;
        }
        prevNode = temp;
        temp = temp->next;
    }
    return false;
}

template<class ItemType>
bool LinkedList<ItemType>::Peek(ItemType target, ItemType &result) const
{
    Node* temp = this->head;
    Node* prevNode = nullptr;
    while(temp != nullptr)
    {
        if(*(temp->data) == target) // check if target matches node
        {
            result = *(temp->data);
            return true;
        }
        prevNode = temp;
        temp = temp->next;
    }
    return false;
}

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

template<class ItemType>
bool LinkedList<ItemType>::Merge(LinkedList &list1)
{
    if(list1->head == nullptr)
    {
        return true; // Exit early if the added list is empty
    }

    // If this list has nothing, and assume list1 has something
    // Shift the LinkedList over to this from list1
    if(this->head == nullptr)
    {
        this->head = list1->head;
        list1->head = nullptr; 
    }

    // Iterate through both lists
    Node* tempThis = this->head;
    Node* prevThis = nullptr;
    Node* tempList1 = list1->head;

    while(tempList1 != nullptr)
    {
        while((tempThis->data) == (tempList1->data))
        {
            // While same, do nothing
        }
        while((tempThis->data) > (tempList1->data))
        {
            // while this is greater, use prev to add in the list1 node
            
        }
        while((tempThis->data) < (tempList1->data))
        {
            // While list1 is greater, keep moving
        }
    }

    /*
    Both lists must be ordered
    1. Iterate through both lists 
        1a. Move forward with list when l1.data is greater 
        1b. While l1.data is smaller, use list's prevNode.next to set equal to l1 node
            Set prevNode to this newly added node
    */
    /*
    if both are same, exit?
    1. Iterate through the extra list one by one
    2. As you encounter each node, Insert() it into list
        2a. This means move each node over to the OG list
    3. exit
    */
    // TODO: Write method
    return false;
}
/*
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