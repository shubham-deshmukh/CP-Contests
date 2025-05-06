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
constexpr int inf = 1e18;

int getMaxSubarraySum(vector<int> &A, int l, int r) {
    int currSum = -inf;
    int maxSum = -inf;

    for(int i = l; i < r; i++) {
        int a = A[i];
        currSum = max(currSum + a, max(int(0),a));
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    int maxSum = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            A[i] = -inf;
        }
    }

    maxSum = getMaxSubarraySum(A,0,n);
    if(maxSum > k) {
        cout << "No\n";
        return;
    }

    
    int pos = -1;
    for(int i = 0; i < n; i++) if(s[i] == '0') {pos = i; break;}

    if(pos == -1) { // All values are present
        if(maxSum == k) { 
            cout << "Yes\n";
            for(auto &a: A) cout << a << " "; cout << "\n";
            return;
        }
        cout << "No\n";
        return;
    }

    A[pos] = inf;
    maxSum = getMaxSubarraySum(A,0,n);
    A[pos] = A[pos] - (maxSum - k);
    cout << "Yes\n";
    for(auto &a: A) cout << a << " "; cout << "\n";
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
