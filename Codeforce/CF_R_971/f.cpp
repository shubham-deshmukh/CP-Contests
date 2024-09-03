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
    int n, Q;
    cin >> n >> Q;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    vector<int> sum(n+1);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + A[i-1];
    
    int blockSum = accumulate(A.begin(), A.end(), int(0));

    auto getSum = [&](const int i)->int {
        if(i == 0)
            return 0;
        
        int blocks = (i-1) / n;
        int tot = blockSum * blocks;
       
        // get the sum in the current block
        // current block is (blocks + 1) cyclic shifted
        int x = blocks + 1;
        int pos = (i-1) % n + 1;
        int boundry = (n+ (1-x))%n + 1;
        
        int j = (pos + x-1) % n;
        if(j==0)
            j = n;
        if(pos < boundry) {
            // [x..j]
            tot += sum[j] - sum[x-1];
        }
        else {
            // [x .. n] + [1..j]
            tot += (x != 1?sum[n] - sum[x-1]: 0) + sum[j] - sum[0];
        }
        return tot;
    };

    while(Q--) {
        int l, r;
        cin >> l >> r;

        cout << getSum(r) - getSum(l-1);
        if(Q) cout << endl;
    }
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
