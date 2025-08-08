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


inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}


#define int int64_t
const int mod = 1e9+7;
vector<int> fact;
void getFact(int n) {
    fact.assign(n+1,1);
    fact[0] = fact[1] = 1;

    for(int i = 2; i < n; i++) {
        fact[i] = (fact[i-1] * i) % mod; 
    }
}

vector<int> parent, sz;
int comp;
int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if(u == v) return false;

    if(sz[u] < sz[v]) swap(u,v);

    parent[v] = u;
    sz[u] += sz[v];
    comp -= 1;

    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    parent.assign(n+1,0);
    iota(parent.begin(), parent.end(), 0);
    sz.assign(n+1,1);

    comp = n;

    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1);

    bool isCycle = false;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        deg[u] += 1;
        deg[v] += 1;

        if(!unite(u,v)) isCycle = true;
    } 

    if(isCycle) {
        cout << "0\n";
        return;
    }
    // find the node with maximum deg
    int src = max_element(deg.begin()+1,deg.end()) - deg.begin();

    vector<int> vis(n+1);
    auto dfs = [&](const auto &self, int u, int p)->int {
        vis[u] = 1;

        int ways = 1;
        int deg1 = 0;
        int children = 0;
        int mx1 = -1, mx2 = -1;
        for(auto &v: adj[u]) {
            if(v == p or vis[v]) continue;
            deg1 += (deg[v] == 1);
            if(deg[v] >= mx1) {
                mx2 = mx1;
                mx1 = deg[v];
            }
            else if(deg[v]>mx2) {
                mx2 = deg[v];
            }
            children += 1;
            ways = ways * self(self,v,u) % mod;
        }

        if(u == src) {
            if(children - deg1 > 2) ways = 0;
            else {
                int ch = children;
                if(mx1 > 1) {
                    ways = ways * 2 % mod;
                    ch -= 1;
                    ch -= (mx2 > 1);

                }
                ways = ways * fact[ch] % mod;
            }
        }
        else {
            if(children-deg1 >= 2) ways = 0;
            else {
                int ch = children;
                ch -= (mx1 > 1);
                ways = ways * fact[ch] % mod;
            }
        }
        
        return ways % mod;
    };
    
    int ways = dfs(dfs,src,0);
    // Change the sides on the river
    ways = 2 * ways * fact[comp] % mod;
    cout << ways << "\n";
}

signed main() {
    // your code goes here
    fast;
    getFact(2e5+1);
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
