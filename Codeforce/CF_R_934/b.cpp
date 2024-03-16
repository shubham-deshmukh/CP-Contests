#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../../../debug.h"
#else
#define debug(x...)
#endif

#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


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
    int n,k;
    cin >> n >> k;

    vector<int> A(n), B(n);
    for(auto &a: A) cin >> a;
    for(auto &b: B) cin >> b;

    set<int> sA(A.begin(), A.end());
    set<int> sB(B.begin(), B.end());

    vector<int> comm;
    vector<int> onlyA, onlyB;
    for(auto a: sA) {
        if(sB.count(a)) {
            comm.push_back(a);
        }
        else {
            onlyA.push_back(a);
        }
    }

    for(auto b: sB) {
        if(!sA.count(b)) {
            onlyB.push_back(b);
        }
    }


    if((int)comm.size() >= 2 * k) {

        for(int i = 0; i < 2*k; i++) cout << comm[i] << " "; cout << endl;
        for(int i = 0; i < 2*k; i++) cout << comm[i] << " "; 
        return;
    }

    int sz = (int)comm.size();
    // k 5
    vector<int> l, r;
    for(int i = 0 ; i < min(k, (int)onlyA.size()); i++) {
        l.push_back(onlyA[i]);
        l.push_back(onlyA[i]);
    }

    for(int i = 0 ; i < min(k, (int)onlyB.size()); i++) {
        r.push_back(onlyB[i]);
        r.push_back(onlyB[i]);
    }    

    // rem
    int rem = 2*k - 2 * min(k, (int)onlyA.size());

    for(int i = 0; i < rem; i++) {
        l.push_back(comm[i]);
        r.push_back(comm[i]);
    }

    for(auto x: l) cout << x << " "; cout << endl;
    for(auto x: r) cout << x << " ";

}
signed main() {
    // your code goes here
    fast;
    #ifndef ONLINE_JUDGE
        freopen("../../../input.txt", "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt", "w", stderr);
    #endif
    
    long long t = 1;
    cin >> t;
    
    while(t--) {
        solve();
        
        if(t > 0) cout << endl;
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";    
    return 0;
}
