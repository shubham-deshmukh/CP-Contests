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
Observations:
1. It is always possible to make a1 = b1
2. consecutive equal values are always possible to make
    - consecutive equal elements can be removed
3. (special case) bi = 1 and bj > 1 where j > i then not possible
4. ai = x1 + x2 ; x2 = prefixMin  and x1 = bi - x2 where x1 >= 0 and x1 < prefixMin

*/
void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    vector<int> prefixMin = A;
    for(int i = 1; i < n; i++) prefixMin[i] = min(prefixMin[i-1],A[i]);

    for(int i = 1; i < n; i++) {
        if(prefixMin[i-1] >= A[i]) continue;
        int x1 = A[i] - prefixMin[i-1];
        if(x1 >= 0 and x1 < prefixMin[i-1]) {

        }
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
