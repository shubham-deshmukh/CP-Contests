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
    int n, k;
    cin >> n >> k;

    vector<int> A(n), B(n);
    for(auto &a: A) cin >> a;
    for(auto &a: B) cin >> a;

    multiset<int> st;
    for(auto &b: B) {
        int rep = b - (b/k) * k;
        st.insert(rep);
    }

    multiset<int> rem;
    for(auto &a: A) {
        int rep = a - (a/k) * k;
        int rev = abs(k - rep);
        if(st.contains(rep)) {
            st.erase(st.find(rep));
        }
        else if(st.contains(rev)) {
            st.erase(st.find(rev));
        }
        else {
            cout << "NO\n";
            return;
        }
    }

    cout << (st.empty()?"YES\n":"NO\n");
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
