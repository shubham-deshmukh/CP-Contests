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
    string p, s;
    cin >> p >> s;

    int i = 0, j = 0;
    while(i < (int)p.size() and j < (int)s.size()) {
        // get L in p 
        int cnt = 0;
        while(i < (int)p.size() and p[i] == 'L') {
            i += 1;
            cnt += 1;
        }

        // get L in s 
        int cnt1 = 0;
        while(j < (int)s.size() and s[j] == 'L') {
            j += 1;
            cnt1 += 1;
        }

        if(cnt1 >= cnt and cnt1 <= 2*cnt) {

        }
        else {
            cout << "NO\n";
            return;
        }

        // get R in p
        cnt = 0;
        while(i < (int)p.size() and p[i] == 'R') {
            i += 1;
            cnt += 1;
        }

        // get R in s 
        cnt1 = 0;
        while(j < (int)s.size() and s[j] == 'R') {
            j += 1;
            cnt1 += 1;
        }

        if(cnt1 >= cnt and cnt1 <= 2*cnt) {

        }
        else {
            cout << "NO\n";
            return;
        }        
    }
    if(i < (int)p.size() or j < (int)s.size()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
