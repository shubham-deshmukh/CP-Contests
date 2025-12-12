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
// const int mod = 1e9+7;

inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}

#define int int64_t
constexpr int mod = 998244353;

using pii = pair<int,int>;

inline void add(int &a, int b) {
    a += b;
    if(a >= mod) a -= mod;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    vector<pii> edges;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        // u->v

        edges.push_back(pii{u,v});
    }

    ranges::sort(edges, [&](const pii & a, const pii &b){
        return A[a.first] + A[a.second] < A[b.first] + A[b.second];
    });

    vector<map<int,int>> dp(n);
    int ans = 0;
    for(auto &[u,v]: edges) {
        // u-->v
        int ways = 0;
        if(dp[u].contains(A[v])) {
            ways = dp[u][A[v]];
        }
        add(ways,1);
        add(dp[v][A[v]+A[u]], ways);
        add(ans, ways);
    }
    
    cout << ans << "\n";
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
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
