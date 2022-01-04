/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a2_p6.cpp
*/

#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main () {
    map <string, string> map1;

    // Open a file for reading purpose
    ifstream file1;
    file1.open ("data.txt", ios::in);

    if (!file1.is_open()) {
           cout << "Cannot open file!" << endl;
           exit(1);
    }

    // Read the data from the file
    while (!file1.eof()) {
        string s1, s2;

        getline (file1, s1);
        getline (file1, s2);
        
        // Store names and birthday dates in the map
        map1.insert (pair <string, string> (s1, s2));
    }

    while (1) {
        // Get input for the name from the keyboard
        string name;
        getline (cin, name);

        map <string, string>::iterator it;
        it = map1.find(name);
        
        // Print the corresponding birthday date
        if (name == it->first) {
            cout << it->second << endl;
        }
        else {
            cout << "Name not found!" << endl;
            break;
        }

    }
    
    file1.close(); 
    return 0;                 
}