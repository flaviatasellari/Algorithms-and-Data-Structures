/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   8.2 a)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BucketSort (vector <int>& arr, int exp) {
    vector <int> bucket[10];

    for (int i = 0; i < arr.size(); i++) {
        int bindex = (arr[i] / exp) % 10;
        bucket[bindex].push_back(arr[i]);
    } 

    for (int i = 0; i < 10; i++) {
        // If the bucket has 0 or 1 element, it is already sorted
        // When the size of the bucket is 2 or more
        if (bucket[i].size() > 1) {
            // Recurse on the bucket for the next lesser digit
            BucketSort (bucket[i], exp/10); 
        }
    }
    
    int k = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[k++] = bucket[i][j];
        }
    }
    
}

void RadixSort (vector <int>& arr) {
    // Find the maximum element
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    // Go to the most significant digit
    int exp = 1;
    while (max/exp > 0) {
        exp = exp * 10;
    }

    BucketSort (arr, exp);
}


int main() {
    vector <int> array = {35, 2, 700, 1001, 94};
    
    cout << "The array before Radix Sort:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;

    RadixSort (array);

    cout << "The array after Radix Sort:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
}