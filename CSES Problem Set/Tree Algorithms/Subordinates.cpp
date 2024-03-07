#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../../../debug.h"
#else
#define debug(x...)
#endif

#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mod = 1e9+7;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;

        adj[x-1].push_back(i-1);
    }

    debug(adj);
    vector<int> sub(n,-1);

    auto dfs = [&](const auto &self, int u)->int {
        if(adj[u].empty()) { // leaf
            return sub[u] = 0;
        }

        if(sub[u] != -1)
            return sub[u];
        
        int cnt = 0;
        for(auto v: adj[u]) {
            cnt += self(self,v);
        }

        sub[u] = cnt + (int)adj[u].size();
        return sub[u];
    };

    dfs(dfs,0);

    for(auto s: sub) cout << s << " ";
}

signed main() {
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