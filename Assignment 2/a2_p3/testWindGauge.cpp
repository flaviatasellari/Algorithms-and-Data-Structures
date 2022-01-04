/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a2_p3.cpp
*/

#include <iostream>
#include "WindGauge.h"
using namespace std;

int main () {
    WindGauge obj;

    // Adding 5 wind speeds
    obj.currentWindSpeed(15);
    obj.currentWindSpeed(16);
    obj.currentWindSpeed(12);
    obj.currentWindSpeed(15);
    obj.currentWindSpeed(15);

    obj.dump(); // dumping

    // Adding 10 more wind speeds
    obj.currentWindSpeed(16);
    obj.currentWindSpeed(17);
    obj.currentWindSpeed(16);
    obj.currentWindSpeed(16);
    obj.currentWindSpeed(20);
    obj.currentWindSpeed(17);
    obj.currentWindSpeed(16);
    obj.currentWindSpeed(15);
    obj.currentWindSpeed(16);
    obj.currentWindSpeed(20);

    obj.dump(); // dumping again

    return 0;
}