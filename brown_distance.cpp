/*
    BROWN, Yuri M.
    BCS32
    Algorithms and Complexity
    Midterm Examination
 */

// Importing libraries
#include <iostream>
#include <cmath>
#include <vector>

// For readability purposes
using namespace std;

/* FUNCTIONS */
// Function: Distance
float get_distance(float x1, float y1, float x2, float y2) {
    // Calculate: d = √[(x2 - x1)^2 + (y2 - y1)^2]
    float distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
}

// Function: Sum of the First N Natural Numbers
size_t get_sum(size_t N) {
    // Calculate: sum = N * (N + 1) / 2
    size_t sum = N * (N + 1) / 2;
    return sum;
}

/* MAIN PROGRAM */
int main() {
    /*  Variable Instantiation
        N: Number of delivery points
        total_distance: total distance traveled
        sum: sum of the first N natural numbers
     */
    size_t N;  // Number of delivery points
    float total_distance = 0; // Total distance traveled
    size_t sum; // Sum of the first N natural numbers
    
    // User Input: Number of delivery points
    cout << "Enter the total number of delivery points: ";
    cin >> N;

    // Vector: Store the coordinates of the delivery points
    vector<pair<float, float>> points(N);

    // Loop: Input the coordinates of the delivery points
    for (size_t i = 0; i < N; ++i) {
        cout << "\nEnter the coordinates for Point " << i + 1 << "." << endl;
        cout << "X: ";
        cin >> points[i].first;
        cout << "Y: ";
        cin >> points[i].second;
    }

    // Loop: Function Call: Distance
    for (size_t i = 1; i < N; ++i) {
        total_distance += get_distance(points[i-1].first, points[i-1].second, points[i].first, points[i].second);
    }

    // Function Call: Sum of the first N natural numbers
    sum = get_sum(N);

    // Print: Total Distance, Sum of Natural Numbers
    cout << "=============== OUTPUT ===============" << endl;
    cout << "Total distance traveled: " << total_distance << endl;
    cout << "Sum of the first " << N << " natural numbers: " << sum << endl;

    return 0;
}