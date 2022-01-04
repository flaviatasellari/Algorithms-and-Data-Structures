/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a2_p3.cpp
*/

#ifndef WINDGAUGE_H
#define WINGGAUGE_H

#include <deque>
using namespace std;

class WindGauge {
    public:
      WindGauge(int period = 12);
      void currentWindSpeed(int speed);
      int highest() const;
      int lowest() const;
      int average() const;
      void dump();
    
    private:
      int period;
      // deque container
      deque <int> WindHistory;
};

#endif