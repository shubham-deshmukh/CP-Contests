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

void solve() {
    int n;
    cin >> n;

    int odd = 0, even = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(x&1) odd += 1;
        else even += 1;
    }

    int s = 0;
    int score = 0;
    while(odd or even) {
        if(s%2 == 0) {
            if(even) {
                even -= 1;
                score += 1;
                s ^= 1;
            }
            else {
                odd -= 1;
                s ^= 1;
            }
        }
        else { // odd
            if(odd) {
                odd -= 1;
                score += 1;
            }
            else {
                even -= 1;
            }
        }
    }

    cout << score << endl;


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
