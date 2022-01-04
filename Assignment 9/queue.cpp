/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   9.1b)
*/

#include <iostream>
using namespace std;

// I used the stack class I implemented in 9.1a)

template <class T>
class Stack {
    private:
       struct StackNode {     // linked list
           T data;
           StackNode *next;
       };
       StackNode *top;        // top of stack
       int size;              // -1 if not set, value otherwise
       int current_size;      // unused if size = -1
       
    public:
       void push (T x) {      // if size set, check for overflow
           if (current_size == size) {
                cout << "Stack overflow!" << endl;
           } 
           else {
                struct StackNode *newnode = new StackNode;
                newnode->data = x;
                newnode->next = top;
                top = newnode;
                current_size++;
                //cout << "Pushing..." << newnode->data << endl;
           }

       }
       
       T pop () {              // return element if not in underflow
           if (isEmpty()) {
               cout << "Stack underflow!" << endl;
           }
           else {
               struct StackNode *temp = new StackNode;
               temp = top;
               T element = temp->data;
               top = temp->next;
               delete temp;
               current_size--;
               //cout << "Popping..." << element << endl;
               return element;
            }
        } 

       bool isEmpty() {         // true if empty, false otherwise
           return top == NULL;
        }

       Stack (int new_size) {   // Parameterized constructor
           size = new_size;
           current_size = 0;
           top = NULL;
        }
        
        Stack () {              // Default constructor
           size = -1;
           current_size = 0;
           top = NULL;
        }

        // I added a new method to find the top
        T findTop () {
            if (top == NULL) {
                cout << "No element" << endl;
            }
            else {
                return top->data;
            }
        }
};

///////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue {
    public:
       Stack <T> stack1, stack2;

       void enqueue (T el) {
           stack1.push(el);
           cout << "Coming to the queue..." << el << endl;
       }

       T dequeue () {
           if (stack1.isEmpty() && stack2.isEmpty()) {
               cout << "Queue underflow!" << endl;
               exit(0);
           }

           if (stack2.isEmpty()) {
               while (!stack1.isEmpty()) {
                   stack2.push (stack1.findTop());
                   stack1.pop();
               }
           }

           T el = stack2.pop();
           cout << "Leaving the queue..." << el << endl;
           return el;
       }

};


int main () {
    Queue <int> queue1;

    queue1.enqueue(5);
    queue1.enqueue(7);
    queue1.enqueue(12);

    for (int i = 0; i <= 3; i++) {
        queue1.dequeue();
    }

    return 0;
}