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
const int inf = int(1e9);
void solve() {
    int n;
    cin >> n;

    vector<int> X(n), Y(n);
    for(auto &a: X) cin >> a;
    for(auto &a: Y) cin >> a;

    vector<int> A, B;
    A.push_back(-inf-1);
    B.push_back(int(0));
    for(int i = 0; i < n; i++) {
        A.push_back(X[i]);
        B.push_back(Y[i]);
    }

    A.push_back(inf+1);
    B.push_back(0);

    vector<int> sum(n+2);
    for(int i = 1; i <= n+1; i++) {
        sum[i] = sum[i-1] + B[i];
    }

    int Q;
    cin >> Q;

    auto getL = [&](int x)->int { // equal to or greater

        auto isOk1 = [&](int m)->bool {
            return A[m] >= x;
        };

        int l = 0, r = n+1;

        while(r-l > 1) {
            int m = l + (r-l) / 2;
            if(isOk1(m))
                r = m;
            else 
                l = m;
        }

        return r;
    };

    auto getR = [&](int x)->int { // equal to or less

        auto isOk2 = [&](int m)->bool {
            return A[m] <= x;
        };

        int l = 0, r = n+1;

        while(r-l > 1) {
            int m = l + (r-l) / 2;
            if(isOk2(m))
                l = m;
            else 
                r = m;
        }

        return l;
    };

    // cout << getL(3) << endl;
    // cout << getR(3);

    debug(sum);
    while(Q--) {
        int l, r;
        cin >> l >> r;

        // int li = lower_bound(A.begin(), A.end(), int(l)) - A.begin();
        // int ri = lower_bound(A.begin(), A.end(), int(r)) - A.begin();

        int li = getL(l);
        int ri = getR(r);

        // debug(li,ri);
        if(li > ri) {
            cout << 0;
        }
        else {
            cout << sum[ri] - sum[li-1];
            // debug(sum[ri],sum[li-1]);
        }

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
    
    solve();
    
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
