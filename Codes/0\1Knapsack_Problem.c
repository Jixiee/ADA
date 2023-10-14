//Write a program to implement 0/1 Knapsack Problem in c
#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(int capacity, int weights[], int values[], int n) {
    if (n == 0 || capacity == 0) {
        return 0;
    }
    if (weights[n - 1] > capacity) {
        return knapsack(capacity, weights, values, n - 1);
    } else {
        int include_item = values[n - 1] + knapsack(capacity - weights[n - 1], weights, values, n - 1);
        int exclude_item = knapsack(capacity, weights, values, n - 1);
        return max(include_item, exclude_item);
    }
}
int main() {
    printf("----------------------------------------------------\n");
    printf("Name=ABC \nEn No. = XYZ");
    printf("\n----------------------------------------------------");
    int n, capacity;
    printf("\nEnter the number of items: ");
    scanf("%d", &n);
    int weights[n], values[n];
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);
    int max_value = knapsack(capacity, weights, values, n);
    printf("The maximum value that can be obtained is: %d\n", max_value);
    printf("----------------------------------------------------");
    return 0;
}
