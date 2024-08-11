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
    int n;
    cin >> n;

    vector<vector<vector<int>>> A(n, vector<vector<int>> (n, vector<int>(n)));
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cin >> A[k][i][j];
        }
    }

    vector<vector<vector<int>>> pSum(n, vector<vector<int>> (n+1, vector<int>(n+1)));
    for(int k = 0; k < n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                pSum[k][i][j] = pSum[k][i-1][j] + pSum[k][i][j-1] - pSum[k][i-1][j-1] + A[k][i-1][j-1];
            }
        }
    }

    int q;
    cin >> q;

    int lk, rk, li, ri, lj, rj;
    while(q--) {
        cin >> lk >> rk >> li >> ri >> lj >> rj;
        lk -= 1; rk -= 1;
        li -= 1; ri -= 1; 
        lj -= 1; rj -= 1;

        int sum = 0;
        for(int k = lk; k <= rk; k++) {
            sum += pSum[k][ri+1][rj+1] - pSum[k][ri+1][lj] - pSum[k][li][rj+1] + pSum[k][li][lj];
        }
        cout << sum;
        if(q) cout << endl;
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
