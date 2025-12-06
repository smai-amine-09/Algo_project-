#include <stdio.h>    // Standard library for input/output functions
#include <time.h>     // Library used to measure execution time
#include <math.h>     // Library for mathematical functions (pow function)

// ================================
//      Recursive Tower of Hanoi
// ================================

// Recursive function to solve Tower of Hanoi
void hanoi(int n, char from, char to, char aux) {

    // Base case: if there is only 1 disk, move it directly
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    // Step 1: Move n-1 disks from "from" to "aux" using "to" as auxiliary
    hanoi(n - 1, from, aux, to);

    // Step 2: Move the largest disk (disk n) from "from" to "to"
    printf("Move disk %d from %c to %c\n", n, from, to);

    // Step 3: Move the n-1 disks from "aux" to "to" using "from" as auxiliary
    hanoi(n - 1, aux, to, from);
}


int main() {
    int n;

    // Display program banner
    printf("========================================\n");
    printf("         TOWER OF HANOI - RECURSIVE     \n");
    printf("========================================\n\n");

    // Ask the user to enter the number of disks
    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Compute total number of moves using the formula: 2^n - 1
    long long total_moves = (long long) pow(2, n) - 1;

    // Display theoretical complexity and expected number of moves
    printf("\n----------------------------------------\n");
    printf("Theoretical Complexity: T(n) = 2^n - 1\n");
    printf("For n = %d disks:\n", n);
    printf("Expected number of moves: %lld\n", total_moves);
    printf("----------------------------------------\n\n");

    // Start measuring execution time
    clock_t start = clock();

    // Perform the recursive Tower of Hanoi algorithm
    hanoi(n, 'A', 'C', 'B');

    // Stop the timer
    clock_t end = clock();

    // Calculate how long the program took to execute (in seconds)
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Display execution results
    printf("\n========================================\n");
    printf("Execution time: %.6f seconds\n", time_taken);   // Time taken by algorithm
    printf("Total moves performed: %lld\n", total_moves);    // Total number of moves
    printf("Time Complexity: O(2^n)\n");                     // Exponential complexity
    printf("========================================\n");

    return 0;   // End of program
}
