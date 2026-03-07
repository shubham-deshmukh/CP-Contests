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
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> mid, rem;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        if(i <= x or i > y) rem.push_back(a);
        else mid.push_back(a);
    }

    if(mid.empty()) {
        for(auto &a: rem) cout << a << " "; cout << "\n";
        return;
    }
    // rotate s.t. them mn at the start
    vector<int> rotated_arr = mid;
    int j = ranges::min_element(mid) - mid.begin();
    for(int i = 0; i < (int)mid.size(); i++) 
        rotated_arr[i] = mid[(i+j)%(int)mid.size()];
    
    if(rem.empty()) {
        for(auto &r: rotated_arr) cout << r << " "; cout << "\n";
        return;
    }
    int i = 0;
    for(; i < (int)rem.size() and rem[i] < rotated_arr[0]; i++) {
        // 1 5 3
        cout << rem[i] << " ";
    }
    for(auto &r: rotated_arr) cout << r << " ";
    for(; i < rem.size(); i++) cout << rem[i] << " "; cout << "\n";

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
