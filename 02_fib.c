#include<Stdio.h>

int fibonacci(int n)
{
    if (n <= 0)
    {
        return -1; // Indicates invalid input
    }
    else if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }

    int first = 0, second = 1, temp;
    for (int i = 3; i <= n; i++)
    {
        temp = first + second;
        first = second;
        second = temp;
    }
    return temp;
}

int main()
{
    int n;

    printf("Enter the position of the Fibonacci number you want to find: ");
    scanf("%d", &n);

    int result = fibonacci(n);


    if (result != -1)
    {
        printf("Fibonacci number at position %d is %d\n", n, result);
    }
    else
    {
        printf("Input should be a positive integer.\n");
    }

    return 0;
}
