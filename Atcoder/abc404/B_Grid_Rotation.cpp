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

int get(vector<string> &A, vector<string> &B) {
    int n = (int) A.size();
    int op = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            op += (A[i][j] != B[i][j]);
    
    return op;
}
void rotate(vector<string> &A) {
    vector<string> C = A;
    int n = (int)A.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = C[n-1-j][i];
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<string> A(n), B(n);
    for(auto &a: A) cin >> a;
    for(auto &b: B) cin >> b;

    // without rotation
    int cnt1 = get(A,B);
    rotate(A); // 90 deg
    cnt1 = min(cnt1,1+get(A,B)); 
    rotate(A); // 180 deg
    cnt1 = min(cnt1,2+get(A,B));
    rotate(A); // 270 deg
    cnt1 = min(cnt1,3+get(A,B));

    cout << cnt1;
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
