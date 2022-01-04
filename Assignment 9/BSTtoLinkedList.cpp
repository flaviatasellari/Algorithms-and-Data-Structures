/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   9.2b)
*/

#include <iostream>
using namespace std;

/* LINKED LIST NODE */
struct list {
    int value;
    struct list* next;
};

// Function to put the elements at the end of the linked list
struct list* AddAtEnd (struct list* head, int element) {
    struct list* ptr;
    ptr = head;

    struct list* temp = new struct list;
    temp->value = element;
    temp->next = NULL;

    if (head == NULL) {
        return temp;
    }

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = temp;
    return head;
}

// Function to print the linked list
void PrintList (struct list* head) {
    if (head == NULL) {
        cout << "Linked List is empty." << endl;
    }

    struct list* ptr;
    ptr = head;

    while (ptr != NULL) {
        cout << ptr->value << " ";
        ptr = ptr->next;
    }

}

/* BINARY TREE CLASS */
class BST {
    int data;
    BST *left, *right;

    public:
        // Default constructor
        BST () {
            data = 0;
            left = right = NULL;
        }

        // Parameterized constructor
        BST (int value) {
            data = value;
            left = right = NULL;
        }

        // Insert method
        BST* Insert (BST* root, int element) {
           if (root == NULL) {
               return new BST(element);
           }
           
           // Insert data to the right if the element is greater than the root
           if (element > root->data) {
               root->right = Insert (root->right, element);
           }
           // Insert data to the left if the element is smaller than the root
           else {
                root->left = Insert (root->left, element);
           }
           
           return root;
        }

        // Find the leftmost element
        BST* Minimum (BST* node) { 
            BST* current = node; 
            
            while (current->left != NULL) { 
                current = current->left; 
            } 
            
            return current;
        } 

        // Find the successor of the element
        BST* Successor (BST* root, BST* node) {
            if (node->right != NULL) {
                BST* node1 = Minimum (node->right);
                return node1;
            }

            BST* succ = NULL;
            
            // Start from root and search for the successor down the tree
            while (root != NULL) {
                if (node->data < root->data) {
                    succ = root;
                    root = root->left;
                }
                else if (node->data > root->data)
                    root = root->right;
                else
                    break;
            }
            
            return succ;
        }

        // Convert BTS to Linked List using Minimum and Successor method
        struct list* BSTtoLinkedList (BST* root, struct list* head) {
            if (root == NULL) {
                return head;
            }

            BST* node1 = Minimum (root);
            BST* newnode = node1;

            while (newnode != NULL) {
                head = AddAtEnd (head, newnode->data);
                newnode = Successor (root, newnode);
            }

            return head;

        }

};

int main () {
    BST b, *root = NULL;
    root = b.Insert(root, 22);                             
    b.Insert(root, 10);
    b.Insert(root, 35);
    b.Insert(root, 7);
    b.Insert(root, 13);
    b.Insert(root, 40);
    b.Insert(root, 38);

    /*             | 22 |
                /         \
            | 10 |       | 35 |
          /        \            \
        | 7 |     | 13 |       | 40 |
                             /
                          | 38 |
    */

    struct list* head = NULL;
 
    // Convert the binary search tree to linked list
    head = b.BSTtoLinkedList (root, head);

    cout << "The Linked List: ";
    PrintList(head);

    return 0;

}