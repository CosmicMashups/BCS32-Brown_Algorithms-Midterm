/*
    BROWN, Yuri M.
    BCS32
    Algorithms and Complexity
    Midterm Examination
*/

// Importing libraries
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime> 

// For readability purposes
using namespace std;

/* FUNCTIONS */
// Function: Merge Sort
void merge_sort(vector<int> &arr, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merging two sorted subarrays
        size_t n1 = mid - left + 1;
        size_t n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (size_t i = 0; i < n1; ++i)
            L[i] = arr[left + i];
        for (size_t j = 0; j < n2; ++j)
            R[j] = arr[mid + 1 + j];

        size_t i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        while (i < n1) {
            arr[k++] = L[i++];
        }

        while (j < n2) {
            arr[k++] = R[j++];
        }
    }
}

// Function: Bubble Sort
void bubble_sort(vector<int> &arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function: Print an Array
void print_array(const vector<int> &arr) {
    for (const int time : arr) {
        cout << time << " ";
    }
    cout << endl;
}

// Function: Analyze and compare sorting algorithms
void analysis(vector<int> delivery_times) {
    /* Chrono: Measure time */
    // Bubble Sort
    vector<int> bubbleSortedTimes = delivery_times;
    auto startBubble = chrono::high_resolution_clock::now();
    bubble_sort(bubbleSortedTimes);
    auto endBubble = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleDuration = endBubble - startBubble;

    // Merge Sort
    vector<int> mergeSortedTimes = delivery_times;
    auto startMerge = chrono::high_resolution_clock::now();
    merge_sort(mergeSortedTimes, 0, mergeSortedTimes.size() - 1);
    auto endMerge = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeDuration = endMerge - startMerge;

    /* Print: Comparison: Bubble Sort vs. Merge Sort */
    // Bubble Sort
    cout << "BUBBLE SORT" << endl;
    cout << "Sorted delivery times: ";
    print_array(bubbleSortedTimes);
    cout << "Time taken: " << bubbleDuration.count() << " seconds\n";
    cout << "Time Complexity: O(n^2)\n";

    // Merge Sort
    cout << "\nMERGE SORT" << endl;
    cout << "Sorted delivery times: ";
    print_array(mergeSortedTimes);
    cout << "Time taken: " << mergeDuration.count() << " seconds\n";
    cout << "Time Complexity: O(n log n)\n";
}

/* MAIN PROGRAM */
int main() {
    /*  Variable Instantiation
        N: Number of deliveries
        time: Generate random delivery times
     */
    size_t N; // Number of deliveries
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    // Display: Description
    cout << "========== BUBBLE VS. MERGE SORT ==========" << endl;

    // Input: Number of deliveries
    cout << "Enter the number of deliveries: ";
    cin >> N;

    // Loop: Check if N is a positive integer
    while (N <= 0) {
        cout << "Please enter a positive number for the number of deliveries: ";
        cin >> N;
    }
    
    // Variable: delivery_times
    vector<int> delivery_times(N); // Array: Different delivery times

    // Loop: Add random numbers to the delivery_times array
    for (size_t i = 0; i < N; ++i) {
        // Generate number between 1 and the value of 360
        delivery_times[i] = rand() % 360 + 1; 
    }

    // Output the generated delivery times
    cout << "Delivery Times: ";
    print_array(delivery_times);
    cout << endl;

    // Function Call: Analyze sorting algorithms
    analysis(delivery_times);

    return 0;
}