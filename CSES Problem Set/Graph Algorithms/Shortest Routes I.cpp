#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;
using pii = pair<long long, long long>;

void solve() {
    int n,m; // n : cities, m : flights
    cin >> n >> m;

    // connections
    vector<vector<pii>> adj(n);
    for(int i = 0; i < m; i++) {
        long long from, to, len;
        cin >> from >> to >> len;

        // Normalize for 0-based indexing
        from--;
        to--;

        adj[from].push_back({to,len});
    }

    vector<long long> dist(n,LLONG_MAX);
    vector<long long> parent(n,-1);

    long long src = 0;
    dist[src] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    /*
    To do:
    - Try with default priority queue 
    - with negative weight approach i.e. pq.push({-dist[to],to});
    - It is failing in my first attempt
    - Figure out why it is failing 
    */
    // priority_queue<pii> pq;
    pq.push({0,src}); // len, node

    while(!pq.empty()) {
        long long node = pq.top().second;
        long long distance = pq.top().first;

        pq.pop();

        if(distance > dist[node]) // is shortest distance calculated?
            continue;

        for(auto edge : adj[node]) {
            long long to = edge.first;
            long long len = edge.second;

            if(dist[node]+len < dist[to]) {
                dist[to] = dist[node]+len;
                parent[to] = node;
                pq.push({dist[to],to});
                // pq.push({-dist[to],to});    
            }
        }
    }

    for(auto &d: dist) cout << d << " ";
    
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