#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

// a) Implementation of Heap Sort      
void MaxHeapify (int arr[], int n, int i) {
    // Find the largest element among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap (arr[i], arr[largest]);
        MaxHeapify (arr, n, largest);
    }
}

void BuildMaxHeap (int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify (arr, n, i);
    }
}

void HeapSort (int arr[], int n) {
    BuildMaxHeap (arr, n);

    for (int i = n-1; i >= 0; i--) {
        swap (arr[0], arr[i]);

        // Get highest element at root again
        MaxHeapify (arr, i, 0);    
    }
}

// Function to randomly sort the elements
void random_sort (int arr[], int size) {
    srand (static_cast <unsigned int> (time(0))); 

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % size) + 1;
    }
}

int main () {
    int array[] = {13, 5, 1, 8, 22, 17};

    cout << "The array before heap sort:" << endl;
	for (int i = 0; i < 6; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

    HeapSort (array, 6);

    cout << "The array after heap sort:" << endl;
	for (int i = 0; i < 6; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
    
    // c) Generating sequences and measuring the computation time
    int size = 100;
    for (int i = 0; i < 4; i++) {
        int a[size];

        random_sort (a, size);
        
        auto begin = std::chrono::high_resolution_clock::now(); // Starting time
        HeapSort (a, size);
        auto end = std::chrono::high_resolution_clock::now(); // Finishing time

        // Duration
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        cout << "The time of an array with " << size << " elements: " << time.count() << endl;

        size = size * 10;
    }

}
