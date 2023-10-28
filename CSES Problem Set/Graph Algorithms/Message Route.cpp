#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n,m; // n : computers , m : connections
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        
        //Normalize for 0-based indexing
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = 0, end = n-1;
    vector<bool> vis(n,false);
    vector<int> dist(n,0);
    vector<int> parent(n,-2);

    vis[start] = true;
    dist[start] = 0;
    parent[start] = -1;

    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int p = q.front();
        q.pop();

        for(auto v: adj[p]) {
            if(!vis[v]) {
                vis[v] = true;
                q.push(v);
                dist[v] = 1+dist[p];
                parent[v] = p;
            }
        }
    }

    if(parent[end]==-2) {cout << "IMPOSSIBLE";return;}
    
    int node = end;
    vector<int> path;
    while(node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    cout << (int)path.size() << endl;
    for(auto &e: path) cout << e+1 << " ";

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