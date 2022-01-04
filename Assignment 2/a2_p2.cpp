/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a2_p2.cpp
*/

#include <iostream>
#include <deque>
using namespace std;

int main () {
    deque <float> A;

    while (1) {
        // Read floats from the keyboard
        float num;
        cin >> num;
        
        if (num > 0) { // Insert the positive elements at the end 
            A.push_back(num);
        }
        else if (num < 0) { // Insert the negative elements at the beginning
            A.push_front(num);
        }
        else {
            break;
        }
    }

    // Printing the elements separated by spaces
    for (auto i : A) {
        cout << i << " ";
    }

    cout << endl;

    deque <float>::iterator it;
    
    // Inserting 0 between the last negative and 
    // before the first positive element
    for (auto i = 0; i < A.size(); i++) {
        if (A[i] > 0) {
            it = (A.begin() + i);

            A.insert(it, 0);
            break;
        }
    }

    // Printing the elements separated by semicolons
    for (it = A.begin(); it != A.end(); ++it) {
        if (it != A.begin()) {
            cout << "; ";
        }

        cout << *it;
    }

}


