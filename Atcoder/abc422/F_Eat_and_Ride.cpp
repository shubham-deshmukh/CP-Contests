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
/*
Problem:
- Graph(n,m) : undirected and connected
- starts from 1
- initial weight : 0
- when visited node v --> weight incs by W_v
- when passes thru edge --> consumes fuel equivalent to currWeight

Obj:
- min amt fuel to reach each node

Constraint:

Obs:
- let f(u) : min amt fuel consumed to reach node u
f(1) : 0

Greedy strategy : Dijasktra
*/
#define int int64_t

using pii = pair<int,int>;
using t4 = array<int,4>;
constexpr int inf = 1e18;

void chmin(int &a, int b){a = min(a,b);}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> cost(n);
    for(auto &c: cost) cin >> c;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u -= 1;
        v -= 1;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector dp(n+1, vector<int> (n, inf));
    for(int rem = 0; rem <= n; rem++) dp[rem][0] = cost[0] * rem;

    for(int rem = n-1; rem >= 0; rem--) {
        for(int u = 0; u < n; u++) {
            for(auto v: adj[u]) {
                chmin(dp[rem][u], dp[rem+1][v] + cost[u] * rem);
            }
        }
    }

    for(int u = 0; u < n; u++) {
        cout << dp[0][u] << "\n";
    }
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
