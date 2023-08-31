# Sorting Algorithms
Sorting algorithms are fundamental techniques used to arrange a list of elements in a particular order. Sorting is a common operation in computer science and is used to organize data for efficient searching, analysis, and other operations.

## Bubble Sort
Description: Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until no swaps are needed, indicating that the list is sorted.

### Time Complexity:

- Best Case: O(n) (when the list is already sorted)
- Average Case: O(n^2)
- Worst Case: O(n^2)

## Selection Sort
Description: Selection Sort is another simple sorting algorithm. It works by dividing the input list into two parts: the sorted sublist and the unsorted sublist. In each iteration, it finds the smallest (or largest, depending on the order) element from the unsorted sublist and swaps it with the leftmost element in the unsorted sublist.

### Time Complexity:

- Best Case: O(n^2)
- Average Case: O(n^2)
- Worst Case: O(n^2)
  
## Insertion Sort
Description: Insertion Sort builds the final sorted array one element at a time. It iterates through the input list and for each element, it moves it to its correct position in the sorted portion of the array.

### Time Complexity:

- Best Case: O(n) (when the list is already sorted)
- Average Case: O(n^2)
- Worst Case: O(n^2)
  
## Merge Sort
Description: Merge Sort is a divide-and-conquer algorithm that divides the input list into smaller halves, sorts them, and then merges them back together. It is known for its efficiency and stable sorting performance.

### Time Complexity:

- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)
  
## Quick Sort
Description: Quick Sort is another divide-and-conquer algorithm that works by selecting a 'pivot' element and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. It then recursively sorts the sub-arrays.

### Time Complexity:

- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n^2) (rare, but can be improved with optimizations)
  
## Heap Sort
Description: Heap Sort is a comparison-based sorting algorithm that utilizes the properties of a binary heap data structure. It builds a max-heap from the input data and repeatedly extracts the maximum element to place it at the end of the sorted array.

### Time Complexity:

- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)
