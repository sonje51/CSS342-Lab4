#include <iostream>
#include "LinkedList.h"

using namespace std;
// g++ -std=c++14 Child.cpp LinkedList.cpp Driver.cpp
// ./a.out

int main()
{
    LinkedList<int> ll1;
    cout << "ll1.isEmpty = " << ll1.isEmpty() << endl;
    int a = 1, b = -1, c = 13, a1 = 1; 
    ll1.Insert(&a);
    cout << "ll1.isEmpty = " << ll1.isEmpty() << endl;
    ll1.Insert(&b);
    cout << "ll1.isEmpty = " << ll1.isEmpty() << endl;
    
    LinkedList<int> ll2;
    ll2.Insert(&a1);
    ll2.Insert(&b);
    if(ll1 == ll2)
    {
        cout << "ll1 and ll2 are equal." << endl;
    }
    else
    {
        cout << "ll1 and ll2 are not equal." << endl;
    }
    
    ll2.Insert(&c);
    if(ll1 == ll2)
    {
        cout << "ll1 and ll2 are equal." << endl;
    }
    else
    {
        cout << "ll1 and ll2 are not equal." << endl;
    }

    ll1.DeleteList();

    // Read from file
    LinkedList<int> ll3;
    ll3.BuildList("numbers.txt");
    cout << "ll3.isEmpty = " << ll3.isEmpty() << endl;
    // print out ll3
    cout << "ll3 contents: ";
    LinkedList<int>::Node* temp = ll3.head;
    while(temp != nullptr)
    {
        cout << *(temp->data) << " ";
        temp = temp->next;
    }
    cout << endl;

    /*
    // Create multiple Child
    Child c1("Angie", "Ham", 7),      c2("Pradnya", "Dhala", 8),
          c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
    Child c5("Piqi", "Tangi", 7),     c6("Pete", "Rose", 13),
          c7("Hank", "Aaron", 3),     c8("Madison", "Fife", 7);
    Child c9("Miles", "Davis", 65),   c10("John", "Zorn", 4), c11;

    // Create LinkedLists full of Childs
    LinkedList<Child> class1, class2, soccer, chess;
    int a = 1, b = -1, c = 13;
    class1.Insert(&c1);
    class1.Insert(&c2);
    class1.Insert(&c3);
    class1.Insert(&c4);
    class1.Insert(&c5);
    class1.Insert(&c6);
    class1.Insert(&c5);
    cout << "class1: " << class1 << endl;
    if (class1.Insert(&c1))
    {
        cout << "ERROR::: Duplicate" << endl;
    }

    // Inserting into class2
    class2.Insert(&c4);
    class2.Insert(&c5);
    class2.Insert(&c6);
    class2.Insert(&c7);
    class2.Insert(&c10);
    cout << "Class2: " << class2 << endl;

    // Merging class 1 and 2
    class1.Merge(class2);
    class2.Merge(class1);
    class1.Merge(class2);
    class1.Merge(class1);
    cout << "class1 and 2 Merged: " << class1 << endl;
    if (!class2.isEmpty())
    {
    cout << "ERROR:: Class2 should be empty empty" << endl;
    }

    // Removing from class 1
    class1.Remove(c4, c11);
    class1.Remove(c5, c11);
    class1.Remove(c11, c11);
    if (class1.Remove(c1, c11))
    {
    cout << "Removed from class1, student " << c11 << endl;
    }
    cout << "class1: " << class1 << endl;

    // Inserting into soccer
    soccer.Insert(&c6);
    soccer.Insert(&c4);
    soccer.Insert(&c9);
    cout << "soccer: " << soccer << endl;

    // Adding class1 into soccer
    soccer += class1;
    cout << "soccer += class1 : " << soccer << endl;

    // creating a football roster
    LinkedList<Child> football = soccer;
    if (football == soccer)
    {
        cout << "football: " << football << endl;
    } 
    if (football.Peek(c6, c11))
    {
        cout << c11 << " is on the football team" << endl;
    }

    // Deleting soccer
    soccer.DeleteList();
    if (!soccer.isEmpty())
    {
        cout << "ERROR: soccer should be empty" << endl;
    }

    // Put values into numbers, print, then delete
    LinkedList<int> numbers;
    numbers.Insert(&a);
    numbers.Insert(&b);
    numbers.Insert(&c);
    cout << "These are the numbers: " << numbers << endl;
    numbers.DeleteList();
    */
    return 0;
}

// g++ -std=c++14 Child.cpp LinkedList.cpp Driver.cpp
// ./a.out