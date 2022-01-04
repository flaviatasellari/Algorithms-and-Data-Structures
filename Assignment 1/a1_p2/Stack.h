/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a1_p2.cpp
*/

#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
using namespace std;

// Generic STACK class
template <class T>
class Stack {
    private:
       T *array;
       int size;
       int top;
    
    public:
       // Default constructor
        Stack () {
           size = 10;
           
           array = new T[size];
           if (array == NULL)
                exit(1);

           top = -1;
        }

       // Copy constructor
        Stack (const Stack& s) {
           size = s.size;
           top = s.top;
           
           array = new T[size];
           if (array == NULL)
                 exit(1);

           for (int i = 0; i < size; i++) {
               array[i] = s.array[i];
            }
        }

        // Parameterized constructor
        Stack (int newsize) {
            size = newsize;

            array = new T[newsize];
            if (array == NULL)
                 exit(1);

            top = -1;
        }

        // Destructor
        ~Stack() {
            delete [] array;
        }

        // Method to add an element
        bool push (T element) {
            if (top == size-1) {
                cout << "Stack Overflow" << endl;
                return false;
            }

            array[++top] = element;
            return true;
        }

        // Method to delete an element
        bool pop (T& out) {
            if (top == -1) {
                cout << "Stack Underflow" << endl;
                return false;
            }

            out = array[top];
            array[top] = 0;
            top--;
            return true;
        }

        // Method to show the top of the stack
        T back (void) {
            if (!(top == -1)) {
                return array[top];
            }
            else {
                exit(1);
            }
        }

        // Method to show the number of elements in the stack
        int getNumEntries () {
            return top + 1;
        }
};

#endif