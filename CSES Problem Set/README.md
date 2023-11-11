# CSES Problem Set

## Graph Algorithms

### Counting Rooms

- DFS or BFS

### Building Roads

- DFS
- Connected Components

### Message Route

- BFS

### Building Teams

- DFS (Coloring)

### Round Trip 

- DFS (Detect & print the cycle)

### Shortest Path - I

- Dijkstra's Algorithm : Single source shortest path (with no negative egde)
- TODO required
    - Implementation with default priority queue is not working
    - Approach Reference : Competitive Programmer's Handbook (Page 128)

### Shortest Path - I (Using Set)

- Dijkstra's implementation using set

### Shortest Path - II

- Floyd-Warshall

### Flight Discount

- Dijkstra (Single Source Shortest Path with no-negative weight)
- There are two approaches 
    - Without Graph Modelling
    - Graph Modelling (using state)
- TODO required
    - Solve using graph modelling approach
    - reference : 
        - https://codeforces.com/blog/entry/45897
        - https://usaco.guide/problems/cses-1195-flight-discount/solution#solution-2
    
### Cycle Finding

- Bellman ford 
    - Detection of negative weight cycle
    - Print the cycle

### Flight Routes

- Dijkstra
    - Generalization of Dijkstra for K shortest distance
    - Nice problem to understand Dijkstra's working in detail

### Round Trip II
- Finding cycle in Directed Graph
- ToDo
    - Implement using colors/states (unvisited, visited, explored)

### Course Schedule
- Finding cycle in Directed Graph using states/colors
- Topological sort using DFS
- ToDo
    - Implement Topological sort using BFS (Completed)

### Course Schedule - using BFS
- Topological sort using BFS

### Longest Flight Route
- Approaches
    1. Dijkstra (Failed! - Did not pass all the test cases) \[TLE\] 
    2. Topological sort
    3. Dynamic Programming (Failed - Did not pass all the test cases)
- TODO
    - Solve using approach 2 and 3.


### Game Routes
- Approaches
    1. Topological sort (BFS version/ Kahn's Algo) + DP 
        - Bottom-Up Approach (Recommonded)
        - Top-Down Approach (Check https://usaco.guide/problems/cses-1681-game-routes/solution)

### Investigation
- Dijkstra with states

### Planets Queries I
- Binary Lifting
- Implementation : 
    - Use array instead of vector