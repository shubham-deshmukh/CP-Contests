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
const int mod = 1e9+7;

inline long long gcd(long long a, long long b) {long long r; while (b) {r = a % b; a = b; b = r;} return a;}
inline long long lcm(long long a, long long b) {return a / gcd(a, b) * b;}

#define int int64_t
void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // dp[0][1] = A[0];
    // for(int i = 1; i < n; i++) {
    //     // odd count
    //     dp[i][1] = dp[i-1][0] + A[i];
    //     //even count
    //     dp[i][0] = dp[i-1][1] + 2 * A[i];
    // }

    // cout << max(dp[n-1][0], dp[n-1][1]);

    auto rec = [&](const auto &self, int i, int count)->int {
        if(i == n)
            return 0;

        

        auto & ans = dp[i][count];
        if(ans != -1)
            return ans;
        
        int notTake = self(self,i+1,count); // not Take
        int take = 0;
        if(count%2 == 0) { // odd parity
                take = 2*A[i] + self(self,i+1,count+1);
        }
        else {
            // if(count+1 <= n)
                take = A[i] + self(self,i+1,count+1);
        }

        return ans = max(take,notTake);
    };

    cout << rec(rec,0,1);
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
