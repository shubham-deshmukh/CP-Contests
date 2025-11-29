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

    if(n == 1) {
        cout << "1\n";
        return;
    }
    if(n == 2) {
        cout << "9\n";
        return;
    }

    vector<vector<int>> A(n, vector<int> (n));
    int cnt = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = cnt;
            cnt += 1;
        }
    }

    auto get = [&](int i, int j)->int {
        int ans = A[i][j];
        if(i-1 >= 0) ans += A[i-1][j];
        if(i+1 < n) ans += A[i+1][j];
        if(j-1>=0) ans += A[i][j-1];
        if(j+1 < n) ans += A[i][j+1];
        return ans;
    };

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, get(i,j));
        }
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
