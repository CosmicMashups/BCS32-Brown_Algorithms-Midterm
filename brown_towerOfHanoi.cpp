/*
    BROWN, Yuri M.
    BCS32
    Algorithms and Complexity
    Midterm Examination
 */

// Importing libraries
#include <iostream>

// For readability purposes
using namespace std;

// Function (Recursive): Solve Tower of Hanoi
void tower_of_Hanoi(int n, char source, char destination, char buffer, int& move_count) {
    // Base Case: Only 1 package to move
    if (n == 1) {
        cout << "Move Package 1 from " << source << " to " << destination << endl;
        // Increment: Add 1 to the value of move_count
        move_count++;
        // End the function by using return
        return;
    }

    // Recursive Case: Move (n-1) packages from source to buffer using destination as a buffer
    tower_of_Hanoi(n - 1, source, buffer, destination, move_count);

    // Move the nth package from source to destination
    cout << "Move Package " << n << " from " << source << " to " << destination << endl;
    // Increment: Add 1 to the value of move_count
    move_count++;

    // Move the n-1 packages from buffer to destination using source as a buffer
    tower_of_Hanoi(n - 1, buffer, destination, source, move_count);
}

/* MAIN PROGRAM */
int main() {
    /*  Variable Instantiation
        N: Number of packages
        move_count: Number of moves
     */
    int N; // Number of packages
    int move_count = 0; // Counter: Number of moves

    // Display: Description
    cout << "========== TOWER OF HANOI ==========" << endl;
    cout << "The Tower of Hanoi is a classic mathematical puzzle that consists of three rods and a number of\ndisks of different sizes that can slide onto any rod. The puzzle starts with the disks stacked in\nascending order of size on one rod, with the smallest disk on top." << endl;
    
    // Input: Number of packagescout << "Please specify the total number of packages: ";
    cin >> N;

    // Function Call: Tower of Hanoi Algorithm
    tower_of_Hanoi(N, 'A', 'C', 'B', move_count);

    // Print: Total number of moves
    cout << "Total number of moves required: " << move_count << endl;

    return 0;
}