#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to print the subset
void printSubset(int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Recursive function to find all subsets with the given sum
void findSubsetsWithSum(int arr[], int n, int targetSum, int subset[], int subsetSize) {
    // Base case: if targetSum is 0, then we found a subset
    if (targetSum == 0) {
        printSubset(subset, subsetSize);
        return;
    }

    // Base case: no elements left or targetSum is negative
    if (n == 0 || targetSum < 0) {
        return;
    }

    // Exclude the last element and try further
    findSubsetsWithSum(arr, n - 1, targetSum, subset, subsetSize);

    // Include the last element
    subset[subsetSize] = arr[n - 1];
    findSubsetsWithSum(arr, n - 1, targetSum - arr[n - 1], subset, subsetSize + 1);
}

int main() {
    int n, targetSum;
    int arr[MAX], subset[MAX];

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements of the array
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target sum
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    // Initialize the subset array
    for (int i = 0; i < MAX; i++) {
        subset[i] = 0;
    }

    // Call the function to find all subsets with the given sum
    printf("Subsets with the given sum are:\n");
    findSubsetsWithSum(arr, n, targetSum, subset, 0);

    return 0;
}
