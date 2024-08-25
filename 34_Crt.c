#include <stdio.h>

// Function to find gcd of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find the modular inverse using the Extended Euclidean algorithm
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply the extended Euclidean algorithm
    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to find the smallest x that satisfies the given system of congruences
int findMinX(int num[], int rem[], int k) {
    int prod = 1;
    int result = 0;

    // Calculate product of all numbers
    for (int i = 0; i < k; i++)
        prod *= num[i];

    // Apply the Chinese Remainder Theorem
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main() {
    int num[10], rem[10], k;

    // Input number of equations
    printf("Enter the number of equations: ");
    scanf("%d", &k);

    // Input values for num[i] and rem[i]
    printf("Enter the values of a and x for x = a (mod n):\n");
    for (int i = 0; i < k; i++) {
        printf("Equation %d:\n", i + 1);
        scanf("%d", &rem[i]);
        scanf("%d", &num[i]);

    }

    // Calculate and print the minimum x
    int x = findMinX(num, rem, k);
    printf("The minimum x that satisfies the given system of congruences is: %d\n", x);
    return 0;
}

