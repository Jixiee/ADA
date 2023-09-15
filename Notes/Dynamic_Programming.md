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

## 2. Longest Common Subsequence (LCS):

The Longest Common Subsequence problem is a classic dynamic programming problem that involves finding the longest subsequence common to two sequences. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

### Dynamic Programming Approach:

To solve the LCS problem, we can use a 2D array to store the length of the LCS for different prefixes of the input sequences.
```
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longest_common_subsequence(char X[], char Y[], int m, int n) {
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    int result = longest_common_subsequence(X, Y, m, n);
    printf("Length of Longest Common Subsequence: %d\n", result);
    return 0;
}
```
>> This algorithm uses a 2D array to store the lengths of LCS for different prefixes of the input sequences, and it efficiently computes the length of the LCS in O(mn) time, where m and n are the lengths of the input sequences


## 3. 0-1 Knapsack Problem:

The 0-1 Knapsack Problem is a classic optimization problem where we are given a set of items, each with a weight and a value, and a knapsack with a maximum weight capacity. The goal is to select a subset of items to maximize the total value while not exceeding the knapsack's weight capacity.

### Dynamic Programming Approach:

We can solve this problem using dynamic programming by creating a 2D array, where the rows represent the items and the columns represent the remaining weight capacities of the knapsack. We iteratively fill in this table to compute the maximum value.
```
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack_01(int values[], int weights[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int n = sizeof(values) / sizeof(values[0]);
    int capacity = 50;
    int result = knapsack_01(values, weights, n, capacity);
    printf("Maximum value in 0-1 Knapsack: %d\n", result);
    return 0;
}
```
>> This dynamic programming algorithm efficiently computes the maximum value that can be obtained in the 0-1 knapsack problem in O(n * capacity) time.
