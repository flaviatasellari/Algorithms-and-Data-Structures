/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a1_p4.cpp
*/

#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector <string> vec;

    while (1) {
        // Read words from the keyboard
        string str;
        cin >> str;

        if (str == "END") {
            break;
        }

        // Insert the words into the vector
        vec.push_back(str);
    }

    // Printing the words separated by spaces
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    cout << endl;

    vector <string>::iterator it;
    // Printing the words separated by comma
    for (it = vec.begin(); it != vec.end(); ++it) {
        if (it == vec.end() - 1) {
            cout << *it;
        }
        else {
            cout << *it << ",";
        }
    }
}