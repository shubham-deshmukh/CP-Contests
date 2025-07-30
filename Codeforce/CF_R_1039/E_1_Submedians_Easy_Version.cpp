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
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    int left = -1, right = -1;
    auto isOk = [&](int mid)->bool {
        vector<int> B(n);
        for(int i = 0; i < n; i++) {
            if(A[i] < mid) B[i] = -1;
            else B[i] = 1;
        }

        vector<int> prefixSum(n+1), prefixMin(n+1);
        vector<int> minIndex(n+1);
        
        for(int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i-1] + B[i-1];

            minIndex[i] = minIndex[i-1];
            prefixMin[i] = prefixMin[i-1];

            if(prefixMin[i] > prefixSum[i]) {
                prefixMin[i] = prefixSum[i];
                minIndex[i] = i;
            }
        }
        
        for(int r = 1; r <= n; r++) {
            //r-l+1 >= k
            // l <= r-k+1
            int l = r-k+1;
            if(l-1 < 0) continue;
            int sm = prefixSum[r] - prefixMin[l-1];
            if(sm >= 0) {
                left = minIndex[l-1]+1, right = r;
                return true;
            }
        }
        return false;
    };

    int l = 0, r = n+1;
    while(r-l>1) {
        int mid = l + (r-l) / 2;
        if(isOk(mid))
            l = mid;
        else 
            r = mid;
    }
    cout << l << " " << left << " " << right << "\n";
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
