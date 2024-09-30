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

const int mod = 1e9+7;
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    // dp(i, last) : number of per considering i elements such that 
    // last element is last;
    // TC : O(N^2)
    // SC : O(N^2)

    vector dp(n+1, vector(n+1,0));
    vector<int> psum(n+1);
    for(int i = 1; i <= n; i++) {
        vector<int> n_psum(n+1);
        for(int last = 1; last <= i; last++) {

            if(i == 1) {
                if(last == 1) 
                    dp[i][last] = 1;
                else 
                    dp[i][last] = 0;

                n_psum[last] = n_psum[last-1]%mod + dp[i][last]%mod;
                n_psum[last] %= mod;
                continue;
            }

            int ways = 0;
            if(s[i-2] == '>') {
                int start = max(1,last);
                int end = i-1;
                if(start <= end) {
                    ways += (psum[end]%mod - psum[start-1]%mod + mod)%mod;
                }
            }
            else {
                int start = 1;
                int end = min(last-1, i-1);
                if(start <= end)
                    ways += (psum[end]%mod - psum[start-1]%mod + mod)%mod;
            }

            dp[i][last] = ways%mod;
            n_psum[last] = n_psum[last-1]%mod + dp[i][last];
            n_psum[last] %= mod;
        }

        psum = n_psum;
    }

    int ways= 0;
    for(int last = 1; last <= n; last++) {
        ways += dp[n][last]%mod;
        ways %= mod;
    }

    cout << ways;

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
