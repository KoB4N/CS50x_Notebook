#include <cs50.h>
#include <stdio.h>

int fib(int n);

int main(void)
{
    int n = get_int("Fibonacci number: ");
    printf("The %i Fibonacci number is %i\n", n, fib(n));
}

int fib(int n)
{
    // Base Case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    // Recursive Case
    return fib(n - 1) + fib(n - 2);
}
