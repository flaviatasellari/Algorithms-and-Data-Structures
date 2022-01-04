/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   9.1a)
*/

#include <iostream>
using namespace std;

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
       /* Time complexity of push() is O(1) as we are inserting elements
       only from the top and there is no need to iterate */
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
                cout << "Pushing..." << newnode->data << endl;
           }

       }
       
       /* Time complexity of pop() is O(1) as there is no need to iterate.
       Simply change the pointer direction and free the memory. */
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
               cout << "Popping..." << element << endl;
               return element;
            }
        } 

       /* Time complexity of isEmpty() is O(1) because 
       we do not check for all the elements, but only for the top */
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
};


int main () {
    Stack <int> stack1 (6);

    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);
    stack1.push(50);
    stack1.push(60);
    stack1.push(70); // this will result in Stack Overflow

    for (int i = 0; i <= 6; i++) {
        stack1.pop();
    }

    return 0;
}