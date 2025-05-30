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
    int n, x;
    cin >> n >> x;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    sort(A.begin(), A.end());
    int cnt = 0;
    int i = n-1;
    int last = n;
    // 6 5 4 3 3 2
    while(i >= 0) {
        int need = (x+A[i]-1) / A[i];
        if(i+need-1 < last) {
            cnt += 1;
            last = i;
        }
        i -= 1;
        
    }
    cout << cnt << "\n";
}
void solve1() {
    int n, x;
    cin >> n >> x;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    sort(A.begin(), A.end());

    auto isOk = [&](int k)->bool {
        int req = 0;
        for(int i = 0; i < k; i++) {
            int need = (x + A[i]-1) / A[i];
            req += need;  
            if(req > n)
                return false;
        }

        return req <= n;
    };

    int l = 0, r = n + 1;
    while(r-l>1) {
        int mid = l + (r-l) / 2;
        if(isOk(mid))
            l = mid;
        else 
            r = mid;
    }
    cout << l << "\n";
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
