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
vector<long long> min_flight;
vector<long long> max_flight;
vector<long long> ways;

void dijkstra(long long src, vector<vector<pll>> &adjList, vector<long long> &dist, vector<long long> &parent) {
    long long n = (long long)adjList.size(); // Number of nodes in the graph

    dist.clear();
    parent.clear();
    min_flight.clear();
    max_flight.clear();
    ways.clear();

    dist.resize(n,inf);
    parent.resize(n,-1);
    min_flight.resize(n,0);
    max_flight.resize(n,0);
    ways.resize(n,0);


    dist[src] = 0;
    parent[src] = -1;
    ways[src] = 1;

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

            //if(dist[u]+len < dist[to]) {
            if(distance+len < dist[to]) {            
                //dist[to] = dist[u]+len;
                dist[to] = distance+len;                
                parent[to] = u;
                pq.push({dist[to],to});
                
                ways[to] = ways[u];
                min_flight[to] = min_flight[u]+1;
                max_flight[to] = max_flight[u]+1;
            }
            else if(distance+len == dist[to]) {
                ways[to] += ways[u];
                ways[to] %= mod;
                min_flight[to] = min(min_flight[to], min_flight[u]+1);
                max_flight[to] = max(max_flight[to], max_flight[u]+1);   
            }
        }
    }
}

void solve() {
    int n,m;
    cin >> n >> m;

    vector<
        vector<
            pair<long long, long long>
            >
    > adj(n);

    for(int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        
        from--; to--;
        adj[from].push_back({to,cost});
    }

    vector<long long> dist, parent;
    dijkstra(0,adj,dist,parent);
    cout << dist[n-1] << " " << ways[n-1] << " " << min_flight[n-1] << " " << max_flight[n-1];
    // cout << dist[n-1];

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