/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a1_p2.cpp
*/

#include <iostream>
#include "Stack.h"
using namespace std;

int main () {
    // Object 1
    cout << "First stack" << endl;
    Stack <int> stack1(3);

    stack1.push(5);
    stack1.push(3);
    stack1.push(44);
    stack1.push(76);

    cout << "The top is " << stack1.back() << endl;
    cout << "The size is " << stack1.getNumEntries() << endl;
    
    int el1;
    stack1.pop(el1);
    cout << el1 << " is deleted from the stack" << endl;
    cout << "Now the top is " << stack1.back() << endl;
    cout << endl;

    // Object 2
    cout << "Second stack" << endl;
    Stack <char> stack2;

    stack2.push('F');
    stack2.push('L');
    stack2.push('A');
    stack2.push('V');
    stack2.push('I');
    stack2.push('A');

    cout << "The top is " << stack2.back() << endl;
    cout << "The size is " << stack2.getNumEntries() << endl;
    
    char el2;
    stack2.pop(el2);
    cout << el2 << " is deleted from the stack" << endl;
    cout << "Now the top is " << stack2.back() << endl; 

}