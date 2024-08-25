
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the minimum of three numbers
int min(int x, int y, int z) {
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

// Function to compute the edit distance between two strings
int editDistance(char *str1, char *str2, int m, int n) {
    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];

    // Fill dp[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, the only option is to insert all characters of the second string
            if (i == 0) {
                dp[i][j] = j; // Insert all j characters of str2
            }
            // If second string is empty, the only option is to remove all characters of the first string
            else if (j == 0) {
                dp[i][j] = i; // Remove all i characters of str1
            }
            // If last characters are the same, ignore the last character and recur for the remaining substring
            else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // If last characters are different, consider all possibilities and find the minimum
            else {
                dp[i][j] = 1 + min(dp[i][j - 1],    // Insert
                                   dp[i - 1][j],    // Remove
                                   dp[i - 1][j - 1] // Replace
                                   );
            }
        }
    }

    return dp[m][n];
}

int main() {
    char str1[100], str2[100];

    // Input strings
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    int m = strlen(str1);
    int n = strlen(str2);

    // Calculate edit distance
    int result = editDistance(str1, str2, m, n);

    // Output the result
    printf("The edit distance between the two strings is: %d\n", result);

    return 0;
}
