#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,m; // n: cities , m = roads
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;

        // Normalize for 0-based indexing
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCycle = false;
    vector<bool> vis(n,false);
    
    vector<int> par(n);
    int start = -1, end = -1;

    auto dfs = [&] (const auto &self, int u, int parent) {

        if(isCycle) return;

        vis[u] = true;
        par[u] = parent;

        for(auto v: adj[u]) {
            if(!vis[v]) {
                self(self,v,u);
            }
            else {
                if(v != parent) {
                    isCycle = true;
                    end = v;
                    start = u;
                }
            }
        }
    };

    for(int i = 0; i < n; i++) {
        if(isCycle) break; // found a solution (no need to get the further solutions)
        if(!vis[i]) {
            start = -1, end = -1;
            dfs(dfs,i,-1);
        }
    }

    if(!isCycle) {
        cout << "IMPOSSIBLE";
    }
    else {
        // get the cyclic path
        int v = end;
        vector<int> path;
        while(v != par[start]) {
            path.push_back(v);
            v = par[v];
        }
        path.push_back(end);

        cout << (int)path.size() << endl;
        for(auto &e: path) cout << e+1 << " ";

    }
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