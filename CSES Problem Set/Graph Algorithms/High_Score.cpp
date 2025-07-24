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

#define int int64_t
using pii = pair<int,int>;
using t3 = array<int,3>;
constexpr int inf = int(1e18);

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n+1), revAdj(n+1);
    vector<t3> edges;
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        // u --> v
        adj[u].push_back(pii{v,-c});
        revAdj[v].push_back(pii{u,-c});
        edges.push_back(t3{u,v,-c});
    }

    vector<int> score(n+1,inf);
    vector<int> reachableFromSrc(n+1), reachableFromDst(n+1);
    
    auto dfs = [&](const auto &self, int u, int p, vector<int> &vis, vector<vector<pii>> &adj)->void {
        vis[u] = 1;
        for(auto [v,_]: adj[u]) {
            if(v == p or vis[v]) continue;

            self(self,v,u,vis,adj);
        }
    };

    dfs(dfs,1,0,reachableFromSrc,adj);
    dfs(dfs,n,0,reachableFromDst,revAdj);
 
    score[1] = 0; 
    bool isNegCycle = false;
    for(int i = 1; i <= n; i++) {
        // relax each edges
        isNegCycle = false;
        for(auto [u,v,c]: edges) {
            // u-->v 
            // u must be reachable from src and 
            // v must be reachable from dst
            if(reachableFromSrc[u] and  reachableFromDst[v] and score[v] > score[u] + c) {
                score[v] = score[u] + c;
                isNegCycle = true;
            }
        }
    }

    if(isNegCycle) {
        cout << -1;
        return;
    }

    cout << -score[n];
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
