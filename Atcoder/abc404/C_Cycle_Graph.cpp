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

vector<int> parent, sz;
int comp = 0;

int find(int u) {
    if(parent[u] == u)
        return u;

    return parent[u] = find(parent[u]);
}

bool unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if(root_u == root_v)
        return false;
    
    if(sz[root_u] < sz[root_v]) {
        swap(root_u, root_v);
        swap(u,v);
    }

    sz[root_u] += sz[root_v];
    parent[root_v] = root_u;
    comp -= 1;
    return true;
}
void solve() {
    int n, m;
    cin >> n >> m;

    parent.assign(n+1,-1);
    sz.assign(n+1,1);

    iota(parent.begin(), parent.end(), 0);
    comp = n;

    vector<int> deg(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        deg[u] += 1;
        deg[v] += 1;

        unite(u,v);
    }

    bool isPos = true;
    for(int i = 1; i <= n; i++)
        isPos &= (deg[i] == 2);
    
    cout << (isPos and comp == 1?"Yes":"No");
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
