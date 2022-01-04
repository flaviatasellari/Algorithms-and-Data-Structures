/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a2_p4.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    vector <int> vec;

    // Filling the vector with numbers from 1 to 30
    for (int i = 1; i <= 30; i++) {
        vec.push_back(i);
    }

    // Adding the value 5 at the end 
    vec.push_back(5);
    
    // Reversing the vector
    reverse (vec.begin(), vec.end());

    vector <int>::iterator it;
    // Printing the vector
    for (it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Replacing all occurrences of the value 5 by the value 129
    replace (vec.begin(), vec.end(), 5, 129);

    // Printing the modified vector
    for (it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }

    return 0;

}