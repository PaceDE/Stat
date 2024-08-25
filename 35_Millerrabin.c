#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include this for bool, true, false types

// Function to perform modular exponentiation
// It returns (base^exp) % mod
long long modularExponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) // If exp is odd, multiply base with the result
            result = (result * base) % mod;

        exp = exp >> 1;   // exp = exp / 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to perform the Miller test
// This function returns false if n is composite and true if n is probably prime
bool millerTest(long long d, long long n) {
    // Pick a random number a in the range [2, n-2]
    long long a = 2 + rand() % (n - 4);

    // Compute a^d % n
    long long x = modularExponentiation(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    // Keep squaring x while one of the conditions is met
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }

    return false;
}

// Function to check if a number is prime using the Miller-Rabin test
bool isPrime(long long n, int k) {
    // Handle base cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    // Find d such that n-1 = d * 2^r, where d is odd
    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Iterate k times
    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return false;

    return true;
}

int main() {
    long long n;
    int k;

    // Input the number to check for primality
    printf("Enter a number to check for primality: ");
    scanf("%lld", &n);

    // Input the number of iterations
    printf("Enter the number of iterations (k): ");
    scanf("%d", &k);

    // Perform the Miller-Rabin primality test
    if (isPrime(n, k))
        printf("%lld is probably a prime number.\n", n);
    else
        printf("%lld is not a prime number.\n", n);

    return 0;
}
