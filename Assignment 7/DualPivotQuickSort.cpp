#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

// a) Modified Quicksort using two pivots
int dual_pivot_partition (int arr[], int start, int end, int *second) {
    // Sort the elements that are going to be used as pivots
    if (arr[start] > arr[start+1]) {
        swap (arr[start], arr[start+1]);
    }

    // The first two elements act as pivots
    int pivot1 = arr[start];
    int pivot2 = arr[start+1];
    
    int i = start;
    int j = start + 1;
    int position = j; 

    for (int k = start+2; k <= end; k++) {
        // The element is smaller than pivot 2
        if (arr[k] <= pivot2) {
            j++; 
            swap (arr[j], arr[k]);
            
            // The element is also smaller than pivot 1 
            if (arr[j] <= pivot1) {
                i++; 
                swap (arr[i], arr[j]);
                
                // Compare the elements with pivot 2
                if (arr[j] == pivot2) {
                    position = j;
                }

                if (arr[i] == pivot2) {
                    position = i;
                }
            }
        }
    }

    // Put the pivots to their appropriate position
    swap (arr[j], arr[position]);
    swap (arr[start], arr[i]);

    // Return the positions of the two pivots
    *second = j; 
    return i;
}

void dual_pivot_quicksort (int arr[], int start, int end) {
    // There are only two elements in the array
    if (end == 1) {
        if (arr[start] > arr[end]) {
            swap (arr[start], arr[end]);
        }

        return;
    }

    if (start < end) {
        int p2;
        int p1 = dual_pivot_partition(arr, start, end, &p2);

        dual_pivot_quicksort (arr, start, p1-1);
        dual_pivot_quicksort (arr, p1+1, p2-1);
        dual_pivot_quicksort (arr, p2+1, end);
    }
}

// c) Randomized Quicksort using two pivots
void randomized_quicksort (int arr[], int start, int end) {
    srand (static_cast <unsigned int> (time(0)));
    int x, y;

    do {
        x = rand() % end;
        y = rand() % end;
    } while (x == y);

    swap (arr[x], arr[start]);
    swap (arr[y], arr[start+1]);

    dual_pivot_quicksort (arr, start, end);

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
    // Example of Quicksort using two pivots
    int array1[4] = {7, 8, 6, 1};

    cout << "The array before Dual Pivot QuickSort:" << endl;
    print (array1, 4);

    dual_pivot_quicksort (array1, 0, 3);

    cout << "The array after Dual Pivot QuickSort:" << endl;
    print (array1, 4);
    cout << endl;

    // Example of Randomized Quicksort using two pivots
    int array2[8] = {15, 4, 26, 11, 2, 20, 33, 7};

    cout << "The array before Randomized Dual Pivot QuickSort:" << endl;
    print (array2, 8);

    randomized_quicksort (array2, 0, 7);

    cout << "The array after Randomized Dual Pivot QuickSort:" << endl;
    print (array2, 8);
    cout << endl;

}