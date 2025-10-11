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

    vector<int> A(n);
    for(auto &a: A) cin >> a;
    sort(A.rbegin(), A.rend());


    // Possible candidates
    // all pairs are valid candidates
    map<int,int> mp;
    for(auto &a: A) mp[a] += 1;

    // take all the pairs
    // odd sides might be bases

    int sum = 0, sides = 0;
    vector<int> odd;
    for(auto [v,f]: mp) {
        sides += f / 2 * 2;
        sum += (f/2) * 2 * v;
        if(f&1) {
            odd.push_back(v);
        }
    }

    if(sum == 0) {
        cout << "0\n";
        return;
    }

    int base_sum = 0;
    // single base
    for(auto &b: odd) {
        if(b < sum) {
            base_sum = max(base_sum,b);
        }
    }

    // double bases
    for(int i = 1; i < (int)odd.size(); i++) {
        if(odd[i] < sum + odd[i-1]) {
            base_sum = max(base_sum, odd[i] + odd[i-1]);
        }
    }

    if(sides == 2) { // valid vase required
        if(base_sum)
            cout << sum + base_sum << "\n";
        else 
            cout << "0\n";
    }
    else 
        cout << sum + base_sum << "\n";
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
