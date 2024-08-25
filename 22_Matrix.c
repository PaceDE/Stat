#include <stdio.h>
#include <limits.h>

void printOptimalParenthesis(int i, int j, int n, int* bracket, char* name) {
    if (i == j) {
        printf("%c", *name);
        (*name)++;
        return;
    }

    printf("(");

    // Recursively put brackets around subexpressions
    printOptimalParenthesis(i, *((bracket + i * n) + j), n, bracket, name);
    printOptimalParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);

    printf(")");
}

int matrixChainOrder(int p[], int n) {
    int m[n][n];
    int bracket[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    // Print the m table
    printf("m table:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j < i) {
                printf("      ");
            } else {
                printf("%6d ", m[i][j]);
            }
        }
        printf("\n");
    }

    // Print the optimal parenthesis order
    char name = 'A';
    printf("Optimal Parenthesization is: ");
    printOptimalParenthesis(1, n - 1, n, (int*)bracket, &name);
    printf("\n");

    return m[1][n - 1];
}

int main() {
    int n;

    // Input the number of matrices
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];
    printf("Enter the dimensions: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int minCost = matrixChainOrder(p, n + 1);

    printf("Minimum number of multiplications is: %d\n", minCost);

    return 0;
}
