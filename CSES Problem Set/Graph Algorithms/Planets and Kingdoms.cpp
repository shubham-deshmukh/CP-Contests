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

    vector<vector<int>> adj(n), rev_adj(n);

    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--;v--;

        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    vector<int> order;
    vector<bool> vis(n,false);
    vector<int> comp;

    auto dfs1 = [&](const auto &self, int u)->void{
        vis[u] = true;

        for(auto v: adj[u]) {
            if(!vis[v]) {
                self(self, v);
            }
        }
        order.push_back(u);    
    };

    for(int i = 0; i < n; i++) {
        if(!vis[i]) 
            dfs1(dfs1,i);
    }

    reverse(order.begin(), order.end());
    // for(auto o: order) cerr << o << " "; cerr<<endl;

    vis.clear();
    vis.resize(n,false);

    auto dfs2 = [&](const auto &self, int u)->void {
        vis[u] = true;
        comp.push_back(u);

        for(auto v: rev_adj[u]) {
            if(!vis[v]) {
                self(self, v);
            }
        }
    };

    int k = 1;
    vector<int> kingdom(n,0);
    for(auto u: order) {
        if(!vis[u]) {
            dfs2(dfs2,u);

            for(auto v: comp) {
                kingdom[v] = k;
            }
            comp.clear();
            k++;
        }
    }
    cout << k-1 << endl;
    for(auto k: kingdom) cout << k << " ";
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