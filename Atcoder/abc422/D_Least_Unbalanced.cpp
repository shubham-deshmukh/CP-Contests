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
Obj: Generate an arr of size 2^N
- with sum of elements = K
- with min imbalance

Observations:
- N is small


*/
#define int int64_t
constexpr int inf = 1e18;
void solve() {
    int n, k;
    cin >> n >> k;

    queue<int> q;
    q.push(k);

    int imb = 0;
    while((int)q.size() < (1<<n)) {
        int sz = (int) q.size();
        int mn = inf;
        int mx = -inf;
        for(int i = 0; i < sz; i++) {
            int u = q.front();
            q.pop();
            
            int a1 = u / 2;
            int a2 = (u+1) / 2;

            mn = min(mn, a1);
            mn = min(mn, a2);

            mx = max(mx, a1);
            mx = max(mx, a2);


            q.push(a1);
            q.push(a2);
        }
        imb = max(imb, mx - mn);
    }
    cout << imb << "\n";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
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
