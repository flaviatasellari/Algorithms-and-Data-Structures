/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a2_p1.cpp
*/

#include <iostream>
#include <list>
#include <fstream>
using namespace std;

int main () {
    list <int> A;
    list <int> B;

    while (1) {
        // Read integers from the keyboard
        int num;
        cin >> num;

        if (num <= 0) {
            break;
        }

        // Insert the integers into list A and list B
        A.push_back(num);
        B.push_front(num);
    }

    // Printing list A on the standard output
    for (auto i : A) {
        cout << i << " ";
    }
    
    // Create and open a file for writing purpose
    ofstream out;
    out.open ("listB.txt", ios::out);

    if (!out.is_open()) {
           cout << "Cannot open file!" << endl;
           exit(1);
    }

    // Printing list B into the file
    for (auto i : B) {
        out << i << " ";
    }

    cout << endl;
    
    // Moving the first element of both lists to the end
    int el1 = A.front();
    A.push_back(el1);
    A.pop_front();

    int el2 = B.front();
    B.push_back(el2);
    B.pop_front();

    list <int>::iterator it;
    // Printing list A and list B separated by comma
    for (it = A.begin(); it != A.end(); ++it) {
        if (it != A.begin()) {
            cout << ", ";
        }

        cout << *it;
    }

    cout << endl;

    for (it = B.begin(); it != B.end(); ++it) {
        if (it != B.begin()) {
            cout << ", ";
        }

        cout << *it;
    }

    cout << endl;

    A.merge(B); // Merging list B into list A
    A.sort(); // Sorting list A

    for (auto i : A) {
        cout << i << " ";
    }
    
    out.close();

}