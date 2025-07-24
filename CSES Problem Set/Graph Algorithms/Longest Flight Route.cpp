#include <bits/stdc++.h>
 
using namespace std;
 
// #ifndef ONLINE_JUDGE
// #include "./debug.h"
// #else
// #define debug(x...)
// #endif
 
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
 
using namespace __gnu_pbds;
 
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// X.find_by_order(k) return kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.
 
 
const int MAX_N = 1e5;
const int mod = 1e9+7;
 
inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}

constexpr int inf = 2e9;
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> adj(n+1), revAdj(n+1);
    vector<int> in_deg(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
 
        // u-->v
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
 
    vector<int> dp(n+1,-1), parent(n+1);
 
    // dp on DAG
    auto f = [&](const auto &self, int u)->int {
        if(u == n) {
            return dp[u] = 1;
        }

        if(dp[u] != -1)
            return dp[u];

        int best = -inf;
        for(auto v: adj[u]) {
            int cnt = self(self,v);
            if(cnt != -inf)
                best = max(best,1+cnt);
        }

        return dp[u] = best;
    };

    f(f,1);
    
    
    if(dp[1] == -inf) {
        cout << "IMPOSSIBLE";
        return;
    }
    
    // path construction
    vector<int> path;
    int u = 1;
    while(u != n) {
        path.push_back(u);
        for(auto v: adj[u]) {
            if(dp[v] != -1 and dp[u] == 1 + dp[v]) {
                u = v;
                break;
            }
        }
    }
    path.push_back(n);
    cout << dp[1] << "\n";
    // print the path
    for(auto &p: path) cout << p << " ";
 
}
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    // int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}