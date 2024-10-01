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
const int inf = int(1e18);

/*

DP definition:
dp(mask) : max cost obtained from forming group using mask elements.
*/
void solve() {
    int n;
    cin >> n;

    vector cost(n, vector(n,0));
    for(auto &v: cost)
        for(auto &a: v)
            cin >> a;

        
    // cost for each submask
    // 1 : in the group
    // 0 : not in the group
    vector<int> score((1<<n));
    for(int m = 0; m < (1<<n); m++) {
        // score for all the pairs which are in the group
        int tot = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int m1 = (1<<i);
                int m2 = (1<<j);
                // Both i and j are in the group
                if((m1 & m) and (m2 & m))
                    tot += cost[i][j];
            }
        }

        score[m] = tot;
    }

    // dp(m) : max possible score grouped formed from mask m i.e. 
    // group formed from the elements at set bit position.
    vector<int> done((1<<n), -1);
    vector<int> dp((1<<n));
    auto rec = [&](const auto &self, int m)->int {
        if(m == 0)
            return 0;
        
        if(done[m] != -1)
            return dp[m];
        
        int maxScore = -inf;
        // for all possible group
        for(int s = m; s; s = ((s-1)&m)) {
            int sc = score[s] + self(self,(s^m));
            maxScore = max(maxScore, sc);
        }

        done[m] = 1;
        return dp[m] = maxScore;

    };

    cout << rec(rec,((1<<n)-1));

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
