/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   8.1 b)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void BucketSort (float arr[], int n) {
    vector <float> bucket[n];

    // Put the elements into the buckets
    for (int i = 0; i < n; i++) {
        int bindex = n * arr[i];
        bucket[bindex].push_back(arr[i]);
    }

    // Sort the elements inside the buckets
    for (int i = 0; i < n; i++) {
        sort (bucket[i].begin(), bucket[i].end());
    }

    // Insert the sorted elements back into the original array
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[k++] = bucket[i][j];
        }
    }

}

int main () {
    float array[] = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};

    cout << "The array before Bucket Sort:" << endl;
	for (int i = 0; i < 7; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;

    BucketSort (array, 7);

    cout << "The array after Bucket Sort:" << endl;
	for (int i = 0; i < 7; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
}