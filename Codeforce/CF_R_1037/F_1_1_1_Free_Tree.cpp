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
void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> color(n);
    for(auto &c: color) cin >> c;

    using pii = pair<int,int>;
    vector<vector<pii>> adj(n);

    for(int i = 0; i < n-1; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        u -= 1; v -= 1;
        adj[u].push_back(pii{v,c});
        adj[v].push_back(pii{u,c});
    }

    // tree rooted at node 0
    vector<map<int,int>> data(n);
    vector<map<int,int>> freq(n);
    vector<int> parent(n,-1);
    map<pii,int> edgeCost;
    int totalSum = 0;
    auto dfs = [&](const auto &self, int u, int p)->void {
        parent[u] = p;
        for(auto &[v,c]: adj[u]) {
            if(v == p) continue;
            edgeCost[pii{u,v}] = c; // parent,node --> cost
            totalSum += (color[u] == color[v]?0:c);
            data[u][color[v]] += c;
            freq[u][color[v]] += 1;
            self(self,v,u);
        }
    };

    dfs(dfs,0,-1);


    for(int qi = 0; qi < q; qi++) {
        int v, x;
        cin >> v >> x;

        v -= 1;
        int p = parent[v];
        // query
        int old = color[v];
        color[v] = x;

        // update with parent
        if(p != -1) {
            int c = edgeCost[pii{p,v}];
            data[p][old] -= c;
            freq[p][old] -= 1;

            if(freq[p][old] == 0) {
                data[p].erase(old);
                freq[p].erase(old);
            }

            data[p][x] += c;
            freq[p][x] += 1;
            
            if(color[p] == old) {
                totalSum += c;
            }

            if(color[p] == color[v]) {
                totalSum -= c;
            }
        }

        // updates with children
        totalSum += data[v][old];
        totalSum -= data[v][x];

        cout << totalSum << "\n";
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
    int t; cin >> t; while(t--)
    solve();
    // std::cout << "C++ Standard: " << __cplusplus << endl;
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
