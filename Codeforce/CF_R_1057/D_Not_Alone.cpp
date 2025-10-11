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
/*
obj:
- solve for non-circular

- f(i) : min op required to make array till i nice
i can be made equal
    - i-1
    - i-1,i-2

make element equals to median


*/
#define int int64_t
constexpr int inf = 1e18;
void chmin(int &a, int b) {a = min(a,b);}
int get_cost(int a, int b) {
    return abs(a-b);
}

int get_cost(int a, int b, int c) {
    int mn = min({a,b,c});
    int mx = max({a,b,c});
    // 1 4 6
    return mx-mn;
}

void solve() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto &a: A) cin >> a;

    // [l,r]
    auto f = [&](int l, int r, vector<int> &A)->int {
        if(l > r) return 0;
        int n = r-l+1;
        vector<int> dp(n,inf);

        for(int i = 1; i < n; i++) {
            // 0 1 2
            if(i-1 >= 0)
                dp[i] = get_cost(A[i+l],A[i+l-1]) + (i-2>=0?dp[i-2]:0);
            // 0 1 2 3
            if(i-2 >= 0)
                chmin(dp[i],get_cost(A[i+l],A[i+l-1],A[i+l-2]) + (i-3>=0?dp[i-3]:0));
        
        }
        return dp[n-1];
    };
    auto move_front = [&](vector<int> &A)->void {
        A.push_back(A[0]);
        A.erase(A.begin());
    };

    int ans = inf;
    for(int i = 0; i < 3; i++) {
        int val = f(0,n-1,A);
        chmin(ans,val);
        move_front(A);
    }
    cout << ans << "\n";
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
