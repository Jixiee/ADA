# Greedy Algorithms
Greedy algorithms are a class of algorithms that make a series of choices at each step with the hope of finding a globally optimal solution. At each step, a greedy algorithm selects the best choice available without considering the consequences of that choice on future steps. Greedy algorithms are often used in optimization problems where you want to find the best solution from a set of possible choices. Here are some different greedy algorithms and the types of problems they are commonly applied to:
- Greedy Algorithm for Minimum Spanning Trees (e.g., Prim's and Kruskal's algorithms)
- Dijkstra's Algorithm
- Fractional Knapsack Problem
- Job Scheduling with Deadlines

## 1. Greedy Algorithm for Minimum Spanning Trees (Prim's and Kruskal's algorithms)
### Problem: 
Finding the minimum spanning tree in a connected, undirected graph.

### Algorithm:

  ### I.) Prim's Algorithm:

- Start with an arbitrary vertex as the initial minimum spanning tree.
- At each step, choose the edge with the smallest weight that connects a vertex in the minimum spanning tree to a vertex outside the tree.
- Add the chosen edge and the connected vertex to the minimum spanning tree.
- Repeat the process until all vertices are included in the tree.
  
 ### II.) Kruskal's Algorithm:

- Start with an empty set of edges as the minimum spanning tree.
- Sort all edges in the graph by their weights in ascending order.
- Iterate through the sorted edges and add each edge to the minimum spanning tree if it doesn't create a cycle.
- Use a data structure like a disjoint-set (union-find) to keep track of connected components and detect cycles.
  
### Applications:

- These algorithms are widely used in network design, such as laying down cables, designing transportation networks, and optimizing infrastructure.
- They are also used in clustering algorithms, image segmentation, and solving problems involving minimal spanning cost.

## 2. Dijkstra's Algorithm
### Problem:
Finding the shortest path between two nodes in a weighted graph.

### Algorithm:

- Initialize the distance to the start node as 0 and all other distances as infinity.
- Create a priority queue (or a min-heap) to keep track of nodes with the smallest tentative distance.
- Start with the source node and explore its neighbors.
- For each neighbor, calculate the tentative distance from the source node through the current node.
- If this tentative distance is smaller than the previously assigned distance, update it.
- Mark the current node as visited.
- Repeat the process by selecting the unvisited node with the smallest tentative distance and continue until the target node is reached or all nodes are visited.
### Applications:

- Dijkstra's algorithm is widely used in network routing protocols like OSPF (Open Shortest Path First).
- It is employed in GPS systems and map services to find the shortest route between two locations.
- It also finds applications in transportation and logistics for optimizing routes and schedules.

 ## 3. Fractional Knapsack Problem
### Problem: 
Given a set of items with weights and values and a maximum weight capacity, select a subset of items to maximize the total value without exceeding the weight capacity.

### Algorithm:

- Calculate the value-to-weight ratio for each item.
- Sort the items in descending order of this ratio.
- Initialize the current weight as 0 and the total value as 0.
- Iterate through the sorted items.
- For each item, add as much of it as possible to the knapsack without exceeding the weight capacity.
- Update the current weight and total value accordingly.
- Continue this process until the knapsack is full or all items are included.
### Applications:

- The fractional knapsack problem finds applications in various resource allocation scenarios, such as:
   - Stock portfolio optimization (maximizing returns within a budget constraint).
   - Cutting stock problems (cutting materials to minimize waste).
   - Loading cargo containers for transportation (maximizing value within weight limits).
     
## 4. Job Scheduling with Deadlines
### Problem: 
Given a set of jobs with deadlines and profits, find the maximum profit that can be obtained by scheduling the jobs within their respective deadlines.

### Algorithm:

- Sort the jobs in descending order of their profit-to-deadline ratio.
- Initialize a schedule and profit variables.
= Iterate through the sorted jobs.
- For each job, place it in the schedule at the latest possible time before its deadline.
- Update the profit and schedule accordingly.
- Continue this process until all jobs are scheduled or no more slots are available.
### Applications:

- Job scheduling with deadlines is applicable in various domains:
   - Task scheduling in operating systems and real-time systems.
   - Project management to maximize project profits.
   - Scheduling jobs on machines to optimize resource utilization.
