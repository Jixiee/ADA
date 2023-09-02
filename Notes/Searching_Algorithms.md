# Searching Algorithms

## Linear Search
### Overview
- Linear search is a simple search algorithm used to find a specific element within a list or array.
- It works by iterating through each element in the list, one at a time, until the desired element is found or the end of the list is reached.
### Algorithm
- Start from the first element (index 0) of the list.
- Compare the current element with the target element.
- If they match, return the index of the current element.
- If not, move to the next element and repeat steps 2-3.
- Continue this process until the target element is found or the end of the list is reached.
- If the target element is not found, return a value indicating that it does not exist in the list.
### Time Complexity
- The worst-case time complexity of linear search is O(n), where n is the number of elements in the list.
- This algorithm is inefficient for large datasets as it needs to potentially examine every element.
## Binary Search
### Overview
- Binary search is an efficient search algorithm used to find a specific element in a sorted list or array.
- It repeatedly divides the search interval in half, reducing the search space by half with each comparison.
### Algorithm
- Start with the entire sorted list.
- Calculate the middle element.
- Compare the middle element with the target element.
- If they match, return the index of the middle element.
- If the middle element is greater than the target, search the left half of the list.
- If the middle element is less than the target, search the right half of the list.
- Repeat steps 2-6 until the target element is found, or the search interval becomes empty.
### Time Complexity
- Binary search has a time complexity of O(log n), making it highly efficient for large datasets.
- It is significantly faster than linear search for sorted lists.
## Hashing
### Overview
- Hashing is a technique used to map data to a fixed-size array or data structure called a hash table.
- It is used to store, retrieve, and search for data efficiently.
- Hashing involves applying a hash function to generate a unique index (hash code) for each data element.
### Hash Table
- A hash table is an array of key-value pairs.
- The hash function calculates an index for each key, allowing for quick retrieval of values.
### Hash Function
- A hash function takes an input (or key) and produces a fixed-size hash code.
- Ideally, the hash function should distribute keys uniformly across the hash table to minimize collisions.
### Collision Handling
- Collisions occur when two different keys produce the same hash code.
- Common collision resolution techniques include chaining (using linked lists) and open addressing.
