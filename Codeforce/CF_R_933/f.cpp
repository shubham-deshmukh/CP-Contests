#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../../../debug.h"
#else
#define debug(x...)
#endif

#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


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
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> A(n), B(m), C(k);
    for(auto &a: A) cin >> a;
    for(auto &b: B) cin >> b;
    for(auto &c: C) cin >> c;

    sort(B.begin(), B.end());
    B.resize(unique(B.begin(), B.end()) - B.begin());
    sort(C.begin(), C.end());
    C.resize(unique(C.begin(), C.end()) - C.begin());


    // current imbalance
    int curr = 0;
    int start = -1, end = -1;
    for(int i = 1; i < n; i++) {
        curr = max(curr, A[i]-A[i-1]);
        if(curr == A[i] - A[i-1]) {
            start = i-1;
            end = i;
        }
    }

    int cnt = 0;
    for(int i = 1; i < n; i++) {
        cnt += (A[i] - A[i-1] == curr);
    }

    if(cnt > 1) {
        cout << curr;
        return;
    }

    for(auto b: B) {
        int mid = (A[start] + A[end]) >> int(1);
        auto it = lower_bound(C.begin(), C.end(), mid - b);

        if(it != C.end()) {
            int x = *it + b;
            if(x > A[start] && x < A[end])
                curr = min(curr, max(x - A[start], A[end]- x));
        }

        if(it != C.begin()) {
            int x = *prev(it) + b;
            if(x > A[start] && x < A[end])
                curr = min(curr, max(x - A[start], A[end]- x));
        }

    }

    for(int i = 1; i < n; i++) {
        if(i == end)
            continue;
        
        curr = max(curr, A[i]-A[i-1]);
    }
    cout << curr;
    
}
signed main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    long long t = 1;
    cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
