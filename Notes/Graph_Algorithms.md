# Graph Algorithms
Graph algorithms are a set of procedures or techniques designed to solve problems related to graphs. A graph is a data structure that consists of a set of vertices (or nodes) and a set of edges connecting these vertices. Graph algorithms are specifically developed to operate on these graph structures and extract useful information or solve particular problems.

- `Vertices` (Nodes): Represent entities or elements.
- `Edges:` Connect vertices and represent relationships between entities.

## Breadth-First Search (BFS):
### Introduction:
Breadth-First Search (BFS) is a graph traversal algorithm that explores all the vertices of a graph level by level. It starts at the source vertex and moves outward, exploring all the neighbors at the current level before moving on to the next level.

### Algorithm Steps:
- Initialize a queue and enqueue the source vertex.
- Mark the source vertex as visited.
- While the queue is not empty, dequeue a vertex, and process it.
- Enqueue all unvisited neighbors of the processed vertex and mark them as visited.
- Repeat steps 3-4 until the queue is empty.

### Applications:
- Shortest path in an unweighted graph.
- Connected components in an undirected graph.
- Web crawling and social networking.

### Time Complexity:
>> The time complexity of BFS is O(V + E), where V is the number of vertices and E is the number of edges in the graph.

## Depth-First Search (DFS):
### Introduction:
Depth-First Search (DFS) is another graph traversal algorithm that explores as far as possible along each branch before backtracking. It uses a stack or recursion to maintain the order of traversal.

### Algorithm Steps:
- Start from the source vertex and mark it as visited.
- Explore an unvisited neighbor of the current vertex.
- If all neighbors are visited, backtrack to the previous vertex.
- Repeat steps 2-3 until all vertices are visited.

### Applications:
- Topological sorting of directed acyclic graphs (DAGs).
- Detecting cycles in a graph.
- Solving puzzles and games.

### Time Complexity:
>> The time complexity of DFS is also O(V + E), where V is the number of vertices and E is the number of edges.

## Dijkstra's:
### Introduction:
Dijkstra's algorithm is a greedy algorithm that finds the shortest path between two vertices in a weighted graph. It maintains a priority queue to select the vertex with the smallest known distance at each step.

### Algorithm Steps:
- Initialize distances to all vertices as infinity and the source as 0.
- Create a priority queue and insert all vertices with their distances.
- While the priority queue is not empty, extract the vertex with the minimum distance.
- Update the distances of its neighbors if a shorter path is found.
- Repeat steps 3-4 until the destination is reached.

### Applications:
- Routing protocols in computer networks.
- Shortest path in maps and navigation systems.

### Time Complexity:
>> The time complexity of Dijkstra's algorithm is O((V + E) log V) using a binary heap.

## Bellman-Ford Algorithm:
### Introduction:
The Bellman-Ford algorithm is used to find the shortest paths from a single source vertex to all other vertices, even in the presence of negative weight edges. It iteratively relaxes edges in the graph.

### Algorithm Steps:
- Initialize distances to all vertices as infinity and the source as 0.
- Relax all edges V-1 times (where V is the number of vertices).
- Check for negative weight cycles.

### Applications:
- Distributed systems and network routing.
- Handling graphs with negative weights.

### Time Complexity:
>> The time complexity of the Bellman-Ford algorithm is O(V * E), where V is the number of vertices and E is the number of edges.

## Kruskal's Minimum Spanning Tree:
### Introduction:
Kruskal's algorithm is a greedy algorithm that finds the minimum spanning tree of a connected, undirected graph. It adds edges to the tree in increasing order of weight, avoiding cycles.

### Algorithm Steps:
- Sort all edges in non-decreasing order of their weight.
- Initialize an empty minimum spanning tree.
- Add edges to the tree while avoiding cycles.

### Applications:
- Network design and clustering.
- Circuit design and image segmentation.

### Time Complexity:
>> The time complexity of Kruskal's algorithm is O(E log V), where E is the number of edges and V is the number of vertices.

## Floyd-Warshall Algorithm:
### Introduction:
The Floyd-Warshall algorithm is used to find the shortest paths between all pairs of vertices in a weighted graph. It works for both positive and negative weight edges but does not handle negative weight cycles.

### Algorithm Steps:
- Initialize a 2D array with the weights of the edges.
- Update the array by considering all vertices as intermediate vertices.
- Repeat step 2 for all vertices.

### Applications:
- Routing and network connectivity.
- All-pairs shortest path in graphs.

### Time Complexity:
>> The time complexity of the Floyd-Warshall algorithm is O(V^3), where V is the number of vertices.
