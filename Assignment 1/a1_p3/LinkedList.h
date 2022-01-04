/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a1_p3.cpp
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

// Generic LIST class
template <class T>
class List {
    private:
        struct node {
            node* prev;
            T data;
            node* next;
            // Node constructor
            node (T data1) {
                data = data1;
                prev = NULL;
                next = NULL;
            };
        };

        node* head; 
        node* tail; 
    
    public:
        // Constructor
        List() {
            head = NULL;
            tail = NULL;
        }

        // Destructor
        ~List() {
            node* ptr1 = head;
            node* ptr2;

            while (!(ptr1 == NULL)) {
                ptr2 = ptr1;
                ptr1 = ptr1 -> next;
                delete ptr2;
            }
        }

        // Method to show the first element 
        T first_element () {
            return head -> data;
        }

        // Method to show the last element
        T last_element () {
            return tail -> data;
        }

        // Method to add an element at the front
        void AddAtFront (T newdata) {
            if (head == NULL && tail == NULL) {
                head = new node (newdata);
                tail = head;
            } 
            else {
                node* ptr = head;
                ptr -> prev = new node (newdata);
                ptr -> prev -> next = head;
                head = ptr -> prev;
            }
        }

        // Method to add an element at the end
        void AddAtEnd (T newdata) {
            if (head == NULL && tail == NULL) {
                tail = new node (newdata);
                head = tail;
            } 
            else {
                node* ptr = tail;
                ptr -> next = new node (newdata);
                ptr -> next -> prev = tail;
                tail = ptr -> next;
            }
        }
        
        // Method to remove an element at the front
        void RemoveAtFront () {
            if (head == tail) {
                head = tail = NULL;
            } 
            else {
                head = head -> next;
                head -> prev = NULL;
            }
        }

        // Method to remove an element at the end
        void RemoveAtEnd () {
            if (head == tail) {
                head = tail = NULL;
            } 
            else {
                tail = tail -> prev;
                tail -> next = NULL;
            }
        }
        
        // Method to show the number of elements in the list
        int ElementsInList () {
            int count = 0;
            node* ptr = head;

            while (ptr != NULL) {
                count++;
                ptr = ptr -> next;
            }

            return count;
        }
};

#endif 
















