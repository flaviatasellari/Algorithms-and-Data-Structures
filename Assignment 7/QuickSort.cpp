#include <iostream>
#include <cstdlib>
#include <chrono>
#include <algorithm>
using namespace std;

// a) Lomuto Quicksort
int partition_lomuto (int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start;

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            swap (arr[j], arr[i]);
            i++;
        }
    }

    swap (arr[i], arr[end]);
    return i;
}

void quicksort_lomuto (int arr[], int start, int end) {
    if (start < end) {
        int pivot = partition_lomuto (arr, start, end);

        quicksort_lomuto (arr, start, pivot-1);
        quicksort_lomuto (arr, pivot+1, end);
    }
}


// b) Hoare Quicksort
int partition_hoare (int arr[], int start, int end) {
    int pivot = arr[start];
    int i = start;
    int j = end;

    while (i < j) {
        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap (arr[i], arr[j]);
        }
    }

    swap (arr[start], arr[j]);
    return j;
}

void quicksort_hoare (int arr[], int start, int end) {
    if (start < end) {
        int pivot = partition_hoare (arr, start, end);

        quicksort_hoare (arr, start, pivot-1);
        quicksort_hoare (arr, pivot+1, end);
    }
}


// c) Median Of Three Quicksort
int partition_median (int arr[], int start, int end) {
    // Find the median and put it in the end of the array
    int mid = (start + end) / 2;

    if (arr[mid] < arr[start]) {
        swap (arr[start], arr[mid]);
    }

    if (arr[end] < arr[start]) {
        swap (arr[start], arr[end]);
    }

    if (arr[mid] < arr[end]) {
        swap (arr[mid], arr[end]);
    }

    // The median is now the pivot
    int pivot = arr[end];
    int i = start;

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            swap (arr[j], arr[i]);
            i++;
        }
    }

    swap (arr[i], arr[end]);
    return i;
}

void quicksort_median (int arr[], int start, int end) {
    if (start < end) {
        int pivot = partition_median (arr, start, end);

        quicksort_median (arr, start, pivot-1);
        quicksort_median (arr, pivot+1, end);
    }
}

// Function to randomly sort the elements
void random (int arr[], int size) {
    srand (static_cast <unsigned int> (time(0))); 

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % size) + 1;
    }
}

// Function to print an array
void print (int arr[], int n) { 
    int i; 

    for (i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl; 
} 


int main () {
    // Example of Lomuto Quicksort
    int array1[6] = {10, 4, 27, 3, 16, 8};

    cout << "The array before Lomuto QuickSort:" << endl;
    print (array1, 6);

    quicksort_lomuto (array1, 0, 5);

    cout << "The array after Lomuto QuickSort:" << endl;
    print (array1, 6);
    cout << endl;

    // Example of Hoare Quicksort
    int array2[8] = {14, 7, 22, 5, 1, 29, 13, 10};

    cout << "The array before Hoare QuickSort:" << endl;
    print (array2, 8);

    quicksort_hoare (array2, 0, 7);

    cout << "The array after Hoare QuickSort:" << endl;
    print (array2, 8);
    cout << endl;

    // Example of Median Of Three Quicksort
    int array3[7] = {10, 13, 1, 9, 15, 20, 6};

    cout << "The array before Median Of Three QuickSort:" << endl;
    print (array3, 7);

    quicksort_median (array3, 0, 6);

    cout << "The array after Median Of Three QuickSort:" << endl;
    print (array3, 7);
    cout << endl;

    /////////////////////////////////////////////////////////////////
    
    // d) Measure the running times of the 3 Quicksort versions 
    
    int lomuto_array[1000];
    int hoare_array[1000];
    int median_array[1000];

    auto sum_lomuto_time = 0;
    auto sum_hoare_time = 0;
    auto sum_median_time = 0; 

    for (int k = 0; k < 100000; k++) {
        random (lomuto_array, 1000);
        copy (lomuto_array, lomuto_array+1000, hoare_array);
        copy (lomuto_array, lomuto_array+1000, median_array);
        
        // Lomuto QuickSort
        auto lomuto_begin = std::chrono::high_resolution_clock::now(); // Starting time
        quicksort_lomuto (lomuto_array, 0, 999);
        auto lomuto_end = std::chrono::high_resolution_clock::now(); // Finishing time
        
        // Duration
        auto lomuto_time = std::chrono::duration_cast<std::chrono::microseconds>(lomuto_end - lomuto_begin);
        
        sum_lomuto_time = sum_lomuto_time + lomuto_time.count();
        
        
        // Hoare QuickSort
        auto hoare_begin = std::chrono::high_resolution_clock::now(); // Starting time
        quicksort_hoare (hoare_array, 0, 999);
        auto hoare_end = std::chrono::high_resolution_clock::now(); // Finishing time
        
        // Duration
        auto hoare_time = std::chrono::duration_cast<std::chrono::microseconds>(hoare_end - hoare_begin);
        
        sum_hoare_time = sum_hoare_time + hoare_time.count();
        

        // Median Of Three Quicksort
        auto median_begin = std::chrono::high_resolution_clock::now(); // Starting time
        quicksort_median (median_array, 0, 999);
        auto median_end = std::chrono::high_resolution_clock::now(); // Finishing time
        
        // Duration
        auto median_time = std::chrono::duration_cast<std::chrono::microseconds>(median_end - median_begin);
        
        sum_median_time = sum_median_time + median_time.count();

    }

    auto average_lomuto_time = sum_lomuto_time / 100000;
    auto average_hoare_time = sum_hoare_time / 100000;
    auto average_median_time = sum_median_time / 100000;

    cout << "The time of Lomuto Quicksort: " << average_lomuto_time << endl;
    cout << "The time of Hoare Quicksort: " << average_hoare_time << endl;
    cout << "The time of Median Quicksort: " << average_median_time << endl;

}