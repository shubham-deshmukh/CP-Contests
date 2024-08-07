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
    int n, k;
    cin >> n >> k;

    vector<int> A(n), B(n);
    for(auto &a: A) cin >> a;
    for(auto &b: B) cin >> b;

    auto isGood = [&](int x)->bool {
        // compute number of operation that can be performed 
        // such that a[i] - b[i], a[j] - b[j] .... >= k
        int op = 0;
        for(int i = 0; i < n; i++) {
            if(A[i] < x)
                continue;
            
            op += (A[i] - x) / B[i] + 1;
        }

        return op >= k;
    };

    // find out largest x for which all the score taken will be greater or equal
    int l = 0, r = int(1e9+7);
    while(r-l > 1) {
        int mid = l + (r-l) / 2;
        if(isGood(mid))
            l = mid;
        else 
            r = mid;
    }

    // each score that is choosen will be greater or equal to l
    // compute the score
    int score = 0;
    int totalOp = 0;
    // choose the score which is greater than l
    for(int i = 0; i < n; i++) {
        if(A[i] < l)
            continue;
        
        int op = (A[i] - l - 1) / B[i] + 1;
        totalOp += op;
        score += (2 * A[i] - (op - 1) * B[i]) * op / 2;
    }

    // choose the score which is equal to l
    score += (k - totalOp) * l;
    cout << score;

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
