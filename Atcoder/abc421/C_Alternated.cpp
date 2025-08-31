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

    n = n + n; 
    
    string t1(n,'A');
    // ABAB
    for(int i = 0; i < n; i++) {
        if(i&1)  t1[i] = 'B';
    }

    string t2(n,'B');
    // BABA
    for(int i = 0; i < n; i++) {
        if(i&1) t2[i] = 'A';
    }

    auto get = [&](const string &s, const string &t)->int {
        vector<int> oldA, newA;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'A') oldA.push_back(i);
            if(t[i] == 'A') newA.push_back(i);
        }
        
        int d = 0;
        for(int i = 0; i < (int)oldA.size(); i++) {
            d += abs(oldA[i]-newA[i]);
        }
        return d;
    };
    
    cout << min(get(s,t1),get(s,t2));    
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
