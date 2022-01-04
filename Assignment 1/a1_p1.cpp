/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   a1_p1.cpp
*/

#include <iostream>
using namespace std;

class Complex
{
    private:
        int real;  
        int imaginary;  
 
    public:
        // Constructor
        Complex (int newreal, int newimaginary) {
            real = newreal;
            imaginary = newimaginary;
        }

        // Overloaded function
        int operator== (const Complex c) {
            return ((real == c.real) && (imaginary == c.imaginary));
        }
};

// The generic function
template <typename T>
int array_search (T arr[], int num, T el) {
    // Element is in the array
    for (int i = 0; i < num; i++) {
        if (arr[i] == el) {
            return i;
        }
    }
    // Element is not in the array
    return -1;
}

int main () {
    // Array with integers
    int arr1[] = {1, 2, 3, 4, 5};
    cout << array_search<int>(arr1, 5, 2);
    cout << endl;

    // Array with floats
    float arr2[] = {2.2, 3.4, 5.7, 6.8, 8.1, 9,2};
    cout << array_search<float>(arr2, 6, 4.4);
    cout << endl;

    // Array with Complex class
    Complex arr3[] = {Complex(3,1), Complex(5,9), Complex(7,7)};
    Complex a (3,1);
    cout << array_search<Complex>(arr3, 3, a);
}