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

#define int int64_t
void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    // x -= 1;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    map<long double,int> freq;
    for(auto &a: A) freq[a] += 1;

    // Simulation
    while(k > 0) {
        long double val = freq.rbegin()->first;
        int cnt = freq.rbegin()->second;

        // 4 .. 3
        long double newLen = val * 1.0 / 2;
        if(k >= cnt) { // break all the highest sticks
            freq[newLen] += 2 * cnt;

            // remove the highest stick
            freq.erase(val);

            k -= cnt;
        }
        else { // 2 ... 3
            freq[newLen] += 2 * k;
            freq[val] -= k;

            k = 0;
        }
    }

    for(auto it = freq.rbegin(); it != freq.rend(); it++) {
        if(it->second >= x) {
            cout<<fixed<<setprecision(20);
            cout << it->first << "\n";
            return;
        }
        x -= it->second;
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
    int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
