#include <stdio.h>
#include <limits.h>
#include <string.h> // For memset

#define MAX_N 15 // Maximum number of cities

int n; // Number of cities
int cost[MAX_N][MAX_N]; // Cost matrix
int dp[1 << MAX_N][MAX_N]; // Dynamic programming table
int path[1 << MAX_N][MAX_N]; // To store the path

// Helper function to get the minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}

// Recursive function to solve the TSP problem
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return cost[pos][0]; // Return to the starting city
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    int best_next_city = -1;

    for (int next = 0; next < n; next++) {
        if ((mask & (1 << next)) == 0) { // If city 'next' is not visited
            int newCost = cost[pos][next] + tsp(mask | (1 << next), next);
            if (newCost < ans) {
                ans = newCost;
                best_next_city = next;
            }
        }
    }

    path[mask][pos] = best_next_city; // Store the best path
    return dp[mask][pos] = ans;
}

// Function to print the path taken
void printPath() {
    int mask = 1; // Starting with city 0
    int pos = 0;  // Starting from city 0

    printf("Path: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", pos + 1); // Print the current city (1-based index)
        int next_city = path[mask][pos];
        mask |= (1 << next_city); // Mark the next city as visited
        pos = next_city; // Move to the next city
    }
    printf("%d\n", 1); // Return to the starting city
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    if (n > MAX_N) {
        printf("Number of cities exceeds maximum allowed (%d).\n", MAX_N);
        return 1;
    }

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] < 0) {
                printf("Cost cannot be negative.\n");
                return 1;
            }
        }
    }

    memset(dp, -1, sizeof(dp));
    memset(path, -1, sizeof(path));

    int minCost = tsp(1, 0); // Start from city 0

    printPath(); // Print the path taken
    printf("Minimum cost of the TSP: %d\n", minCost);

    return 0;
}
