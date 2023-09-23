// Write a program to implement Quick Sort in C
#include <stdio.h>
void swap(int* a, int* b) {
 int temp = *a;
 *a = *b;
 *b = temp; }
int partition(int arr[], int low, int high) {
 int pivot = arr[high];
 int i = (low 
- 1);
 for (int j = low; j <= high 
- 1; j++) {
 if (arr[j] < pivot) {
 i++;
 swap(&arr[i], &arr[j]);
 
}
 
}
 swap(&arr[i + 1], &arr[high]);
 return (i + 1); }
void quick_sort(int arr[], int low, int high) {
 if (low < high) {
 int pi = partition(arr, low, high);
 quick_sort(arr, low, pi 
- 1);
 quick_sort(arr, pi + 1, high);
 
}
}
int main() {
 int n;
 printf("\n=====================================");
 printf("\nEnter the number of elements: ");
 scanf("%d", &n);
 int arr[n];
 printf("Enter %d elements:", n);
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 printf("\n=====================================");
 printf("\nUnsorted array: ");
 for (int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
 quick_sort(arr, 0, n - 1);
 printf("Sorted array: ");
 for (int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
 printf("=====================================");
 return 0;
}
