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
    string s;
    cin >> s;
    
    int n = (int)s.size();
    vector<int> ones(n+1), zeros(n+1);
    int z = 0, o = 0;
    for(int i = 1; i <= n; i++) {
        o += (s[i-1] == '1');
        z += (s[i-1] == '0');

        ones[i] = o;
        zeros[i] = z;
    }

    
    map<int,int> diff;
    map<int,int> start;
    diff[0] += 1;
    start[0] = 0;
    // vector<int> endAt(n+1);
    int tot = 0;
    for(int r = 1; r <= n; r++) {
        int d = ones[r] - zeros[r];
        if(diff.count(d)) {
            // endAt[r] = diff[d];
            // endAt[r] %= mod;
            tot += (start[d] + diff[d]) * (n-r+1);
            tot %= mod;
        }
        diff[d] += 1;
        start[d] += r;
        // diff[d] %= mod;
        
    }

    // debug(diff);
    // for(int i = 1; i <= n; i++) {
    //     endAt[i] += endAt[i-1];
    //     endAt[i] %= mod;
    // }

    // int ans = accumulate(endAt.begin(), endAt.end(), int(0));
    // ans %= mod;
    // cout << ans;
    tot %= mod;
    cout << tot;

}
signed main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    long long t = 1;
    cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
