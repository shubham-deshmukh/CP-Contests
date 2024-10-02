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
// const int mod = 1e9+7;

inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}

#define int int64_t
void solve() {
    int n, mod;
    cin >> n >> mod;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;

        u -= 1;
        v -= 1;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    // down(u) : number of ways to color the subtree rooted at u
    // such that black can reach via black
    vector<int> down(n,0);
    auto dfs = [&](const auto &self, int u, int parent)->int {;

        int ways = 1; // paint the tree rooted at u as white
        int children = 1; // ways to paint the subtree if u is painted as black
        for(auto v: adj[u]) {
            if(v == parent)
                continue;
            
            children *= self(self, v, u);
            children %= mod;
        }

        ways += children;
        return down[u] = ways%mod;
    };

    // dfs(dfs, 0, -1);
    // debug(down);

    // number of ways to paint the parent of u
    vector<int> up(n, 1);
    auto dfs1 = [&](const auto &self, int u, int parent)->void {
        // Compute prefix
        {
            int prefix = 1;
            for(auto v: adj[u]) {
                if(v == parent)
                    continue;
                
                up[v] *= prefix;
                up[v] %= mod;

                prefix *= down[v];
                prefix %= mod;
            }
        }

        // compute suffix
        {
            int suffix = 1;
            for(int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                if(v == parent)
                    continue;
                
                up[v] *= suffix;
                up[v] %= mod;

                suffix *= down[v];
                suffix %= mod;
            }
        }

        // Compute up
        {
            for(auto v: adj[u]) {
                if(v == parent)
                    continue;
                
                up[v] *= up[u];
                up[v] %= mod;
            
                up[v] += 1;
                up[v] %= mod;

                self(self, v, u);
            }
        }

    };

    dfs(dfs, 0, -1);
    dfs1(dfs1,0,-1);
    // debug(up);
    // debug(down);
    for(int i = 0; i < n; i++) {
        int ways = (down[i]-1) * (up[i]) % mod;
        cout << (ways+mod)%mod << endl;
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
