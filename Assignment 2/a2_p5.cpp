/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a2_p5.cpp
*/

#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

int main () {
    set <int> set1;
    
    srand (static_cast <unsigned int> (time(0)));
    int RandNo;

    while (1) {
        // Random number
        RandNo = (rand() % 49) + 1;
        
        // Inserting numbers into the set container
        set1.insert(RandNo);

        if (set1.size() == 6) {
            break;
        }
    }

    set <int>::iterator it;
    // Printing the numbers in ascending order (by default)
    for (it = set1.begin(); it != set1.end(); ++it) {
        cout << *it << " ";
        
    }
}