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
const int mod = 998244353;
using t3 = array<int,3>;

struct DSU {
    vector<int> parent, sz;
    int comp;
    int n;

    DSU(int _n) : n(_n), parent(_n, 0), sz(_n, 1), comp(_n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if(u == v) return false;
        if(sz[u] < sz[v]) swap(u,v);

        sz[u] += sz[v];
        parent[v] = u;
        comp -= 1;
        return true;
    }
};

int binpow(int a, int b) {
    int rst = 1;
    while(b > 0) {
        if(b&1) rst = rst * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return rst;
}
void add(int &a, int b) {
    a += b;
    if(a >= mod) a -= mod;
}

void sub(int &a, int b) {
    a = ((a-b)%mod+mod)%mod;
}
void solve() {
    int n, m;
    cin >> n >> m;

    vector<t3> edges;
    DSU dsu(n);

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        u -= 1, v -= 1;
        edges.push_back(t3{u,v,i});
    }

    ranges::sort(edges, [&](const t3 &a, const t3 &b) {
        return a[2] > b[2];
    });

    int i = 0;
    int cost = 0;
    while(dsu.comp > 2) {
        int u = edges[i][0];
        int v = edges[i][1];
        int c = edges[i][2];
        c = binpow(2,c);
        // cost += c;
        add(cost, c);
        dsu.unite(u,v);
        i += 1;
    }

    for(int j = i; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int c = edges[j][2];
        c = binpow(2,c);
        if(dsu.find(u) == dsu.find(v)) {
            dsu.unite(u,v);
            // cost += c;
            add(cost, c);
        }
    }

    int tot = 0;
    for(auto &[u,v,c]: edges) add(tot,binpow(2,c));
    sub(tot,cost);
    cout << (tot%mod+mod)%mod;
    // cout << tot - cost;
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
