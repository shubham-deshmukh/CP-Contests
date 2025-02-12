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

    vector<int> A(n), B(m);
    for(auto &a: A) cin >> a;
    for(auto &b: B) cin >> b;

    sort(B.begin(), B.end());
    A[n-1] = max(A[n-1], B.back() - A[n-1]);
    bool isPos = true;
    for(int i = n-2; i >= 0; i--) {
        int j = lower_bound(B.begin(), B.end(), A[i]+A[i+1]+1) - B.begin();
        if(A[i] > A[i+1]) {
            j -= 1;
            if(j == -1) {
                isPos = false;
                break;
            }
            A[i] = B[j] - A[i];
        }
        else if(j) {
            A[i] = max(A[i], B[j-1]-A[i]);
        }
    }
    cout << (isPos?"YES\n":"NO\n");
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
