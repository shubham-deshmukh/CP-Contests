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

using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
using viiii = vector<viii>;

void solve() {
    string r;
    cin >> r;

    int d;
    cin >> d;

    int n = (int)r.size();
    string l(n,'0');
    l.back() = '1';

    viiii dp(n+1, viii(2, vii(2, vi(d, -1))));
    auto rec = [&](const auto &self, int i, int left, int right, int rem)->int {
        if(i == n) {
            if(rem == 0)    
                return 1;

            return 0;
        }

        auto &ans = dp[i][left][right][rem];
        if(ans != -1)  
            return ans;
        // set the limits
        char start = '0', end = '9';
        if(left == 1)
            start = l[i];
        
        if(right == 1)
            end = r[i];
        
        int cnt = 0;
        for(char digit = start; digit <= end; digit++) {
            int newRem = (rem + digit - '0')%d;
            
            // set the new left and right  
            int newLeft = left, newRight = right;

            if(digit != l[i])
                newLeft = 0;
            
            if(digit != r[i])
                newRight = 0;
            
            (cnt += self(self,i+1,newLeft,newRight,newRem)) %= mod;
        }

        return ans = cnt;
    };

    cout << rec(rec,0,1,1,0);
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
