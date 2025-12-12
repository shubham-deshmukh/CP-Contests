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

    string s;
    cin >> s;

    // string t = s + s;
    vector<int> prev(n,-1);
    int p = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') p = i;
        prev[i] = p;
    }

    vector<int> next(n,n);
    p = n;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '1') p = i;
        next[i] = p;
    }

    p = prev.back();
    for(int i = 0; i < n and prev[i] == -1; i++) {
        prev[i] = p;
    }

    p = next[0];
    for(int i = n-1; i >= 0 and next[i] == n; i--) {
        next[i] = p;
    }

    
    int ans = 0;
    vector<int> dist(n);
    int i = 0;
    while(s[i] == '0') i += 1;
    int d = 0;
    for(; i < n; i++) {
        if(s[i] == '1') d = 0;
        else {
            d += 1;
            dist[i] = d;
        }
    }
    d = dist.back();
    i = 0;
    while(s[i] == '0') {
        d += 1;
        dist[i] = d;
        i += 1; 
    }


    for(int i = 0; i < n; i++) {
        ans = max(ans, dist[i]);
    }
    
    cout << ans << "\n";
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
