#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,m; // n : pupils, m : friendship
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

    vector<int>team(n,0);
    vector<bool> vis(n,false);
    bool isPos = true;

    auto dfs = [&] (const auto &self, int u, int t) -> void {
        if(!isPos) return;

        vis[u] = true;
        team[u] = 1-t; 

        for(auto v: adj[u]) {
            if(!vis[v]) {
                self(self,v,team[u]);
            }
            else {
                if(team[v] == team[u])
                    isPos = false;
            }
        }
    };

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(dfs,i,1);
        }
    }

    if(!isPos) {
        cout << "IMPOSSIBLE";
    }
    else {
        for(auto &c: team) cout << c + 1 << " ";
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