#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> in_degree(n,0);

    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        from--; to--;
        adj[from].push_back(to);
        in_degree[to]++;
    }

    vector<long long> ways(n,0);
    ways[0] = 1;

    // topological sort
    queue<int> q;

    for(int i = 0; i < n; i++) {
        if(in_degree[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        // Since it is moving forward i.e. 
        // from state v(i-1) --> state v(i)
        // Bottom-Up approach
        for(auto v: adj[u]) {
            in_degree[v]--;

            if(in_degree[v] == 0) 
                q.push(v);

            ways[v] = (ways[v] + ways[u]);
            ways[v] %= mod;
        }
    }

    cout << ways[n-1];

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