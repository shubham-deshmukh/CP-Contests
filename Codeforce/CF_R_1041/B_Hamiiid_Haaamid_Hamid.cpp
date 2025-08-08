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
    int n, x;
    cin >> n >> x;

    x -= 1;

    string s;
    cin >> s;

    int walls = count(s.begin(), s.end(), '#');
    if(walls == 0 or x == 0 or x == n-1) {
        cout << "1\n";
        return;
    }

    auto f = [&](string &s)->int {
        int left = 0;
        for(int i = x-1; i >= 0; i--) {
            if(s[i] == '#') {
                left = i+1;
                break;
            }
        }

        left += 1;

        int right = 0;
        for(int i = x+1; i < n; i++) {
            if(s[i] == '#') {
                right = n-i;
                break;
            }
        }

        right += 1;

        return min(left,right);
    };

    string t = s;
    t[x-1] = '#';
    int best = f(t);
    
    t = s;
    t[x+1] = '#';
    best = max(best,f(t));

    cout << best << "\n";
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
