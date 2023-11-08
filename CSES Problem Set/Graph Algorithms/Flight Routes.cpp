#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    const long long inf = LLONG_MAX;
    int n,m,k;
    cin >> n >> m >> k;

    vector<
        vector<
            pair<int,long long>
        >
    > adj(n);
    for(int i = 0; i < m; i++) {
        int from, to, price;
        cin >> from >> to >> price;
        from--;to--;
        adj[from].push_back({to,price}); // node, cost
    }

    vector<long long> dist(n,inf);
    vector<long long> parent(n,-1);

    using pli = pair<long long, int>; // cost, node
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vector<
        priority_queue<long long>
    > vdist(n);

    // Initialize the queues
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            vdist[i].push(inf);
        }
    }

    int src = 0;
    dist[src] = 0;
    vdist[src].push(0);
    vdist[src].pop();

    pq.push({0,src}); // cost, node

    while(!pq.empty()) {
        int u = pq.top().second;
        long long cost = pq.top().first;

        pq.pop();

        if(cost > vdist[u].top()) 
            continue;
        
        for(auto [v,price]: adj[u]) {
            
            if(vdist[v].top() > cost+price) {
                vdist[v].pop();
                vdist[v].push(cost+price);
                pq.push({cost+price,v}); // cost, node
                parent[v] = u;
            }
            
        }
    }
    vector<long long> prices;
    while(!vdist[n-1].empty()) {
        // cout << vdist[n-1].top() << " ";
        prices.push_back(vdist[n-1].top());
        vdist[n-1].pop();
    }
    reverse(prices.begin(), prices.end());

    for(auto price: prices) cout << price << " ";

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