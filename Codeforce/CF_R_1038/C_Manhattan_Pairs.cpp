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
void solve() {
    int n;
    cin >> n;

    vector<int> X(n), Y(n);
    for(int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int i, int j) {
        return X[i] < X[j];
    });

    vector<int> quadrant(n); 
    for(int i = 0; i < n; i++) {
        if(i < n/2) {
            quadrant[order[i]] = quadrant[order[i]] * 2 + 1;
        }
        else {
            quadrant[order[i]] = quadrant[order[i]] * 2 + 0;
        }
    }

    sort(order.begin(), order.end(), [&](int i, int j) {
        return Y[i] < Y[j];
    });
    
    vector<vector<int>> q(4,vector<int>());
    for(int i = 0; i < n; i++) {
        int idx = -1;
        if(i < n/2) {
            idx = quadrant[order[i]] * 2 + 1;
        }
        else {
            idx = quadrant[order[i]] * 2 + 0;
        }
        q[idx].push_back(order[i]+1);
    }
    int ans = 0;
    assert(q[0].size() == q[3].size());
    for(int i = 0; i < (int)q[0].size(); i++) {
        cout << q[0][i] << " " << q[3][i] << endl;
        // ans += abs(X[q[0][i]-1] - X[q[3][i]-1]);
        // ans += abs(Y[q[0][i]-1] - Y[q[3][i]-1]);
    }
    assert(q[1].size() == q[2].size());
    for(int i = 0; i < (int)q[1].size(); i++) {
        cout << q[1][i] << " " << q[2][i] << endl;
        // ans += abs(X[q[1][i]-1] - X[q[2][i]-1]);
        // ans += abs(Y[q[1][i]-1] - Y[q[2][i]-1]);
    }
    // cout << "ans: " <<ans << "\n";
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
