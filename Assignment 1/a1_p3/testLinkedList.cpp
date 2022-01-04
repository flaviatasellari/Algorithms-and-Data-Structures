/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a1_p3.cpp
*/

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main () {
    // Object 1
    cout << "First linked list" << endl;
    List <int> list1;

    list1.AddAtFront(50);
    list1.AddAtFront(100);
    list1.AddAtEnd(150);
    list1.AddAtEnd(200);

    cout << "Total elements: " << list1.ElementsInList() << endl;

    cout << "Removing elements..." << endl;
    list1.RemoveAtFront();
    list1.RemoveAtEnd();

    cout << "Total elements now: " << list1.ElementsInList() << endl;
    cout << "The first element: " << list1.first_element() << endl;
    cout << "The last element: " << list1.last_element() << endl;
    cout << endl;

    // Object 2
    cout << "Second linked list" << endl;
    List <string> list2;

    list2.AddAtFront("strawberry");
    list2.AddAtFront("watermelon");
    list2.AddAtFront("cherry");
    list2.AddAtEnd("pineapple");
    list2.AddAtEnd("banana");

    cout << "Total elements: " << list2.ElementsInList() << endl;

    cout << "Removing elements..." << endl;
    list2.RemoveAtFront();
    list2.RemoveAtEnd();
    list2.RemoveAtEnd();
    list2.RemoveAtEnd();

    cout << "Total elements now: " << list2.ElementsInList() << endl;
    cout << "The first element: " << list2.first_element() << endl;
    cout << "The last element: " << list2.last_element() << endl;
    cout << endl;

}