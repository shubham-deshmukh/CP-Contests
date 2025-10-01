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
int m;
int C[5005][5005];
void pre() {
    for(int n = 1; n <= 5000; n++) {
        C[n][0] = 1;
        C[n][1] = n%m;
        C[n][n] = 1;

        for(int r = 2; r < n; r++) {
            // nCr = n-1Cr-1 + n-1Cr
            C[n][r] = C[n-1][r-1] + C[n-1][r];
            // C[n][r] %= m;
            if(C[n][r] > m) C[n][r] = C[n][r] - m;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    int ans = 1;
    int sm = 0;
    for(auto &a: A) {
        sm += a;
        ans = (ans * C[sm][a]) % m;
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
    int t; cin >> t >> m; 
    pre();
    while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
