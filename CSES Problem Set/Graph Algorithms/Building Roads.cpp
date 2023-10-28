#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,m; // n : cities, m : roads
    cin >> n >> m; 

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--; // 0-based indexing
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n,false);

    auto dfs = [&] (const auto &self, int u) -> void {
        vis[u] = true;
        for(auto v: adj[u]) {
            if(!vis[v])
                self(self,v);
            
        }
    };

    // find connected components
    vector<int> comp;
    for(int u = 0; u < n; u++) {
        if(!vis[u]) {
            dfs(dfs,u);
            comp.push_back(u);
        }
    }

    int k = 0;
    if(!comp.empty()) {
        k = (int)comp.size();
    }
    
    cout << k-1;
    if(k-1) cout << endl;

    for(int i = 1; i < k; i++) {
        cout << comp[0]+1 << " " << comp[i]+1;
        if(i < k-1) cout << endl;
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