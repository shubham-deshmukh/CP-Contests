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
    int Q;
    cin >> Q;

    // approach : simulation
    vector<int> next(Q+1,-1), prev(Q+1,-1);

    for(int q = 0; q < Q; q++) {
        int type;
        cin >> type;

        if(type == 1) {
            int x;
            cin >> x;
            
            int curr = q+1;
            // x -- curr
            next[curr] = next[x];
            prev[curr] = x;
            if(next[x] != -1) {
                prev[next[x]] = curr;
            }

            next[x] = curr;
        }
        else {
            int x, y;
            cin >> x >> y;

            // erase between x and y
            // and sum
            int sm1 = 0, sm2 = 0;
            // x -- y
            // y -- x

            int curr1 = next[x];
            int curr2 = next[y];

            while(curr1 != y and curr2 != x) {
                if(curr1 != -1) {
                    sm1 += curr1;
                    curr1 = next[curr1];
                }
                
                if(curr2 != -1) {
                    sm2 += curr2;
                    curr2 = next[curr2];
                }
            }
            if(curr1 == y) {
                // x -- y 
                next[x] = y;
                prev[y] = x;
                cout << sm1 << "\n";
            }
            else {
                // y -- x
                next[y] = x;
                prev[x] = y;
                cout << sm2 << "\n";
            }
        }
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
