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

vector<int> parent;
vector<int> sz;

int find(int u) {
    if(parent[u] == u)
        return u;
    
    return parent[u] = find(parent[u]);
}

int unite(int u, int v) {
    u = find(u);
    v = find(v);

    if(u == v)
        return false;

    // u is bigger than v
    if(sz[u] < sz[v])
        swap(u,v);

    sz[u] += sz[v];
    parent[v] = u;

    return true; 
}

void solve() {
    int n, m;
    cin >> n >> m;

    parent.assign(n, -1);
    sz.assign(n,1);
    iota(parent.begin(), parent.end(), 0);

    for(int i = 0; i < m; i++) {
        string op;
        int u, v;
        cin >> op >> u >> v;

        u -= 1, v -= 1;

        if(op == "union") {
            unite(u,v);
        }
        else if(op == "get") {
            u = find(u);
            v = find(v);

            cout << (u == v?"YES":"NO") << "\n";
        }
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
