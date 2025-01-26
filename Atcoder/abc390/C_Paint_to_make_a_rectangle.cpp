#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "./debug.h"
#else
#define debug(x...)
#endif

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

    vector<string> A(n);
    for(auto &a: A) cin >> a;

    int mxRow = -1, mnRow = n, mxCol = -1, mnCol = m;
    int mxQRow = -1, mnQRow = n, mxQCol = -1, mnQCol = m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == '#') {
                mxRow = max(mxRow,i);
                mnRow = min(mnRow,i);
                mxCol = max(mxCol,j);
                mnCol = min(mnCol,j);
            }
            else if(A[i][j] == '?') {
                mxQRow = max(mxQRow,i);
                mnQRow = min(mnQRow,i);
                mxQCol = max(mxQCol,j);
                mnQCol = min(mnQCol,j);
            }
        }
    }
    auto check = [&](int mxRow, int mnRow, int mxCol, int mnCol)->bool {
        for(int i = mnRow; i <= mxRow; i++) {
            for(int j = mnCol; j <= mxCol; j++) {
                if(A[i][j] == '.') {
                    return false;
                }
            }
        }
        return true;
    };

    if(mxRow != -1) {
        if(check(mxRow,mnRow,mxCol,mnCol)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
    }
    else {
        if(check(mxQRow,mnQRow,mxQCol,mnQCol)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
    }
}
signed main() {
    // your code goes here
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    //     freopen("./error.txt", "w", stderr);
    // #endif
    // int t; cin >> t; while(t--)
    solve();
    
    // cout<<fixed<<setprecision(10);
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
