#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../../../debug.h"
#else
#define debug(x...)
#endif

#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


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

#define int int64_t
const int inf = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;

    using t3 = array<int,3>; // u, v, time
    vector<t3> edges;
    for(int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u -= 1;
        v -= 1;
        edges.push_back({u,v,t});
    }

    vector<vector<int>> adj(n, vector<int> (n,inf));
    for(int i = 0; i < n; i++)
        adj[i][i] = 0;
    
    for(auto [u,v,t]: edges) {
        adj[u][v] = min(adj[u][v],t);
        adj[v][u] = min(adj[v][u],t);
    }

    // All pair shortest path   
    // u----k....v
    // dist(u,v) = min(dist(u,v), dist(u,k) + dist(k,v))
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adj[i][k] != inf and adj[k][j] != inf) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    int Q;
    cin >> Q;

    while(Q--) {
        int k;
        cin >> k;

        vector<int> E(k);
        for(int i = 0; i < k; i++) {
            cin >> E[i];
            E[i] -= 1;
        }

        int minTime = inf;
        vector<int> p(k);
        iota(p.begin(), p.end(), int(0));
        do {
            // k : 3 
            //B0,B1,B2

            // check for all direction
            for(int i = 0; i < (int(1)<<k); i++) {
                int pNode = 0;
                int time = 0;
                for(int j=0; j < k; j++) {
                    int dir = (i & (int(1)<<j));
                    int idx = E[p[j]];
                    int u = edges[idx][0];
                    int v = edges[idx][1];
                    int t = edges[idx][2];
                    if(dir) { // Non-zero : right direction
                        // u--v
                        time += adj[pNode][u];
                        pNode = v;
                    }
                    else { // zero: left direction
                        // v--u
                        time += adj[pNode][v];
                        pNode = u;
                    }
                    time += t;
                }
                time += adj[pNode][n-1];
                minTime = min(minTime, time);
            } 

        } while(next_permutation(p.begin(), p.end()));

        cout << minTime;
        if(Q) cout << endl;
    }
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
