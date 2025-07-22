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
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    vector<vector<int>> adj(n);
    int m = n-1;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u -= 1;
        v -= 1;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<multiset<int>> psum(2);
    psum[0].insert(0);
    psum[1].insert(0);

    vector<int> ans = A;
    auto dfs = [&](const auto &self, int u, int p, int parity, int sum)->void {
        sum = A[u] - sum;
        int mn = *psum[parity].begin();
        int mx = *psum[1-parity].rbegin();

        ans[u] = max(ans[u], sum - mn);
        ans[u] = max(ans[u], sum + mx);

        psum[parity].insert(sum);
        for(auto v: adj[u]) {
            if(v == p) continue;

            self(self,v,u,1-parity,sum);
        }
        psum[parity].erase(psum[parity].find(sum));
    };

    dfs(dfs,0,-1,0, 0);
    for(auto &a: ans) cout << a << " "; cout << endl;
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
