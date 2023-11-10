#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

/*
Single source shortest path for non-negative weights
0-based indexing
*/
using pll = pair<long long, long long>;
using _pq = priority_queue<pll, vector<pll>, greater<pll>>;
const long long inf = LLONG_MAX;

void dijkstra(long long src, vector<vector<pll>> &adjList, vector<long long> &dist, vector<long long> &parent) {
    long long n = (long long)adjList.size(); // Number of nodes in the graph

    dist.clear();
    parent.clear();

    dist.resize(n,inf);
    parent.resize(n,-1);

    dist[src] = 0;
    parent[src] = -1;

    _pq pq;
    pq.push({0,src}); // {cost, node number}
    
    while(!pq.empty()) {
        long long u = pq.top().second;
        long long distance = pq.top().first;

        pq.pop();

        if(distance > dist[u]) // is shortest distance calculated? multi-edge??
            continue;

        for(auto edge : adjList[u]) {
            long long to = edge.first;
            long long len = edge.second;

            
            if(distance+len < dist[to]) {            
                dist[to] = distance+len;                
                parent[to] = u;
                pq.push({dist[to],to});   
            }
        }
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    using pll = pair<long long, long long>;
    vector<vector<pll>> adj(n);
    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        from--;to--;
        adj[from].push_back({to,-1}); // node, cost
    }

    vector<long long> dist, parent;
    dijkstra(0,adj,dist,parent);

    // retrive the longest path

    if(dist[n-1] == inf) {
        cout << "IMPOSSIBLE";
        return;
    }

    int src = 0;
    int x = n-1;
    vector<int> path;
    while(x != parent[src]) {
        path.push_back(x);
        x = parent[x];
    }

    reverse(path.begin(), path.end());
    cout << (int)path.size() << endl;
    for(auto p: path) cout << p+1 << " ";

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