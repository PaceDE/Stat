#include <stdio.h>

#define MAX 1000  // Maximum size of the memoization array

// Memoization table to store computed Fibonacci values
int memo[MAX];

// Function to initialize the memoization table
void initializeMemo() {
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;  // -1 indicates that the value is not computed yet
    }
}

// Recursive function to compute Fibonacci numbers using memoization
int fibonacci(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }

    // Check if the value is already computed
    if (memo[n] != -1) {
        return memo[n];
    }

    // Compute and store the value
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int n;
    printf("Enter the position of Fibonacci number to compute: ");
    scanf("%d", &n);

    // Check for valid input
    if (n < 0 || n >= MAX) {
        printf("Position must be between 0 and %d.\n", MAX - 1);
        return 1;
    }

    // Initialize memoization table
    initializeMemo();

    // Compute and print the Fibonacci number
    printf("Fibonacci number at position %d is %d\n", n, fibonacci(n));

    return 0;
}
