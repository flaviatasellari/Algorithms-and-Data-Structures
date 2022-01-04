#include <iostream>
using namespace std;

enum Color {RED, BLACK};

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
};

/*                     RED BLACK TREE class                      */
class RedBlackTree {
    private:
        Node *root;
    
    protected:
        
        void rotateLeft (Node *&x) {
            if (x->right == NULL)
                return;
            else {
                Node* y = x->right;
                
                if (y->left != NULL) {
                    x->right = y->left;
                    y->left->parent = x;
                }
                else
                    x->right = NULL;

                if (x->parent != NULL)
                    y->parent = x->parent;
                
                if (x->parent == NULL)
                    root = y;
                else {
                    if (x == x->parent->left)
                        x->parent->left = y;
                    else
                        x->parent->right = y;
                }

                y->left = x;
                x->parent = y;
             }
        }

        void rotateRight(Node *&x) {
            if (x->left == NULL)
                return;
            else {
                Node* y = x->left;

                if (y->right != NULL) {
                    x->left = y->right;
                    y->right->parent = x;
                }
                else
                    x->left = NULL;

                if (x->parent != NULL)
                    y->parent = x->parent;

                if (x->parent == NULL)
                    root = y;
                else {
                    if (x == x->parent->left)
                        x->parent->left = y;
                    else
                        x->parent->right = y;
                }

                y->right = x;
                x->parent = y;
            }
        }

    public:
        // Default constructor
        RedBlackTree () {
            root = NULL;
        }
        
        /*                     INSERTION                    */
        void insertRB (int value) {
            Node *z;
            z = new Node;
            z->data = value;
            z->left = NULL;
            z->right = NULL;
            z->color = RED;
            
            Node *x = root;
            Node *y = NULL;
            
            if (root == NULL) {
                root = z;
                z->parent = NULL;
            } 
            else {
                while (x != NULL) {
                    y = x;
                    
                    if (z->data < x->data) {
                        x = x->left;
                    }
                    else {
                        x = x->right;
                    }
                }
                    
                z->parent = y;
                    
                if (z->data < y->data) {
                    y->left = z;
                }
                else {
                    y->right = z;
                }
            }
            insertFixUp(z);
        }

        void insertFixUp (Node *&z) {
            if (root == z) {
                z->color = BLACK;
                return;
            }
            
            while (z->parent != NULL && z->parent->color == RED) {
                Node *grandparent = z->parent->parent;
                Node *y;

                if (z->parent == grandparent->left) {
                    if (grandparent->right != NULL) {
                        y = grandparent->right;
                        
                        if (y->color == RED) {
                            z->parent->color = BLACK;   //  Case 1
                            y->color = BLACK;
                            grandparent->color = RED;
                            z = grandparent;
                        }
                    } 
                    else {
                        if (z == z->parent->right) {    //  Case 2
                            z = z->parent;   
                            rotateLeft(z);
                        }
                        
                        z->parent->color = BLACK;       //  Case 3
                        grandparent->color = RED;
                        rotateRight(grandparent);
                    }
                } 
                // The other 3 symmetric cases
                else {
                    if (grandparent->left != NULL) {
                        y = grandparent->left;
                        
                        if (y->color == RED) {
                            z->parent->color = BLACK;
                            y->color = BLACK;
                            grandparent->color = RED;
                            z = grandparent;
                        }  
                    } 
                    else {
                        if (z == z->parent->left) {
                            z = z->parent;
                            rotateRight(z);
                        }
                        
                        z->parent->color = BLACK;
                        grandparent->color = RED;
                        rotateLeft(grandparent);
                    }
                }
                
                root->color = BLACK;
            }
        }


        /*                     DELETION                    */
        void deleteRB (Node *&z) {
            if (root == NULL) {
                cout << "The tree is empty." << endl;
                return ;
            }
            
            Node* x = root;
            Node* y = NULL;
            Node* w = NULL;
            int exist = 0;
            
            while (x != NULL && exist == 0) {
                if (x->data == z->data) {
                    exist = 1;
                }
                
                if (exist == 0) {
                    if (x->data < z->data) {
                        x = x->right;
                    } 
                    else {
                        x = x->left;
                    }
                }
            }
            
            if (exist == 0) {
                cout << "The element is not in the tree." << endl;
                return ;
            } 
            else {
                if (x->left == NULL || x->right == NULL) {
                    y = x;
                }
                else {
                    y = successor(x);
                }
                
                if (y->left != NULL) {
                    w = y->left;
                }
                else {
                    if (y->right != NULL)
                       w = y->right;
                    else
                       w = NULL;
                }
                
                if (w != NULL)
                    w->parent = y->parent;
                   
                
                if (y->parent == NULL) {
                    root = w;
                }
                else {
                    if (y == y->parent->left)
                       y->parent->left = w;
                    else
                       y->parent->right = w;
                }   
                
                if (y != x) {
                    x->color = y->color;
                    x->data = y->data;
                }
                
                if (y->color == BLACK)
                    deleteFixUp(w);
            }
        }
        
        void deleteFixUp (Node *&x) {
            Node *w;
            
            while (x != root && x->color == BLACK) {
                if (x == x->parent->left) {
                    w = x->parent->right;
                    
                    if (w->color == RED) {                                       //  Case 1
                        w->color = BLACK;
                        x->parent->color = RED;
                        rotateLeft(x->parent);
                        w = x->parent->right;
                    }
                    
                    if (w->right->color == BLACK && w->left->color == BLACK) {   //  Case 2
                        w->color = RED;
                        x = x->parent;
                    }
                    else {
                        if (w->right->color == BLACK) {                          //  Case 3
                            w->left->color == BLACK;
                            w->color = RED;
                            rotateRight(w);
                            w = x->parent->right;
                        }
                        
                        w->color = x->parent->color;                             //  Case 4
                        x->parent->color = BLACK;
                        w->right->color = BLACK;
                        rotateLeft(x->parent);
                        x = root;
                    }
                } 
                // The other 4 symmetric cases
                else {
                    w = x->parent->left;
                    
                    if (w->color == RED) {
                        w->color = BLACK;
                        x->parent->color = RED;
                        rotateRight(x->parent);
                        w = x->parent->left;
                    }
                    
                    if (w->left->color == BLACK && w->right->color == BLACK) {
                        w->color = RED;
                        x = x->parent;
                    }
                    else {
                        if(w->left->color == BLACK) {
                            w->right->color = BLACK;
                            w->color = RED;
                            rotateLeft(w);
                            w = x->parent->left;
                        }
                        
                        w->color = x->parent->color; 
                        x->parent->color = BLACK;
                        w->left->color = BLACK;
                        rotateRight(x->parent);
                        x = root;
                    }
                }
                
                x->color = BLACK;
                root->color = BLACK;
            }
        }
    
        // Method to find the predecessor
        Node* predecessor (Node *& x) {
            Node* y = new Node;
            
            if (x->left) {
                while (x->left->right)
                   x->left = x->left->right;
		        return x->left;
	        }
            
            y = x->parent;
            
            while (y != NULL && x == y->left) {
                x = y;
                y = y->parent;
	        }
            
            return y;
        }
        
        // Method to find the successor
        Node* successor (Node *&x) {
            Node* y = new Node;
            
            if (x->right) {
                while (x->right->left)
                   x->right = x->right->left;
                return x->right;
	        }
            
            y = x->parent;
            
            while (y != NULL && x == y->right) {
                x = y;
                y = y->parent;
            }

	        return y;
        }

        // Method to find the minimum element
        Node* getMinimum() {
            Node* x = new Node;
            x = root;
            
            while (x->left != NULL) {
                x = x->left;
            }
	
            return x;
        }

        // Method to find the maximum element
        Node* getMaximum() {
            Node* x = new Node;
            x = root;
            
            while (x->right != NULL)
		        x = x->right;
	        
            return x;
        }
        
        // Method to search for a certain element
        Node* search (int value) {
            if (root == NULL) {
                cout << "The tree is empty." << endl;
                return  0;
            }
            
            Node* x = root;
            int exist = 0;
            
            while (x != NULL && exist == 0) {
                if (x->data == value) {
                    exist = 1;
                }
                
                if (exist == 0) {
                    if (value < x->data)
                       x = x->left;
                    else
                       x = x->right;
                }
            }
            
            if (exist == 0) {
                cout << "The element is not in the tree." << endl;
                return 0;
            }
            else {
                return x;
            }
        }

        // Method to print a certain node
        void printNode (Node *x) {
            cout << x->data;

            if (x->color == RED)
               cout << " (color RED)" << endl;
	        else
		       cout << " (color BLACK)" << endl;
        }

};


int main () {
    RedBlackTree RBT;

    // Creating a Red Black Tree
    RBT.insertRB(15);
    RBT.insertRB(9);
    RBT.insertRB(24);
    RBT.insertRB(40);
    RBT.insertRB(2);

    Node* min;
    min = RBT.getMinimum();
    cout << "The minimum element is ";
    RBT.printNode(min);

    Node* succ1;
    succ1 = RBT.successor(min);
    cout << "The successor of the minimum element is ";
    RBT.printNode(succ1);

    Node* succ2;
    succ2 = RBT.successor(succ1);
    cout << "The successor of the element above is ";
    RBT.printNode(succ2);

    Node* succ3;
    succ3 = RBT.successor(succ2);
    cout << "The successor of the element above is ";
    RBT.printNode(succ3);
    
    Node* max;
    max = RBT.getMaximum();
    cout << "The maximum element is ";
    RBT.printNode(max);

    Node* pre;
    pre = RBT.predecessor(max);
    cout << "The predecessor of the maximum element is ";
    RBT.printNode(pre);

    // Delete existing node
    Node* delete1 = new Node;
    delete1->data = 15;
    RBT.deleteRB(delete1);

    // Delete a node that is not part of the tree
    Node* delete2 = new Node;
    delete2->data = 33;
    RBT.deleteRB(delete2);    

}