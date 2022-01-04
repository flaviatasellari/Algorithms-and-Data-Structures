/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a1_p5.cpp
*/

#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector <string> vec;

    while (1) {
        // Read strings from the keyboard
        string str;
        getline (cin, str);

        if (str == "END") {
            break;
        }

        // Insert the strings into the vector
        vec.push_back(str);
    }
 
    // Swapping the second and the fifth element
    if (vec.size() >= 5) {
        swap (vec[1], vec[4]);
    }
    else {
        cout << "One or both strings do not exist" << endl;
    }

    // Replacing the last element
    vec[vec.size() - 1] = "???";

    // Printing the strings separated by comma
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == vec[vec.size() - 1]) {
            cout << vec[i] << " ";
        }
        else {
            cout << vec[i] << ",";
        }
    }
    
    cout << endl;

    vector <string>::iterator it;
    // Printing the strings separated by semicolons
    for (it = vec.begin(); it != vec.end(); ++it) {
        if (it == vec.end() - 1) {
            cout << *it;
        }
        else {
            cout << *it << ";";
        }
    }

    cout << endl;

    vector <string>::reverse_iterator rit;
    // Printing the strings in the reversed order
    for (rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << *rit << " ";
    }

}   