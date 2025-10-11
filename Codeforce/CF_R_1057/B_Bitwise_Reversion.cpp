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
    int x, y, z;
    cin >> x >> y >> z;

    // a, b, c
    auto add = [&](int bit, int pos, int &val)->void {
        if(bit) {
            val += (1<<pos);
        }
    };

    int a = 0, b = 0, c = 0;
    for(int i = 0; i < 30; i++) {
        int x_i = ((x>>i) & 1);
        int y_i = ((y>>i) & 1);
        int z_i = ((z>>i) & 1);
        bool isFound = false;
        for(auto a_i:{0,1}) {
            for(auto b_i:{0,1}) {
                for(auto c_i:{0,1}) {
                    if(((a_i & b_i) == x_i) and ((b_i & c_i) == y_i) and ((a_i & c_i) == z_i)) {
                        // add(a_i,i,a);
                        // add(b_i,i,b);
                        // add(c_i,i,c);
                        isFound = true;
                        break;
                    }
                }
                if(isFound)break;
            }
            if(isFound) break;
        }
        if(!isFound) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";

    // verify

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
