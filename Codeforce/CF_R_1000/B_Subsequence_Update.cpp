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

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    l -= 1, r -= 1;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    
    sort(A.begin(), A.begin()+l);
    sort(A.begin()+l, A.begin()+r+1);
    sort(A.begin()+r+1,A.end());

    // case 1: 
    vector<int> B = A;
    long long sum = accumulate(A.begin()+l, A.begin()+r+1,0LL);
    long long sum1 = sum;
    int i = 0, j = r;
    while(i<l and j >= l and A[i] <= A[j]) {
        sum1 -= A[j];
        sum1 += A[i];

        i += 1;
        j -= 1;
    }
    long long sum2 = sum;
    i = r+1, j = r;
    while(i < n and j >= l and A[i] <= A[j]) {
        sum2 -= A[j];
        sum2 += A[i];

        i += 1;
        j -= 1;
    }
    // cout <<"rst: "<< sum << " " << sum1 << " " << sum2 << endl;
    cout << min({sum,sum1,sum2}) << endl;
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
