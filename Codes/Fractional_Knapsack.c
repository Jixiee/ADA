// Write a program to implement Fractional Knapsack using Greedy approach in c
#include <stdio.h>
struct Item {
 int value;
 int weight;
 float ratio;
};
void fractionalKnapsack(struct Item items[], int n, int capacity)
 {
 for (int i = 0; i < n; i++) {
 items[i].ratio = (float)items[i].value / items[i].weight;
 }
 for (int i = 0; i < n - 1; i++) {
 int maxIndex = i;
 for (int j = i + 1; j < n; j++) {
 if (items[j].ratio > items[maxIndex].ratio) {
 maxIndex = j;
 }
 }
 struct Item temp = items[i];
 items[i] = items[maxIndex];
 items[maxIndex] = temp;
 }
 float totalProfit = 0.0;
 int currentWeight = 0;
 printf("\nSelected Items:\n");
 printf("Item\tValue\tWeight\t Fraction\tProfit\n");
 printf("-----------------------------------------------\n");
 for (int i = 0; i < n; i++) {
 if (currentWeight + items[i].weight <= capacity) {
 currentWeight += items[i].weight;
 totalProfit += items[i].value;
 printf("%d\t\t%d\t\t\t%d\t%.2f\t\t%d\n", i + 1, items[i].value, items[i].weight, 1.0, items[i].value);
 } else {
 int remainingWeight = capacity - currentWeight;
 float fraction = (float)remainingWeight / items[i].weight;
 totalProfit += (fraction * items[i].value);
 printf("%d\t\t%d\t\t\t%d\t%.2f\t\t%d\n", i + 1, items[i].value, items[i].weight, fraction, (int)(fraction * 
items[i].value));
 break;
 }
 }
 printf("-----------------------------------------------\n");
 printf("Total Profit = %.2f\n", totalProfit);
}
int main() {
 int n, capacity;
 printf("=============================================");
 printf("\n <Your Name>");
 printf("\n<Enrollment Number>");
 printf("\n=============================================");
 printf("\nEnter the number of items: ");
 scanf("%d", &n);
 struct Item items[n];
 printf("Enter the capacity of the knapsack: ");
 scanf("%d", &capacity);
 printf("Enter the value and weight of each item:\n");
 for (int i = 0; i < n; i++) {
 printf("Item %d: ", i + 1);
 scanf("%d %d", &items[i].value, &items[i].weight);
 }
 fractionalKnapsack(items, n, capacity);
 printf("===============================================");
 return 0;
}
