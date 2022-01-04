#include <iostream>
#include <cstdlib>
using namespace std;

/*                 PROBLEM 4.1 a)                */

// Declare k as global variable
int k;

// merge function
void merge (int arr[], int lower_bound, int mid, int upper_bound) {
    int i, j, h;

    int left = mid - lower_bound + 1;
    int right = upper_bound - mid;

    int larray[left]; // temporary array

    for (i = 0; i < left; i++) {
        larray[i] = arr[lower_bound + i];
    }

    int rarray[right]; // temporary array

    for (j = 0; j < right; j++) {
        rarray[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    h = lower_bound;

    while (i < left && j < right) {
        if (larray[i] <= rarray[j]) {
            arr[h] = larray[i];
            i++;
        }
        else {
            arr[h] = rarray[j];
            j++;
        }
        h++;
    }

    // If there are still elements from the temporary arrays
    // which have not been put in the ending array

    while (i < left) {
        arr[h] = larray[i];
        i++;
        h++;
    }

    while (j < right) {
        arr[h] = rarray[j];
        j++;
        k++;
    }
} 

// Implementation of Insertion Sort
void Insertion (int arr[], int lb, int ub) {
    int i, j, key;

    for (i = lb + 1; i <= ub; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= lb && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Implementation of Merge Sort
void MergeSort (int arr[], int lb, int ub) {
    if (ub-lb <= k) {
        Insertion (arr, lb, ub);
    }
    else {
        int mid;
        mid = (lb + ub) / 2;
        
        MergeSort (arr, lb, mid);
        MergeSort (arr, mid+1, ub);
        merge (arr, lb, mid, ub);
    }
}

int main () {
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    // Create an array
    int array[n];     
    cout << "Enter elements:" << endl;
    for(int i = 0; i<n; i++) {
      cin >> array[i];
    } 
    cout << endl;

    cout << "The value of k:" << endl;
    cin >> k;
    cout << endl;

    cout << "The array before being sorted:" << endl;
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;

    MergeSort (array, 0, 9);

    cout << "The array after being sorted:" << endl;
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

}