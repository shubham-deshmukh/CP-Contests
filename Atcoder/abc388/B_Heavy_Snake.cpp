#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "./debug.h"
#else
#define debug(x...)
#endif

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

void solve() {
    int n, d;
    cin >> n >> d;

    vector<int> T(n), L(n);
    for(int i = 0; i < n; i++)
        cin >> T[i] >> L[i];
    
    vector<int> order(n);
    iota(order.begin(), order.end(),0);
    for(int k = 1; k <= d; k++) {
        sort(order.begin(), order.end(),[&](int i, int j) {
            return 1LL * T[i] * (L[i]+k) > 1LL * T[j] * (L[j]+k);
        });

        int j = order[0];
        cout << T[j] * (L[j]+k) << endl;
    }
}
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
