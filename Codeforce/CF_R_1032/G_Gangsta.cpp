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

    string s;
    cin >> s;

    // 2*max(1s,0s) = 1s + 0s + abs(1s-0s);
    // 1s + 0s = len of segment
    // sum of len of all the segments 
    int cSum = 0;
    int tot = 0;
    for(int i = 0; i < n; i++) {
        cSum = cSum + i + 1;
        tot += cSum;
    }
    // cout << tot << endl;

    // abs(1s-0s) over all the segments
    // pref(r) - pref(l-1)
    vector<int> pref;
    int ones = 0, zeros = 0;
    pref.push_back(ones-zeros);

    for(int i = 0; i < n; i++) {
        ones += (s[i] == '1');
        zeros += (s[i] == '0');

        pref.push_back(ones-zeros);
    }

    sort(pref.begin(), pref.end());
    cSum = 0;
    int tot2 = 0;
    for(int i = 0; i <= n; i++) {
        // i * pref[i] - cSum
        tot2 += i * pref[i] - cSum;
        cSum += pref[i];
    }

    cout << (tot + tot2) / 2 << "\n";
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
