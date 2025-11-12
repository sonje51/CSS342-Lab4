#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template<class ItemType>
class LinkedList 
{
    public:
        // Constructors
        LinkedList(); // default constructor
        LinkedList(LinkedList<ItemType> &); // copy constructor
        // ~LinkedList();
        // Setters/Getters

        // Actions
        /*
        bool BuildList(string fileName);
        bool Insert(ItemType *obj);
        bool Remove(ItemType target, ItemType &result);
        bool Peek(ItemType target, ItemType &result) const;
        bool isEmpty() const;
        void DeleteList();
        bool Merge(LinkedList &list1);
        */

        // Operator Overloads
        /*
        LinkedList& operator+=(const LinkedList &ll);
        LinkedList operator+(const LinkedList &ll) const;
        bool operator==(const LinkedList &ll) const;
        bool operator!=(const LinkedList &ll) const;
        */
        // TODO: =

    private:
        struct Node 
        {
            ItemType *data = nullptr;
            Node *next = nullptr;
        };
        Node* head;
        
    // Friend methods
    //friend ostream& operator <<(ostream &outStream, const LinkedList &ll);
};
#include "LinkedList.cpp"
#endif