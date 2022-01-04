#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

// a) Implementation of Selection Sort
void select_sort (int array[], int num) {
    int min_el, i, j;
    
    for (i = 0; i < num - 1; i++ ) {
        min_el = i;

        for (j = i + 1; j < num; j++) {
            if (array[j] < array[min_el]) {
                min_el = j;
            }
        }

        if (min_el != i) {
            int swapping = array[min_el];
            array[min_el] = array[i];
            array[i] = swapping;
        }
    }
}

// Function to put the elements in ascending order
void best_case (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i+1;
    }
}

// Function to put the elements in ascending order
// but the largest element is at the beginning
void worst_case (int arr[], int size) {
    for (int i = 0; i < size; i++) {
	    if (i == 0) {
	        arr[i] = size;
	    }
	    else {
	        arr[i] = i;
	    }
	}
}

// Function to randomly sort the elements
void average_case (int arr[], int size) {
    srand (static_cast <unsigned int> (time(0))); 

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % size) + 1;
    }
}


int main () {
    int array[8] = {4, 10, 5, 13, 7, 20, 1, 18};

    cout << "The array before selection sort:" << endl;
	for (int i = 0; i < 7; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

    select_sort (array, 8);

    cout << "The array after selection sort:" << endl;
	for (int i = 0; i < 7; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;

    // c) Generating sequences
    // d) Measuring the computation time

    /*             AN ARRAY WITH 100 ELEMENTS           */

    // Best case - No swap at all, so array is already sorted

    cout << "Array with 100 elements" << endl;
    int best1[100];
    best_case(best1, 100);

    auto bbegin1 = std::chrono::high_resolution_clock::now(); // Starting time
    select_sort(best1, 100);
    auto bend1 = std::chrono::high_resolution_clock::now(); // Finishing time

    // Duration
    auto btime1 = std::chrono::duration_cast<std::chrono::microseconds>(bend1 - bbegin1);

    cout << "The time of the best case: " << btime1.count() << endl;


    // Average case - The elements of the array are randomly sorted
    // I used rand() function to generate random numbers
    // In order to compute reliable measurements for the average case,
    // I ran the algorithm 5 times for the array with n elements.
    // I summed the duration of each and then took the average time of these five.

    auto sum1 = 0;

    for (int k = 0; k < 5; k++) {
        int average1[100];
        average_case(average1, 100);
        
        auto abegin1 = std::chrono::high_resolution_clock::now(); // Starting time
        select_sort(average1, 100);
        auto aend1 = std::chrono::high_resolution_clock::now(); // Finishing time
        
        // Duration
        auto atime1 = std::chrono::duration_cast<std::chrono::microseconds>(aend1 - abegin1);

        sum1 = sum1 + atime1.count();
    }

    auto average_time1 = sum1 / 5;

    cout << "The time of the average case: " << average_time1 << endl;
    
    
    // Worst case - The case with the most swaps 
    // Every time the outer loop is executed, elements are swapped
    // The worst case is when the largest element is the first

    int worst1[100];
    worst_case(worst1, 100);

    auto wbegin1 = std::chrono::high_resolution_clock::now(); // Starting time
    select_sort(worst1, 100);
    auto wend1 = std::chrono::high_resolution_clock::now(); // Finishing time

    // Duration
    auto wtime1 = std::chrono::duration_cast<std::chrono::microseconds>(wend1 - wbegin1);

    cout << "The time of the worst case: " << wtime1.count() << endl << endl;


    
    /*               AN ARRAY WITH 1000 ELEMENTS               */   

    // Best case - No swap at all, so array is already sorted

    cout << "Array with 1000 elements" << endl;
    int best2[1000];
    best_case(best2, 1000);

    auto bbegin2 = std::chrono::high_resolution_clock::now(); // Starting time
    select_sort(best2, 1000);
    auto bend2 = std::chrono::high_resolution_clock::now(); // Finishing time

    // Duration
    auto btime2 = std::chrono::duration_cast<std::chrono::microseconds>(bend2 - bbegin2);

    cout << "The time of the best case: " << btime2.count() << endl;


    // Average case - The elements of the array are randomly sorted

    auto sum2 = 0;

    for (int k = 0; k < 5; k++) {
        int average2[1000];
        average_case(average2, 1000);
        
        auto abegin2 = std::chrono::high_resolution_clock::now(); // Starting time
        select_sort(average2, 1000);
        auto aend2 = std::chrono::high_resolution_clock::now(); // Finishing time
        
        // Duration
        auto atime2 = std::chrono::duration_cast<std::chrono::microseconds>(aend2 - abegin2);

        sum2 = sum2 + atime2.count();
    }

    auto average_time2 = sum2 / 5;

    cout << "The time of the average case: " << average_time2 << endl;

    
    // Worst case - The case with the most swaps 
    // Every time the outer loop is executed, elements are swapped
    // The worst case is when the largest element is the first

    int worst2[1000];
    worst_case(worst2, 1000);

    auto wbegin2 = std::chrono::high_resolution_clock::now(); // Starting time
    select_sort(worst2, 1000);
    auto wend2 = std::chrono::high_resolution_clock::now(); // Finishing time

    // Duration
    auto wtime2 = std::chrono::duration_cast<std::chrono::microseconds>(wend2 - wbegin2);

    cout << "The time of the worst case: " << wtime2.count() << endl << endl;



    /*               AN ARRAY WITH 5000 ELEMENTS               */

    // Best case - No swap at all, so array is already sorted

    cout << "Array with 5000 elements" << endl;
    int best3[5000];
    best_case(best3, 5000);

    auto bbegin3 = std::chrono::high_resolution_clock::now(); // Starting time
    select_sort(best3, 5000);
    auto bend3 = std::chrono::high_resolution_clock::now(); // Finishing time

    // Duration
    auto btime3 = std::chrono::duration_cast<std::chrono::microseconds>(bend3 - bbegin3);

    cout << "The time of the best case: " << btime3.count() << endl;


    // Average case - The elements of the array are randomly sorted

    auto sum3 = 0;

    for (int k = 0; k < 5; k++) {
        int average3[5000];
        average_case(average3, 5000);
        
        auto abegin3 = std::chrono::high_resolution_clock::now(); // Starting time
        select_sort(average3, 5000);
        auto aend3 = std::chrono::high_resolution_clock::now(); // Finishing time
        
        // Duration
        auto atime3 = std::chrono::duration_cast<std::chrono::microseconds>(aend3 - abegin3);

        sum3 = sum3 + atime3.count();
    }

    auto average_time3 = sum3 / 5;

    cout << "The time of the average case: " << average_time3 << endl;

    
    // Worst case - The case with the most swaps 
    // Every time the outer loop is executed, elements are swapped
    // The worst case is when the largest element is the first

    int worst3[5000];
    worst_case(worst3, 5000);

    auto wbegin3 = std::chrono::high_resolution_clock::now(); // Starting time
    select_sort(worst3, 5000);
    auto wend3 = std::chrono::high_resolution_clock::now(); // Finishing time

    // Duration
    auto wtime3 = std::chrono::duration_cast<std::chrono::microseconds>(wend3 - wbegin3);

    cout << "The time of the worst case: " << wtime3.count() << endl << endl;

}

