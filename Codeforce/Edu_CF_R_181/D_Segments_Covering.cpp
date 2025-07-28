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
constexpr int mod = 998244353;
// a^b % mod
int binpow(int a, int b, int mod) {
    a %= mod;
    int rst = 1;
    while(b) {
        if(b&1)
            rst = (rst * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return rst%mod;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> l(n), r(n), p(n), q(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> p[i] >> q[i];
    }

    int c1 = 1;
    vector<vector<int>> X(m+1,vector<int>());
    for(int i = 0; i < n; i++) {
        c1 *= ((q[i]-p[i]) % mod * binpow(q[i],mod-2,mod))%mod;
        c1 %= mod;

        X[l[i]].push_back(i);
    }

    vector<int> dp(m+2);
    dp[m+1] = 1;

    for(int i = m; i >= 1; i--) {
        int sop = 0;
        for(auto &j: X[i]) {
            sop += ((p[j] * binpow(q[j]-p[j],mod-2,mod))%mod * dp[r[j]+1]) % mod;
            sop %= mod;
        }
        dp[i] = sop;
    }

    cout << (dp[1] * c1) % mod;


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
