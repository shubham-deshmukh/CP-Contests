#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
const long long INF = LLONG_MAX;

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

        if(distance > dist[u]) // is shortest distance calculated?
            continue;

        for(auto edge : adjList[u]) {
            long long to = edge.first;
            long long len = edge.second;

            if(dist[u]+len < dist[to]) {
                dist[to] = dist[u]+len;
                parent[to] = u;
                pq.push({dist[to],to});   
            }
        }
    }
}

/*
Intuition : 
Let's say A-B is the edge on which discound is applied 
then 1---> A-B ---> N
=> 1---> A-B <----N (why to reverse B-->N?)
It is easy to calculate the distance from N rather than each node (B) to N.
Now we need to check for all the edges which are reachable from 1 and N
such that dist_1[A] + price(A,B) / 2 + dist_N[B] is minimum
*/

void solve() {
    int n,m; // n: nodes, m : vertices
    cin >> n >> m;

    using pll = pair<long long,long long>;
    vector<vector<pll>> adj(n), revAdj(n);

    for(int i = 0; i < m; i++) {
        long long u, v, price;
        cin >> u >> v >> price;
        u--;v--;
        adj[u].push_back({v,price});
        revAdj[v].push_back({u,price});
    }

    vector<long long> dist_src, parent_src;
    int src = 0;
    dijkstra(src,adj,dist_src,parent_src);

    vector<long long> dist_dst, parent_dst;
    int dst = n-1;
    dijkstra(dst, revAdj, dist_dst, parent_dst);

    // for(auto d: dist_src) cout << d << " "; cout << endl;
    // for(auto d: dist_dst) cout << d << " "; cout << endl;

    long long totalPrice = inf;
    for(int u = 0; u < n; u++) {
        for(auto e: adj[u]) {
            long long v = e.first;
            long long price = e.second;
            price = price / 2; // applied discounted price
            
            if(dist_src[u] == inf || dist_dst[v] == inf) { // nodes are unreachable
                continue;
            }
            totalPrice = min(totalPrice, dist_src[u] + price + dist_dst[v]);
        }
    }
    cout << totalPrice;

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