#ifndef FILENAME_H
#define FILENAME_H

class LinkedList 
{
    public:
        // Constructors
        LinkedList();
        ~LinkedList();
        // Setters/Getters

        // Actions
        bool BuildList(string fileName);
        bool Insert(ItemType *obj);
        bool Remove(ItemType target, ItemType &result);
        bool Peek(ItemType target, ItemType &result) const;
        bool isEmpty() const;
        void DeleteList();
        bool Merge(LinkedList &list1);

        // Operator Overloads
        LinkedList& operator+=(const LinkedList &ll);
        LinkedList operator+(const LinkedList &ll) const;
        bool operator==(const LinkedList &ll) const;
        bool operator!=(const LinkedList &ll) const;
        // TODO: =

    private:
        
    // Friend methods
    friend ostream& operator <<(ostream &outStream, const LinkedList &ll);
};

#endif