# Dynamic Programming
 Dynamic programming is a powerful technique used to solve a wide range of optimization and combinatorial problems. It involves breaking down a complex problem into smaller subproblems and solving each subproblem only once, storing the results in a table (usually an array) to avoid redundant calculations. This approach can significantly improve the efficiency of algorithms and is commonly used in various domains of computer science and programming.

 ## 1. Fibonacci Series:

The Fibonacci sequence is a well-known mathematical sequence where each number is the sum of the two preceding ones, usually starting with 0 and 1. The sequence begins as follows: 0, 1, 1, 2, 3, 5, 8, 13, 21, and so on. In dynamic programming, we can compute the nth Fibonacci number efficiently using a technique called memoization.

### Memoization Approach:

Memoization involves storing previously computed Fibonacci numbers to avoid redundant calculations. We can create an array to store the Fibonacci values and initialize it with -1 to indicate that no values have been calculated yet.

```
#include <stdio.h>

int fibonacci(int n) {
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n = 10;
    int result = fibonacci(n);
    printf("The %dth Fibonacci number is %d\n", n, result);
    return 0;
}
```
