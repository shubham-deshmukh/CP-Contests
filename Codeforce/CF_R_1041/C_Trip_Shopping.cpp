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
using pii = pair<int,int>;
const int inf = int(1e18);
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n), B(n);
    for(auto &a: A) cin >> a;
    for(auto &b: B) cin >> b;

    int v = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] > B[i]) swap(A[i],B[i]);
        v += B[i]-A[i];
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int i, int j) {
        if(A[i] == A[j])
            return B[i] < B[j];

        return A[i] < A[j];
    });

    int diff = inf;
    for(int i = 0; i+1 < n; i++) {
        int bi = B[order[i]];
        int aj = A[order[i+1]];

        if(bi < aj) diff = min(diff,2*(aj-bi));
        else diff = 0;
    }

    cout << v + diff << "\n";
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
