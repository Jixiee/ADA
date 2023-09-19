//Write a Program to implement Selection Sort in C
#include <stdio.h>
void swap(int *x, int *y) {
 int temp = *x;
 *x = *y;
 *y = temp;
}
void selectionSort(int arr[], int n) {
 int i, j, min_index;
 for (i = 0; i < n - 1; i++) {
 min_index = i;
 for (j = i + 1; j < n; j++) {
 if (arr[j] < arr[min_index]) {
 min_index = j;
 }
 }
 if (min_index != i) {
 swap(&arr[i], &arr[min_index]);
 }
 }
}
int main() {
 printf("========================================");
 int n, i;
 printf("\nEnter the number of elements in the array: ");
 scanf("%d", &n);
 int arr[n];
 printf("Enter the elements of the array:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 printf("========================================");
 printf("\nOriginal array: ");
 for (i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 selectionSort(arr, n);
 printf("\nSorted array: ");
 for (i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n========================================");
 return 0;
}
