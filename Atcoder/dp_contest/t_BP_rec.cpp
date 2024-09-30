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

    // TC : O(N^3)
    // SC : O(N^2)
    
    auto check = [&](int curr, int last, char op)->bool {
        if(op == '>' and curr < last)
            return false;
        
        if(op == '<' and curr >= last)
            return false;
        
        return true;
    };

    vector dp(n+1, vector(n+1,-1));
    auto rec = [&](const auto &self, int i, int last)->int {
        if(i == 1) {
            if(last == 1)
                return dp[i][last] = 1;
            
            return dp[i][last] = 0;
        }

        auto &ans = dp[i][last];
        if(ans != -1)
            return ans;

        int ways = 0;
        for(int curr = 1; curr <= i-1; curr++) {
            if(check(curr,last,s[i-2])) {
                ways += self(self,i-1,curr)%mod;
                ways %= mod;
            }
        }
        return ans = ways%mod;
    };

    int ways = 0;
    for(int last = 1; last <= n; last++) {
        ways += rec(rec,n,last)%mod;
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
