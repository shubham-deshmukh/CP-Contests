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
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    vector<int> B(m);
    for(auto &b: B) cin >> b;

    // with 0 operations
    int j = 0;
    for(int i = 0; i < n and j < m; i++) {
        if(A[i] >= B[j]) j += 1;
    }

    if(j == m) {
        cout << 0 << endl;
        return;
    }

    vector<int> left(n), right(n);
    for(int i = 0, j = 0; i < n and j < m; i++) {
        if(A[i] >= B[j]) {
            left[i] = 1;
            j += 1;
        }
    }
    for(int i = 1; i < n; i++) left[i] += left[i-1];

    for(int i = n-1, j = m-1; i >= 0 and j >= 0; i--) {
        if(A[i] >= B[j]) {
            right[i] = 1;
            j -= 1;
        }
    }

    for(int i = n-2; i >= 0; i--) right[i] += right[i+1];
    int minK = 2e9;

    // place before 0th pos
    int rem = m - 1;
    if(right[0] >= rem) {
        minK = min(minK, B[0]);
    }
    for(int i = 0; i < n; i++) {
        int l = left[i];
        rem = m - l - 1;
        if(i+1 < n and right[i+1] >= rem) {
            minK = min(minK, B[l]);
        }
    }
    // place after n-1th pos
    rem = m-1;
    if(left[n-1] >= rem) {
        minK = min(minK, B.back());
    }
    if(minK == 2e9)
        minK = -1;
    cout << minK << endl;
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
