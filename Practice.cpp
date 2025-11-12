#include <iostream>
using namespace std;

void foo()
{
    int *z = new int(100);  // Allocating memory on the heap
    cout << "z = " << z << endl;
    cout << "*z = " << *z << endl;
    delete z;   // deallocating memory on the heap
}

int main()
{
    for(int k=0; k<10; k++)
    {
        foo();
    }
    return 0;
}

// cat .. val ./a.out
// valgrind --leak-check=full -v ./a.out
// ----------------------------------------------------------------------------------------------

struct Node {
    int data;
    Node* next;
};
Node* head;

struct Node {
    ItemType *pItem = nullptr;
    Node* next = nullptr;
};

int main()
{
    Node* head = new Node();
    head->data = 42;

    Node* node2 = new Node();
    head->data = 43;

    head->next = node2;
    node2->next = nullptr;

    Node* temp = head;
    while(temp!=nullptr)
    {
        Node* current = temp;
        temp = temp->next;
        delete temp; // Free the allocated memory on the heap
    }



    return 0;
}