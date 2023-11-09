#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    // multi-source bfs
    // Topological sort

    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> in_deg(n,0), out_deg(n,0);
    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        from--; to--;
        adj[from].push_back(to);

        // Store degree information
        out_deg[from]++;
        in_deg[to]++;
    }

    // check if graph is acylic or not
    bool isCycle = false;
    vector<int> state(n,0); // 0 - unvisited, 1-visited but not explored, 2-explored
    vector<bool> visited(n,false);

    auto is_cycle = [&] (const auto &self, int u)->void {
        if(isCycle) return;

        state[u] = 1;
        visited[u] = true;
        
        for(auto v: adj[u]) {
            if(state[v] == 0) {
                self(self,v);
            }
            else {
                if(state[v] == 1) {
                    isCycle = true;
                    return;
                }
            }
        }
        state[u] = 2;
    };

    

    for(int i = 0; i < n; i++) {
        if(isCycle) break;

        if(!visited[i]) {
            is_cycle(is_cycle, i);
        }
    }
    if(isCycle) {
        cout << "IMPOSSIBLE";
        return;
    }

    
    vector<int> order;
    visited.clear();
    visited.resize(n,false);
    auto dfs = [&](const auto &self, int u)->void {
        visited[u] = true;

        for(auto v: adj[u]) {
            if(!visited[v])
                self(self,v);
            
        }
        order.push_back(u);
    };

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(dfs,i);
        }
    }

    reverse(order.begin(), order.end());
    for(auto o: order) cout << o+1 << " ";

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