/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   9.2c)
*/

#include <iostream>
using namespace std;
  
/* LINKED LIST NODE */
class list_node { 
    public:
    int data; 
    list_node* next; 
}; 

// Function to put the elements at the beginning of the linked list
void add_begin (list_node** head_ptr, int element) { 
    list_node* ptr = new list_node();
    ptr->data = element; 
    ptr->next = (*head_ptr); 
    
    (*head_ptr) = ptr; 
} 

// Function to count the nodes of the linked list
int count_list_nodes (list_node *head) { 
    int count = 0; 

    if (head == NULL) {
        cout << "Linked list is empty." << endl;
    }

    list_node *ptr = head; 
    while (ptr != NULL) { 
        count++; 
        ptr = ptr->next; 
    } 
    return count; 
}
  
// Function to print the linked list
void print_list (list_node *head) { 
    if (head == NULL) {
        cout << "Linked list is empty." << endl;
    }

    while (head !=NULL) { 
        cout << head->data << " "; 
        head = head->next; 
    } 
} 
  
/* BINARY TREE NODE */
class tree_node { 
    public:
    int data; 
    tree_node* left; 
    tree_node* right; 
}; 

// Function to create a new tree node
tree_node* create_tree_node (int element) { 
    tree_node* node = new tree_node();
    node->data = element; 
    node->left = NULL; 
    node->right = NULL; 
  
    return node; 
} 

// Function to build a balanced BST
tree_node* LinkedListToBSTRecursion (list_node **head_ptr, int n) { 
    // Base case
    if (n <= 0) {
        return NULL; 
    }
  
    // Build the left subtree recursively 
    tree_node *left = LinkedListToBSTRecursion (head_ptr, n/2); 
  
    // The root
    tree_node *root = create_tree_node ((*head_ptr)->data); 
    root->left = left; 
  
    *head_ptr = (*head_ptr)->next; 

    // Build the right subtree recursively
    root->right = LinkedListToBSTRecursion (head_ptr, n - n/2 - 1); 
  
    return root; 
} 

// Build the binary search tree
tree_node* LinkedListToBST (list_node *head) { 
    int size = count_list_nodes(head); 
  
    return LinkedListToBSTRecursion (&head, size); 
} 

// Function to print the BTS in the preorder traversal
void print_BTS (tree_node* node) { 
    if (node == NULL) 
        return; 

    cout << node->data << " "; 
    print_BTS (node->left); 
    print_BTS (node->right); 
} 
  

int main()  { 
    list_node* head = NULL; 
  
    add_begin (&head, 88); 
    add_begin (&head, 67); 
    add_begin (&head, 50); 
    add_begin (&head, 44); 
    add_begin (&head, 42); 
    add_begin (&head, 31); 
    add_begin (&head, 10); 
    add_begin (&head, 6); 
  
    cout << "The Linked List: "; 
    print_list (head); 
    cout << endl << endl;
  
    /* Convert the linked list to binary search tree */
    tree_node *root = LinkedListToBST(head); 

    cout << "The Binary Search Tree (preorder traversal): "; 
    print_BTS (root); 
    cout << endl << endl;
  
    return 0; 
} 