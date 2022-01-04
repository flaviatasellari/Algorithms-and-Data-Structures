#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

// b) Implementation of Bottom-Up Heap Sort
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

int FindLeaf (int arr[], int n){
    int i = 0; // root position
    int LeftChildPos = 2 * i + 1;
    int RightChildPos = 2 * i + 2;
    
    // 2 children exist
    while (RightChildPos < n) {
        // Determine which child is the greatest
        if (arr[RightChildPos] > arr[LeftChildPos]) {
            i = RightChildPos;
        }
        else {
            i = LeftChildPos;
        }
        LeftChildPos = i * 2 + 1;
        RightChildPos = i * 2 + 2;
    }

    // At the last level, there might be only one child
    if (LeftChildPos < n) {
        i = LeftChildPos;
    }

    return i;
}

// Float the new root all the way down to a leaf level
void SiftDown (int arr[], int n) {
    int i = 0; // root position
    int pos = FindLeaf(arr, n);

    while (arr[i] > arr[pos]) {
        pos = (int) (pos-1) / 2; // the parent
    }

    int x = arr[pos];
    arr[pos] = arr[i];
    
    while (pos > i) {
        swap (x, arr[(int) (pos-1)/2]);
        pos = (int) (pos-1) / 2;
    }
}

void BottomUpHeapSort (int arr[], int n) {
    BuildMaxHeap (arr, n);

    for (int i = n-1; i > 0; i--) {
        swap (arr[0], arr[i]);
        n--;

        // Float the root down
        SiftDown (arr, n);    
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

    cout << "The array before bottom up heap sort:" << endl;
	for (int i = 0; i < 6; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

    BottomUpHeapSort (array, 6);

    cout << "The array after bottom up heap sort:" << endl;
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
        BottomUpHeapSort (a, size);
        auto end = std::chrono::high_resolution_clock::now(); // Finishing time

        // Duration
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        cout << "The time of an array with " << size << " elements: " << time.count() << endl;

        size = size * 10;
    }

}
