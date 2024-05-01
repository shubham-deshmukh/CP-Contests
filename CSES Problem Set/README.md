# CSES Problem Set

# Sorting and Searching

### Distinct Numbers
- Remove duplicates
- Approaches
    - Set / map

### Apartments
- Sorting + Greedy

### Ferris Wheel
- Sorting + Two pointers

### Concert Tickets
- Upper bound + Set/multiset

### Restaurant Customers
- Critical Thinking
    - Make entry when customer enters the restaurant
    - Remove entry when customer leaves the restaurant

### Movie Festival
- Standard problem
- Approach : Sorting + Greedy
    - Greedy : Select greedly Earliest ending next event

### Sum of Two Values
- Approaches
    - Two pointer 
    - Online mapping
        - Why unordered map is not working (instead of map)?

### Maximum Subarray Sum*
- Approaches
    - Prefix sum (Recommonded: Why? - Easy to model the solution)
    - Kadane's algorithm

### Stick Lengths*
- Approach
    - Mathematical observation
    - Ternary Search (TODO)

### Missing Coin Sum*
- Approach

> At any index i in a sorted array a, currSum represents sum(a[ 0...i ]).
We can form every possible sum from 1...currSum, when we are at index i. So the next possible smallest sum at index i can be currSum+1.
We can get currSum+1 as the answer if and only if a[i+1] > currSum + 1, otherwise we would be able to form subsets with sums from 1...(currSum + a[i+1])
( just add a[i+1] to all subsets which give sum 1...currSum to get subsets giving sum 1...currSum+a[i+1]). Try this on pen and paper and it will be more clear. 
Reference : [https://discuss.codechef.com/t/cses-missing-coin-sum/84039/3]

- Doubt 
    - How can we form every possible sum from 1...curr_sum, when we are at index i.

- TODO 
    - Look for mathematical proof / modelling

### Collecting Numbers

- Index order

### Collecting Numbers II
- Unsolved

### Playlist
- Approach: Sliding window

### Towers
- Binary Search (Upper/lower bound)

### Traffic Lights
- Unsolved

### Josephus Problem I
- Linked List

### Josephus Problem II
- Policy based data structure
- TODO
    - Explore other approaches
    Ref: [https://cses.fi/problemset/hack/2163/entry/7747668/]

### Nested Ranges Check
- Unsolved

### Nested Ranges Count
-Unsolved

### Room Allocation
- Approaches
    - Sorting & constructive algorithm
    - Using Min Heap

### Factory Machines
- Approach
    - Binary Search
- TODO
    - Solve using different Binary Search Template

### Tasks and Deadlines
- Approach
    - Greedy --> Sorting

### Reading Books
- Approach
    - Constructive Algorithm
    - Critical Thinking

### Sum of Three Values
- Unsolved

### Sum of Four Values
- Unsolved

### Nearest Smaller Values
- Approach
    - Stack

### Subarray Sums I & Subarray Sums II
- Approaches 
    - Sliding Window / Two pointer (Ref: https://cses.fi/problemset/hack/1660/entry/7784181/)
    - Prefix sum

### Subarray Divisibility
- Approach
    - Model mathematically + Prefix sum

### Subarray Distinct Values
- Approach
    - Sliding Window

### Array Division
- Unsolved

### Sliding Median
- Approach
    - Sliding window
        - Multiset
        - Order Statistic Tree

### Sliding Cost
- Approach
    - Sliding window + min cost making all elements equal

### Maximum Subarray Sum II
- Approach
    - prefix sum

# Graph Algorithms

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

### Road Reparation
- Minimum Spanning Tree (MST)
- Implemenation:
    - Krushkal
    - Prim's
- TODO
    - Implement using Prim

### Road Construction
- Dijoint set union by size

### Flight Routes Check
- Strongly connected Components (SCC)

### Planets and Kingdoms
- Strongly connected Components (SCC)

# Range Queries

### Static Range Sum Queries
- Approach
    - Prefix sum

### Static Range Minimum Queries
- Approach
    - Segment tree
    - Sparse Table
- ToDo
    - Implement using sparse table

### Dynamic Range Sum Queries
- Approach
    - Segment tree
-ToDO
    - Look for other implementation

### Dynamic Range Minimum Queries
- Approach
    - Segment tree
-ToDO
    - Look for other implementation

### Range Xor Queries
- Approach
    - prefix xor (similar to prefix sum)
    - Segment tree

### Range Update Queries
- Approach
    - Segment tree
-TODO
    - Look for other approaches (implementation)

### Hotel Queries
- Approach
    - Segment Tree (Point Update and range queries + search)

### List Removals 
- Approach
    - Segment Tree (Point Update and range queries + search)
    - Policy based data structure

### Salary Queries
- Approach 
    - Segment Tree (Point Update and range queries + search)
    - Policy Based data structure
- ToDo
    - Segment Tree (Point Update and range queries + search)

### Prefix Sum Queries
- Approach 
    - Segment Tree (Point Update and range queries)

### Pizzeria Queries
- Approach
    - Mathematical modelling + Segment Tree 

### Subarray Sum Queries
- Approach
    - Segment Tree (Point Update and range queries)

# String Algorithms

### String Matching
-TODO for most of the problems : Solve using various alternate algos
    - Prefix Function - (KMP) 
    - Hashing (Rabin-Karp)
    - Z-function
    - Suffix Array
    - Aho-Corasick

- Approach 
    - KMP

### Finding Borders
- Approach
    - String hashing

### Finding Periods
- Approach
    - String hashing

### Longest Palindrome
- Approach
    - Manacher Algorithm

### Finding Patterns
- Appraoch
    - Suffix Array + Binary Search
- ToDo
    - Aho-Corasick
    - Suffix Automaton

### Counting Patterns
- Appraoch
    - Suffix Array + Binary Search
- ToDo
    - Aho-Corasick
    - Suffix Automaton

### Pattern Positions
- Appraoch
    - Suffix Array + Binary Search
- ToDo
    - Aho-Corasick
    - Suffix Automaton

### Distinct Substrings
- Approach
    - Suffix Array + LCP (Longest Common Prefix)
- ToDo
    - Aho-Corasick
    - Suffix Automaton    

### Repeating Substring
- Approach
    - Suffix Array + LCP (Longest Common Prefix)
- ToDo
    - Aho-Corasick
    - Suffix Automaton  

### String Functions
- Approach
    - prefix function and z function
