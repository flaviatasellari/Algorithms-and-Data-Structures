/*
   Flavia Tasellari
   ftasellari@jacobs-university.de
   8.1 d)
*/

#include <iostream>
#include <string>
using namespace std;

void CountingSort (string arr[], int n, int pos) {
    int range = 123;
    int count[range];
    string sorted[n];

    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        // When the word does have a letter in a certain position
        if (pos < arr[i].size()) {
            count[arr[i][pos]]++;
        }
        // When the word does not have a letter in a certain postition
        else {
            count[0]++;
        }
    }

    for (int i = 1; i < range; i++) {
        count[i] = count[i] + count[i - 1];
    }

    // Create the sorted array
    for (int i = n-1; i >= 0; i--) {
        if (pos < arr[i].size()) {
            sorted[count[arr[i][pos]] - 1] = arr[i];
            count[arr[i][pos]]--;
        }
        else {
            sorted[count[0] - 1] = arr[i];
            count[0]--;
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }

}

void RadixSort (string arr[], int n) {
    // Find the word with most letters
    int max = arr[0].size();
    for (int i = 1; i < n; i++) {
        if (arr[i].size() > max) {
            max = arr[i].size();
        }
    }

    // Call Counting Sort to sort the words
    // starting from the last letter to the right 
    // till going to the first letter to the left
    for (int i = max - 1; i >= 0; i--) {
        CountingSort (arr, n, i);
    }
}

int main() {
    string array[] = { "word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time" };

    cout << "The array before sorting alphabetically:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
    
    RadixSort (array, 10);

    cout << "The array after sorting alphabetically:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
}