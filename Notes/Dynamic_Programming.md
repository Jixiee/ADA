# Dynamic Programming
 Dynamic programming is a powerful technique used to solve a wide range of optimization and combinatorial problems. It involves breaking down a complex problem into smaller subproblems and solving each subproblem only once, storing the results in a table (usually an array) to avoid redundant calculations. This approach can significantly improve the efficiency of algorithms and is commonly used in various domains of computer science and programming.

## 1. Longest Common Subsequence (LCS):

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


## 2. 0-1 Knapsack Problem:
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

## 4. Matrix Chain Multiplication:
The Matrix Chain Multiplication problem involves finding the most efficient way to multiply a given set of matrices.

### Dynamic programming approach
Dynamic programming introduces a 2D array to store and reuse results.
```
def matrix_chain_dynamic(p):
    n = len(p)
    dp = [[0] * n for _ in range(n)]

    for length in range(2, n):
        for i in range(1, n - length + 1):
            j = i + length - 1
            dp[i][j] = sys.maxsize
            for k in range(i, j):
                operations = (
                    dp[i][k]
                    + dp[k + 1][j]
                    + p[i - 1] * p[k] * p[j]
                )
                dp[i][j] = min(dp[i][j], operations)

    return dp[1][n - 1]
```
>>This approach has a time complexity of O(n^3), where n is the number of matrices.
