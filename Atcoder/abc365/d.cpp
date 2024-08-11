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
/*

[Note: In this game, Rock beats Scissors, Scissors beats Paper, and Paper beats Rock.]
*/
void solve() {
    int n;
    cin >> n;

    string t;
    cin >> t;

    //2 S - S,R
    //1 R - R,P
    //0 P - P,S
    vector<vector<int>> dp(n+1, vector<int> (3));
    for(int i = 1; i <= n; i++) {
        if(t[i-1] == 'P') {
            dp[i][1] = INT_MIN;
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 1;
        }
        if(t[i-1] == 'R') {
            dp[i][2] = INT_MIN;
            dp[i][1] = max(dp[i-1][2], dp[i-1][0]);
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + 1;
        }
        if(t[i-1] == 'S') {
            dp[i][0] = INT_MIN;
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 1;
        }
    }
    debug(dp);
    cout << *max_element(dp[n].begin(), dp[n].end());
    
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
