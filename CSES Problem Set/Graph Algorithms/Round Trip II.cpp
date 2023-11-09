#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,m; // n : cities, m : connection
    cin >> n >> m;

    vector<vector<long long>> adj(n);

    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        from--; to--;
        adj[from].push_back(to);
    }

    vector<int> parent(n,-1);
    vector<bool> vis(n, false);
    vector<int> in(n,-1), out(n,-1);
    int timer = 0;

    auto dfs1 = [&] (const auto &self, int u, int par)->void {
        vis[u] = true;
        parent[u] = par;
        in[u] = timer++;
        for(auto v: adj[u]) {
            if(!vis[v]) {
                self(self, v, u);
            }
        }
        out[u] = timer++;
    };

    // Get the in and out time
    for(int i = 0; i < n; i++) {
        if(!vis[i])
            dfs1(dfs1,i,-1);
    }
    
    // Find the cycle 
    bool isCycle = false;
    vis.clear();
    vis.resize(n,false);
    int start = -1, end = -1;
    auto is_cycle = [&] (const auto &self, int u) {
        if(isCycle) return;

        vis[u] = true;

        for(auto v: adj[u]) {
            if(!vis[v])
                self(self, v);
            else {
                if(in[v] < in[u] && out[v] > out[u]) {
                    isCycle = true;
                    start = u;
                    end = v;
                    return;
                }
            }
        }
    };

    for(int i = 0; i < n; i++) {
        
        if(isCycle) // Is Cycle found?
            break;

        if(!vis[i])
            is_cycle(is_cycle,i);  
    }

    if(!isCycle) {
        cout << "IMPOSSIBLE";
        return;
    }
    // Retrieve the cycle
    vector<int> path;
    int ss = start;
    while(start != parent[end]) {
        path.push_back(start);
        start = parent[start];
    }
    path.push_back(ss);

    reverse(path.begin(), path.end());
    cout << (int) path.size() << endl;
    for(auto i: path) cout << i+1 << " ";

    // for(int i = 0; i < n; i++) {
    //     cerr << "Node - " << i+1 << " in time: " << in[i] << " , out time: " << out[i] << endl;
    // }


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