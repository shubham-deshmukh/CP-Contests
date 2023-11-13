#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    // Concept: Strongly connected components
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n), rev_adj(n);

    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;

        u--;v--;

        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    vector<bool> vis(n,false);
    vector<int> order;
    
    auto dfs1 = [&](const auto &self, int u)->void {
        vis[u] = true;

        for(auto v: adj[u]) {
            if(!vis[v]) {
                self(self,v);
            }
        }
        order.push_back(u);
    };

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs1(dfs1,i);
        }
    }

    vis.clear();
    vis.resize(n,false);
    reverse(order.begin(), order.end());

    vector<int> comp;
    auto dfs2 = [&] (const auto &self, int u)->void {
        vis[u] = true;
        comp.push_back(u);

        for(auto v: rev_adj[u]) {
            if(!vis[v]) {
                self(self,v);
            }
        }
    };

    int compSize = 0;
    for(auto u: order) {
        if(!vis[u]) {
            dfs2(dfs2, u);
            compSize++;
            if(compSize == 1) 
                break;
        }
    }

    
    // for(auto c: comp) cout << c+1 << " ";

    if((int)comp.size() == n) {
        cout << "YES";
        return;
    }
    int u,v = comp[0];
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            u = i;
            break;
        }
    }

    // Check the reachability (direction)
    order.clear();
    vis.clear();
    vis.resize(n,false);
    dfs1(dfs1,u);

    if(vis[v] == true) swap(u,v);

    cout << "NO\n";
    cout << u+1 << " " << v+1;
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