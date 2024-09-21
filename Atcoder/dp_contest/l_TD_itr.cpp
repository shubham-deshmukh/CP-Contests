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
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;

void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    // dp(l,r,turn) : value of x-y when A[l...r] and player 'turn' is playing
    // turn 1 (Taro), 0 (Jiro)
    viii dp(n+1, vii(n+1, vi(2,0)));

    for(int l = n-1; l >= 0; l--) {
        for(int r = 0; r < n; r++) {
            for(int turn = 0; turn < 2; turn++) {
                if(l > r) {
                    dp[l][r][turn] = 0;
                    continue;
                }

                if(l == r) {
                    dp[l][r][turn] = (turn?1:-1) * A[l]+ dp[l+1][r][1-turn];
                    continue;
                }

                int first = (turn?1:-1) * A[l]+ dp[l+1][r][1-turn];
                int last = (turn?1:-1) * A[r] + dp[l][r-1][1-turn];

                int diff = min(first,last);
                if(turn)
                    diff = max(first,last);
                
                dp[l][r][turn] = diff;
            }
        }
    }
    cout << dp[0][n-1][1];

    // auto rec = [&](const auto &self, int l, int r, int turn) ->int {
    //     if(l > r)
    //         return 0;
        
    //     if(done[l][r][turn] != -1)
    //         return dp[l][r][turn];

    //     int diff = 0;
    //     if(turn == 1) { // tries to maximize
    //         // take first
    //         int first = A[l] + self(self,l+1,r,1-turn);
    //         int last = A[r] + self(self,l,r-1,1-turn);

    //         diff = max(first, last);
    //     }
    //     else {
    //         int first = -A[l] + self(self,l+1,r,1-turn);
    //         int last = -A[r] + self(self,l,r-1,1-turn);

    //         diff = min(first, last);
    //     }

    //     done[l][r][turn] = 1;
    //     return dp[l][r][turn] = diff;
    // };

    // cout << rec(rec,0,n-1,1);

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
