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
using int64 = long long;

vector<vector<int64>> operator*(const vector<vector<int64>> &A, const vector<vector<int64>> &B)  {
    int r1 = (int)A.size(), c1 = (int)A[0].size();
    int r2 = (int)B.size(), c2 = (int)B[0].size();

    assert(c1 == r2);
    vector ans(r1, vector<int64>(c2));

    for(int j = 0; j < c2; j++) {
        for(int i = 0; i < r1; i++) {
            for(int k = 0; k < c1; k++) {
                ans[i][j] = (ans[i][j] + A[i][k] * B[k][j])%mod; 
            }
        }
    }

    return ans;
}

vector<vector<int64>> matpow(vector<vector<int64>> mat, int b) {
    int n = (int)mat.size();
    vector rst(n, vector<int64>(n));
    for(int i = 0; i < n; i++) rst[i][i] = 1; // Identity matrix

    while(b>0) {
        if(b&1) rst = rst * mat;
        mat = mat * mat;
        b >>= 1;
    }
    return rst;
}

void solve() {
    int n;
    cin >> n;

    if(n==0) {
        cout << 0;
        return;
    }

    vector<vector<int64>> X = {{0,1}};
    vector<vector<int64>> Y = {{0,1},{1,1}};

    n = n-1;
    X = X * matpow(Y,n);
    cout << X[0][1];
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
