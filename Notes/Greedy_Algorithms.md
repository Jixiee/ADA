# Greedy Algorithms
Greedy algorithms are a class of algorithms that make a series of choices at each step with the hope of finding a globally optimal solution. At each step, a greedy algorithm selects the best choice available without considering the consequences of that choice on future steps. Greedy algorithms are often used in optimization problems where you want to find the best solution from a set of possible choices. Here are some different greedy algorithms and the types of problems they are commonly applied to:
- Greedy Algorithm for Minimum Spanning Trees (e.g., Prim's and Kruskal's algorithms)
- Dijkstra's Algorithm
- Fractional Knapsack Problem
- Job Scheduling with Deadlines

## 1.) Greedy Algorithm for Minimum Spanning Trees (Prim's and Kruskal's algorithms)
### Problem: Finding the minimum spanning tree in a connected, undirected graph.

### Algorithm:

  ### Prim's Algorithm:

- Start with an arbitrary vertex as the initial minimum spanning tree.
- At each step, choose the edge with the smallest weight that connects a vertex in the minimum spanning tree to a vertex outside the tree.
- Add the chosen edge and the connected vertex to the minimum spanning tree.
- Repeat the process until all vertices are included in the tree.
  
 ### Kruskal's Algorithm:

- Start with an empty set of edges as the minimum spanning tree.
- Sort all edges in the graph by their weights in ascending order.
- Iterate through the sorted edges and add each edge to the minimum spanning tree if it doesn't create a cycle.
- Use a data structure like a disjoint-set (union-find) to keep track of connected components and detect cycles.
  
### Applications:

- These algorithms are widely used in network design, such as laying down cables, designing transportation networks, and optimizing infrastructure.
- They are also used in clustering algorithms, image segmentation, and solving problems involving minimal spanning cost.
