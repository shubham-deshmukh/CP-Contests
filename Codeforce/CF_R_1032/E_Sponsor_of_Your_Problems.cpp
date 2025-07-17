#include <bits/stdc++.h>

using namespace std;

// #ifndef ONLINE_JUDGE
// #include "./debug.h"
// #else
// #define debug(x...)
// #endif

#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

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

void solve() {
    string l, r;
    cin >> l >> r;

    int n = (int)r.size();
    viii dp(n+1, vii(2, vi(2,-1)));

    auto f = [&](const auto &self, int i, int lb, int rb)->int {
        if(i == n) return 0;

        if(dp[i][lb][rb] != -1)
            return dp[i][lb][rb];
        int start = 0;
        int end = 9;

        if(lb) start = l[i]-'0';
        if(rb) end = r[i]-'0';

        int ans = 100;
        for(int d = start; d <= end; d++) {
            int newLb = lb, newRb = rb;
            if(d != l[i]-'0') newLb = 0;
            if(d != r[i]-'0') newRb = 0;

            int score = (d == l[i]-'0') + (d == r[i]-'0') + self(self,i+1,newLb,newRb);
            ans = min(ans,score);
        }

        return dp[i][lb][rb] = ans;
    };
    cout << f(f,0,1,1) << endl;


}
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
