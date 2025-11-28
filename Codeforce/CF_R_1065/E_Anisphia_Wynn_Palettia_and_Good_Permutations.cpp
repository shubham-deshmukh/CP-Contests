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
/*
- construction
- 
*/
void solve() {
    int n;
    cin >> n;

    vector<int> good, bad;
    // 2 4 6 ...
    for(int i = 2; i <= n; i += 2) {
        good.push_back(i);
    }

    // 3 9 
    for(int i = 3; i <= n; i += 3) {
        if(i%2)
            good.push_back(i);
    }
    // bad 
    for(int i = 1; i <= n; i++) {
        if(i%2 and i%3)
            bad.push_back(i);
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(i%3 == 0 and !bad.empty()) {
            ans.push_back(bad.back());
            bad.pop_back();
        }
        else {
            ans.push_back(good.back());
            good.pop_back();
        }
    }
    for(auto &a: ans) cout << a << " "; cout << "\n";
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
