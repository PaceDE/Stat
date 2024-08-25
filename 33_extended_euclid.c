#include <stdio.h>

// Function to perform the Extended Euclidean Algorithm
int extendedGCD(int a, int b, int *x, int *y) {
    // Base case: gcd(a, b) = a if b is 0
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b, x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int gcd = extendedGCD(a, b, &x, &y);

    printf("The GCD of %d and %d is %d\n", a, b, gcd);
    printf("Coefficients x and y are %d and %d, respectively.\n", x, y);
    printf("Verification: %d * %d + %d * %d = %d\n", a, x, b, y, gcd);

    return 0;
}
