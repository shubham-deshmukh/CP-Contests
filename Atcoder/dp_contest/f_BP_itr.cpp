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

void solve() {
    string s, t;
    cin >> s >> t;

    int n_s = (int)s.size();
    int n_t = (int)t.size();

    vector<vector<int>> dp(1+n_s, vector<int> (1+n_t,0));
    for(int i = 0; i <= n_s; i++) {
        for(int j = 0; j <= n_t; j++) {
            if(i == 0 or j == 0) {
                dp[i][j] = 0;
                continue;
            }
            int lcs = 0;
            if(s[i-1] == t[j-1]) {
                lcs = 1 + dp[i-1][j-1];
            }
            else 
                lcs = max(dp[i][j-1], dp[i-1][j]);
            
            dp[i][j] = lcs;
        }
    }

    // cout << dp[n_s][n_t];
    // Path construction
    string lcs = "";
    int i = n_s, j = n_t;
    while(i and j) {
        if(s[i-1] == t[j-1]) {
            lcs.push_back(s[i-1]);
            i -= 1;
            j -= 1;
        }
        else if(dp[i-1][j] == dp[i][j]) {
            i = i - 1;
        }
        else 
            j = j - 1;
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs;
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
