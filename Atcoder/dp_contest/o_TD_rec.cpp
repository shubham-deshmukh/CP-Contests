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

inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}


#define int int64_t
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;

const int mod = 1e9+7;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> A(n, vector<int> (n));
    for(auto &v: A)
        for(auto &a: v)
            cin >> a;
        

    // dp(mIdx,matched) : number of ways to form 'mIdx' pairs from men [mIdx..N]
    // paired with matched women
    // TC = O(N* (2^N)  * N)
    // SC = O(N * (2^N))
    vii dp(n, vi((1<<n), -1));
    auto rec = [&](const auto &self, int mIdx,int matched)->int {
        if(mIdx == n) {
            return 1;
        }

        auto &ans = dp[mIdx][matched];
        if(ans != -1)
            return ans;
        

        int ways = 0;
        for(int i = 0; i < n; i++) {
            int mask = (1<<i);
            if((matched & mask) or A[mIdx][i] == 0)
                continue;
            
            ways += self(self,mIdx+1, matched | (mask)) % mod;
            ways %= mod;
        }
        return ans = ways;
    };

    cout << rec(rec,0,0);
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
