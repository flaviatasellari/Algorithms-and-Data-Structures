/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a2_p3.cpp
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include "WindGauge.h"
using namespace std;

// The constructor
WindGauge::WindGauge (int period) {
    this -> period = period;
}

// Method to add the current wind speed to the history
void WindGauge::currentWindSpeed (int speed) {
    if (WindHistory.size() == (unsigned int) period) {
        // Discard the oldest wind speed
        WindHistory.pop_front();
    }

    WindHistory.push_back(speed);
}

// Method to find the highest wind speed
int WindGauge::highest() const {
    deque <int>::const_iterator it;
    
    // Using the max_element function
    it = max_element(WindHistory.begin(), WindHistory.end());
    return *it;
}

// Method to find the lowest wind speed
int WindGauge::lowest() const {
    deque <int>::const_iterator it;
    
    // Using the min_element function
    it = min_element(WindHistory.begin(), WindHistory.end());
    return *it;
}

// Method to find the average wind speed
int WindGauge::average() const {
    int sum = 0;

    for (auto i : WindHistory) {
        sum = sum + i;
    }

    int average = (sum / WindHistory.size());
    return average;
}

// Method to print the lowest, highest and average wind speed 
void WindGauge::dump() {
    cout << "Highest wind speed: " << highest() << endl;
    cout << "Lowest wind speed: " << lowest() << endl;
    cout << "Average wind speed: " << average() << endl;
    cout << endl;
}


