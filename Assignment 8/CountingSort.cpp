/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   8.1 a)
*/

#include <iostream>
using namespace std;

void CountingSort (int arr[], int n, int k) {
    int count[k+1];
    int sorted[n];

    // Initialize the count array with 0
    for (int i = 0; i <= k; i++) {
        count[i] = 0;
    }

    // Count the ocurrences of the elements in the unsorted array
    for (int i = 0; i < n; i++) {
        ++count[arr[i]];
    }

    // The cumulative sum
    for (int i = 1; i <= k; i++) {
        count[i] = count[i] + count[i-1];
    }

    // Create the sorted array
    for (int i = n-1; i >= 0; i--) {
        sorted[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }

}

int main () {
    int array[] = {9, 1, 6, 7, 6, 2, 1};

    cout << "The array before Counting Sort:" << endl;
	for (int i = 0; i < 7; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;

    CountingSort (array, 7, 9);

    cout << "The array after Counting Sort:" << endl;
	for (int i = 0; i < 7; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
}