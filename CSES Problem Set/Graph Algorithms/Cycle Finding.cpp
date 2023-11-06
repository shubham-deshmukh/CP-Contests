#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const long long inf = LLONG_MAX;
void solve() {
    int n,m; // n : nodes, m : edges
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++) {
        int from, to, len;
        cin >> from >> to >> len;

        // Normalize 0-based indexing
        from--;to--;        
        edges.push_back({from, to, len});
    }

    /*
    In case finding the negative weight cycle, 
    dist vector is initailized to zero (0), Why?

    If not zero, and it is ∞ then for disconnect graph of two nodes 
    2 2
    1 1 0
    2 2 -2
    In this case, distance will be infinite(∞) regardless of source node

    To make Bellman ford work, small modification is made in terms of graph
    Let's take a pseudo node say (s1) and connect it all other nodes in graph with zero distance,
    thus making graph connected. That's why dist vector is initialized to zero
    w.r.t. new source node s1 which is connected to every node in the graph.
    */
    // vector<long long> dist(n,inf);

    vector<long long> dist(n,0);
    vector<int> parent(n,-1);



    int src = 0;
    dist[src] = 0;

    int reachableNodeFromCycle;
    for(int i=1; i <=n; i++) {
        reachableNodeFromCycle = -1;
        for(auto e: edges) {
            int from = e[0];
            int to = e[1];
            int len = e[2];

            if(dist[from] != inf && dist[to] > dist[from]+len) {
                dist[to] = dist[from]+len;
                parent[to] = from;
                reachableNodeFromCycle = from;
            }
        }
    }

    if(reachableNodeFromCycle == -1) {
        cout << "NO";
        return;
    }

    cout << "YES\n";
    int x = reachableNodeFromCycle;
    for(int i = 0; i < n; i++) { // Enter into the cycle
        x = parent[x];
    }

    vector<int> cycle;
    int v = x;
    while(true) { // retrive the cycle
        cycle.push_back(v);
        if(v == x && cycle.size() > 1) break;
        v = parent[v];
    }

    reverse(cycle.begin(), cycle.end());

    for(auto v: cycle) cout << v+1 << " ";

}

int main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    solve();
    
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}